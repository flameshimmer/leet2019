﻿#include "stdafx.h"
//Given an array which consists of non-negative integers and an integer m, you can split the
//array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum
//among these m subarrays.
//
//Note:
//If n is the length of array, assume the following constraints are satisfied:
//1 ≤ n ≤ 1000
//1 ≤ m ≤ min(50, n)
//
//Examples:
//
//Input:
//nums = [7,2,5,10,8]
//m = 2
//
//Output:
//18
//
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8],
//where the largest sum among the two subarrays is only 18.

namespace Solution2019
{
	namespace SplitArrayLargestSum
	{
		namespace BinarySearch {
			// if we have cut+1 chunk and every chunk's sum can be controlled under max
			// return true, otherwise returns false
			bool doable(const vector<int>& nums, int cuts, long long max) {
				long long acc = 0;
				for (int num : nums) {
					if (acc + num <= max) { acc += num; }
					else {
						cuts--;
						acc = num;
						if (cuts < 0) { return false; }
					}
				}
				return true;
			}

			int splitArray(vector<int>& nums, int m) {
				long long left = 0; // maxElem in the array - if each chunk size is 1
				long long right = 0; // sum of the array - if the entire array is a single chunk
				for (int num : nums) {
					left = max(left, (long long)num);
					right += num;
				}

				while (left < right) {
					long long mid = left + (right - left) / 2;
					if (doable(nums, m - 1, mid)) {
						right = mid;
					}
					else {
						left = mid + 1;
					}
				}
				return left;
			}
		}

		namespace DP {
			int splitArray(vector<int>& nums, int m) {
				const int len = nums.size();
				vector<long long> sum(len);
				// spliting nums from 0 ~ j index into i groups.
				vector<vector<int>> dp(m + 1, vector<int>(len, INT_MAX));

				sum[0] = nums[0];
				for (int i = 1; i < len; i++) { sum[i] = sum[i - 1] + nums[i]; }

				for (int i = 0; i < len; i++) {
					dp[1][i] = sum[i];
				}

				for (int i = 2; i <= m; i++) {
					for (int j = i - 1; j < len; j++) {
						for (int k = 0; k < j; k++) {
							dp[i][j] = min(dp[i][j], max(dp[i - 1][k], (int)(sum[j] - sum[k])));
						}
					}
				}
				return dp[m][len - 1];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

