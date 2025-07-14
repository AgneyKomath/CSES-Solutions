#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> x(n);
    for(int &i:x) cin>>i;

    vector<int> pos(n,-1);
    for(int i = 0; i<n; i++){
        pos[x[i] - 1] = i;
    }

    int res = 1;
    for(int i = 1; i<n; i++){
        if(pos[i] < pos[i-1]) res++;
    }
    cout<<res;
    
    return 0;
}
