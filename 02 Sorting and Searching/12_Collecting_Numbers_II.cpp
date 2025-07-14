#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int> a(n+1,0),mp(n+2,0);
    mp[0] = n+1;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]] = i;
    }

    int res=0;
    for(int i=1;i<=n;i++){
        if(mp[i]<mp[i-1]) res++;
    }

    while(m--){
        int x,y;
        cin>>x>>y;

        int xv = a[x];
        int yv = a[y];
        swap(a[x],a[y]);

        if(xv>yv) swap(xv,yv);

        bool flagBefore1 = (mp[xv-1]<mp[xv]);
        bool flagBefore2 = (mp[yv-1]<mp[yv]);
        bool flagBefore3 = (yv-xv==1)?0:(mp[xv]<mp[xv+1]);
        bool flagBefore4 = (mp[yv]<mp[yv+1]);

        swap(mp[xv],mp[yv]);

        bool flagAfter1 = (mp[xv-1]<mp[xv]);
        bool flagAfter2 = (mp[yv-1]<mp[yv]);
        bool flagAfter3 = (yv-xv==1)?0:(mp[xv]<mp[xv+1]);
        bool flagAfter4 = (mp[yv]<mp[yv+1]);

        res += flagBefore1 + flagBefore2 + flagBefore3 + flagBefore4 - flagAfter1 - flagAfter2 - flagAfter3 - flagAfter4;
        
        cout<<res<<'\n';
    }


    
    
    return 0;
}
