#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	vector<string> a(n);
	for(auto &i:a) cin>>i;
	
	string res;
	vector<vector<bool>> vis(n, vector<bool>(n, 0));
	vector<pair<int, int>> q, nq;
	q.push_back({0, 0});
	vis[0][0] = 1;
	while(!q.empty()){
        char smallest = 'Z';
	    for(auto &[r, c]:q) smallest = min(smallest, a[r][c]);
	    res.push_back(smallest);
 
        nq.clear();
	    for(auto &[r, c]:q){
	        if(a[r][c]!=smallest) continue;
	        if(r!=n-1 && !vis[r+1][c]) {
	            vis[r+1][c] = 1;
	            nq.emplace_back(r+1, c);
	        }
	        if(c!=n-1 && !vis[r][c+1]){
	            vis[r][c+1] = 1;
	            nq.emplace_back(r, c+1);
	        } 
	    }
	    swap(q, nq);
	}
	cout<<res;

    return 0;
}