/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

public class Solution {
    public boolean isValid(String s) 
	{
        char []array = s.toCharArray();
		if(s.length() == 0)
			return true;
		else if(s.length() % 2 != 0)
			return false;
		Stack<Character> stack = new Stack<Character>();
		for(int i = 0; i != s.length(); ++i)
		{
			if(array[i] == '(' || array[i] == '{' || array[i] == '[')
				stack.push(array[i]);
			else // array[i]是反括号
			{
				if(stack.isEmpty())
					return false;
				char ch = stack.pop();
				if(!((ch == '(' && array[i] == ')') || (ch == '{' && array[i] == '}') ||(ch == '[' && array[i] == ']') ))
					return false;
			}
		}
		if(!stack.isEmpty())  // 栈应该被pop完
			return false; 
		return true; 
    }
}