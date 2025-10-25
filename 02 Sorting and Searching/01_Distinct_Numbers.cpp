#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    cout<<a.size();

    // set<int> st(a.begin(),a.end());
    // cout<<st.size();

    return 0;
}
