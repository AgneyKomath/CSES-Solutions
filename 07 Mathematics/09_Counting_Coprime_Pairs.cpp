#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> mp(1000001, 0);

    long long res = 0;
    for(int id = 0; id<n; id++){
        int x;
        cin>>x;

        vector<int> pf;
        if(x % 2 == 0){
            pf.push_back(2);
            while(x % 2 == 0) x /= 2;
        }
        for(int p = 3; p * p <= x; p += 2){
            if(x % p == 0){
                pf.push_back(p);
                while(x % p == 0) x /= p;
            }
        }
        if(x > 1) pf.push_back(x);  

        int m = pf.size();
        int nums = 0;
        for(int i = 1; i < (1 << m); i++){
            int p = 1;
            for(int j = 0; j<m; j++){
                if((i >> j) & 1){
                    p *= pf[j];
                }
            }
            nums += (__builtin_parity(i) ? 1 : -1) * mp[p];
            mp[p]++;
        }

        res += id - nums;
    }

    cout<<res;
    
    return 0;
}
