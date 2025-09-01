#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> slope(int x1, int y1, int x2, int y2){
    int xd = x2-x1;
    int yd = y2-y1;
    int g = gcd(xd, yd);
    xd /= g;
    yd /= g;
    if(xd<0 || (xd==0 && yd<0)){
        xd *= -1;
        yd *= -1;
    }
    return {yd, xd};
}

pair<ll, ll> calc_b(pair<int, int> slope, int x1, int y1){
    auto [yd, xd] = slope;
    ll num = 1ll * y1 * xd - 1ll * x1 * yd;
    int g = gcd(xd, yd);
    num /= g;
    if(xd==0 && num<0) return {-num, xd};
    return {num, xd};
}

void solve(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    pair<int, int> m1 = slope(x1, y1, x2, y2);
    pair<int, int> m2 = slope(x3, y3, x4, y4);
    auto b1 = calc_b(m1, x1, y1);
    auto b2 = calc_b(m2, x3, y3);
    
    auto [yd1, xd1] = m1;
    auto [yd2, xd2] = m2;
    auto num1 = b1.first;
    auto num2 = b2.first;

    if(xd1==0 && xd2==0){
        if(x1 != x3){
            cout<<"NO\n";
            return;
        }
        if(max(y1, y2)>max(y3, y4)){
            if(min(y1, y2)<=max(y3, y4)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(min(y3, y4)<=max(y1, y2)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        return;
    }

    if(xd1==0 || xd2 == 0){

        long double y, x;

        if(xd1==0){
            y = ((long double)yd2 * x1 + num2)/xd2; 
            x = x1;
        }
        else{
            y = ((long double)yd1 * x3 + num1)/xd1; 
            x = x3;
        }

        if(-x+min(x1, x2) > 1e-9 || x-max(x1, x2) > 1e-9 || -y+min(y1, y2) > 1e-9 || y-max(y1, y2) > 1e-9 || -x+min(x3, x4) > 1e-9 || x-max(x3, x4) > 1e-9 || -y+min(y3, y4) > 1e-9 || y-max(y3, y4) > 1e-9){
            cout<<"NO\n";
        }
        else cout<<"YES\n";

        return;
    }

    if(m1==m2){
        if(b1 != b2){
            cout<<"NO\n";
            return;
        }

        if(max(x1, x2)>max(x3, x4)){
            if(min(x1, x2)<=max(x3, x4)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(min(x3, x4)<=max(x1, x2)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        
        return;
    }


    ll den = (1ll * xd2 * yd1 - 1ll * xd1 * yd2);
    
    long double x = ((long double)xd1 * num2 - (long double)xd2 * num1)/den; 
    long double y = ((long double)yd1 * num2 - (long double)yd2 * num1)/den;

    if(-x+min(x1, x2) > 1e-9 || x-max(x1, x2) > 1e-9 || -y+min(y1, y2) > 1e-9 || y-max(y1, y2) > 1e-9 || -x+min(x3, x4) > 1e-9 || x-max(x3, x4) > 1e-9 || -y+min(y3, y4) > 1e-9 || y-max(y3, y4) > 1e-9){
        cout<<"NO\n";
    }
    else cout<<"YES\n";

}

int main(){
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
