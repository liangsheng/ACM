import os, sys
import subprocess

def gao():
    if len(sys.argv) < 2:
        return 

    pid = sys.argv[1]

    # 当前题目目录
    base_dir = os.path.dirname(os.path.abspath(__file__)) + '/' + pid + '/'
    os.system('cd ' + base_dir)
    os.system('rm -rf testdata/*.in')
    os.system('rm -rf testdata/*.out') 
    test_dir = base_dir + "/testdata/"

    # 编译成成数据的程序和标程
    os.system('g++ -o gen_in additional_file/gen_data.cpp')
    os.system('g++ -o sol additional_file/solution.cpp')

    # 生成数据
    os.system('./gen_in')

    # 获取当 ./in 下的所有文件
    # files = [os.path.join(in_dir, file) for file in os.listdir(in_dir)]

    # 遍历文件列表，输出文件名
    in_file = list(filter(lambda x: x[-2: ] == "in", os.listdir(test_dir)))
    for f_in in in_file:
        f_out = f_in[: -3] + '.out'
        with open(test_dir + f_in, 'r') as o_in:
            res = subprocess.run('./sol', stdin=o_in, capture_output=True, text=True)
            with open(test_dir + f_out, 'w') as o_out:
                o_out.write(res.stdout)

    # 删除生成数据的程序
    os.system('rm gen_in')
    os.system('rm sol')

gao()