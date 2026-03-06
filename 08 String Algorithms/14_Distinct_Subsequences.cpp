#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    vector<int> last(26, 0);
    int res = 0;
    for(int i = 0; i < n; i++){
        int p = last[s[i] - 'a'];
        last[s[i] - 'a'] = res + 1;
        res = ((2 * res + 1 - p) % mod + mod) % mod;
    }
    cout<<res;

    return 0;
}