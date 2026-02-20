#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int B = 31;

    vector<int> basis(B);
    int rank = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        for(int j = B - 1; j >= 0; j--){
            if((x >> j) & 1){
                if(!basis[j]){
                    basis[j] = x;
                    rank++;
                    break;
                }
                else x ^= basis[j];
            }
        }
    }

    if(n - rank >= 18){
        for(int i = 0; i < k; i++){
            cout<<"0 ";
        }
        return 0;
    }

    int mult = 1 << (n - rank);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    int curr = 0;

    while(k > 0){
        auto [v, id] = pq.top();
        pq.pop();
        for(int i = 0; i < min(k, mult); i++){
            cout<<v<<' ';
        }
        curr = v;
        k -= mult;
        for(int i = id; i < B; i++){
            int x = v ^ basis[i];
            if(x > curr){
                pq.emplace(x, i + 1);
            }
        }
    }

    return 0;
}