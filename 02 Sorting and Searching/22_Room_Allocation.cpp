#include <bits/stdc++.h>
using namespace std;

// Set Approach
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<array<int, 3>> a(n);
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        a[i] = {s, e, i};
    }

    sort(a.begin(), a.end());

    int roomCount = 0;
    set<pair<int, int>> st;

    vector<int> res(n);
    for(auto [s, e, i]:a){
        if(st.empty() || st.begin()->first>=s){
            roomCount++;
            st.emplace(e, roomCount);
            res[i] = roomCount;
        }
        else{
            auto roomNo = st.begin()->second;
            st.erase(st.begin());
            st.emplace(e, roomNo);
            res[i] = roomNo;
        }
    }

    cout<<roomCount<<'\n';
    for(int i:res) cout<<i<<' ';

    return 0;
}

// // Vector Approach, Better Runtime
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;
    
//     vector<array<int, 3>> a(2*n);
//     for(int i = 0; i<n; i++){
//         int s, e;
//         cin>>s>>e;
//         a[2*i] = {s, 0, i};
//         a[2*i+1] = {e, 1, i};
//     }

//     sort(a.begin(), a.end());

//     int roomCount = 0;
//     vector<int> rooms, res(n);
//     for(auto [time, type, id]:a){
//         if(type==0){
//             if(rooms.empty()){
//                 roomCount++;
//                 res[id] = roomCount;
//             }
//             else{
//                 res[id] = rooms.back();
//                 rooms.pop_back();
//             }
//         }
//         else{
//             rooms.push_back(res[id]);
//         }
//     }

//     cout<<roomCount<<'\n';
//     for(int i:res) cout<<i<<' ';

//     return 0;
// }