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

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<int> st;

    auto binarySearch=[&](int val){
        int lo = 0, hi = st.size()-1;
        int res=-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(a[st[mid]]<val){
                res = max(res,st[mid]);
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return res+1;
    };

    for(int i=0;i<n;i++){
        cout<<binarySearch(a[i])<<' ';
        while(!st.empty() && a[st.back()]>=a[i]) st.pop_back();
        st.push_back(i);
    }

    // vector<pair<int,int>> st;

    // auto binarySearch=[&](int val){
    //     int lo = 0, hi = st.size()-1;
    //     int res=0;
    //     while(lo<=hi){
    //         int mid = lo + (hi-lo)/2;
    //         if(st[mid].first<val){
    //             res = max(res,st[mid].second);
    //             lo = mid+1;
    //         }
    //         else hi = mid-1;
    //     }
    //     return res;
    // };

    // for(int i=1;i<=n;i++){
    //     int a;cin>>a;
    //     cout<<binarySearch(a)<<' ';
    //     while(!st.empty() && st.back().first>=a) st.pop_back();
    //     st.emplace_back(a,i);
    // }
        
    return 0;
}
