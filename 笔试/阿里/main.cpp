#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solution(unordered_map<int, vector<int>> r, int selfId, int otherId)
    {
        unordered_map<int, vector<int>> relationMap = r;
        int path = 0;

        unordered_set<int> visited;
        queue<int> que;
        que.push(selfId);
        while(!que.empty())
        {
            int n = que.size();
            ++path;
            for(int i=0; i<n; ++i)
            {
                int id = que.front();
                que.pop();
                vector<int> relation = relationMap[id];
                for(int other: relation)
                {
                    if(visited.count(other))
                        continue;
                    visited.insert(other);

                    if(other == otherId)
                        return path;
                    que.push(other);
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n, m;
    cin>>n>>m;
    unordered_map<int, vector<int>> relation;
    for(int i=0; i<m; i++)
    {
        int r1, r2;
        cin>>r1>>r2;
        relation[r1].push_back(r2);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int r1, r2;
        Solution so;
        cin>>r1>>r2;
        int res = so.solution(relation, r1, r2);
        cout<<res<<endl;
    }

    return 0;
}
