#include <vector>

using namespace std;

// Builds the Prefix XOR array
vector<long long> build_prefix_xor(int n, const vector<long long>& a) {
    vector<long long> prefXor(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        prefXor[i] = prefXor[i - 1] ^ a[i]; // XOR operation
    }
    return prefXor;
}

// Queries the XOR sum in range [L, R]
long long query_xor(const vector<long long>& prefXor, int L, int R) {
    return prefXor[R] ^ prefXor[L - 1]; // XOR instead of subtraction
}