#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    
    int n = s.size();

    int maxLen = 1;
    for(int i = 1, curr = 1; i<n; i++){
        if(s[i] == s[i-1]) curr ++;
        else curr = 1;
        maxLen = max(maxLen, curr);
    }

    cout<<maxLen;
    
    return 0;
}
