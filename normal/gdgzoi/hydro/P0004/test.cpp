#include <bits/stdc++.h>
using namespace std;

// 在 main 函数外面，定义 Student 结构体
struct Student {
    string name;        // 学成姓名
    int chinese, math;  // 语文成绩, 数学成绩

    // 为结构体添加函数
    void print() {
        cout << name << " 的语文成绩是: " << chinese << ", 数学成绩是: " << math << ", 总分是: " << chinese + math << '\n';
    }

    // 为结构体添加小于号(<) 的判断逻辑
    // other 是另一个学生
    // 如果自己的语文和数学成绩之和，小于 other 的成绩和
    // 那么就是自己是小于 other 的
    bool operator <(const Student& other) const {
        return chinese + math < other.chinese + other.math;
    }
};

int main() {
    // 创建 Student 类型的变量并操作
    Student stu;
    stu.name = "liangsheng";
    stu.chinese = 100;
    stu.math = 90;

    // 可以用 Student* 的指针指向 stu
    Student* it = &stu;
    cout << it->name << '\n';   
    cout << it->chinese << '\n';  // 通过指针的 -> 操作, 访问具体值
    cout << (*it).math << '\n';   // 也可以先通过 * 解引用 
    
    // 输出: liangsheng 的语文成绩是: 100, 数学成绩是: 90, 总分是: 190
    stu.print();

    Student stu2;
    stu2.name = "liudehua";
    stu2.chinese = 100;
    stu2.math = 100;

    // 调用 Student 类型的 小于号(<) 逻辑
    // 输出: liangsheng 的总分小于 liudehua 的总分
    if (stu < stu2) cout << stu.name << " 的总分小于 " << stu2.name << " 的总分" << '\n';
    return 0;
}