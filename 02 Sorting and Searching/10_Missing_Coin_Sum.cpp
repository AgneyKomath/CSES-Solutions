#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;
    
    sort(a.begin(),a.end());

    long long res=1;
    for(int i:a){
        if(i > res) break;
        res += i;
    }
    cout<<res;
    
    return 0;
}
