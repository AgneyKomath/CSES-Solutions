#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    sort(s.begin(), s.end());

    set<string> res;
    auto backtrack = [&](int begin, auto &&self){
        if(begin>=s.size()){
            res.insert(s);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            swap(s[begin],s[i]);
            self(begin+1,self);
            swap(s[begin],s[i]);
        }
    };

    backtrack(0, backtrack);

    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<'\n';
    
    return 0;
}
