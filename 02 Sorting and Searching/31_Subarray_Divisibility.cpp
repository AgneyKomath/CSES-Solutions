#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> table(n,0);
    table[0]=1;

    int curr=0,res=0;

    for(int &i:a){
        curr = ((curr+i)%n+n)%n;
        res += table[curr];
        table[curr]++;
    }
    
    cout<<res<<'\n';
    
    return 0;
}
