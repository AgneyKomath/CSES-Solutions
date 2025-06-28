#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<int> h(n);
	for(int &i:h) cin>>i;
	
	vector<int> left(n, -1), right(n, -1);
	vector<int> st;
	for(int i = 0; i<n; i++){
	    while(!st.empty() && h[st.back()]<=h[i]) st.pop_back();
	    if(!st.empty()) left[i] = st.back();
	    st.push_back(i);
	}
	st.clear();
	for(int i = n-1; i>=0; i--){
	    while(!st.empty() && h[st.back()]<=h[i]) st.pop_back();
	    if(!st.empty()) right[i] = st.back();
	    st.push_back(i);
	}

	vector<pair<int, int>> a(n);
	for(int i = 0; i<n; i++) a[i] = {h[i], i};
	sort(a.begin(), a.end());

	vector<int> dp(n, 1);
	for(auto [v, i]:a){
	    if(left[i]!=-1){
	        dp[left[i]] = max(dp[left[i]], 1 + dp[i]);
	    }
	    if(right[i]!=-1){
	        dp[right[i]] = max(dp[right[i]], 1 + dp[i]);
	    }
	}
    
	int res = *max_element(dp.begin(), dp.end());
	cout<<res;
}