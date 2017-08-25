/*Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

 You may assume the integer do not contain any leading zero, except the number 0 itself.

 The digits are stored such that the most significant digit is at the head of the list.
 */
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int[] ret = new int[len + 1];
        if (digits[len - 1] < 9)//如果末位小于9，不进位
        {
            digits[len - 1]++;
            return digits;
        } else if (digits[len - 1] == 9)
        //如果末位为9，考虑进位
        {
            digits[len - 1] = 0;
            for (int i = len - 2; i != -1; i--) {
                if (digits[i] < 9) {
                    digits[i]++;
                    return digits;
                } else if (digits[i] == 9) {
                    digits[i] = 0;
                }
            }
            if (digits[0] == 0)//首位是0，应在首位前加上1
            {

                ret[0] = 1;
                for (int i = 0; i != len; i++)
                    ret[i + 1] = digits[i];
            } else return digits;
        }
        return ret;
    }
}