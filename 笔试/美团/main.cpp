#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> solution(vector<vector<int>> vec)
    {
        vector<vector<int>> vecT(vec[0].size(), vector<int>(vec.size(), 0));
        for(int i=0; i<vec.size(); i++)
        {
            for(int j=0; j<vec[0].size(); j++)
            {
                vecT[j][i] = vec[i][j];
            }
        }
        return vecT;
    }
};

//int main()
//{
//    int n, m;
//    cin>>n>>m;
//    vector<vector<int>> vec;
//    for(int i=0; i<n; i++)
//    {
//        vector<int> temp;
//        int t;
//        for(int j=0; j<m; j++)
//        {
//            cin>>t;
//            temp.push_back(t);
//        }
//        vec.push_back(temp);
//    }
//    Solution so;
//    vector<vector<int>> res = so.solution(vec);
//    for(auto& v: res)
//    {
//        for(int& i: v)
//        {
//            cout<<i<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}







class Solution2
{
public:
    vector<int> solution(const string& str)
    {
        if(str.empty()) return {};

        vector<int> res;
        int temp = 0;
        for(int i=0; i<str.size(); i++)
        {
            if(isdigit(str[i]))
            {
//                if(str[i] - '0' == 0 && temp == 0)
//                {
//                    continue;
//                }
//                else
//                {
                    temp *= 10;
                    temp += str[i] - '0';
//                }

            }
            else
            {
                if(i > 0 && isdigit(str[i-1]))
                {
                    res.push_back(temp);
                    temp = 0;
                }
            }
        }
        if(isdigit(str.back()))
            res.push_back(temp);

        sort(res.begin(), res.end());
        return res;
    }
};

//int main()
//{
//    string str("00a0b10c1023ddd");
////    cin>>str;

//    Solution2 so;
//    vector<int> res = so.solution(str);
//    for(auto& v: res)
//    {
//        cout<<v<<endl;
//    }
//    return 0;
//}



class Solution3
{
public:
    vector<int> solution(vector<int>& vec, int K)
    {
        if(vec.empty()) return {};

        unordered_map<int, int> umap;
        vector<int> res;

        int left = 0, right = 0;
        while(right < vec.size())
        {
            umap[vec[right]]++;
            right++;

            if(right-left == K)
            {
                int r = helper(umap);
                res.push_back(r);

                umap[vec[left]]--;
                left++;
            }
        }

        return res;
    }

    int helper(unordered_map<int, int>& umap)
    {
        map<int, int> mp;
        for(auto& p: umap)
        {
            mp[p.second] = p.first;
        }
        int res = 0, time = 0;
        for(auto& p: mp)
        {
            if(p.first > time)
                res = p.second;
            else
            {
                if(p.second < res)
                    res = p.second;
            }
        }
        return res;
    }
};




//int main()
//{
//    int n=5, K=3;
////    cin>>n>>K;

//    vector<int> vec{1,2,2,1,3};
////    for(int i=0; i<n; i++)
////    {
////        int temp;
////        cin>>temp;
////        vec.push_back(temp);
////    }

//    Solution3 so;
//    vector<int> res = so.solution(vec, K);
//    for(auto& v: res)
//    {
//        cout<<v<<endl;
//    }
//    return 0;
//}



class Solution5
{
public:
    int maxPos = 0;
    int curPos = 0;
// dfs
    void dfs(vector<vector<int>>& route, vector<int>& heights, int idx)
    {
        for(int i=0; i<route[0].size(); i++)
        {
            if(route[idx][idx] == 1 && heights[i] < heights[idx])
            {
                curPos++;
                maxPos = max(curPos, maxPos);
                route[idx][idx] = -1;
                dfs(route, heights, i);
                route[idx][idx] = 1;
                curPos--;
            }

        }
    }

    int solution(vector<vector<int>>& route, vector<int>& heights)
    {
        maxPos = 0;
        curPos = 0;
        for(int i=0; i<route.size(); i++)
        {
            dfs(route, heights, i);
        }

        return maxPos;
    }
};

int main()
{

    vector<int> heights{3,2,3,4,6};

    int n=5, m=4;
   // cin>>n>>m;
    vector<vector<int>> route(n, vector<int>(n, 0));
//    for(int i=0; i<n; i++)
//    {
//        int t;
//        cin>>t;
//        heights.push_back(t);
//    }
//    for(int i=0; i<m; i++)
//    {
//        int src, dst;
//        cin>>src>>dst;
//        route[src-1][dst-1] = 1;
//    }
    route[0][1] = 1;
    route[1][2] = 1;
    route[2][3] = 1;
    route[3][4] = 1;
    route[1][0] = 1;
    route[2][1] = 1;
    route[3][2] = 1;
    route[4][3] = 1;

    route[0][0] = 1;
    route[1][1] = 1;
    route[2][2] = 1;
    route[3][3] = 1;
    route[4][4] = 1;

    Solution5 so;
    int res = so.solution(route, heights);
    cout<<res;


    return 0;
}
