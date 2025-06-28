#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    long long mx = -1e9;
    long long curr = 0;

    for(int i = 0; i<n; i++){
        curr += a[i];
        mx = max(mx, curr);
        if(curr < 0) curr = 0;
    }

    cout<<mx;
    
    return 0;
}
