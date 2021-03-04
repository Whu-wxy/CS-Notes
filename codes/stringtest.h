#ifndef STRINGTEST_H
#define STRINGTEST_H

#include <string>
#include <array>
#include <assert.h>

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//字符串函数strcat, strcpy, strcmp, strlen实现
char * m_strcat(char *strDst, const char *strSrc)
{
    char *address = strDst;

    assert(strDst); //如果为空，则是false，会终止程序的运行
    assert(strSrc);
//    assert((str1 != NULL) && (str2 != NULL));
    //注意断言assert 是仅在Debug 版本起作用的宏，是在Debug时做的无害测试

    while(*strDst)
    {
        strDst++;
    }//最后strDst指向Src末尾的\0
    while(*strSrc) *strDst++=*strSrc++;
    return address;
}


char * m_strcpy(char *strDst, const char *strSrc)
{
    char *address = strDst;   //记录首地址，用于返回
    assert(strDst); //如果为空，则是false，会终止程序的运行
    assert(strSrc);
//    assert((str1 != NULL) && (str2 != NULL));

    while(*strSrc)
    {
        *strDst++ = *strSrc++;
    }

    *strDst = '\0';  //注意最后加\0

    return address;
}

//用于比较两个字符串并根据比较结果返回整数。基本形式为strcmp(str1,str2)，
//若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
int m_strcmp(const char *str1, const char *str2)
{
    assert(str1); //如果为空，则是false，会终止程序的运行
    assert(str2);
//    assert((str1 != NULL) && (str2 != NULL));
    //注意断言assert 是仅在Debug 版本起作用的宏，是在Debug时做的无害测试
    //若想在Release 版也可以判断NULL，那我们必须用别的代码来判断。
//    可以在程序前面加入if判断
//    if ((NULL != str1) && (NULL != str2))
//    {
//    return 0;
//    }

    // 目标是对比第一个不同的字符（如果存在的话）
    while(*str1 && *str2 && (*str1 == *str2)) //注意字符长度可能会不同，遇到\0直接返回
    {
        str1++;
        str2++;
    }

    return *str1 - *str2; // 在ascii码表中\0是0
}

int m_strlen(const char *str)
{
    int len = 0;
    assert(str); //如果为空，则是false，会终止程序的运行

    while(*str++)
    {
        len++;
    }
    return len;
}

int m_atoi(const char *str) {
    if(str == nullptr) return 0;
     if(*str == '\0') return 0; //为空
     while(*str == ' ') str++; //跳过前面的0和空格

     int sign = 1;   //判断符号
     if(*str == '+')
         str++;
     else if(*str == '-')
     {
         str++;
         sign = -1;
     }

     int res = 0;     //处理数字
     while(isdigit(*str))   //跳过字母
     {
         if (res>INT_MAX/10 || (res == INT_MAX/10 && (*str-'0' >= INT_MAX%10)))  //处理越界
               return sign == 1 ? INT_MAX : INT_MIN;

         res = res*10 + *str-'0';
         str++;
     }
     return res*sign;
}

//string构造函数，拷贝构造，移动构造




//给你一个字符串，找出第一个不重复的字符，如“abbbabcd”，则第一个不重复就是c。
char    findFirstNonRepeat(const string &str)
{
    array<int, 256> checkArray;   //不用unordered_map，添加的时候前面的排在后面了
    checkArray.fill(0);
    for(size_t i=0; str[i]!='\0'; i++)
    {
        checkArray[str[i]]++;
    }
    for(size_t i=0; i<checkArray.size(); i++)
    {
        if(checkArray[i] == 1)
            return i;
    }

    return '\0';
}

void    findFirstNonRepeat_test()
{
    string str("abbbabcd");
    char res = findFirstNonRepeat(str);
    std::cout<<"result: "<<res<<endl;
}


void stringstreamTest()
{
    string str("1,2,3, 4 5 6");
    stringstream ss(str);
    string item;
    while(getline(ss, item, ','))
        cout<<item<<endl;

//    getline(ss, item, ',');
//    cout<<item<<endl;
//    getline(ss, item, ',');
//    cout<<item<<endl;
//    getline(ss, item, ',');
//    cout<<item<<endl;
//    getline(ss, item, ',');
//    cout<<item<<endl;
//    getline(ss, item, ',');
//    cout<<item<<endl;
//    getline(ss, item, ',');
//    cout<<item<<endl;
}


// ////////////////////////// KMP ////////////////////////
// 辅函数 - 计算next数组
void calNext(const string &needle, vector<int> &next) {
    for (int j = 1, p = -1; j < needle.length(); ++j)
    {
        while (p > -1 && needle[p+1] != needle[j])
            p = next[p]; // 如果下一位不同，往前回溯

        if (needle[p+1] == needle[j])
            ++p; // 如果下一位相同，更新相同的最大前缀和最大后缀长

        next[j] = p;
    }
}

// 主函数
int KMP(string haystack, string needle) {
    int k = -1, n = haystack.length(), p = needle.length();
    if (p == 0) return 0;
    vector<int> next(p, -1); // -1表示不存在相同的最大前缀和后缀

    calNext(needle, next); // 计算next数组
    for (int i = 0; i < n; ++i) {
        while (k > -1 && needle[k+1] != haystack[i])
            k = next[k]; // 有部分匹配，往前回溯

        if (needle[k+1] == haystack[i])
            ++k;

        if (k == p-1)
            return i - p + 1; // 说明k移动到needle的最末端，返回相应的位置
    }
    return -1;
}
// //////////////////////////////////////////////////


#endif // STRINGTEST_H
