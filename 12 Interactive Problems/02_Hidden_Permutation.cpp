#include <bits/stdc++.h>
using namespace std;

int query(int i, int j){
    cout<<"? "<<i+1<<" "<<j+1<<endl;
    string res;
    cin>>res;
    return res=="YES";
}

vector<int> pos;

void mergeSort(int l, int r){
    if(l==r) return;
    
    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);

    int n = mid - l + 1;
    int m = r - mid;

    vector<int> a(pos.begin()+l, pos.begin()+mid+1);
    vector<int> b(pos.begin()+mid+1, pos.begin()+r+1);

    int i = 0, j = 0, k = l;
    while(i<n && j<m){
        if(query(a[i], b[j])) pos[k++] = a[i++];
        else pos[k++] = b[j++];
    }
    while(i<n) pos[k++] = a[i++];
    while(j<m) pos[k++] = b[j++];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    pos.resize(n);
    iota(pos.begin(), pos.end(), 0);
    mergeSort(0, n-1);
    
    vector<int> res(n);
    for(int i = 0; i<n; i++){
        res[pos[i]] = i+1;
    }

    cout<<"! ";
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    
    return 0;
}