/*
Implement int sqrt(int x).

Compute and return the square root of x.
 */
class Solution {
    public int mySqrt(int x)
    // Newton's Method
    // f(x) = x^2 - n
    // x[i+1] = x[i] - f(x[i]) / f'(x[i])
    {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (res != last) {
            last = res;
            res = (res + x / res) / 2;
        }
        return (int) res;
    }
}