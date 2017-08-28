/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
 */

/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        // 三分查找
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            int res1 = guess(mid1);
            if (res1 == 0)
                return mid1;
            int res2 = guess(mid2);
            if (res2 == 0)
                return mid2;
            if (res1 > 0)
                low = mid1 + 1;
            else
                high = mid1 - 1;
            if (res2 > 0)
                low = mid2 + 1;
            else
                high = mid2 - 1;
        }
        return 0;
    }
}