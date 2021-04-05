#include <iostream>
#include <vector>
using namespace std;

/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。每行的第一个整数大于前一行的最后一个整数。

示例 1：

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3 输出：true

*/

class Solution {
public:

    int n, m;//global
    bool inMatrix(int x, int y) {
        return x>=0 && x<m && y>=0 && y<n;
    }
    //BST查找
    bool findTargetInMatrixBST(vector<vector<int> >& matrix, int target){
        m = matrix.size();
        n = matrix[0].size();

        int i = 0, j = n - 1;
        while (inMatrix(i, j)) {
            if (matrix[i][j] == target) {
                return true;
            } else if (target < matrix[i][j]) {
                j--;
            } else if (target > matrix[i][j]) {
                i++;
            }
        }
        return false;
    }

    //二分查找
    bool findTargetInMatrixBinSearch(vector<vector<int> > matrix, int target){
        m = matrix.size();
        n = matrix[0].size();

        int l = 0;
        int r = n * m - 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            int x = mid / n;
            int y = mid % n;
            if (target == matrix[x][y]){
                return true;
            }else if(target < matrix[x][y]){
                r = mid - 1;
            }else if(target > matrix[x][y]){
                l = mid + 1;
            }
        }
        return false;
    }

    //库函数实现二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        // if (m==1) {
         //   int y = lower_bound(matrix[0].begin(), matrix[0].end(),target) - matrix[0].begin();
         //   return y!=n && matrix[0][y] == target;
        //}

        vector<int> cols;
        for (int i=0;i<m;i++) cols.push_back(matrix[i][0]);
        int x = upper_bound(cols.begin(),cols.end(),target) - cols.begin() - 1;
        // [[1]] 2 end
        // [[1]] 1 end
        // [[1]] 0
        if (x < 0) return false;

        int y = lower_bound(matrix[x].begin(), matrix[x].end(),target) - matrix[x].begin();
        return y != n && matrix[x][y] == target;
    }
private:

};


int main(){
    Solution s;
    /*
    int a1[] = { 1, 2, 8, 9, };
	int a2[] = { 2, 4, 9, 12,};
	int a3[] = { 4, 7, 10, 13,};
	int a4[] = { 6, 8, 11, 15,};
	vector<vector<int>> arr;
	arr.push_back(vector<int>(a1, a1 + 4));
	arr.push_back(vector<int>(a2, a2 + 4));
	arr.push_back(vector<int>(a3, a3 + 4));
	arr.push_back(vector<int>(a4, a4 + 4));
    */
    int a1[4] = {1,3,5,7};
    int a2[4]= {10,11,16,20};
    int a3[4] = {23,30,34,60};
    int a4[4] = {25,35,42,70};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 4));
	matrix.push_back(vector<int>(a2, a2 + 4));
	matrix.push_back(vector<int>(a3, a3 + 4));
	matrix.push_back(vector<int>(a4, a4 + 4));
    // bool flag = s.findTargetInMatrixBST(matrix, 25);
    bool flag = s.findTargetInMatrixBinSearch(matrix, 25);
    cout<<flag <<endl;

    return 0;
}
//ps:测试通过