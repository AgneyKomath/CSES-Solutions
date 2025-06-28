#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<pair<int,int>> a(n);
    for(int i = 0; i<n; i++){
        int v;
        cin>>v;
        a[i] = {v,i+1};
    }

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    while(i<j){
        int v = a[i].first + a[j].first;
        if(v<x) i++;
        else if(v>x) j--;
        else{
            cout<<a[i].second<<' '<<a[j].second;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    // int n,target;
    // cin>>n>>target;

    // map<int,int> mp;

    // bool found = false;
    // int i1=-1,i2=-1;

    // for(int i=0;i<n;i++){
    //     int temp;
    //     cin>>temp;
    //     if(found) continue;

    //     int toFind = target-temp;
    //     if(!mp.count(toFind)){
    //         mp[temp] = i+1;
    //     }
    //     else{
    //         i1=mp[toFind];
    //         i2=i+1;
    //         found = true;
    //     }
    // }
    // if(i1==-1){
    //     cout<<"IMPOSSIBLE";
    // }
    // else{
    //     cout<<i1<<" "<<i2;
    // }

    
    return 0;
}
