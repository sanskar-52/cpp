#include <vector>
#include <utility>
#include <queue>

using namespace std;
class Solution
{
private:
  int BFS(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q;
    int rows = grid.size();
    int columns = grid[0].size();
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
        }
      }
    }
    int minutes = 0;
    if (q.empty())
      return 0;

    while (!q.empty())
    {
      int n = q.size();
      minutes++;
      for (int i = 0; i < n; i++)
      {
        pair<int, int> front = q.front();
        q.pop();
        // up
        if (front.first - 1 >= 0 && grid[front.first - 1][front.second] == 1)
        {
          grid[front.first - 1][front.second]++;
          q.push({front.first - 1, front.second});
        }
        // down
        if (front.first + 1 < rows && grid[front.first + 1][front.second] == 1)
        {
          grid[front.first + 1][front.second]++;
          q.push({front.first + 1, front.second});
        }
        // left
        if (front.second - 1 >= 0 && grid[front.first][front.second - 1] == 1)
        {
          grid[front.first][front.second - 1]++;
          q.push({front.first, front.second - 1});
        }
        // right
        if (front.second + 1 < columns && grid[front.first][front.second + 1] == 1)
        {
          grid[front.first][front.second + 1]++;
          q.push({front.first, front.second + 1});
        }
      }
    }
    return minutes - 1;
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int minutes = BFS(grid);

    int rows = grid.size();
    int columns = grid[0].size();
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if (grid[i][j] == 1)
          return -1;
      }
    }
    return minutes;
  }
};