#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int mxn = 1e6;
    
    int n;
    cin>>n;
    
    vector<int> freq(mxn + 1, 0);
    for(int i = 0; i<n; i++){
        int v;
        cin>>v;
        freq[v]++;
    }

    for(int i = mxn; i>=1; i--){
        int cnt = 0;
        for(int j = i; j<=mxn; j+=i){
            cnt += freq[j];
        }
        if(cnt >= 2){
            cout<<i;
            break;
        }
    }
    
    return 0;
}
