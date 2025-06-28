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

    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i:a) cin>>i;
    int i=0;

    int res=0,curr=0;

    for(int j=0;j<n;j++){
        curr += a[j];
        if(curr==x) res++;

        while(i<=j && curr>=x){
            curr -= a[i++];
            if(curr==x) res++;
        }
    }
    cout<<res<<'\n';
    
    return 0;
}
