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
    
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]) cnt++;
    }
    cout<<cnt;

    // set<int> st(a.begin(),a.end());
    // cout<<st.size();
    
    return 0;
}
