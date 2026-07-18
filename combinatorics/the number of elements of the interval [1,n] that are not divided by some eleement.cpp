#include <iostream>
#include <vector>
#include <numeric> // Required for std::gcd

using namespace std;
using ll = long long;

// Counts how many numbers in [1, r] are NOT divisible by ANY number in array 'p'
ll solve_general(ll r, const vector<ll>& p) {
    if (r <= 0) return 0;
    
    ll sum = 0;
    ll sz = p.size();
    
    // Iterate over all subsets using 1LL to prevent 32-bit shift overflow
    for (ll msk = 1; msk < (1LL << sz); ++msk) {
        ll lcm_val = 1;
        ll bits = 0;
        bool overflow = false;

        for (ll i = 0; i < sz; ++i) {
            if (msk & (1LL << i)) {
                ++bits;
                
                // 1. Calculate the Greatest Common Divisor
                ll g = std::gcd(lcm_val, p[i]);
                
                // 2. Safely check if the new LCM will exceed 'r'
                if (lcm_val / g > r / p[i]) {
                    overflow = true;
                    break;
                }
                
                // 3. Calculate true LCM (replaces simple multiplication)
                lcm_val = (lcm_val / g) * p[i];
            }
        }
        
        // If the LCM exceeds r, n / LCM == 0, so skip it
        if (overflow) continue;

        ll cur = r / lcm_val;
        
        // Add for odd number of elements, subtract for even
        if (bits % 2 == 1) {
            sum += cur;
        } else {
            sum -= cur;
        }
    }
    
    // Total numbers (r) minus the overlapping multiples (sum)
    return r - sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll r = 24;
    // This array can now safely contain ANY numbers, even with shared factors
    vector<ll> p = {4, 6}; 
    
    cout << solve_general(r, p) << "\n"; // Will correctly output 16
    
    return 0;
}