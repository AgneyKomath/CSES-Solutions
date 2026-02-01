#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> prev(n + 1, INF), curr(n + 1, INF);

    auto dnc = [&](int l, int r, int optl, int optr, auto &&dnc){
        if(l > r) return;
        int mid = (l + r) / 2;

        pair<ll, int> best = {INF, optl};

        for(int i = optl; i <= min(mid - 1, optr); i++){
            ll sum = pref[mid] - pref[i];
            ll val = prev[i] + sum * sum;
            best = min(best, make_pair(val, i));
        }

        curr[mid] = best.first;
        int opt = best.second;
        dnc(l, mid - 1, optl, opt, dnc);
        dnc(mid + 1, r, opt, optr, dnc);
    };

    prev[0] = 0;
    for(int i = 0; i < k; i++){
        dnc(1, n, 0, n - 1, dnc);
        swap(prev, curr);
    }
    cout<<prev[n];

    return 0;
}
