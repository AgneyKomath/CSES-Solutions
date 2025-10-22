#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin>>s>>t;

    int n = s.size(), m = t.size();

    vector<int> prev(m + 1), curr(m + 1);
    iota(prev.begin(), prev.end(), 0);

    for(int i = 0; i<n; i++){
        curr[0] = i + 1;

        for(int j = 0; j < m; j++){
            curr[j + 1] = min({1 + curr[j], 1 + prev[j + 1], (s[i] != t[j]) + prev[j]});
        }

        swap(prev, curr);
    }

    cout<<prev[m];

    return 0;
}
