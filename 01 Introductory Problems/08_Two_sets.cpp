#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    long long sum = 1ll * n * (n + 1) / 2;
    if(sum & 1){
        cout<<"NO";
        return 0;
    }

    sum /= 2;

    vector<int> st1, st2;

    for(int i = n; i >= 1; i--){
        if(i <= sum){
            sum -= i;
            st1.push_back(i);
        }
        else st2.push_back(i);
    }

    cout<<"YES\n";

    cout<<st1.size()<<'\n';
    for(int i : st1) cout<<i<<' ';
    cout<<'\n';

    cout<<st2.size()<<'\n';
    for(int i : st2) cout<<i<<' ';

    return 0;
}
