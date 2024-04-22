# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random

N = [5, 10, 20, 50, 80, 100]
K = [5, 10, 20, 50, 80, 100]
T = len(N) - 1

for i in range(1, T + 1):
    io = IO(file_prefix="", data_id=i)

    n = randint(N[i - 1], N[i])
    a = [randint(1, 10000) for _ in range(n)]
    b = [randint(1, 10000) for _ in range(n)]
    s = 0
    for i in range(n):
        s += a[i] * b[i]
    k = randint(1, min(s, 100000))
    io.input_writeln(n, k)
    for i in range(n):
        io.input_writeln(a[i], b[i])

    # def my_func():
        # return randint(-10000, 10000)

    # g = Graph.UDAG(n, m, weight_limit=(1, n), self_loop=False, repeated_edges=False)  # 无向连通图
    # g = Graph.DAG(n, m, weight_gen=my_func, self_loop=False, repeated_edges=False)  # 有向无环图
    # io.input_writeln(g.to_str(output=Edge.unweighted_edge))  # 输出无权图，以每条边u v一行的格式
    # io.input_writeln(g)  # 输出有权图
    io.output_gen("./a.out")  # 标程编译后的可执行文件，不需要freopen等，CYaRon自动给该程序输入并获得输出作为.out
