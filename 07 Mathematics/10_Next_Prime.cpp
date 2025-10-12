#include <bits/stdc++.h>
using namespace std;

// Segmented Sieve Approach
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int lim = 1e6;
    vector<int> prime(lim + 1, 1);
    prime[0] = prime[1] = 0;
    vector<long long> primes;
    for(int i = 2; i <= lim; i++){
        if(prime[i]){
            primes.emplace_back(i);
            for(long long j = 1ll * i * i; j <= lim; j += i){
                prime[j] = 0;
            }
        }
    }

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        n++;

        // largest prime gap below 10 ^ 12 is 540
        vector<int> isPrime(540, 1);
        for(int i:primes){
            for(long long j = max(1ll * i * i, (n + i - 1) / i * i); j < n + 540; j += i){
                isPrime[j - n] = 0;
            }
        }
        for(int i = 0; i<540; i++){
            if(isPrime[i]){
                cout<<n + i<<'\n';
                break;
            }
        }
    }
    
    return 0;
}

// // Simple Approach
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     auto prime = [&](long long n)->bool{
//         if(n < 2) return false;
//         if(n == 2) return true;
//         if(n % 2 == 0) return false;
//         for(int i = 3; 1ll * i * i <= n; i += 2){
//             if(n % i == 0) return false;
//         }
//         return true;
//     };

//     int t;
//     cin>>t;
//     while(t--){
//         long long n;
//         cin>>n;
//         n++;
//         while(!prime(n)) n++;
//         cout<<n<<'\n';
//     }
    
    
//     return 0;
// }
