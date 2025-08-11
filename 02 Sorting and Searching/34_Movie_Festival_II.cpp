#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<pair<int, int>> a(n);
    for(auto &[e, s]:a){
        cin>>s>>e;
    }

    sort(a.begin(), a.end());

    int res = 0;

    multiset<int> st;
    for(auto [e, s]:a){
        if(st.empty()){
            st.insert(e);
            res++;
            continue;
        }
        auto it = st.upper_bound(s);
        if(it!=st.begin()){
            it--;
            st.erase(it);
            st.insert(e);
            res++;
        }
        else{
            if(st.size()<k){
                st.insert(e);
                res++;
            }
        }
    }

    cout<<res;
    
    return 0;
}
