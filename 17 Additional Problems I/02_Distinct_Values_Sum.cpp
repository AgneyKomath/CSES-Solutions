#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    for(int &i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin();

    vector<int> last(n, -1);
    long long res = 0, curr = 0;
    for(int i = 0; i < n; i++){
        curr += i - last[a[i]];
        last[a[i]] = i;
        res += curr;
    }

    cout<<res;

    return 0;
}