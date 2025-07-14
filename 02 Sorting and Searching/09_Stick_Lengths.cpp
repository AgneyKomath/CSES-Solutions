#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a)cin>>i;

    sort(a.begin(), a.end());

    int median = a[n/2];

    long long res = 0;
    for(auto i:a) res += abs(median - i);

    cout<<res;
    
    return 0;
}
