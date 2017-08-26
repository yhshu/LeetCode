/*
Given an integer, write a function to determine if it is a power of two.
 */
class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n > 0 && 1073741824 % n == 0)
            return true;
        return false;
    }
}