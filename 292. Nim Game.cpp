/*
 *You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 */

 /*
  *基本情况：当n = 4时，根据问题提示的建议，无论第一名玩家是哪一个，第二名玩家总是能够选择剩余的数字。

 对于1 * 4 <n <2 * 4，（n = 5，6，7），第一名玩家可以将初始号码相应减少为4，这将使死亡号码4留给第二名玩家。 即数字5,6,7是获得第一名的玩家的获奖号码。

 现在到下一个周期的开始，n = 8，无论第一个玩家选择哪个号码，都会将获胜号码（5,6,7）留给第二名玩家。 因此，8％4 == 0，再次是死亡人数。

 在第二种情况下，对于第（2 * 4 = 8）和（3 * 4 = 12）之间的数字，即9,10,11，再次是第一名玩家的获胜号码，因为第一名玩家总是可以减少号码 进入死亡人数8人。
  */

class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
};