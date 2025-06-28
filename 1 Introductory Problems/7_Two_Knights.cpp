#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int k = 1; k<=n; k++){
        int combinations = (k * k) * (k * k - 1) / 2;

        int bad = 0;
        if(n>=3) bad += 4*2 + ; // corners
        if(n>=4) bad += 


        int ans = ((i*i)*(i*i-1))/2 -4*(i-1)*(i-2);
        cout<<ans<<'\n';
    }

    
    return 0;
}
