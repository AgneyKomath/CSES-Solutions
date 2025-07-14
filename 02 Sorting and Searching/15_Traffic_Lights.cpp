#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int x,n;
    cin>>x>>n;

    vector<int> p(n);
    for(int &i:p) cin>>i;

    set<int> lights{0, x};
	multiset<int> dist{x};

    for(int val:p){
        auto it1 = lights.upper_bound(val);
        auto it2 = it1;
        it2--;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(val - *it2);
        dist.insert(*it1 - val);

        lights.insert(val);

        cout<<*dist.rbegin()<<' ';
    }
    
    return 0;
}
