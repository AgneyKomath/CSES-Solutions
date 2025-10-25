#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin>>x>>n;

    multiset<int> distances{x};
    set<int> lights{0, x};

    for(int i = 0; i < n; i++){
        int p;
        cin>>p;

        int prev = *(--lights.lower_bound(p));
        int next = *lights.upper_bound(p);

        distances.erase(distances.find(next - prev));

        distances.insert(next - p);
        distances.insert(p - prev);

        lights.insert(p);

        cout<<*distances.rbegin()<<' ';
    }

    return 0;
}
