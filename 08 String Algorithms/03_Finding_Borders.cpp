#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    vector<int> lps(n, 0);
    for(int i = 1, len = 0; i < n; ){
        if(s[i] == s[len]){
            lps[i++] = ++len;
        }
        else if(len != 0){
            len = lps[len - 1];
        }
        else{
            lps[i++] = 0;
        }
    }

    vector<int> res;
    for(int i = lps[n - 1]; i > 0; i = lps[i - 1]){
        res.push_back(i);
    }
    
    reverse(res.begin(), res.end());
    for(int i : res) cout<<i<<' ';
    
    return 0;
}
