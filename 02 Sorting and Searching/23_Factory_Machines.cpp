#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,t;
    cin>>n>>t;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    int low = 1,high = 1e18;

    int res = 1e18;
    while(low<=high){
        int mid = low + (high-low)/2;

        int sum =0;

        for(auto i:a){
            sum += mid/i;
            if(sum>=t) break;
        }

        if(sum<t){
            low = mid+1;
        }
        else{
            res = min(res,mid);
            high = mid-1;
        }
    }

    cout<<res<<'\n';
    
    return 0;
}
