#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;
    
    long long sum = 0;
    for(int i:a) sum += i;

    long long mnDiff = sum;
    for(int i = 0; i<(1<<n); i++){
        long long curr = 0;
        for(int j = 0; j<n; j++){
            if(i & (1<<j)){
                curr += a[j];
            }
        }
        mnDiff = min(mnDiff, abs((sum - curr) - curr)) ;
    }    

    cout<<mnDiff;

    return 0;
}
