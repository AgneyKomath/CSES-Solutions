#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> freq(k, 0);
    set<int> mex;
    for(int i = 0; i<=k; i++) mex.insert(i);

    for(int i = 0, j = 0; j<n; j++){
        if(a[j]<k && ++freq[a[j]]==1){
            mex.erase(a[j]);
        }
        if(j-i+1==k){
            cout<<*mex.begin()<<" ";
            if(a[i]<k && --freq[a[i]]==0){
                mex.insert(a[i]);
            }
            i++;
        }
    }

    return 0;
}
