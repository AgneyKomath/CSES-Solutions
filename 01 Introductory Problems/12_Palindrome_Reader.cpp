#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int freq[26]{};

    for(auto c:s) freq[c-'A']++;

    int cnt=0;
    char mid;
    for(int i = 0; i<26; i++){
        if(freq[i] & 1){
            cnt++;
            mid = i+'A';
        } 
    }

    if(cnt>1){
        cout<<"NO SOLUTION";
        return 0;
    }

    for(int i = 0; i<26; i++){
        for(int j = 1; j<freq[i]; j+=2){
            char c = i + 'A';
            cout<<c;
        }
    }
    if(cnt) cout<<mid;
    for(int i = 25; i>=0; i--){
        for(int j = 1; j<freq[i]; j+=2){
            char c = i + 'A';
            cout<<c;
        }
    }
    
    return 0;
}
