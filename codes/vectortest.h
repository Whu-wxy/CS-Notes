#ifndef VECTORTEST_H
#define VECTORTEST_H

#include <vector>
#include <iostream>

using namespace std;

vector<int> findDisappearedNums(const vector<int>& nums)
{
    vector<int> temp, res;
    for(int i=0; i<nums.size(); i++)
        temp.push_back(i+1);
    for(int i=0; i<nums.size(); i++)
    {
        if(temp[nums[i]-1]>0)
            temp[nums[i]-1] *= -1;
    }
    for(int t: temp)
        if(t>0)
            res.push_back(t);
    return res;
}

vector<int> findDisappearedNums2(vector<int>& nums)
{
    vector<int> res;
    for(int num: nums)
    {
        if(nums[abs(num)-1] > 0)
            nums[abs(num)-1] *= -1;
    }
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] > 0)
            res.push_back(i+1);
    }
    return res;
}

void findDisappearedNums_test()
{
    vector<int> origin({4,3,2,7,8,2,3,1});
    vector<int> res = findDisappearedNums2(origin);
    for(int num: res)
        cout<<num<<endl;
}

// ///////////////////////////////////////////////

void    rotate90Matrix(vector<vector<int>> &matrix)
{
    for(int i=0; i<matrix.size()/2; i++)
    {
        for(int j=i; j<matrix.size()-i-1; j++)
        {
            int temp, temp2;
            temp = matrix[j][matrix.size()-1-i];
            matrix[j][matrix.size()-1-i] = matrix[i][j];

            temp2 = matrix[matrix.size()-1-i][matrix.size()-1-j];
            matrix[matrix.size()-1-i][matrix.size()-1-j] = temp;

            temp = matrix[matrix.size()-1-j][i];
            matrix[matrix.size()-1-j][i] = temp2;

            matrix[i][j] = temp;
        }
    }
}

void    rotate90Matrix2(vector<vector<int>> &matrix)
{
    for(int i=0; i<matrix.size()/2; i++)
    {
        for(int j=i; j<matrix.size()-i-1; j++)
        {
            int temp;
            temp = matrix[j][matrix.size()-1-i];
            matrix[j][matrix.size()-1-i] = matrix[i][j];
            matrix[i][j] = matrix[matrix.size()-1-j][i];
            matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
            matrix[matrix.size()-1-i][matrix.size()-1-j] = temp;
        }
    }
}
//转置+翻转
void    rotate90Matrix3(vector<vector<int>> &matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size()/2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[0].size()-1-j];
            matrix[i][matrix[0].size()-1-j] = temp;
        }
    }
}

void    rotate90Matrix_test()
{
    //  {1,2,3}, {4,5,6}, {7,8,9}
    //  {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}
    vector<vector<int>> matrix({{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}});
    rotate90Matrix3(matrix);
    for(const vector<int>& row: matrix)
    {
        for(const int &val: row)
            cout<<val<<",";
        cout<<endl;
    }
}

// ////////////////////////////////////////////////////

bool    searchValInMatrix(const vector<vector<int>> &matrix, int target)
{
    if(matrix.empty())
        return false;
    int i = 0;
    int j = matrix[0].size()-1;
    while(i<matrix.size() && j>=0)
    {
        if(target>matrix[i][j])
            i +=1;
        else if(target<matrix[i][j])
            j -= 1;
        else
            return true;

    }
    return false;
}

void    searchValInMatrix_test()
{
    bool res = searchValInMatrix({{1, 4, 7, 11, 15},
                                   {2, 5, 8, 12, 19},
                                   {3, 6, 9, 16, 22},
                                   {10, 13, 14, 17, 24},
                                   {18, 21, 23, 26, 30}}, 18);
    if(res)
        cout<<"value in matrix."<<endl;
    else {
        cout<<"value not in matrix."<<endl;
    }
}

#endif // VECTORTEST_H
