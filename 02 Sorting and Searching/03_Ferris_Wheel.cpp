#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    sort(a.begin(), a.end());

    int res = 0;
    for(int i = 0, j = n-1; i<=j; j--){
        if(a[i] + a[j] <= x) i++;
        res++;
    }

    cout<<res;
    
    return 0;
}
