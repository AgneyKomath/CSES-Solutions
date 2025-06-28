#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int res = n;
    for(int i = 0; i<n-1; i++){
        int v;
        cin>>v;
        res -= v;
        res += i;
    }
    cout<<res;
    
    return 0;
}
