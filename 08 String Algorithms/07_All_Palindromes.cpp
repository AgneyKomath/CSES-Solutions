#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();
    int m = 2 * n + 1;

    string ip(m, '*');
    for(int i = 0; i < n; i++) ip[2 * i + 1] = s[i];

    int left = 0, right = 0;
    vector<int> len(m);
    for(int i = 0; i < m; i++){
        int l = 1;
        if(i <= right){
            l = min(right - i + 1, len[left + right - i]);
        }
        while(i - l >= 0 && i + l < m && ip[i - l] == ip[i + l]){
            l++;
            left = i - l + 1;
            right = i + l - 1;
        }
        len[i] = l;
    }

    vector<int> suff(m, 0);
    for(int i = m - 1; i >= 0; i--){
        int l = len[i];
        suff[i + l - 1] = max(suff[i + l - 1], l);
    }

    for(int i = m - 2; i >= 0; i--){
        suff[i] = max(suff[i], suff[i + 1] - 1);
    }

    for(int i = 1; i < m; i += 2){
        cout<<suff[i]<<' ';
    }

    return 0;
}