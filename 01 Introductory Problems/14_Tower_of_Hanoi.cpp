#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int dest, int aux){
    if(n==0) return;
    hanoi(n-1, src, aux, dest);
    cout<<src<<' '<<dest<<'\n';
    hanoi(n-1, aux, dest, src);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    cout<<(1<<n)-1<<'\n';
    hanoi(n, 1, 3, 2);

    return 0;
}
