#include <iostream>
#include <unordered_set>

using namespace std;

// //////////////////////////////////11111
struct tree
{
    int x;
    tree* l;
    tree* r;
    tree(int n): x(n), l(nullptr), r(nullptr){}
};

//class so
//{
//public:
//    int maxVal = 0;
//    unordered_set<int> uset;

//    void backTracking(tree * T, int val)
//    {
//        if(!T) return;
//        if(uset.count(T->x)) return;

//        uset.insert(T->x);
//        val++;
//        maxVal = max(maxVal, val);
//        backTracking(T->l, val);
//        backTracking(T->r, val);
//        uset.erase(uset.find(T->x));
//        val--;
//    }

//    int solution(tree * T) {
//        // write your code in C++14 (g++ 6.2.0)

//        backTracking(T, 0);
//        return maxVal;
//    }
//};


//// //////////////////////////////////22222
#include <map>
#include <vector>
#include <climits>

//int solution(vector<int> &A) {
//    // write your code in C++14 (g++ 6.2.0)
//    if(A.empty()) return 0;

//    map<int, int> dict;
//    int minStep = INT_MAX;

//    for(int a: A)
//        dict[a]++;

//    for(auto iter=dict.begin(); iter!=dict.end(); iter++)
//    {
//        int key = iter->first;
//        int val = iter->second;
//        int step = 0;
//        for(auto iter2=dict.begin(); iter2!=dict.end(); iter2++)
//        {
//            if(iter == iter2) continue;
//            step += (iter2->first-key) * iter2->second;
//        }
//        minStep = min(minStep, step);
//    }
//    return minStep;
//}


//// //////////////////////////////////33333

//int getTrailZeroNum(int num)
//{
//    int count = 0;
//    while(num%10 == 0)
//    {
//        count++;
//        num /= 10;
//    }
//    return count;
//}

//// 笔试提交版本
////int solution4(vector< vector<int> > &A) {
////    // write your code in C++14 (g++ 6.2.0)
////    if(A.empty()) return 0;

////    int maxNum = 0;
////        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
////        // horizontal
////        for(int i=0; i<A.size(); i++)
////        {
////            for(int j=0; j<A[0].size(); j++)
////            {
////                int multiplyL = 1, multiplyR = 1;
////                for(int k=j; k<A[0].size(); k++)
////                {
////                    multiplyR *= A[i][k];
////                }
////                for(int k=j; k>=0; k--)
////                {
////                    multiplyL *= A[i][k];
////                }
////                dp[i][j] = max(getTrailZeroNum(multiplyL), getTrailZeroNum(multiplyR));
////                maxNum = max(dp[i][j], maxNum);
////            }
////        }
////        // vertival
////        vector<vector<int>> dp2(A.size(), vector<int>(A[0].size(), 0));

////        for(int i=0; i<A.size(); i++)
////        {
////            for(int j=0; j<A[0].size(); j++)
////            {
////                int multiplyL = 1, multiplyR = 1;
////                for(int k=i+1; k<A.size(); k++)
////                {
////                    multiplyR *= A[k][j];
////                }
////                dp2[i][j] = max(dp[i][j], max(getTrailZeroNum(A[i][j]*multiplyR), dp[i][j] + getTrailZeroNum(multiplyR)) );

////                for(int k=i-1; k>=0; k--)
////                {
////                    multiplyL *= A[k][j];
////                }
////                dp2[i][j] = max(dp[i][j], max(getTrailZeroNum(A[i][j]*multiplyL), dp[i][j] + getTrailZeroNum(multiplyL)) );

//////                dp[i][j] += max(getTrailZeroNum(multiplyL), getTrailZeroNum(multiplyR));
////                maxNum = max(dp2[i][j], maxNum);
////            }
////        }

////    return maxNum;
////}

//// 正确的
//int solution4(vector< vector<int> > &A) {
//    // write your code in C++14 (g++ 6.2.0)
//    if(A.empty()) return 0;

//    int maxNum = 0;
//    for(int i=0; i<A.size(); i++)
//    {
//        for(int j=0; j<A[0].size(); j++)
//        {
//            int multiplyL = 1, multiplyR = 1, multiplyT = 1, multiplyB = 1;
//            for(int k=j+1; k<A[0].size(); k++) multiplyR *= A[i][k];
//            for(int k=j-1; k>=0; k--) multiplyL *= A[i][k];
//            for(int k=i+1; k<A.size(); k++) multiplyB *= A[k][j];
//            for(int k=i-1; k>=0; k--) multiplyT *= A[k][j];

//            int LT = multiplyL*multiplyT*A[i][j];
//            int LB = multiplyL*multiplyB*A[i][j];
//            int RT = multiplyR*multiplyT*A[i][j];
//            int RB = multiplyR*multiplyB*A[i][j];
//            int maxZero = max(getTrailZeroNum(LT),max(getTrailZeroNum(LB),max(getTrailZeroNum(RT),getTrailZeroNum(RB)))) ;
//            maxNum = max(maxNum, maxZero);
//        }
//    }

//    return maxNum;
//}



// ///////////////////微软第二次 /////////////////
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

int main()
{
//    tree* t1 = new tree(1);
//    tree* t2 = new tree(2);
//    tree* t3 = new tree(1);
//    tree* t4 = new tree(1);
//    tree* t5 = new tree(4);
//    t1->r = t2;
//    t2->l = t3;
//    t2->r = t4;
//    t4->l = t5;
//    so s;
//    int res = s.solution(t1);


//    vector<int> A{3,2,1,1,1,2,3};
//    int res = solution(A);


//       int res = getTrailZeroNum(1000);
//       cout<<res<<endl;


    //{6,25,4,10},{12,25,1,15}, {7,15,15,5}
    //{10,100,10},{1,10,1}, {1,10,1}
//    vector<vector<int>> A{{10,100,10},{1,10,1}, {1,10,1}};
//    int res = solution4(A);
//    cout<<res<<endl;


// ///////////////////微软第二次 /////////////////


    //2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5
    //2, 2, 3, 4, 3, 3, 2,2,4,1    5
//vector<int> A{2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5};
//    int res = solution1(A);
//    cout<<res<<endl;


//    solution2 so;
//    //.xxx...x     ..x.xxxx  //6
//    //..xx.x.      x.x.x..     //4
//    string s1("..xx.x.");
//    string s2("x.x.x..");
//    int res = so.solution(s1, s2);
//cout<<res<<endl;


    int res = solution3({0,0,0,1,2,2});
    cout<<res<<endl;

    return 0;
}
