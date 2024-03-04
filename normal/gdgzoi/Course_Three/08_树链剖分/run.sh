# g++ -o a.out luogu_P1505.cpp
# g++ -o b.out luogu_P1505_AC.cpp
# g++ -o c.out luogu_P1505_RND.cpp

for i in $( seq 1 10)
do
    ./c.out
    ./a.out < luogu_P1505_1.in > wa.out
    ./b.out < luogu_P1505_1.in > ac.out
    ans=`diff ac.out wa.out`
    if [ -z "$ans" ]; then
        echo $i "结果正确"
    else
        echo $i "结果错误"
        break
    fi
done