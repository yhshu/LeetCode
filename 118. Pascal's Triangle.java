/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

//使用二级List
public class Solution {
    public List<List<Integer>> generate(int numRows) 
	{
		List<List<Integer>> triangle = new ArrayList<List<Integer>>(); // List是抽象的，不能初始化
		if(numRows < 0)
			return triangle;
		for(int j = 0; j < numRows; j++)
		{
			List<Integer> row = new ArrayList<Integer>();
			row.add(1);  //每行第一位是1
			for(int i = 1; i < j; i++)  // i=1即该行第二位；第一行和第二行不会执行此循环
			{
				List<Integer> preRow = triangle.get(j-1); //当前行的上一行
				int t = preRow.get(i-1) + preRow.get(i);
				row.add(t);
			}
			if(j != 0) // 除第一行外，末尾加1
				row.add(1);
			triangle.add(row);
		}
		return triangle;
    }
}