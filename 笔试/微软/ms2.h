#ifndef MS2_H
#define MS2_H

#include <map>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution1(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() <= 1) return A.size();
    if(A.size() == 2)
    {
        if(A[0] == A[1]) return 1;
        else return 2;
    }

    int count = 1;
    int lastDiff = 0, curDiff = 0;
    lastDiff = A[1]-A[0];
    for(int i=2; i<A.size(); i++)
    {
        curDiff = A[i] - A[i-1];
        if(curDiff == 0) continue;

        if(lastDiff * curDiff < 0)
            count++;
        lastDiff = curDiff;
    }
//    if(curDiff != 0) count++;
    return ++count;
}



///////////////////////////////////////////

class solution2
{
public:
    int maxCount = 0;
    int count = 0;

    void backTracking(string &L1, string &L2, int idx, vector<vector<bool>>& repairing)
    {
        if(idx >= L1.size())
        {
            maxCount = max(maxCount, count);
            return;
        }

        if(L1[idx] != 'x' && L2[idx] != 'x')
            backTracking(L1, L2, idx+1, repairing);
        else
        {
            if(L1[idx] == 'x' && canRepair(L1, L2, 0, idx, repairing))
            {
                count++;
                repairing[0][idx] = true;
                backTracking(L1, L2, idx+1, repairing);
                repairing[0][idx] = false;
                count--;
            }
            else
                backTracking(L1, L2, idx+1, repairing);

            if(L2[idx] == 'x' && canRepair(L1, L2, 1, idx, repairing))
            {
                count++;
                repairing[1][idx] = true;
                backTracking(L1, L2, idx+1, repairing);
                repairing[1][idx] = false;
                count--;
            }
            else
                backTracking(L1, L2, idx+1, repairing);
        }
    }

    bool canRepair(string &L1, string &L2, int i, int j, vector<vector<bool>> repairing)
    {
        if(j == 0) return true;

        if(repairing[1-i][j-1])
            return false;

        return true;
    }

    int solution(string &L1, string &L2) {
        // write your code in C++14 (g++ 6.2.0)

        vector<vector<bool>> repairing(2, vector<bool>(L1.size(), false));

        backTracking(L1, L2, 0, repairing);
        return maxCount;
    }
};



///////////////////////////////////////////

#include <math.h>
int solution3(const vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return 0;

    int val = 0;
    for(int i: A)
    {
        val += pow(2, i);
    }

    int minCount = 0;
    int rest = val;
    while(rest)
    {
        int temp = 0;
        while(pow(2, temp) <= rest)
            temp++;
        temp--;
        rest -= pow(2, temp);
        minCount++;
    }
    return minCount;

}

#endif // MS2_H
