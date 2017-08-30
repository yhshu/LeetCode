/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//返回的字符串数组必须是使用malloc分配的
char **fizzBuzz(int n, int *returnSize) {
    *returnSize = n;// *returnSize 是需要返回的数组的个数
    char buf[10] = {0};// 放一行字符串
    char **ret = (char **) malloc(n * sizeof(char *));
    int i;
    for (i = 1; i != n + 1; ++i) {
        if (i % 15 == 0) sprintf(buf, "FizzBuzz");
        else if (i % 3 == 0) sprintf(buf, "Fizz");
        else if (i % 5 == 0) sprintf(buf, "Buzz");
        else sprintf(buf, "%d", i);
        ret[i - 1] = malloc(sizeof(buf));
        memcpy(ret[i - 1], buf,
               strlen(buf) + 1);//strlen是buf里字符串的长度，加1是为了复制‘\0’
        memset(buf, '\0', sizeof(buf));
    }
    return ret;
}