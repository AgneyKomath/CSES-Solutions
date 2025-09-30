#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    int rank = 0;
    vector<int> basis(31, 0);
    for(int x:a){
        for(int i = 30; i>=0; i--){
            if((x>>i) & 1){
                if(!basis[i]){
                    basis[i] = x;
                    rank++;
                    break;
                }
                else x ^= basis[i];
            }
        }
    }

    cout<<(1<<rank);
    
    return 0;
}
