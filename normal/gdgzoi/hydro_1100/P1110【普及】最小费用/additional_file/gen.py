# /root/anaconda3/envs/py311/bin/python3.11

# https://zhuanlan.zhihu.com/p/593957471
# https://github.com/luogu-dev/cyaron/
from cyaron import *
import random

T = 5
N = [5, 10, 100, 1000, 5000, 10000]
K = [5, 10, 100, 1000, 5000, 10000]

for i in range(1, T + 1):
    io = IO(file_prefix="", data_id=i)

    n = N[i]
    io.input_writeln(n)
    for _ in range(n):
        x, y = randint(1, 1000000000), randint(1, 1000000000)
        io.input_writeln(x, y)
    io.output_gen("./a.out") 
