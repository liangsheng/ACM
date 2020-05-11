#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int NODE = 1500;
const int CH = 4;

int chd[NODE][CH] , sz;//结点个数
int word[NODE];//关键数组，记录每个单词尾结点的信息，每道题目都不一样
int fail[NODE];//传说中的失败指针
int Que[NODE];//辅助队列
int sw[128];//string swap每个字符对应的Index，方便模板化

void Ins(char *a, int val)
{
    int p = 0;
    for (; *a ; a ++)
    {
        int c = sw[*a];
        if (!chd[p][c])
        {
            memset(chd[sz], 0, sizeof(chd[sz]));
            word[sz] = 0;
            chd[p][c] = sz ++;
        }
        p = chd[p][c];
    }
    word[p] = val;
}

void AC()
{
    int *s = Que , *e = Que;
    for (int i = 0; i < CH; i++)
        if (chd[0][i])
        {
            fail[ chd[0][i] ] = 0;
            *e++ = chd[0][i];
        }
    while (s != e)
    {
        int p = *s++;
        for (int i = 0; i < CH; i++)
        {
            if(chd[p][i])
            {
                int v = chd[p][i];
                *e++ = v;
                fail[v] = chd[fail[p]][i];
                //对word[v]按word[fail[v]]里的内容进行处理
            }
            else chd[p][i] = chd[fail[p]][i];
        }
    }
}

//AC()函数处理后	chd[p][i] 就是在p结点进行i转移到达的结点
int main()
{
    fail[0] = 0;
    for (int i = 0; i < 26; i++) sw[i + 'a'] = i;
    //下面两句每次都必须初始化
    memset(chd[0], 0, sizeof(chd));
    sz = 1;
    return 0;
}
