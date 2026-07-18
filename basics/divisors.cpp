
/*finding all divisors of any number starting from 1 in O(sqrt(n))*/
using ll=long long;


void findDivisors(ll n) {
   for (ll i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
         if (n / i == i) {
            cout << i << " ";
         }
         else {
            cout << i << " " << n / i << " ";
         }
      }
   }
   cout << endl;
}