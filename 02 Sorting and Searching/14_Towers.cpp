#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> st;
    for(int i : a){
        if(st.empty() || st.back() <= i) st.push_back(i);
        else *upper_bound(st.begin(), st.end(), i) = i;
    }

    cout<<st.size();

    return 0;
}
