import os, sys
import subprocess

def gao():
    if len(sys.argv) < 2:
        return 

    pid = sys.argv[1]

    # 当前题目目录
    base_dir = os.path.dirname(os.path.abspath(__file__)) + '/' + pid + '/'
    os.system('cd ' + base_dir)
    in_dir = base_dir + '/in/'
    out_dir = base_dir + '/out/'
    os.system('rm -rf ' + in_dir)
    os.system('rm -rf ' + out_dir)
    os.system('mkdir ' + in_dir)
    os.system('mkdir ' + out_dir)

    # 编译成成数据的程序和标程
    os.system('g++ -o gen_in gen_data.cpp')
    os.system('g++ -o sol solution.cpp')

    # 生成数据
    os.system('./gen_in')

    # 获取当 ./in 下的所有文件
    # files = [os.path.join(in_dir, file) for file in os.listdir(in_dir)]

    # 遍历文件列表，输出文件名
    for f_in in os.listdir(in_dir):
        f_out = f_in[: -3] + '.out'
        with open(in_dir + f_in, 'r') as o_in:
            res = subprocess.run('./sol', stdin=o_in, capture_output=True, text=True)
            with open(out_dir + f_out, 'w') as o_out:
                o_out.write(res.stdout)

    # 删除生成数据的程序
    os.system('rm gen_in')
    os.system('rm sol')

gao()