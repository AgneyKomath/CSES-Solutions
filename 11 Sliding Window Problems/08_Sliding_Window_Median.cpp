#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    multiset<int> lower, upper;

    auto balance = [&](){
        if(lower.size() > upper.size() + 1){
            upper.insert(*prev(lower.end()));
            lower.erase(prev(lower.end()));
        }
        else if(upper.size() > lower.size()){
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    };

    auto add = [&](int v){
        if(lower.empty() || *lower.rbegin() >= v) lower.insert(v);
        else upper.insert(v);
        balance();
    };

    auto remove = [&](int v){
        if(upper.count(v)) upper.extract(v);
        else lower.extract(v);
        balance();
    };

    for(int i = 0; i < n; i++){
        add(a[i]);
        if(i >= k - 1){
            cout<<*lower.rbegin()<<' ';
            remove(a[i - k + 1]);
        }
    }

    return 0;
}
