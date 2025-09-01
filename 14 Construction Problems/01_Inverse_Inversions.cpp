#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long k;
    cin>>n>>k;

    vector<int> res(n);

    for(int i = 1; i<=n; i++){
        if(n-i<=k){ 
            res[n-i] = i;
            k -= n-i;
        }
        else{
            res[k] = i;
            i++;
            for(int j = 0; i<=n; j++){
                if(j==k) continue;
                res[j] = i++;
            }
        }
    }

    for(int i:res) cout<<i<<' ';
    
    return 0;
}
