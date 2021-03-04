#ifndef XIPAI_H
#define XIPAI_H

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


// œ¥≈∆À„∑®
void    xipai1(vector<int> &oriPai, vector<int> &resPai)
{
    size_t count = oriPai.size();
    for(int i=count-1; i>=0; i--)
    {
        int idx = rand() % (i+1);
        resPai.push_back(oriPai.at(idx));
        vector<int>::iterator iter = oriPai.begin()+idx;
        oriPai.erase(iter);
    }
}

void    xipai2(vector<int> &Pai)
{
//    int count = Pai.size();
//    for(int i=count-1; i>=0; i--)
//    {
//        int idx = rand() % (i+1);
//        Pai.push_back(Pai.at(idx));
//        auto iter = Pai.begin()+idx;
//        Pai.erase(iter);
//    }

    for(int i=0;i<Pai.size();++i){
        int cnt=rand()%(Pai.size()-i);
        swap(Pai[cnt],Pai[Pai.size()-i-1]);
    }
}

void    xipai1_test()
{
    vector<int> resPai;
    vector<int> oriPai({1,2,3,4,5,6,7,8,9,10});
    xipai1(oriPai, resPai);
    cout<<"after xipai1: "<<endl;
    for(auto pai:resPai)
        cout<<pai<<endl;
}

void    xipai2_test()
{
    vector<int> Pai({1,2,3,4,5,6,7,8,9,10});
    xipai2(Pai);
    cout<<"after xipai2: "<<endl;
    for(auto pai:Pai)
        cout<<pai<<endl;
}


#endif // XIPAI_H
