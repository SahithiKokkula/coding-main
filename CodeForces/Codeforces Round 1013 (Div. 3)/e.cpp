#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e7;
vector<int> primes;

void precompute_primes() {
    vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (i <= MAX_N / i) { // Prevent integer overflow
                for (int j = i * i; j <= MAX_N; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

int main() {
    precompute_primes();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long count = 0;
        // Find the first prime greater than n
        auto it = upper_bound(primes.begin(), primes.end(), n);
        int num_primes = it - primes.begin();
        for (int i = 0; i < num_primes; ++i) { 
            count += n / primes[i];
        }
        printf("%lld\n", count);
    }
    return 0;
}