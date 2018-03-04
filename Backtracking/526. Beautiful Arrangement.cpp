/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation:

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
 */

class Solution {
public:
    bool visited[20];

    void arrange(int pos, int &n) {
        // pos 表示位置，num 表示放置的数字
        if (pos == n + 1) {
            // num 的有效范围是[1, n]
            res++;
            return;
        }
        for (int num = 1; num <= n; num++) {
            if (!visited[num] && (pos % num == 0 || num % pos == 0)) {
                visited[num] = true;
                arrange(pos + 1, n);
                visited[num] = false;
            }
        }
    }

    int countArrangement(int N) {
        arrange(1, N);
        return res;
    }

private:
    int res = 0;
};