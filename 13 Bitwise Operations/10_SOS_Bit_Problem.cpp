#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;

    int m = __lg(*max_element(a.begin(), a.end())) + 1;
    int len = 1 << m;

    vector<int> sos1(len, 0), sos2(len, 0);
    for(int i : a){
        sos1[i]++;
        sos2[i]++;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < len; j++){
            if((j >> i) & 1){
                sos1[j] += sos1[j ^ (1 << i)];
            }
            else{
                sos2[j] += sos2[j ^ (1 << i)];
            }
        }
    }

    for(int i : a){
        cout<<sos1[i]<<' '<<sos2[i]<<' '<<n - sos1[i ^ (len - 1)]<<'\n';
    }

    return 0;
}