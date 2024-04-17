# /root/anaconda3/envs/py311/bin/python3.11
from cyaron import *
import random


T = 5
N = [5, 10, 100, 1000, 5000, 10000]
K = [5, 5, 10, 20, 50, 100]

for i in range(1, T + 1):
    io = IO(file_prefix="", data_id=i)

    n = randint(N[i - 1], N[i])
    m = randint(n, min(n * (n - 1) / 2, 10000))
    k = randint(K[i - 1], K[i])
    s = randint(k // 2, k)
    io.input_writeln(n, m, k, s)
    a = [1] * n
    for j in range(n):
        if j < k:
            a[j] = j + 1
        else:
            a[j] = randint(1, k)
    random.shuffle(a)
    io.input_writeln(a)
    g = Graph.UDAG(n, m, self_loop=False, repeated_edges=False)
    io.input_writeln(g.to_str(output=Edge.unweighted_edge))  # 输出无权图，以每条边u v一行的格式
    io.output_gen("./a.out")  # 标程编译后的可执行文件，不需要freopen等，CYaRon自动给该程序输入并获得输出作为.out
