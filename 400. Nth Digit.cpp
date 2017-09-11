/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;//减1*9，减2*90，减3*900，……；即减掉所有个位数、十位数、百位数……
            ++len;//位数
            cnt *= 10;//9,90,900,……
            start *= 10;
        }
        start += (n - 1) / len;//定位所求数字所属的自然数
        string res = to_string(start);//将该自然数转为string
        return res[(n - 1) % len] - '0';//找到所求数字
    }
};