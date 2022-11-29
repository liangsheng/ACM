/*
ID: ls_02221
TASK: runround
LANG: C++
*/
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

const int N = 15;

bool num_check(int n){
    char num[N];
    bool used[10];
    int i, len;

    memset(used, 0, sizeof(used));

    sprintf(num, "%d", n);

    len=strlen(num);

    for(i=0; i<len; ++i)
        if(used[num[i]-'0'] == true || num[i]=='0')
            return false;
        else
            used[num[i]-'0'] = true;
    return true;
}

bool round_check(int n){
    char num[N];
    bool f[N];
    int steps, i, len;

    memset(f, 0, sizeof(f));

    sprintf(num, "%d", n);

    len=strlen(num);

    steps=0, i=0;

    while(steps<len){
        if(f[i]==true)
            return false;
        else
            f[i] = true;
        i = (i+num[i]-'0') % len;
        steps++;
    }
    if(i==0)
        return true;
    else
        return false;
}

int main(){

    int n,num;

    ifstream in("runround.in");
    ofstream out("runround.out");

    in>>n;

    for(num=n+1; ;num++)
        if(num_check(num) && round_check(num))
            break;

    out<<num<<endl;

    return 0;
}
