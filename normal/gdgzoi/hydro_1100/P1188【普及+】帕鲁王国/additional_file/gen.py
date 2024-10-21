# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random, math

N = [1, 6, 6, 6, 6, 8, 10, 12, 1000, 2000, 3000, 4000, 5000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
D = [1, 4,  8,  16, 32, 64,  128, 256,  1024, 1024,   1024]
T = len(N) - 1

for t in range(1, T + 1):
    io = IO(file_prefix="", data_id=t)

    n, k = randint(N[t] // 2, N[t]), randint(0, 1)
    f = [1] * (n + 1)
    b = list()
    for i in range(n + 1):
        b.append(list())
    for i in range(2, n + 1):
        f[i] = randint(1, i - 1)
        b[f[i]].append(i)
    io.input_writeln(n, k)
    for i in range(1, n + 1):
        c = list()
        if len(b[i]) == 1:
            c.append('not')
        if t < 14 or t > 16:
            c.append('and')
        if t < 17 or t > 19:
            c.append('or')
        cmd = c[randint(0, len(c) - 1)]
        if len(b[i]) == 0:
            cmd = 'input'
        s = [cmd]
        if cmd != 'input':
            s.append(len(b[i]))
            for x in b[i]:
                s.append(x)
        io.input_writeln(' '.join(map(str, s)))

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
