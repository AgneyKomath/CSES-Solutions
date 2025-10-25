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

    int res = 1;
    for(int i = 0, j = 0; j < n; j++){
        i = max(i, last[a[j]] + 1);
        last[a[j]] = j;
        res = max(res, j - i + 1);
    }

    cout<<res;

    return 0;
}
