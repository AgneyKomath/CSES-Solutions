#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> h(n), t(m);
    for(int &i : h) cin>>i;
    for(int &i : t) cin>>i;

    multiset<int> st(h.begin(), h.end());

    for(int i : t){
        auto it = st.upper_bound(i);
        if(it == st.begin()) cout<<-1<<'\n';
        else{
            it--;
            cout<<*it<<'\n';
            st.erase(it);
        }
    }

    return 0;
}
