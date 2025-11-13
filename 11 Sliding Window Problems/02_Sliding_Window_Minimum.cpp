#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = (1ll * a * arr[i - 1] + b) % c;
    }

    deque<int> q;
    int res = 0;
    for(int i = 0; i < n; i++){
        while(!q.empty() && arr[q.back()] >= arr[i]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) res ^= arr[q.front()];
        if(q.front() == i - k + 1) q.pop_front();
    }

    cout<<res;

    return 0;
}
