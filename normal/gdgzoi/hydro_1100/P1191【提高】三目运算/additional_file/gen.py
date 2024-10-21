# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random

NL = [1, 0,   1,  1,  10, 50,  10,  20,  50,  50,  100,  500, 1000, 2000, 5000,  10000, 20000, 30000, 40000, 50000, 60000, 70000, 71000, 72000, 73000, 74000]
NR = [1, 0,   1,  10, 50, 100, 100, 100, 100, 100, 500, 1000, 2000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 71000, 72000, 73000, 74000, 75000]

ML = [1, 5,   5,  5,   5,  5,   10,  100,    500,    1000, 5, 5, 5, 10000, 10000, 10000, 10000, 5, 5, 10000, 10000, 10000, 10000, 10000, 10000, 10000]
MR = [1, 9, 100,  9,   9,  9,   100, 500,   1000,   10000, 9, 9, 9, 20000, 50000, 80000, 90000, 9, 9, 90000, 90000, 90000, 90000, 90000, 90000, 90000]

Q = [1, 3,    4,  5,   6,  7,   8,   9,  10,  10, 10, 10, 10, 10, 10, 10, 10]
T = len(NR) - 1


for t in range(1, T + 1):
    io = IO(file_prefix="", data_id=t)

    n, m = randint(NL[t], NR[t]), randint(ML[t], MR[t])
    q = randint(40000, 50000)
    if t <= 16:
        q = Q[t]

    cnt = 0
    def gao(l, r):
        # 三目运算符够了, 已经不能分了, 或者按概率不能分了
        # 就直接返回一个数
        global cnt
        down = randint(1, n)
        if (cnt == n) or (l == r) or (down <= cnt):
            return str(randint(1, m))
        
        # 需要往下分, 也就是一个三目运算符
        # 左边: < div, 右边: >= div
        cnt += 1
        div = randint(l + 1, r)
        if randint(0, 1) == 0:
            s = "x<" + str(div) + "?"
            left = gao(l, div - 1)
            right = gao(div, r)
            return s + left + ":" + right
        s = "x>" + str(div - 1) + "?"
        right = gao(l, div - 1)
        left = gao(div, r)
        return s + left + ":" + right

    io.input_writeln(m, q)

    if n == 0:
        io.input_writeln(randint(1, m))
    else:
        s = gao(1, m)
        io.input_writeln(s)
        print('t=', t, 'n=', n, 'cnt=', cnt)

    for _ in range(q):
        x = randint(1, m)
        io.input_writeln(x)

    # n = N[t]
    # # tree = Graph.tree(n)  # 生成一棵n个节点的随机树    
    # tree = Graph.tree(n, 0.0, 0.0)  # 生成一棵n个节点的树，其中10%的节点呈现链状，10%的节点呈现菊花图状，剩余25%的节点随机加入
    # io.input_writeln(n)
    # c = [randint(1, 10) for _ in range(n)]
    # io.input_writeln(c)
    # for edge in tree.iterate_edges():  # 遍历所有边，其中edge内保存的也是Edge对象
    #     io.input_writeln(edge.start, edge.end) # 输出这条边，以u v w的形式

    # def my_func():
        # return randint(-10000, 10000)

    # n = N[i]
    # m = randint(n - 1, min(10000, n * (n - 1) // 2))
    # g = Graph.UDAG(n, m, weight_limit=(1, n), self_loop=False, repeated_edges=False)  # 无向连通图
    
    # g = Graph.DAG(n, m, weight_gen=my_func, self_loop=False, repeated_edges=False)  # 有向无环图
    # io.input_writeln(g.to_str(output=Edge.unweighted_edge))  # 输出无权图，以每条边u v一行的格式
    # io.input_writeln(n, m)
    # io.input_writeln(g)  # 输出有权图
    # for edge in g.iterate_edges():  # 遍历所有边，其中edge内保存的也是Edge对象
        # edge.start  # 获取这条边的起点
        # edge.end  # 获取这条边的终点
        # edge.weight  # 获取这条边的边权
        # a, b = randint(1, n), randint(1, n)
        # io.input_writeln(edge.start, edge.end, a, b) # 输出这条边，以u v w的形式
    io.output_gen("./a.out")  # 标程编译后的可执行文件，不需要freopen等，CYaRon自动给该程序输入并获得输出作为.out
