﻿#include "stdafx.h"

//Given a n x n matrix where each of the rows and columns are sorted in ascending
//order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth
//distinct element.
//
//Example:
//matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//return 13.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ n2.

namespace Solution2019
{
	namespace KthSmallestElementinaSortedMatrix
	{

		struct Elem {
			int r;
			int c;
			int v;
			bool operator<(const Elem& rhs) const {
				return v > rhs.v;
			}
		};

		int kthSmallest(vector<vector<int>>& matrix, int k) {
			int rowCount = matrix.size();
			int colCount = matrix[0].size();

			priority_queue<Elem> pq;
			for (int j = 0; j < colCount; j++) {
				pq.push({ 0, j, matrix[0][j] });
			}
			for (int i = 0; i < k - 1; i++) {
				auto [r, c, v] = pq.top();
				pq.pop();
				if (r == rowCount - 1) { continue; }
				pq.push({ r + 1, c, matrix[r + 1][c] });
			}
			return pq.top().v;
		}

		void Main() {
			vector<vector<int>> test = { {1,5,9},{10,11,13},{12,13,15} };
			print(kthSmallest(test, 8));
		}
	}
}

