#include <bits/stdc++.h>
using namespace std;

// Recursive MergeSort Tree gives TLE so use Iterative

constexpr int mxn = 2e5;
vector<int> tree[2*mxn];

void merge(vector<int> &a, vector<int> &b, vector<int> & c){
    int n = a.size(), m = b.size();
    c.resize(n+m);

    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c[i+j] = a[i];
            i++;
        } 
        else{
            c[i+j] = b[j];
            j++;
        };
    }
    while(i<n){
        c[i+j] = a[i];
        i++;
    }
    while(j<m){
        c[i+j] = b[j];
        j++;
    }
}

void build(vector<int> &a){
    int n = a.size();
    for(int i = 0; i<n; i++) tree[n+i] = {a[i]};
    for(int i = n-1; i>=1; i--){
        merge(tree[2*i], tree[2*i+1], tree[i]);
    }
}

int count(vector<int> &a, int lo, int hi){
    return upper_bound(a.begin(), a.end(), hi) - lower_bound(a.begin(), a.end(), lo); 
}

int query(int l, int r, int lo, int hi, int n){
    l += n;
    r += n+1;

    int res = 0;

    while(l<r){
        if(l&1){
            res += count(tree[l], lo, hi);
            l++;
        }
        if(r&1){
            r--;
            res += count(tree[r], lo, hi);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    build(a);

    while(q--){
        int l, r, lo, hi;
        cin>>l>>r>>lo>>hi;
        l--;r--;
        cout<<query(l, r, lo, hi, n)<<'\n';
    }
    
    return 0;
}
