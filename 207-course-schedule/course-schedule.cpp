class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;

          vector<vector<int>> graph(n);
          vector<int> inDegree(n, 0);

          int preq_sz = prerequisites.size();
          for (auto& preq: prerequisites)
          {
              int a = preq[0];
              int b = preq[1];

              // b->a
              graph[b].push_back(a);
              inDegree[a]++;
          }

          queue<int> q;

          for (int i = 0; i < n; i++)
          {
              if (inDegree[i] == 0)
                q.push(i);
          }

          int cnt = 0;
          while(!q.empty())
          {
              int q_sz = q.size();
              for (int i = 0; i < q_sz; i++)
              {
                  int cur = q.front();
                  q.pop();

                  cnt++;

                  for (auto nei: graph[cur])
                  {
                      inDegree[nei]--;
                      if (inDegree[nei] == 0)
                        q.push(nei);
                  }
              }
          }

          return cnt == numCourses ? true : false;
    }
};