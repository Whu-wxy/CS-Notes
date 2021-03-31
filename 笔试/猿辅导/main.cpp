#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
   bool solution(vector<int>& arr)
   {
       vector<int> temp;
       for(int i=0; i<arr.size(); i++)
       {
           temp.push_back(arr[i]);
       }
       for(int i=0; i<arr.size(); i++)
       {
           temp.push_back(arr[i]);
       }

       for(int i=0; i<arr.size(); i++)
       {
           if(bValid(temp, i, arr.size()))
               return true;
       }
       return false;
    }

    bool bValid(vector<int>& arr, int idx, int n)
    {
        for(int i=idx+1; i<idx+n; i++)
        {
            if(arr[i] > arr[i-1]) return false;
        }
        return true;
    }
};

//int main()
//{
//    int N;
//    cin>>N;
//    Solution so;
//    for(int i=0; i<N; i++)
//    {
//        int num;
//        cin>>num;
//        vector<int> arr;
//        for(int j=0; j<num; j++)
//        {
//            int val;
//            cin>>val;
//            arr.push_back(val);
//        }
//        bool res = so.solution(arr);
//        if(res)
//            cout<<"Y"<<endl;
//        else
//            cout<<"N"<<endl;
//    }

//    vector<int> arr{1,4,3};
//    bool res = so.solution(arr);
//    if(res)
//        cout<<"Y"<<endl;
//    else
//        cout<<"N"<<endl;



//    return 0;
//}




class Solution2
{
public:

   long long solution(vector<int>& arr, int threshold)
   {
       if(arr.empty()) return 0;

       long long count = 0;
       for(int i=0; i<arr.size(); i++)
       {
           int temp = arr[i];
           for(int j=i; j<arr.size(); j++)
           {
               temp |= arr[j];
               if(temp <= threshold) count++;
               else break;
           }
       }

       return count % 100000007;
    }
};

int main()
{
////    int N;
////    cin>>N;
//    Solution2 so;
//    vector<int> arr{7,6,6,8,15};  //7,6,6,5,15
////    for(int i=0; i<N; i++)
////    {
////        int num;
////        cin>>num;
////       arr.push_back(num);
////    }
//    int T=14;  //14
////    cin>>T;

//    long long res = so.solution(arr, T);
//    cout<<res;




    return 0;
}
