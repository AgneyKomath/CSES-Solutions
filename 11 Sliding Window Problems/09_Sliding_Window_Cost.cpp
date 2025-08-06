#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    multiset<int> lower, upper;
    long long sum1 = 0, sum2 = 0;

    auto balance = [&](){
        if(lower.size()>upper.size()+1){
            int val = *lower.rbegin();
            upper.insert(val);
            lower.erase(prev(lower.end()));
            sum2 += val;
            sum1 -= val;
        }
        else if(upper.size()>lower.size()){
            int val = *upper.begin();
            lower.insert(val);
            upper.erase(upper.begin());
            sum1 += val;
            sum2 -= val;
        }
    };

    auto add = [&](int v){
        if(lower.empty()|| v<= *lower.rbegin()){
            lower.insert(v);
            sum1 += v;
        } 
        else{
            upper.insert(v);
            sum2 += v;
        } 
        balance();
    };
    
    auto remove = [&](int v){
        if(upper.find(v)!=upper.end()){
            upper.erase(upper.find(v));
            sum2 -= v;
        }
        else if(lower.find(v)!=lower.end()) {
            lower.erase(lower.find(v));
            sum1 -= v;
        }
        balance();
    };

    for(int i = 0, j = 0; j<n; j++){
        add(a[j]);
        if(j-i+1==k){
            int med = *lower.rbegin();
            int n1 = lower.size();
            int n2 = upper.size();
            long long res = 1ll * med * n1 - sum1 + sum2 - 1ll * med * n2;
            cout<<res<<' ';
            remove(a[i++]);
        }
    }
    
    return 0;
}
