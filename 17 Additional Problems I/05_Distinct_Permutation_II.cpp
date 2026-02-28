#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    if(n == 1){
        cout<<"1";
        return 0;
    }

    if(n <= 3){
        cout<<"NO SOLUTION";
        return 0;
    }

    if(n == 4){
        cout<<"2 4 1 3";
        return 0;
    }

    int b = (n - 5) / 5;

    int curr = 0;
    for(int i = 0; i < b; i++){
        cout<<curr + 1<<' '<<curr + 3<<' '<<curr + 5<<' '<<curr + 2<<' '<<curr + 4<<' ';
        curr += 5;
    }

    cout<<curr + 1<<' '<<curr + 3<<' '<<curr + 5<<' '<<curr + 2<<' ';

    if(n % 5 == 0){
        cout<<curr + 4;
    }
    else if(n % 5 == 1){
        cout<<curr + 4<<' '<<curr + 6;
    }
    else if(n % 5 == 2){
        cout<<curr + 6<<' '<<curr + 4<<' '<<curr + 7;
    }
    else if(n % 5 == 3){
        cout<<curr + 6<<' '<<curr + 8<<' '<<curr + 4<<' '<<curr + 7;
    }
    else if(n % 5 == 4){
        cout<<curr + 4<<' '<<curr + 7<<' '<<curr + 9<<' '<<curr + 6<<' '<<curr + 8;
    }

    return 0;
}