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

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    multiset<int> lower,upper;

    auto balance = [&](){
        if(lower.size()>upper.size()+1){
            upper.insert(*lower.rbegin());
            lower.erase(prev(lower.end()));
        }
        else if(upper.size()>lower.size()){
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    };

    auto add = [&](int v){
        if(lower.empty()|| v<= *lower.rbegin()) lower.insert(v);
        else upper.insert(v);
        balance();
    };

    auto remove = [&](int v){
        if(upper.find(v)!=upper.end())upper.erase(upper.find(v));
        else if(lower.find(v)!=lower.end()) lower.erase(lower.find(v));
        else cout<<"error"<<'\n';
        balance();
    };


    for(int i=0,j=0;j<n;j++){
        add(a[j]);
        if(j-i+1==k){
            cout<<*lower.rbegin()<<' ';
            remove(a[i]);
            i++;
        }
    }
    
    return 0;
}
