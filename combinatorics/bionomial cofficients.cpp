#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 2e6 + 9, mod = 1e9 + 7;

ll f[N], inv[N], finv[N];
void prec() {
  f[0] = 1;
  for (ll i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (ll i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (ll i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
ll ncr(ll n, ll r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}

void solve(){
    int n;
    cin>>n;
    cout<<((2*ncr(2*n-1,n))%mod-n%mod+mod)%mod<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    prec(); 

    
   

       solve();
    
    return 0;
}