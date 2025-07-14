#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> a(n);
    iota(a.begin(),a.end(),1);

    int i=0;
    int cnt=0;

    while(cnt<n){
        while(a[i]==0)i = (i+1)%n;    
        i = (i+1)%n;

        while(a[i]==0)i = (i+1)%n;
        
        cout<<a[i]<<' ';
        a[i]=0;
        cnt++;
    }
    
    return 0;
}
