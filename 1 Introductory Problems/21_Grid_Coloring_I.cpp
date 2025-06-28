#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i:a) cin>>i;
    vector<string> res(n, string(m, '.'));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            bool flag = false;
            int ind = a[i][j] - 'A';
            for(int k = 1; k<=3; k++){
                char c = ((ind+k)%4) + 'A';
                if(i>0 && res[i-1][j]==c) continue;
                if(j>0 && res[i][j-1]==c) continue;
                res[i][j] = c;
                flag = true;
            }
            if(!flag){
                cout<<"IMPOSSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 0; i<n; i++) cout<<res[i]<<'\n';
    
    return 0;
}
