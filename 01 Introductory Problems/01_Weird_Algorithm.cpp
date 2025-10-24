#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;

    while(n != 1){
        cout<<n<<' ';
        n = n & 1 ? 3 * n + 1 : n / 2;
    }
    cout<<1;

    return 0;
}
