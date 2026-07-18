#include <vector>

using namespace std;

// Builds the 1D prefix sum array
vector<long long> build_prefix_1D(int n, const vector<long long>& a) {
    // pref array size is n + 1, initialized to 0
    vector<long long> pref(n + 1, 0); 
    
    // a is 1-indexed (or shift by -1 if a is 0-indexed)
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i]; // a[i] assuming 'a' is 1-indexed
    }
    return pref;
}

// Queries the sum in range [L, R] (1-based)
long long query_1D(const vector<long long>& pref, int L, int R) {
    return pref[R] - pref[L - 1];
}