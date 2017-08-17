//Implement pow(x, n).

class Solution {
public:
    double myPow(double x, int n) 
	{
        if(x < 0 && n % 2 != 0)
            return -exp(n * log(abs(x)));
        return exp(n * log(abs(x)));
    }
};