#include "stdafx.h"
//Design a Tic-tac-toe game that is played between two players on a n x n grid.
//
//You may assume the following rules:
//
//A move is guaranteed to be valid and is placed on an empty block.
//Once a winning condition is reached, no more moves is allowed.
//A player who succeeds in placing n of their marks in a horizontal, 
//vertical, or diagonal row wins the game.
//
//Example:
//Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
//
//TicTacToe toe = new TicTacToe(3);
//
//toe.move(0, 0, 1); -> Returns 0 (no one wins)
//|X| | |
//| | | |    // Player 1 makes a move at (0, 0).
//| | | |
//
//toe.move(0, 2, 2); -> Returns 0 (no one wins)
//|X| |O|
//| | | |    // Player 2 makes a move at (0, 2).
//| | | |
//
//toe.move(2, 2, 1); -> Returns 0 (no one wins)
//|X| |O|
//| | | |    // Player 1 makes a move at (2, 2).
//| | |X|
//
//toe.move(1, 1, 2); -> Returns 0 (no one wins)
//|X| |O|
//| |O| |    // Player 2 makes a move at (1, 1).
//| | |X|
//
//toe.move(2, 0, 1); -> Returns 0 (no one wins)
//|X| |O|
//| |O| |    // Player 1 makes a move at (2, 0).
//|X| |X|
//
//toe.move(1, 0, 2); -> Returns 0 (no one wins)
//|X| |O|
//|O|O| |    // Player 2 makes a move at (1, 0).
//|X| |X|
//
//toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
//|X| |O|
//|O|O| |    // Player 1 makes a move at (2, 1).
//|X|X|X|
//Follow up:
//Could you do better than O(n2) per move() operation?

namespace Solution2019
{
	namespace DesignTicTacToe
	{
		class TicTacToe {
		private:
			vector<int> r;
			vector<int> c;
			int d;
			int a;
			int sz;
		public:
			/** Initialize your data structure here. */
			TicTacToe(int n) {
				sz = n;
				d = 0;
				a = 0;
				r.resize(n);
				c.resize(n); //---> second param of resize is the fill value. if omitted is the auto init value. 
			}

			/** Player {player} makes a move at ({row}, {col}).
				@param row The row of the board.
				@param col The column of the board.
				@param player The player, can be either 1 or 2.
				@return The current winning condition, can be either:
						0: No one wins.
						1: Player 1 wins.
						2: Player 2 wins. */
			int move(int row, int col, int player) {
				int add = player == 1 ? 1 : -1;
				r[row] += add;
				c[col] += add;
				if (row == col) { d += add; } //---> only central line matters
				if (row + col + 1 == sz) { a += add; } // --->  this is very interesting
				if (abs(r[row]) == sz || abs(c[col]) == sz || abs(d) == sz || abs(a) == sz) {
					return player;
				}
				return 0;
			}
		};

		/**
		 * Your TicTacToe object will be instantiated and called as such:
		 * TicTacToe* obj = new TicTacToe(n);
		 * int param_1 = obj->move(row,col,player);
		 */

		void Main() {

			//["TicTacToe","move","move","move"]
			//[[2],[0,0,2],[1,1,1],[0,1,2]]

			TicTacToe* game = new TicTacToe(2);
			print(game->move(0, 0, 2));
			print(game->move(1, 1, 1));
			print(game->move(0, 1, 2));
		}
	}
}

