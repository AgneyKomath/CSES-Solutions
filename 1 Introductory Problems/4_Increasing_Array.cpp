#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int maxSoFar = 0;
    long long res = 0;

    for(int i = 0; i<n; i++){
        int v;
        cin>>v;
        if(v > maxSoFar) maxSoFar = v;
        else res += maxSoFar - v; 
    }

    cout<<res;
    
    return 0;
}
