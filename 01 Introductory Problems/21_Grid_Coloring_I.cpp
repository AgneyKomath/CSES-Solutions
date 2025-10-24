#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    vector<string> res(n, string(m, '.'));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c = a[i][j] - 'A';
            bool flag = false;

            for(int k = 1; k <= 3; k++){
                char nc = (c + k) % 4 + 'A';
                if(i > 0 && res[i - 1][j] == nc) continue;
                if(j > 0 && res[i][j - 1] == nc) continue;

                res[i][j] = nc;
                flag = true;
                break;
            }

            if(!flag){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(auto &i : res) cout<<i<<'\n';

    return 0;
}
