#include <bits/stdc++.h>
#define int long long
using namespace std;


int side(int x1, int x2, int y1, int y2, int x3, int y3){
    int x = ((y3-y1)*(x2-x1)) + x1*(y2-y1);

    x3 *= y2-y1;

    if(x==x3) return 0;
    else if(x3<x) return -1;
    else return 1;

}

int vert(int x1, int x2, int y1, int y2, int x3, int y3){
    int y = ((x3-x1)*(y2-y1)) + y1*(x2-x1);

    y3 *= x2-x1;

    if(y==y3) return 0;
    else if(y3<y) return -1;
    else return 1;
}


void solve(){
    int x1, x2, y1, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    int d1 = side(x1, x2, y1, y2, x3, y3);
    int d2 = side(x1, x2, y1, y2, x4, y4);
    int d3 = vert(x1, x2, y1, y2, x3, y3);
    int d4 = vert(x1, x2, y1, y2, x4, y4);

    if((d1+d2==0 || d1!=d2 ) && (d3+d4==0 || d3!=d4)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";



}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }


    
    
    return 0;
}
