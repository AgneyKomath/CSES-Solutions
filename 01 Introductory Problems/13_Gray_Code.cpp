#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int len = 1 << n;

    vector<string> res(len, string(n, '0'));

    for(int i = 0; i < n; i++){
        int md = 1 << (i + 2);
        int lb = 1 << i;
        for(int j = 0; j < len; j++){
            if((j % md) >= lb && (j % md) <= (3 * lb - 1)){
                res[j][n - i - 1] = '1';
            }
        }
    }

    for(auto i : res) cout<<i<<'\n';

    return 0;
}

/*
n = 4
0000
0001
0011
0010
0110
0111
0101
0100
1100
1101
1111
1110
1010
1011
1001
1000

see the pattern for each bit

*/