/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
 */
public class Solution {
    public String reverseVowels(String s) {
        char[] cs = s.toCharArray();

        int start = 0;
        int end = cs.length - 1;

        while (start < end) {
            while (start < end && !isVowel(cs[start])) {
                start++;
            }

            while (start < end && !isVowel(cs[end])) {
                end--;
            }

            if (start < end) {
                swap(cs, start, end);
                start++;
                end--;
            }
        }

        return new String(cs);
    }

    private boolean isVowel(char b) {
        char c = Character.toLowerCase(b);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private void swap(char[] cs, int start, int end) {
        char temp = cs[start];
        cs[start] = cs[end];
        cs[end] = temp;
    }
}