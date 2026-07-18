#include <iostream>
#include <utility> // For std::swap

using namespace std;

// 1. Calculate GCD using the Euclidean Algorithm
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 2. Calculate LCM safely to prevent overflow
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // Edge case protection
    
    // Divide first, then multiply!
    return (a / gcd(a, b)) * b;
}