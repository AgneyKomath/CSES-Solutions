#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int res = 0;
    while(n){
        n /= 5;
        res += n;
    }

    cout<<res;

    return 0;
}
