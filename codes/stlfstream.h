#ifndef STLFSTREAM_H
#define STLFSTREAM_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void of_test()
{
    ofstream out("out.txt");
    if (out.is_open())
    {
        out << "This is a line.\n";
        out << "This is another line.\n";
        out.close();
    }
}

void if_test()
{
//    char buffer[256];
    char* buffer=new char[256];
    ifstream in("out.txt");

    if (!in.is_open())
    {
        cout << "Error opening file";
        return;
    }
    while (!in.eof())   //eof表示文本末尾
    {
        in.getline (buffer,20);
        cout << buffer << endl;
    }
    in.close();
}

vector<vector<int>> if_test2()
{
    string s;
    vector<int> temp;
    vector<vector<int>> res;
    ifstream in("matrix.txt");
    if (in.is_open())
    {
        while(in >> s)
        {
           if(s == "\\n")
           {
               res.push_back(temp);
               temp.clear();
           }
           else
           {
               temp.push_back(stoi(s));
           }
        }
        in.close();
        return res;
    }
    return {};
}

//迷宫问题
bool dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& out, vector<pair<int, int>>& path)
{
    if(matrix[i][j] != 1) return false;
    if(i == matrix.size()-1 && j == matrix[0].size()-1) return true;

    vector<int> direction{-1, 0, 1, 0, -1};
    matrix[i][j] = -1;

    bool res = false;
    for(int k=0; k<4; k++)
    {
        int x = i + direction[k];
        int y = j + direction[k+1];
        if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) continue;
        if(matrix[x][y] == 1)
        {
            out[x][y] = 1;
            path.push_back(make_pair(x, y));
            res = dfs(matrix, x, y, out, path);
            if(!res)
            {
                out[i][j] = 0;
                path.pop_back();
            }
            else  return true;
        }
    }
    matrix[i][j] = 1;
    return res;
}

bool dfs2(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& out, vector<pair<int, int>>& path)
{
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return false;
    if(matrix[i][j] == -1 || matrix[i][j] == 0) return false;
    if(i == matrix.size()-1 && j == matrix[0].size()-1)
    {
        out[i][j] = 1;
        path.push_back(make_pair(i, j));
        return true;
    }

    bool result = false;

    matrix[i][j] = -1;
    path.push_back(make_pair(i, j));
    result = dfs2(matrix, i+1, j, out, path) || dfs2(matrix, i, j+1, out, path)
        || dfs2(matrix, i, j-1, out, path) || dfs2(matrix, i-1, j, out, path);
    if (!result)
    {
        path.pop_back();
        out[i][j] = 0;
        matrix[i][j] = 1;
    }

    return result;
}


void findMatrixPath()
{
    vector<vector<int>> matrix = if_test2();
    if(matrix.empty() || matrix[0][0] != 1) return;
    vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
    vector<pair<int, int>> path;  //如果需要记录路径点坐标
    res[0][0] = 1;
    path.push_back(make_pair(0, 0));
    dfs(matrix, 0, 0, res, path);

    ofstream out("res.txt");
    if (out.is_open())
    {
        for(auto row: res)
        {
            for(auto val: row)
            {
                out<<val << " ";
            }
            out << "\\n" << endl;
        }
        out.close();
    }
}


#endif // STLFSTREAM_H
