#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0] = x;
    for(int i = 1; i<n; i++){
        arr[i] = (1ll * a * arr[i-1] + b) % c;
    }

    long long res = 0, curr = 0;
    for(int i = 0, j = 0; j<n; j++){
        curr += arr[j];
        if(j-i+1==k){ 
            res ^= curr;
            curr -= arr[i++];
        }
    }
    cout<<res;
    
    return 0;
}
