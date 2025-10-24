#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int a, b;
        cin>>a>>b;

        if((a + b) % 3 != 0 || max(a, b) > 2 * min(a, b)) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}
