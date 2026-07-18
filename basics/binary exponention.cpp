#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

const int mod = 1e9 + 7;

ll power(ll x, ll n) { // O(log n)
  ll ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0
}