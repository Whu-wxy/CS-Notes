#include <bits/stdc++.h>
using namespace std;

string solution(string& str)
{
    if(str.empty()) return "";

    string res;
    stack<char> st;
    st.push(str[0]);
    int idx = 1;
    while(idx < str.size())
    {
        if(str[idx] == ')')
        {
            string temp;
            while(!st.empty() && st.top() != '(')
            {
                temp.push_back(st.top());
                st.pop();
            }
            if(st.top() == '(')
                st.pop();
            //for(int i=temp.size()-1; i>=0; i--)
              //  st.push(temp[i]);
            for(auto c: temp)
                st.push(c);

        }
        else
            st.push(str[idx]);

        idx++;
    }

    while(!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

//int main()
//{
//    string str;
//    cin>>str;

//    string res = solution(str);
//    cout<<res;

//    return 0;
//}



int solution2(vector<int>& vec)
{
    if(vec[0] >= vec.size()-1) return 1;

    int idx = 0;
    int res = 1;
    int maxDist = vec[0];
    while(idx < vec.size())
    {
        int newDist = 0;
        for(int i=idx+1; i<=maxDist; i++)
        {
            newDist = max(vec[i]+i, newDist);
            if(newDist >= vec.size()-1) return res+1;
        }
        idx = maxDist + 1;
        maxDist = newDist;

        res++;
    }
    return res;
}


int main()
{
//    int N;
//    cin>>N;
    vector<int> vec{2,1,3,1,1,1,2};
//    for(int i=0; i<N; i++)
//    {
//        int t;
//        cin>>t;
//        vec.push_back(t);
//    }

    int res = solution2(vec);
    cout<<res;

    return 0;
}
