#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int n = s.size();

    int freq[26]{};
    for(char c:s) freq[c-'A']++;

    for(int i = 0; i<26; i++){
        if(n - freq[i] < freq[i] - 1){
            cout<<"-1";
            return 0;
        }
    }

    vector<int> res(n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<26; j++){
            if(freq[j]==0) continue;
            if(i!=0 && res[i-1]==j) continue;
            
            bool ok = true;

            for(int k = 0; k<26; k++){
                if(k==j) continue;
                if(n - i - 1 - freq[k] < freq[k] - 1){
                    ok = false;
                    res[i] = k;
                    freq[k]--;
                    break;
                }
            }

            if(ok){
                res[i] = j;
                freq[j]--;
            }
            break;
        }
    }

    for(int i:res) cout<<(char)(i+'A');
    
    return 0;
}
