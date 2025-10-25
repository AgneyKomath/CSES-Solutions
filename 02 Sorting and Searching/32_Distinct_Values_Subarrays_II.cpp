#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    for(int &i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin();

    long long res = 0;
    vector<int> freq(n, 0);
    for(int i = 0, j = 0, cnt = 0; j < n; j++){
        cnt += (++freq[a[j]] == 1);
        while(cnt > k){
            cnt -= (--freq[a[i++]] == 0);
        }
        res += j - i + 1;
    }

    cout<<res;

    return 0;
}
