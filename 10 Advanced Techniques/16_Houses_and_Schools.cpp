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

    vector<ll> pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] +  a[i];
    }

    vector<ll> left(n + 1), right(n + 1);
    left[0] = right[n] = 0;
    for(int i = 0; i < n; i++){
        left[i + 1] = left[i] + 1ll * a[i] * (i + 1);
    }
    for(int i = n - 1; i >= 0; i--){
        right[i] = right[i + 1] + 1ll * a[i] * (n - i);
    }

    auto leftSum = [&](int l, int r){
        if(l > r) return 0ll;
        ll sum = pref[r + 1] - pref[l];
        ll isum = left[r + 1] - left[l];
        return isum - sum * l;
    };

    auto rightSum = [&](int l, int r){
        if(l > r) return 0ll;
        ll sum = pref[r + 1] - pref[l];
        ll isum = right[l] - right[r + 1];
        return isum - sum * (n - r - 1);
    };

    vector<ll> prev(n + 1, INF), curr(n + 1, INF);

    auto dnc = [&](int l, int r, int optl, int optr, auto &&dnc){
        if(l > r) return;
        int mid = (l + r) / 2;

        pair<ll, int> best{INF, optl};

        for(int i = optl; i <= min(mid - 1, optr); i++){
            int mp = (i + mid) / 2;
            ll v1 = leftSum(i + 1, mp);
            ll v2 = rightSum(mp + 1, mid - 1);
            ll val = prev[i + 1] + v1 + v2;
            best = min(best, make_pair(val, i));
        }

        curr[mid + 1] = best.first;
        int opt = best.second;
        dnc(l, mid - 1, optl, opt, dnc);
        dnc(mid + 1, r, opt, optr, dnc);
    };

    for(int i = 0; i < n; i++){
        prev[i + 1] = rightSum(0, i - 1);
    }

    for(int _ = 2; _ <= k; _++){
        dnc(1, n - 1, 0, n - 1, dnc);
        swap(prev, curr);
    }

    ll res = INF;
    for(int i = 0; i < n; i++){
        res = min(res, prev[i + 1] + leftSum(i + 1, n - 1));
    }
    cout<<res;

    return 0;
}
