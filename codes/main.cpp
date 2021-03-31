#include <iostream>
#include "sharedptr.h"
#include "threadtest.h"
#include "threadinclass.h"
#include <random>

#include <QScopedPointer>
#include <QFile>
#include <QList>

#include <memory>
#include <ctime>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <stack>
#include <set>

#include "threadpool.h"

#include "xipai.h"
#include "stringtest.h"
#include "vectortest.h"
#include "treetest.h"
#include "classtest.h"

#include "singleton.h"
#include "listtest.h"

#include <stlfstream.h>
#include <sortalg.h>
#include <sstream>

using namespace std;

//QList<QFile*> fileVector;
//void testScopedPointer();


vector<vector<string>> res;


bool isValid(int row, int col, int n, vector<string>& path)
{
    for(int i=0; i<row; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(j == col && path[i][j] == 'Q')
                return false;
            if(abs(row-i) == abs(col-j) && path[i][j] == 'Q')
                return false;
        }
    }
    return true;
}


void backTracking(int row, int n, vector<string>& path)
{
    if(row == n)
    {
        res.push_back(path);
        return;
    }

    for(int col=0; col<n; col++)
    {
        if(isValid(row, col, n, path))
        {
            path[row][col] = 'Q';
            backTracking(row+1, n, path);
            path[row][col] = '.';
        }
    }
}


vector<vector<string>> solveNQueens(int n, vector<string>& path) {
    if(n == 0) return {};


    for(int i=0; i<n; i++)
        path.push_back(string('.', n));
    backTracking(0, n, path);
    return res;
}


int numTrees(int n) {
       vector<int> dp(n+1, 0); //n个节点组成的二叉搜索树种类
       dp[0] = 1;
       for(int i=1; i<=n; i++)
       {
           for(int j=1; j<=i; j++)
           {
               //1到n，分别为根节点
               //例如n为10，j为5，则左子树有dp[4]种，右子树有dp[5]种
               dp[i] += dp[j-1] * dp[i-j];
           }
       }
       return dp.back();
   }


string solve(string s, string t) {
        // write code here

    if(s.empty()) return t;
    if(t.empty()) return s;

    vector<int> res(s.size()+t.size(), 0);
    for(int sPtr = s.size()-1;sPtr>=0; sPtr--)
    {
        for(int tPtr = t.size()-1;tPtr>=0; tPtr--)
        {
            int num = (s[sPtr]-'0')*(t[tPtr]-'0');
            int sum = res[sPtr+tPtr+1] + num;
            res[sPtr+tPtr+1] = sum % 10;
            res[sPtr+tPtr] += sum / 10;
        }
    }
    int i=0;
    for(; i<res.size(); i++)
    {
        if(res[i] != 0)
            break;
    }
    string out;
    for(; i<res.size(); i++)
    {
        out.push_back(res[i]+'0');
    }
    return out.size() == 0? "0": out;
}


class SSS {
public:
    vector<string> res;
    string path;
    void dfs(int n, int cur)
    {
        if(cur > n || cur < 0) return;
        if(path.size() == n*2 && cur == 0)
        {
            res.push_back(path);
            return;
        }

        path.push_back('(');
        dfs(n, cur+1);
        path.pop_back();

        path.push_back(')');
        dfs(n, cur-1);
        path.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        path.push_back('(');
        dfs(n, 1);
        return res;
    }
};


//#define myswap(a,b) (int c=a;a=b;b=c;)

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define mymax(x,y) ((x)>(y)?(x):(y))



class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> highQue; //大顶堆存小于中位数的
    priority_queue<int, vector<int>, greater<int>> lowQue; //小顶堆存大于中位数的
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(lowQue.empty())
        {
            lowQue.push(num);
            return;
        }

        if(lowQue.top() <= num) lowQue.push(num);
        else highQue.push(num);

        // rebalance
        int l = lowQue.size(), h = highQue.size();
        if(abs(l - h) <= 1) return;
        if(l > h + 1)
        {
            highQue.push(lowQue.top());
            lowQue.pop();
        }
        else if(h > l + 1)
        {
            lowQue.push(highQue.top());
            highQue.pop();
        }
    }

    double findMedian() {
        int l = lowQue.size(), h = highQue.size();
        if(l == h)
            return (lowQue.top()+highQue.top()) / 2.0;
        else if(l > h) return lowQue.top();
        else return highQue.top();
    }
};




