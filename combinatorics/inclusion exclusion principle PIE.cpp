#include <iostream>

using namespace std;
using ll=long long;

// Generic template for N <= 20 conditions
ll generic_iep(ll n) {
    ll total_ans = 0LL;
    
    // 1 << n is 2^n. We loop from 1 to 2^n - 1 (all non-empty subsets)
    for (ll mask = 1; mask < (1ULL << n); ++mask) {
        ll bits = __builtin_popcount(mask);
        
        ll current_intersection = 0; 
        
        // TODO: Calculate the intersection size for the active bits in 'mask'
       /* 
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                // Condition 'i' is active
            }
        }
        */
        
        // Add if odd number of conditions, subtract if even
        if (bits % 2 == 1) {
            total_ans += current_intersection;
        } else {
            total_ans -= current_intersection;
        }
    }
    return total_ans;
}