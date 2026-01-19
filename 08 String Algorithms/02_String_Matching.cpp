#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, p;
    cin>>s>>p;

    int n = s.size(), m = p.size();

    vector<int> lps(m, 0);
    for(int i = 1, len = 0; i < m; ){
        if(p[i] == p[len]){
            lps[i++] = ++len;
        }
        else if(len != 0){
            len = lps[len - 1];
        }
        else{
            lps[i++] = 0;
        }
    }

    int res = 0;
    for(int i = 0, j = 0; i < n; ){
        if(s[i] == p[j]){
            i++, j++;
            if(j == m){
                res++;
                j = lps[j - 1];
            }
        }
        else if(j != 0) j = lps[j - 1];
        else i++;
    }
    cout<<res;
    
    return 0;
}
