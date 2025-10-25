#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n), b(m);
    for(int &i : a) cin>>i;
    for(int &i : b) cin>>i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    for(int i = 0, j = 0; i < n && j < m; ){
        if(a[i] > b[j] + k) j++;
        else if(a[i] < b[j] - k) i++;
        else{
            res++;
            i++;
            j++;
        } 
    }

    cout<<res;

    return 0;
}
