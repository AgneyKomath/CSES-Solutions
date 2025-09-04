#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
    
        int blocks = (n+k-1)/k;
        if(blocks>k){
            cout<<"IMPOSSIBLE\n";
            continue;
        }

        for(int i = 0; i<blocks; i++){
            for(int j = max(1, n - k * i - k + 1); j <= n - k * i; j++){
                cout<<j<<' ';
            }
        }
        cout<<'\n';

    }

    return 0;
}
