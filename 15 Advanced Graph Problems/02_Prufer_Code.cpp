#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n - 2);
    for(int &i : a){
        cin>>i;
        i--;
    } 

    vector<int> freq(n, 0);
    for(int i : a) freq[i]++;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        if(freq[i] == 0) pq.push(i);
    }

    for(int i : a){
        cout<<i + 1<<' '<<pq.top() + 1<<'\n';
        pq.pop();
        freq[i]--;
        if(freq[i] == 0) pq.push(i);
    }

    cout<<pq.top() + 1<<' '<<n;

    return 0;
}
