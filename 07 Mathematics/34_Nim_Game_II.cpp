#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int sum = 0;
        for(int i = 0; i < n; i++){
            int v;
            cin>>v;
            sum ^= v % 4;
        }

        cout<<(sum == 0 ? "second" : "first")<<'\n';
    }

    return 0;
}
