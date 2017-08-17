/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    string intToRoman(int num) 
	{
        string ret;
		string Roman[20] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
        int Arabic[20] =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
		for (int i = 0; num != 0; ++i)
		{
			while(num >= Arabic[i])
			{
				num -= Arabic[i];
				ret += Roman[i];
			}
		}
		return ret;
    }
};