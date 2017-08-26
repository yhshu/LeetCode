/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 */
class Solution {
    public int firstUniqChar(String s) {
        int minIndex = Integer.MAX_VALUE;
        int index;
        char[] array = s.toCharArray();
        int[] cnt = new int[30];
        for (int i = 0; i != s.length(); ++i) {
            cnt[array[i] - 'a']++;
        }
        for (int i = 0; i != cnt.length; ++i)
            if (cnt[i] == 1) // 仅出现一次的字母
            {
                index = findFirst(array, (char) (i + 'a'));
                if (index < minIndex)
                    minIndex = index;
            }
        if (minIndex == Integer.MAX_VALUE) return -1;
        return minIndex;
    }

    public int findFirst(char[] array, char ch) {
        for (int i = 0; i != array.length; ++i)
            if (array[i] == ch)
                return i;
        return 30;
    }
}