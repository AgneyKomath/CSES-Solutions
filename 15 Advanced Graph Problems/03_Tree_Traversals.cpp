#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> preorder(n), inorder(n);
    for(int &i : preorder){
        cin>>i;
        i--;
    } 
    for(int &i : inorder){
        cin>>i;
        i--;
    } 

    vector<int> pos(n);
    for(int i = 0; i < n; i++) pos[inorder[i]] = i;

    auto rec = [&](int l, int r, int &id, auto &&rec){
        if(l > r) return;
        int u = preorder[++id];
        int p = pos[u];
        rec(l, p - 1, id, rec);
        rec(p + 1, r, id, rec);
        cout<<u + 1<<' ';
    };

    int id = -1;
    rec(0, n - 1, id, rec);

    return 0;
}
