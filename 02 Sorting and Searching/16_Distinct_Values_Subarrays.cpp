#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    // Last Seen Index
    map<int, int> last;
    long long res = 0;
    int left = 0;
    for(int i = 0; i<n; i++){
        int prev = (last.count(a[i])?last[a[i]]:-1);
        left = max(left, prev + 1);
        res += i - left + 1;
        last[a[i]] = i;
    }
    cout<<res<<'\n';

    // // Sliding Window
    // long long res = 0;
    // map<int, int> mp;
    // for(int i = 0, j = 0; j<n; j++){
    //     mp[a[j]]++;
    //     while(mp[a[j]]>1){
    //         mp[a[i++]]--;
    //     }
    //     res += (j-i+1);
    // }
    // cout<<res;

    
    return 0;
}
