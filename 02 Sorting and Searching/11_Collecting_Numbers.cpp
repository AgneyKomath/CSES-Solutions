#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        int v;
        cin>>v;
        pos[v - 1] = i;
    }

    int res = 1;
    for(int i = 1; i < n; i++){
        res += pos[i] < pos[i - 1];
    }

    cout<<res;

    return 0;
}
