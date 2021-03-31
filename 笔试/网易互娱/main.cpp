#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      int solution(int M, int N, int X, int Y, int P)
      {
          int origin = 100000;
          int diffP = P - origin;

          if(M*X >= diffP)    //前M天就够
          {
              int d = diffP / X;
              if(diffP % X == 0) return d;
              else return d+1;
          }
          if(N*Y >= M*X) return -1;   //一直亏

          int days = 0;
          while(diffP > 0)
          {
              diffP -= M*X;
              days = days + M;
              if(diffP == 0) return days;
              else if(diffP < 0)
              {
                  diffP += M*X;
                  days = days - M;
                  int d = diffP / X;
                  if(diffP % X == 0) return d+days;
                  else return d+days+1;
              }
              diffP +=  N*Y;
              days = days + N;
          }

         // days = diffP / (M*X - N*Y);
          //if((days-1)*M*X)
         // days--;
          //days = days*(M+N);

          //diffP = diffP % (M*X - N*Y);

//          while(diffP > 0)
//          {
//              diffP -= X;
//              days++;
//          }
//          return days;

          return -1;
      }
};


//int main()
//{
////    int num;
////    cin>>num;
//    Solution so;
////    for(int i=0; i<num; i++)
////    {
////        int M, N, X, Y, P;
////        cin>>M;
////        cin>>N;
////        cin>>X;
////        cin>>Y;
////        cin>>P;
////        int res = so.solution(M, N, X, Y, P);
////        cout<<res<<endl;
////    }

//    int res = so.solution(1,1,4,2,100005);
//    cout<<res<<endl;


//    return 0;
//}




class Solution2
{
public:
      int token_flag = 0;
      unordered_map<char, int> umap;
      int solution(const char* str)
      {
          if(!str) return 0;

          int count = 0;
          const char* ptr = str;
          umap['s'] = 1;
          umap['d'] = 2;
          umap['u'] = 3;
          umap['p'] = 4;
          umap['f'] = 5;
          for(int i=0; i<=9; i++) umap['0'+i] = 6;
          umap['%'] = 7;
          while(*ptr)
          {
              count += helper(ptr);
              ptr++;
          }
          return count+1;
      }

    int helper(const char* ptr)
    {
        int count = 0;
        if(*ptr != '\0')
        {
            count++;
        }

        if(token_flag)
        {
            count++;
            if(umap.count(*ptr))
            {
                if(*ptr < '0' || *ptr > '9')
                    token_flag = 0;
                count += umap[*ptr];
            }
            else
            {
                token_flag = 0;
                count += 7;
            }
        }
        else
        {
            count++;
            if(*ptr == '%')
            {
                token_flag = 1;
                count++;
            }
            else count++;
        }
        return count;
    }
};


//int main()
//{
////    int num;
////    cin>>num;
//    Solution2 so;
////    for(int i=0; i<num; i++)
////    {
////        string s;
////        cin>>s;
////        int res = so.solution(s.data());
////        cout<<res<<endl;
////    }

//    string s("%123pqr");
//    int res = so.solution(s.data());
//    cout<<res<<endl;


//    return 0;
//}



class Solution3
{
public:

      int solution(vector<string> vec, string str)
      {
          int count = 0;
          for(auto &s: vec)
          {
              if(s.find(str.data(), 0) != -1)
              {
                  count++;
              }

          }
          return count;
      }



};


int main()
{
    int num;
 //   cin>>num;

    Solution3 so;
    vector<string> vec{" A two", "B go to school", "C  A"};   //{" A two", "B go to school", "C  A"}
//    for(int i=0; i<num; i++)
//    {
//        string s;
//        if(getline(cin, s))
//            vec.push_back(s);
//    }

////    for(auto sss: vec)
////        cout<<sss<<endl;

//    cin>>num;
//    for(int i=0; i<num; i++)
//    {
//        string s;
//        cin>>s;
//        int res = so.solution(vec, s);
//        cout<<res<<endl;
//    }


    string s("A");
    int res = so.solution(vec, s);
    cout<<res<<endl;



    return 0;
}
