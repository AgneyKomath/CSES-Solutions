#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    map<int, int> mp;
    int cnt = 0;
    for(int i = 0, j = 0; j<n; j++){
        if(++mp[a[j]]==1) cnt++;
        if(j-i+1==k){
            cout<<cnt<<' ';
            if(--mp[a[i++]]==0) cnt--;
        }
    }
    
    return 0;
}
