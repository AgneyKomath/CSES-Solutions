#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int res = n;
    for(int i = 1; i <= n - 1; i++){
        int v;
        cin>>v;
        res += i - v;
    }

    cout<<res;

    return 0;
}
