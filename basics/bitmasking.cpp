 for(long long  mask = 0LL; mask < (1ULL << n); mask++) {
/*2^(n-1) = the number of all subsequences so we are shifting*/
long long sum_of_this_subset = 0LL;

for(long long  i = 0; i < n; i++) {

if(mask & (1 << i)) {
/*choosing the elements of the subsequences*/

sum_of_this_subset += a[i];

}

}

if(sum_of_this_subset == S) {

puts("YES");

return 0;

}}

puts("NO"); 
/*the snippet of using bitmasking to find all the subsequences in the array
and make sure the number n should be less than 63 or less than that due to
the time duration and the ability of shifting*/