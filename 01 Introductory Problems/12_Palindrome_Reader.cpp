#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int freq[26]{};
    for(char c : s) freq[c - 'A']++;

    int odd = -1;
    for(int i = 0; i < 26; i++){
        if(freq[i] & 1){
            if(odd != -1){
                cout<<"NO SOLUTION";
                return 0;
            }
            odd = i;
        }
    }

    for(int i = 0; i < 26; i++){
        cout<<string(freq[i] / 2, i + 'A');
    }

    if(odd != -1) cout<<char(odd + 'A');

    for(int i = 25; i >= 0; i--){
        cout<<string(freq[i] / 2, i + 'A');
    }

    return 0;
}
