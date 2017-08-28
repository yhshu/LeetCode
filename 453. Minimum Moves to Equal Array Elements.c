/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */
#define INT_MAX 2147483647

int minMoves(int *nums, int numsSize) {
    int mov = 0;//返回的最小移动次数
    int i = 0;
    int min = INT_MAX;
    while (i != numsSize) {
        if (*(nums + i) < min)
            min = *(nums + i);
        i++;
    }
    i = 0;
    while (i != numsSize) {
        mov += (*(nums + i) - min);
        i++;
    }
    return mov;
}