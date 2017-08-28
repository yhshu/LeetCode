/*
 Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 */

int minMoves2(int *nums, int numsSize) {
    int *i = nums;
    int *j = nums + numsSize - 1;
    int a, b, temp;
    //冒泡排序
    for (a = 0; a != numsSize - 1; ++a) {
        for (b = 0; b != numsSize - a - 1; ++b) {
            if (*(nums + b) > *(nums + b + 1)) {
                temp = *(nums + b);
                *(nums + b) = *(nums + b + 1);
                *(nums + b + 1) = temp;
            }
        }
    }

    int mov = 0;
    while (i <= j) {
        mov += (*j - *i);
        i++;
        j--;
    }
    return mov;
}