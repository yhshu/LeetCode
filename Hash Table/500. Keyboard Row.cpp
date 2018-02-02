/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 */

class Solution {
public:
    vector <string> findWords(vector <string> &words) {
        vector <string> res;
        unordered_set<char> firstRow = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I',
                                        'o', 'O', 'p', 'P'};
        unordered_set<char> secondRow = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K',
                                         'l', 'L'};
        unordered_set<char> thirdRow = {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};
        for (string word:words) {
            bool first = true, second = true, third = true;
            for (char c:word) {
                if (firstRow.find(c) == firstRow.end())
                    first = false;
                if (secondRow.find(c) == secondRow.end())
                    second = false;
                if (thirdRow.find(c) == thirdRow.end())
                    third = false;
            }
            if (first || second || third)
                res.push_back(word);
        }
        return res;
    }
};