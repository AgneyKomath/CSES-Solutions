#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    auto query = [](int v)->bool{
        cout<<"? "<<v<<endl;
        string res;
        cin>>res;
        return res=="YES";
    };

    int lo = 1, hi = 1e9;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(query(mid)) lo = mid+1;
        else hi = mid;
    }

    cout<<"! "<<hi<<endl;
    
    return 0;
}
