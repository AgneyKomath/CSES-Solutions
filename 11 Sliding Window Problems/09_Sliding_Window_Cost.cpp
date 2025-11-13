#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    long long sl = 0, su = 0;
    multiset<int> lower, upper;
    auto balance = [&](){
        if(lower.size() > upper.size() + 1){
            int v = *lower.rbegin();
            upper.insert(v);
            lower.extract(v);
            su += v;
            sl -= v;
        }
        else if(upper.size() > lower.size()){
            int v = *upper.begin();
            lower.insert(v);
            upper.extract(v);
            sl += v;
            su -= v;
        }
    };

    auto add = [&](int v){
        if(lower.empty() || *lower.rbegin() >= v){
            lower.insert(v);
            sl += v;
        }
        else{
            upper.insert(v);
            su += v;
        }
        balance();
    };

    auto remove = [&](int v){
        if(lower.count(v)){
            lower.extract(v);
            sl -= v;
        }
        else{
            upper.extract(v);
            su -= v;
        }
        balance();
    };

    auto get = [&](){
        long long m = *lower.rbegin();
        return m * lower.size() - sl + su - m * upper.size();
    };

    for(int i = 0; i < n; i++){
        add(a[i]);
        if(i >= k - 1){
            cout<<get()<<' ';
            remove(a[i - k + 1]);
        }
    }

    return 0;
}
