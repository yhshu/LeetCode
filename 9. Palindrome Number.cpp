//Determine whether an integer is a palindrome. Do this without extra space.


class Solution {
public:
    bool isPalindrome(int x) {
        int reverse = 0; // 此处不要使用 long 或 long long
        int t = x;
		while (t > 0) // 负数不是回文数 
		{
            reverse = 10 * reverse + t % 10;
            t /= 10;
        }
		if(reverse == x)
			return true;
		else return false;
    }
};