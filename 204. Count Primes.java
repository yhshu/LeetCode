/*
Count the number of prime numbers less than a non-negative number, n.
 */
class Solution {
    public int countPrimes(int n) {
        boolean[] isPrime = new boolean[n + 10];
        for (int i = 2; i != isPrime.length; ++i)
            isPrime[i] = true;
        if (n <= 1)
            return 0;
        for (int i = 2; i != n; ++i) // 埃拉托斯特尼筛法 Sieve of Eratosthenes
        {
            for (int j = 2; ; ++j) {
                if (i * j > n)
                    break;
                isPrime[i * j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i != n; ++i)
            if (isPrime[i]) cnt++;
        return cnt;
    }
}