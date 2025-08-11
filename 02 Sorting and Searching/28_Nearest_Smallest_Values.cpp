#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    stack<int> stack;
    for(int i = 0; i<n; i++){
        while(!stack.empty() && a[stack.top()]>=a[i]) stack.pop();
        if(stack.empty()) cout<<0<<' ';
        else cout<<stack.top() + 1<<' ';
        stack.push(i);
    }
    
    return 0;
}
