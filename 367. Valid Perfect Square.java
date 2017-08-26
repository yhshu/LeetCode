/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
 */
class Solution {
    public boolean isPerfectSquare(int num) {
        int[] perfectSquare = new int[47000];
        for (int i = 0; i != 46340; ++i) {
            perfectSquare[i] = i * i + 2 * i + 1;
        }
        for (int i = 0; i != 46340; ++i)
            if (num == perfectSquare[i])
                return true;
        return false;
    }
}