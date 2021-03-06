/**
 * 区间并集
 *  输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

    解决：
    只要这个区间按照第一个元素(区间开始，记作first)排序，那么区间合并只需要关注已经合并区间的最后一个区
    间的last(第二个元素)与新区间的first(第一个元素)。
 * 
*/
#include <iostream>
#include <vector>
using namespace std;

//区间并集 
 class Solution {
        public:
            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                vector<vector<int>> ans;
                int n = intervals.size();
                if (n == 0 || n == 1) return intervals;
                sort(intervals.begin(), intervals.end(), [](auto& x, auto & y) {
                    return x[0] < y[0];
                });

                ans.push_back(intervals[0]);
                for (int i = 1; i < n; i++) {
                    // 拿到合并好的区间的最后一个区间
                    auto& last = ans.back();

                    // 新区间的第一个元素与最后一个区间的第二个元素比较
                    if (intervals[i][0] > last[1]) { // 产生了新区间
                        ans.push_back(intervals[i]);
                    } else if (intervals[i][1] > last[1]) { 
                        last[1] = intervals[i][1];
                    } 
                }

                return ans;
            }
 };

 /*
 区间合集

    输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
    输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

        我们需要区分有交集与没有交集情况。
        现有如下两个区间求交集。
        [a1,a2]
        [b1,b2]
        没有交集
        那就是两种情况：1） a2 < b1 2） a1 > b2

        有交集 a2>=b1 && a1 <= b2
        可以发现，有交集就是下面区间:

        [max(a1, b1), min(a2, b2)]
 
 */

 class Solution {
        public:
            vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
                vector<vector<int>> ans;
                int i = 0, j = 0;
                while (i < A.size() && j < B.size()) {
                    int a1 = A[i][0];
                    int a2 = A[i][1];
                    int b1 = B[j][0];
                    int b2 = B[j][1];
                    //  a2 < b1 || a1 > b2 无交集
                    if (a2 >= b1 && a1 <= b2) {
                        ans.push_back({max(a1, b1), min(a2, b2)});
                    }
                    if (b2 < a2) {
                        j++;
                    } else {
                        i++;
                    }
                }

                return ans;
            }
};
    