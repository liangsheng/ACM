# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random

N = [1, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5]
M = [1, 3, 6, 4, 5, 6, 7, 6, 7, 8, 9]
T = len(N) - 1

for t in range(1, T + 1):
    io = IO(file_prefix="", data_id=t)

    n, m = N[t], M[t]
    io.input_writeln(n, m)

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
