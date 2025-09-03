#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int mxn = 1e6;
    vector<int> divs(mxn + 1, 0);
    for(int i = 1; i<=mxn; i++){
        for(int j = i; j<=mxn; j+=i){
            divs[j]++;
        }
    }

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        cout<<divs[x]<<'\n';
    }
    
    return 0;
}
