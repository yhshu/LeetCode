/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 */

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // 参考 264. Ugly Number II
        if (n <= 0)return 0;
        vector<int> pointer(primes.size() + 1, 0);
        vector<int> ugly(n + 1, INT_MAX); // ugly[i-1]表示第i个丑陋数
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            ugly[i] = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                ugly[i] = min(ugly[i], ugly[pointer[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); j++)
                if (ugly[i] == ugly[pointer[j]] * primes[j])
                    pointer[j]++;
        }
        return ugly[n - 1];
    }
};