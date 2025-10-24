#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int res = 1;
    for(int i = 1, curr = 1; i < (int)s.size(); i++){
        if(s[i] == s[i - 1]) curr++;
        else curr = 1;
        res = max(res, curr);
    }

    cout<<res;

    return 0;
}
