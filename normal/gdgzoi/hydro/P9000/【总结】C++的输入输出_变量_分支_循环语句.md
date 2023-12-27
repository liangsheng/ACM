# 0、正确答案
* 如果看不见代码，可以点击登录
* [P1000【入门】Hello World!](http://www.gzezoi.cn/d/gzezoi2023/record/6564943df7726adb17dd76aa)
* [P1001【入门】四则运算](http://www.gzezoi.cn/d/gzezoi2023/record/65461976f7726adb17dd0b5a)
* [P1002【入门】翻转三位数](http://www.gzezoi.cn/d/gzezoi2023/record/656495a3f7726adb17dd76c9)
* [P1003【入门】三个数排序](http://www.gzezoi.cn/d/gzezoi2023/record/65465a4cf7726adb17dd0ca6)
* [P1004【入门】水仙花数](http://www.gzezoi.cn/d/gzezoi2023/record/65465fa3f7726adb17dd0cbd)
* [P1005【入门】求和](http://www.gzezoi.cn/d/gzezoi2023/record/6546fa62f7726adb17dd0cf8)
* [P1006【入门】判断素数](http://www.gzezoi.cn/d/gzezoi2023/record/65472010f7726adb17dd0d2b)
* [P1007【入门】输出棋盘](http://www.gzezoi.cn/d/gzezoi2023/record/654742bdf7726adb17dd0d4e)
* [P1008【入门】角谷猜想](http://www.gzezoi.cn/d/gzezoi2023/record/654746a9f7726adb17dd0d63)
* [P1009【入门】最大公约数](http://www.gzezoi.cn/d/gzezoi2023/record/65474f62f7726adb17dd0d80)
* [P1010【入门】分解质因数](http://www.gzezoi.cn/d/gzezoi2023/record/6547565bf7726adb17dd0d9a)
# 1、语法问题（编译错误）
## 1-1、请对齐代码，有大括号记得缩进！！！
* 代码对齐，记得缩进
* 变量，关键词，标点之间记得空格！！
* **<font color="#FF0000">错误代码</font>**
```c++
#include<iostream>
using namespace std;
int main(){
        double a,c;
        string b;
        cin >> a >> b >> c;
        // 错误: string 类型要用双引号!!
        if(b==' - '){
        // 大括号里面的语句, 需要空 4 格在开始编写, 或者说要先摁 tab, 再开始写代码
        cout << a-b;
        }
else if(b==' + '){  // else 请写在 } 后面
        cout << a+b;
        }
else if(b==' * '){
        cout << a*b;
        }
else if(b==' / '){
        cout << a/b;
        }
	return 0;
}
```

# 1-2、输出字符串时要用双引号
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    for (int i = 1;i <= 9;i++){
        for (int j = 0;j <= 9;j++){
            for (int k = 0;k <= 9;k++){
                int x = 1 * 100 + j * 10 + k;
                if(i * i * i + j * j * j + k * k *k == x) {
                    // 错误: 输出空格没有用引号
                    // cout << x << " ";
                    // cout << x << ' ';
                    cout << x <<  ;
                }
            }
        }
    }
    return 0;
}
```
# 1-3、每句话结束要打分号
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    // 错误: end1 改成 endl
    cout <<"Hello World!"<< end1;
    // 错误: 没写分号
    return 0
}
```
# 2、P1005【入门】求和
* while 的计算逻辑不清楚
* **<font color="#FF0000">错误代码</font>**
```c++
#include<iostream>
#include<iomanip> 
using namespace std;
int main(){
	double n=1,ans=1;
	while(ans<10){
		ans+=1.0/(++n); 
	}
    // 错误: 这里输出 n !!!
	cout<<n-1;
}
```