#include <vector>

using namespace std;
using ll =long long;

ll count_coprimes(ll n, ll r) {
    vector<ll> primes;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) primes.push_back(n);

    ll sum = 0;
    ll p_size = primes.size();
    
    for (ll mask = 1; mask < (1 << p_size); ++mask) {
        ll mult = 1;
        ll bits = 0;
        for (ll i = 0; i < p_size; ++i) {
            if (mask & (1 << i)) {
                bits++;
                mult *= primes[i];
            }
        }
        ll cur = r / mult;
        if (bits % 2 == 1) sum += cur;
        else sum -= cur;
    }
    return r - sum;
}