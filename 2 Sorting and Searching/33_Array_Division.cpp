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

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    int sm=0,mx=0;
    for(int &i:a){
        cin>>i;
        sm +=i;
        mx = max(mx,i);
    }

    int res=sm;

    int lo = mx,hi = sm;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        int tot=1,curr=0;
        for(int &i:a){
            if(curr+i>mid){
                tot++;
                curr=i;
            }
            else curr += i;
        }
        if(tot<=k){
            res = min(res,mid);
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout<<res<<'\n';
    
    return 0;
}
