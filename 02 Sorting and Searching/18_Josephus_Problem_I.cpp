#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    for(int i = 0; i < a.size(); i++){
        if(i & 1) cout<<a[i]<<' ';
        else a.push_back(a[i]);
    }

    return 0;
}
