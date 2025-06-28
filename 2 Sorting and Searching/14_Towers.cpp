#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> k(n);
    for(int &i:k) cin>>i;

    multiset<int> st;
    for(int v:k){
        auto it = st.upper_bound(v);
        if(it != st.end()) st.erase(it);
        st.insert(v);
    }

    cout<<st.size();

    // // Vector instead of multiset
    // vector<int> st;
    // for(int i=0;i<n;i++){
    //     int val;cin>>val;

    //     auto it = upper_bound(st.begin(),st.end(),val);
    //     if(it==st.end()) st.push_back(val);
    //     else *it = val;
    // }
    // cout<<st.size();
    
    return 0;
}
