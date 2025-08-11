#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    ordered_set st;
    for(int i = 1; i<=n; i++) st.insert(i);

    int curr = 0;
    for(int i = 0; i<n; i++){
        int sz = st.size();
        curr = (curr + k) % sz;
        auto it = st.find_by_order(curr);
        cout<<*it<<' ';
        st.erase(it);
    }
    
    return 0;
}
