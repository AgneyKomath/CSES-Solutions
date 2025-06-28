#include <bits/stdc++.h>
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

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
 
    for(int i=0;i<n;i++){
        int target = x - a[i].first;
        int l = i+1, r = n-1,sum;
        while(l<r){
            sum = a[l].first + a[r].first;
            if(sum==target){
                cout<<a[i].second<<' '<<a[l].second<<' '<<a[r].second;
                return 0;
            }
            else if(sum>target) r--;
            else l++;
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    
    
    return 0;
}
