#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(ll n, ll r) {
    vector<ll> p;
    
    // SAFETY FIX 1: Use 'i <= n / i' instead of 'i * i <= n'
    // If n is close to the 64-bit limit, i * i can overflow long long.
    // i <= n / i achieves the exact same math without doing the multiplication.
    for (ll i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        p.push_back(n);
    }

    ll sum = 0;
    
    // SAFETY FIX 2: Use '1LL' for bitwise shifts.
    // A standard '1' is a 32-bit integer. Even though p.size() will be small,
    // using 1LL is the mathematically correct way to deal with 64-bit bitmasks.
    for (ll msk = 1; msk < (1LL << p.size()); ++msk) {
        ll mult = 1;
        ll bits = 0;
        bool overflow = false;

        for (ll i = 0; i < (ll)p.size(); ++i) {
            if (msk & (1LL << i)) {
                ++bits;
                
                // SAFETY FIX 3: The division-based overflow guard.
                // If mult * p[i] > r, then r / (mult * p[i]) will just be 0.
                // This prevents overflow AND heavily optimizes the code by skipping
                // combinations that are larger than the range 'r'.
                if (mult > r / p[i]) {
                    overflow = true;
                    break;
                }
                
                mult *= p[i];
            }
        }
        
        // If the product exceeded r, it contributes 0 to the sum, so we skip it.
        if (overflow) continue;

        ll cur = r / mult;
        
        if (bits % 2 == 1) {
            sum += cur;
        } else {
            sum -= cur;
        }
    }
    
    return r - sum;
}