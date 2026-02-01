#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line{
    ll m, b;
    Line(ll _m = 0, ll _b = 0){
        m = _m, b = _b;
    }
    ll eval(ll x){
        return m * x + b;
    }
};

bool bad(Line & l1, Line & l2, Line & l3){
    ll left = (l2.b - l1.b) * (l2.m - l3.m);
    ll right = (l3.b - l2.b) * (l1.m - l2.m);
    return left >= right;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> s(n), f(n);
    for(int &i : s) cin>>i;
    for(int &i : f) cin>>i;

    vector<ll> dp(n);

    deque<Line> q;
    q.push_back(Line(x, 0));

    for(int i = 0; i < n; i++){
        while(q.size() >= 2){
            ll v1 = q[0].eval(s[i]);
            ll v2 = q[1].eval(s[i]);
            if(v1 >= v2){
                q.pop_front();
            }
            else break;
        } 
        
        dp[i] = q.front().eval(s[i]);

        Line nl(f[i], dp[i]);
        while(q.size() >= 2){
            auto l1 = q[q.size() - 2], l2 = q[q.size() - 1];
            if(bad(l1, l2, nl)){
                q.pop_back();
            }
            else break;
        }
        q.push_back(nl);
    }

    cout<<dp[n - 1];

    return 0;
}