#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<tuple<int,int,int>> a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i] = {x,y,i};
    }

    sort(a.begin(),a.end());

    set<pair<int,int>> st;
    vector<int> res(n);

    int roomNo = 0;
    for(auto &[s,e,ind]:a){
        if(st.empty() || (*st.begin()).first>=s){
            roomNo++;
            st.insert({e,roomNo});
            res[ind] = roomNo;
        }
        else{
            auto tp = *st.begin();
            st.erase(st.begin());
            tp.first = e;
            res[ind] = tp.second;
            st.insert(tp);
        }
    }

    cout<<roomNo<<'\n';
    for(int i:res) cout<<i<<' ';
    cout<<'\n';
    
    return 0;
}


// // Ordered Set
// #include <bits/stdc++.h>
// using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set;

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n;
//     cin>>n;

//     vector<array<int,3>> a(n);
//     int ind = 0;
//     for(auto &[s,e,i]:a) {
//         cin>>s>>e;
//         i = ind++;
//     }
//     sort(a.begin(), a.end());

//     ordered_set st;
    
//     vector<int> res(n,0);
//     int id = 0;
    
//     for(auto &[s,e,ind]:a){
//         auto it = st.lower_bound({s, -1});
//         if(it == st.begin()){
//             ++id;
//             st.insert({e,id});
//             res[ind] = id;
//         } 
//         else{
//             it--;
//             int room = it->second;
//             st.erase(it);
//             st.insert({e,room});
//             res[ind] = room;
//         }
//     }

//     cout<<id<<'\n';
//     for(auto i:res) cout<<i<<' ';
    
//     return 0;
// }
