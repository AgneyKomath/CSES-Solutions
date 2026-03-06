#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    vector<int> lps(n), z(n);
    for(int i = 1, len = 0; i < n; ){
        if(s[i] == s[len]) lps[i++] = ++len;
        else if(len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }

    for(int i : z) cout<<i<<' '; 
    cout<<'\n';
    for(int i : lps) cout<<i<<' ';

    return 0;
}