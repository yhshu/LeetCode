/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
 */
class Solution {
    public boolean isPowerOfFour(int num) {
        if (num == 1 || num == 4 || num == 16 || num == 64 || num == 256 || num == 1024 || num == 4096 || num == 16384 || num == 65536 || num == 262144 || num == 1048576 || num == 4194304 || num == 16777216 || num == 67108864 || num == 268435456 || num == 1073741824)
            return true;
        return false;
    }
}