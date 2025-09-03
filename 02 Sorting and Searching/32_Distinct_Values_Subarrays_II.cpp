#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    long long res = 0;

    map<int, int> mp;
    for(int i = 0, j = 0, cnt = 0; j<n; j++){
        if(++mp[a[j]]==1) cnt++;
        while(cnt>k){
            if(--mp[a[i++]]==0) cnt--;
        }
        res += (j-i+1);
    }

    cout<<res;
    
    return 0;
}

// // Coordinate Compression
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, k;
//     cin>>n>>k;

//     vector<int> a(n);
//     for(int &i:a) cin>>i;

//     vector<int> b(a);
//     sort(b.begin(), b.end());
//     b.erase(unique(b.begin(), b.end()), b.end());
//     for(int &i:a) i = lower_bound(b.begin(), b.end(), i) - b.begin();
//     int sz = b.size();

//     long long res = 0;

//     vector<int> mp(sz, 0);
//     for(int i = 0, j = 0, cnt = 0; j<n; j++){
//         cnt += (++mp[a[j]]==1);
//         while(cnt>k) cnt -= (--mp[a[i++]]==0);
//         res += (j-i+1);
//     }

//     cout<<res;
    
//     return 0;
// }