int main()
{

    ////////// 智能指针 /////////
    //    int *pa = new int(10);
    //    //定义三个智能指针类对象，对象都指向基础类对象 pa
    //    //使用花括号控制三个智能指针的生命周期，观察计数的变化
    //    SharedPtr<int> sptr1(pa);//此时计数 count=1
    //    {
    //        SharedPtr<int> sptr2(sptr1); //调用拷贝构造函数，此时计数为 count=2
    //        {
    //            SharedPtr<int> sptr3;
    //            sptr3 = sptr1; //调用赋值操作符，此时计数为 conut=3
    //        }
    //        //此时count=2
    //        cout << sptr1.use_count() << endl;

    //    }
    //    //此时count=1；
    //    cout << sptr1.use_count() << endl;

    ////////// 线程-通过类的一个成员函数 /////////
    //    Test test(1, 20);
    //    thread t{&Test::func, &test, "start"}; //通过成员函数创建线程 （&类::函数，&函数， 参数）
    //    t.join();


    ////////// 线程-类中进行 /////////
//    threadInClass thread;

//    // This is the front-end.
//    std::default_random_engine generator(123); //seed
//    std::uniform_int_distribution<int> distribution(1, 1000);
//    for (size_t i = 0; i < 10; ++i) {
//        // Produce data.
//        int random_var = distribution(generator);

//        // Send data to the back-end.
//        thread.addData(random_var);

//        std::cout << "[main]: Add var " << random_var << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }

    /// QScopedPointer
//    testScopedPointer();
//    if(fileVector.at(0) == nullptr)
//    {
//        std::cout << "fileVector[0] is null "<<std::endl;
//    }
//    else
//    {
//        std::cout << "fileVector[0] is not null "<<std::endl;
//    }
    /// QScopedPointer


    /// threadpool
//    threadpool pool(4);

//    for(int i=0; i<1000; i++)
//    {
//        Task* pTask = new MyTask(i);
//        pool.addTask(pTask);
//    }

//    std::this_thread::sleep_for(std::chrono::seconds(8));
    /// threadpool


    /// priority_queue
//    priority_queue<int, vector<int>, less<int> > a;
//    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
//    for (int i = 0; i < 5; i++)
//    {
//        a.push(i);
//        c.push(i);
//    }
//    while (!a.empty())
//    {
//        cout << a.top() << ' ';
//        a.pop();
//    }
//    cout << endl;

//    while (!c.empty())
//    {
//        cout << c.top() << ' ';
//        c.pop();
//    }
//    cout << endl;
    /// priority_queue

      ///xipai
//    xipai2_test();
//    findFirstNonRepeat_test();

//    std::cout<<sizeof(A)<<std::endl;

//    std::cout<<sizeof(B)<<std::endl;
//    std::cout<<sizeof(A2)<<std::endl;
//    A2 a2;
//    std::cout<<sizeof(a2)<<std::endl;
//    std::cout<<sizeof(A3)<<std::endl;
    ///


//    findDisappearedNums_test();
//    rotate90Matrix_test();
//    searchValInMatrix_test();

//    tree_test();

//     Class_Test *p = new Mytest();
//     p->show();

//    Test2();

//    int a = 1;
//    int *ptr = &a;
//    vector<int> v({1,2});
//    int *p2 = &v[1];
//    auto iter = v.begin();
//    (*p2)++;
//    (*iter)++;
//    (*ptr)++;

//    cout<<a<<endl;
//    for(auto i: v)
//        cout<<i<<endl;


//    auto res = singleNonDuplicate({1,1,2,3,3,4,4,8,8});
//        cout<<res<<endl;


//    auto res = singleNonDuplicate({1,1,2,2,3,3,4,4,8,8,9});
//    cout<<res<<endl;


//    detectCycle_test();


//        reverseWords(" asdasd df f");

//    int n=5;
//    string bbb(n, '.');


//    vector<int> path{1,2,22,-23,-9,-30,-6,-9,1,8,24,2,21,29,10,-25,18,30,1,9,-8,-11,-22,-23,-17,-12,19,28,19,28};
//    auto ress = solve("999", "999");
////    int ress = largestSumAfterKNegations(path, 24);
//    std::cout<<ress;


//    vector<vector<char>> test{{'0','0','0','1'},
//                              {'1','1','0','1'},
//                              {'1','1','1','1'},
//                              {'0','1','1','1'},
//                              {'0','1','1','1'}};
//    int ress = maximalSquare(test);
//    std::cout<<ress;


//    sortTest();

//    vector<int> vec{3,2,1,5,6,4};
//    int res = findKthLargest(vec, 4);
//        std::cout<<res;

//    int i = 1;
//    vector<int> vec2(vec.begin()+i+2, vec.end());
//    int a = 2;

//    stringstreamTest();


//    String s("123");
//    String s2(s);
//    s2 = s;

//    String s3(std::move(s));
//    String s4;
//    s4 = std::move(s);


//    MedianFinder finder;
//    finder.addNum(1);
//    finder.addNum(2);
//    double res = finder.findMedian();
//    cout<<res<<endl;
//    finder.addNum(3);
//    res = finder.findMedian();
//    cout<<res<<endl;



//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n2 = new TreeNode(2);
//    n3->left = n1;
//    n3->right = n4;
//    n1->right = n2;

//    Solution222 solu;
//    solu.kthLargest(n3, 1);


//    int a;
//    while(cin>>a)
//    {
//        if(cin.get() == ' ') cout<<"blank"<<endl;
//        if(cin.get() == '\n') cout<<"enter"<<endl;
//        cout<<a<<endl;

//    }


    // 3 4 5
    // 3 2 6
    // 2 1 1



    return 0;
}


//void testScopedPointer()
//{
//    QFile* pFile = new QFile();
//    QScopedPointer<QFile> filePointer(pFile);
//    fileVector.append(filePointer.data());
//}
