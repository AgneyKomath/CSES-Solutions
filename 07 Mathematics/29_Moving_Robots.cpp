#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;

    int n = 8;

    vector<vector<double>> res(n, vector<double>(n, 1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vector<vector<double>> prev(n, vector<double>(n, 0)), curr;
            prev[i][j] = 1;
            for(int it = 0; it < k; it++){
                curr.assign(n, vector<double>(n, 0));
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < n; c++){
                        int cnt = 0;
                        for(int d = 0; d < 4; d++){
                            int nr = r + dir[d], nc = c + dir[d + 1];
                            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                            cnt++;
                        }
                        for(int d = 0; d < 4; d++){
                            int nr = r + dir[d], nc = c + dir[d + 1];
                            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                            curr[nr][nc] += prev[r][c] / cnt;
                        }
                    }
                }
                swap(prev, curr);
            }
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    res[r][c] *= 1 - prev[r][c];
                }
            }
        }
    }

    double ans = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            ans += res[r][c];
        }
    }

    cout<<fixed<<setprecision(6)<<ans;

    return 0;
}
