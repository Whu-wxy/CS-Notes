#ifndef MS1_H
#define MS1_H


#include <map>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution1(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return 0;

    map<int, int> dict;
    int minStep = INT_MAX;

    for(int a: A)
        dict[a]++;

    for(auto iter=dict.begin(); iter!=dict.end(); iter++)
    {
        int key = iter->first;
        int val = iter->second;
        int step = 0;
        for(auto iter2=dict.begin(); iter2!=dict.end(); iter2++)
        {
            if(iter == iter2) continue;
            step += (iter2->first-key) * iter2->second;
        }
        minStep = min(minStep, step);
    }
    return minStep;
}

///////////////////////////////


struct tree
{
    int x;
    tree* l;
    tree* r;
    tree(int n): x(n), l(nullptr), r(nullptr){}
};

class solution2
{
public:
    int maxVal = 0;
    unordered_set<int> uset;

    void backTracking(tree * T, int val)
    {
        if(!T) return;
        if(uset.count(T->x)) return;

        uset.insert(T->x);
        val++;
        maxVal = max(maxVal, val);
        backTracking(T->l, val);
        backTracking(T->r, val);
        uset.erase(uset.find(T->x));
        val--;
    }

    int solution(tree * T) {
        // write your code in C++14 (g++ 6.2.0)

        backTracking(T, 0);
        return maxVal;
    }
};

///////////////////////////////

int getTrailZeroNum(int num)
{
    int count = 0;
    while(num%10 == 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int solution3(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return 0;

    int maxNum = 0;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            int multiplyL = 1, multiplyR = 1, multiplyT = 1, multiplyB = 1;
            for(int k=j+1; k<A[0].size(); k++) multiplyR *= A[i][k];
            for(int k=j-1; k>=0; k--) multiplyL *= A[i][k];
            for(int k=i+1; k<A.size(); k++) multiplyB *= A[k][j];
            for(int k=i-1; k>=0; k--) multiplyT *= A[k][j];

            int LT = multiplyL*multiplyT*A[i][j];
            int LB = multiplyL*multiplyB*A[i][j];
            int RT = multiplyR*multiplyT*A[i][j];
            int RB = multiplyR*multiplyB*A[i][j];
            int maxZero = max(getTrailZeroNum(LT),max(getTrailZeroNum(LB),max(getTrailZeroNum(RT),getTrailZeroNum(RB)))) ;
            maxNum = max(maxNum, maxZero);
        }
    }

    return maxNum;
}

#endif // MS1_H
