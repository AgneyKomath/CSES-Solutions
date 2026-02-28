#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int seen = 0;

    string res;
    for(char c : s){
        seen |= 1 << (c - 'A');
        // 2 ^ 0 + 2 ^ 2 + 2 ^ 6 + 2 ^ 19
        if(seen == 524357){
            res += c;
            seen = 0;
        }
    }

    for(char c : "ACGT"){
        if(!((seen >> (c - 'A')) & 1)){
            res += c;
            break;
        }
    }

    cout<<res;

    return 0;
}