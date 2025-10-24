#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<bitset<200>> rows(n), cols(n);

    auto mex = [&](int r, int c)->int{
        auto x = rows[r] | cols[c];
        x.flip();
        return x._Find_first();
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int v = mex(i, j);
            rows[i].set(v);
            cols[j].set(v);
            cout<<v<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
