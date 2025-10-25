#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n + 1, 0), pos(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }

    int cnt = 1;
    for(int i = 2; i <= n; i++){
        cnt += pos[i] < pos[i - 1];
    }

    while(q--){
        int i, j;
        cin>>i>>j;

        int x = a[i], y = a[j];

        swap(a[i], a[j]);
        if(x > y) swap(x, y);

        int s1 = (pos[x - 1] < pos[x]) + (pos[y - 1] < pos[y]) + (y - x == 1 ? 0 : pos[x] < pos[x + 1]) + (pos[y] < pos[y + 1]);

        swap(pos[x], pos[y]);

        int s2 = (pos[x - 1] < pos[x]) + (pos[y - 1] < pos[y]) + (y - x == 1 ? 0 : pos[x] < pos[x + 1]) + (pos[y] < pos[y + 1]);

        cnt += s1 - s2;

        cout<<cnt<<'\n';
    }

    return 0;
}
