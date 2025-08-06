#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0] = x;
    for(int i = 1; i<n; i++){
        arr[i] = (1ll * a * arr[i-1] + b) % c;
    }

    int res = 0;
    deque<int> q;
    for(int i = 0, j = 0; j<n; j++){
        while(!q.empty() && arr[q.back()]>=arr[j]) q.pop_back();
        q.push_back(j);
        if(j-i+1==k){
            res ^= arr[q.front()];
            if(q.front()==i) q.pop_front();
            i++;
        }
    }   
    cout<<res;
    
    return 0;
}
