#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int cnt5=0;

    while(n){
        n /= 5;
        cnt5 += n;
    }

    cout<<cnt5;
    
    return 0;
}