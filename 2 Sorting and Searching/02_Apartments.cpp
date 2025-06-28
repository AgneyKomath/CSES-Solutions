#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n),b(m);
    for(int &i:a) cin>>i;
    for(int &i:b) cin>>i;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // int ans=0;
    // int j=0,i=0;
    // while(i<n&&j<m){
    //     int mx = a[i]+k;
    //     int mn = a[i]-k;
    //     if(b[j]<mn){
    //         j++;
    //         continue;
    //     }
    //     if(b[j]>mx){
    //         i++;
    //         continue;
    //     }
    //     ans++;
    //     i++;
    //     j++;
    // }
    // cout<<ans;

    int res = 0;
    for(int i = 0, j = 0; i<n && j<m; i++){
        while(j < m && a[i] > b[j] + k) j++;
        if(a[i] < b[j] - k) continue;
        if(j != m){
            res++;
            j++;
        }
    }
    cout<<res<<'\n';

    return 0;
}
