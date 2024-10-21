# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random

N = [5, 10, 100, 1000, 10000, 100000, 1000000, 1000000]
M = [5, 25, 25, 168, 1229, 9592, 78498, 664579]
T = len(N) - 1

for i in range(1, T + 1):
    io = IO(file_prefix="", data_id=i)

    io.input_writeln(5)
    for _ in range(5):
        io.input_writeln(randint(N[i] // 10, N[i]))

    # io.input_writeln(n, q)
    # a = [randint(1, M[i]) for _ in range(n)]
    # io.input_writeln(a)
    # b = [randint(1, M[i]) for _ in range(n)]
    # io.input_writeln(b)
    # for j in range(q):
    #     c, l, r = j % 3 + 1, randint(1, n), randint(1, n)
    #     if l > r:
    #         l, r = r, l
    #     if c < 3:
    #         x = randint(1, M[i])
    #         io.input_writeln(c, l, r, x)
    #     else:
    #         io.input_writeln(c, l, r)

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
