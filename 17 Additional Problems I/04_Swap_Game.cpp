#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull encode(vector<int> a){
    ull res = 0;
    for(int i = 0; i < 9; i++){
        res |= (ull)a[i] << (4 * i);
    }
    return res;
}

const vector<pair<int, int>> swaps{
    {0, 1},
    {1, 2},
    {3, 4},
    {4, 5},
    {6, 7},
    {7, 8},
    {0, 3},
    {3, 6},
    {1, 4},
    {4, 7},
    {2, 5},
    {5, 8},
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a(9);
    for(int &i : a) cin>>i;

    ull start = encode(a);
    ull target = encode({1, 2, 3, 4, 5, 6, 7, 8, 9});

    if(start == target){
        cout<<0;
        return 0;
    }

    unordered_set<ull> st;
    st.insert(start);

    vector<ull> prev{start};

    int dist = 0;
    while(1){
        dist++;
        vector<ull> curr;
        for(ull x : prev){
            for(auto &[i, j] : swaps){
                ull y = x;
                ull t = ((y >> (4 * i)) ^ (y >> (4 * j))) & 15ull;
                y ^= (t << (4 * i));
                y ^= (t << (4 * j));
                if(y == target){
                    cout<<dist;
                    exit(0);
                }
                if(!st.count(y)){
                    st.insert(y);
                    curr.push_back(y);
                }
            }
        }
        swap(prev, curr);
    }

    return 0;
}