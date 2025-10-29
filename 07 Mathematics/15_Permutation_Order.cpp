#include <bits/stdc++.h>
using namespace std;

vector<long long> facs(21);

void solve1(){
    int n;
    cin>>n;
    long long k;
    cin>>k;
    k--;

    vector<int> unused(n);
    iota(unused.begin(), unused.end(), 1);

    for(int i = n - 1; i >= 0; i--){
        int id = k / facs[i];
        k %= facs[i];
        cout<<unused[id]<<' ';
        unused.erase(unused.begin() + id);
    }

    cout<<'\n';
}

void solve2(){
    int n;
    cin>>n;

    vector<int> p(n);
    for(int &i : p) cin>>i;
    reverse(p.begin(), p.end());

    vector<int> used;
    long long res = 0;

    for(int i = 0; i < n; i++){
        int id = lower_bound(used.begin(), used.end(), p[i]) - used.begin();
        res += id * facs[i];
        used.insert(used.begin() + id, p[i]);
    }

    cout<<res + 1<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    facs[0] = 1;
    for(int i = 1; i <= 20; i++){
        facs[i] = facs[i - 1] * i;
    }
    
    int t;
    cin>>t;

    while(t--){
        int type;
        cin>>type;
        if(type == 1) solve1();
        else solve2();
    }

    return 0;
}
