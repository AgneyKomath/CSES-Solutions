#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>> a(2*n);

    for(int i = 0; i<n; i++){
        int arr,leave;
        cin>>arr>>leave;
        a[2*i] = {arr, 1};
        a[2*i+1] = {leave, -1};
    }
    sort(a.begin(),a.end());

    int curr = 0, res = 0;

    for(auto &[time, value]:a){
        curr += value;
        res = max(res,curr);
    }

    cout<<res;
    
    return 0;
}
