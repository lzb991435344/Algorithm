/*
岛屿数量
由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//bfs
//第一步：用visit标记是否访问过
class Solution {
private:
  int direct[4][2] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0}};
  vector<vector<bool> > visited;
  int n, m;

public:
  // bfs
  int numIslands(vector<vector<char> > &grid)
  {
    n = grid.size();
    if (n == 0)
    {
      return 0;
    }
    m = grid[0].size();

    //用于标记是否访问过
    visited = vector<vector<bool> >(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1' && !visited[i][j]) // 是小岛
        {
          visited[i][j] = true;
          // bfs逻辑
          ans++; // 岛屿数量
        } 
      }
    }
    return ans;
  }
  bool inArea(int x, int y)
  {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
};

//第二步：什么时候进队列，出队列
//进队列那就是满足特定条件，这里特定条件有：

//(1)新节点(上下左右四个方向的节点)未访问过
//(2)新节点是岛
//(3)新节点未超出边界

queue<pair<int, int> > q;
q.push({i, j});
while (!q.empty())
{
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int newX = x + direct[k][0];
      int newY = y + direct[k][1];
      if (inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1')
      {
        q.push({newX, newY});
        visited[newX][newY] = true;
      }
    }
}


//dfs框架
//与dfs框架不同在于两点：

//(1)visited[i][j] = true dfs内部处理
//(2)bfs逻辑替换未dfs逻辑
// 其他部分不变

for (int i = 0; i < n; i++)
{
  for (int j = 0; j < m; j++)
  {
    if (grid[i][j] == '1' && !visited[i][j])
    {
      int area = dfs(grid, i, j); // 这里变了 
      ans++;
    }
  }
}
// 其他部分不变

//dfs什么时候递归终止，如何防止死递归。

//防止死递归，前面有个visited即可防止
//递归终止：新节点不在网格区域或者在网格区域但是被访问过，再或者不是岛。

int dfs(vector<vector<char>> &grid, int x, int y)
{
    if (!inArea(x, y) || (inArea(x, y) && visited[x][y]) || grid[x][y] == '0')
      return 0;
    int area = 1; // (x,y)
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
      int newX = x + direct[i][0];
      int newY = y + direct[i][1];
      area += dfs(grid, newX, newY);
    }
    return area;
}

//完整code
//bfs

class Solution
{
private:
  int direct[4][2] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0}};
  vector<vector<bool>> visited;
  int n, m;

public:
  // bfs
  int numIslands(vector<vector<char> > &grid)
  {
    n = grid.size();
    if (n == 0)
    {
      return 0;
    }
    m = grid[0].size();

    visited = vector<vector<bool> >(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1' && !visited[i][j])
        {
          visited[i][j] = true;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty())
          {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
              int newX = x + direct[k][0];
              int newY = y + direct[k][1];
              if (inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1')
              {
                q.push({newX, newY});
                visited[newX][newY] = true;
              }
            }
          }
          ans++;
        }
      }
    }
    return ans;
  }
  bool inArea(int x, int y)
  {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
};



//dfs

class Solution
{
private:
  int direct[4][2] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0}};
  vector<vector<bool> > visited;
  int n, m;

public:
  int numIslands(vector<vector<char> > &grid)
  {
    n = grid.size();
    if (n == 0)
    {
      return 0;
    }
    m = grid[0].size();

    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1' && !visited[i][j])
        {
          int area = dfs(grid, i, j);
          ans++;
        }
      }
    }
    return ans;
  }

  int dfs(vector<vector<char> > &grid, int x, int y)
  {
    if (!inArea(x, y) || (inArea(x, y) && visited[x][y]) || grid[x][y] == '0')
      return 0;
    int area = 1; // (x,y)
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
      int newX = x + direct[i][0];
      int newY = y + direct[i][1];
      area += dfs(grid, newX, newY);
    }
    return area;
  }
  bool inArea(int x, int y)
  {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
};