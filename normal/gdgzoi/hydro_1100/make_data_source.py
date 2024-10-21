import os, sys, shutil
import subprocess

# 生成用于 lemon 评测的 data(测试数据) 和 source（选手答案, 这里一般指标程）
# 使用方法:
# 1、将本文件(make_lemon_format.py) 复制到 source 目录
# 2、填写 problems, 主要是题目名和对应的题号
# 3、运行 python make_data_source.py, 将在 data 和 source 目录生成数据
def gao():

    problems = {
        "division": "P1185【普及】带余除法",
        "medal": "P1190【普及】奖牌排序",
        "expr": "P1191【提高】三目运算",
        "pairing": "P1192【提高-】匹配序列"
    }

    # 当前目录
    # base_dir = "/root/ACM/normal/gdgzoi/hydro_1100"
    base_dir = os.path.dirname(os.path.abspath(__file__))

    # 先删除 data, source 里面原来的东西
    if os.path.isdir(base_dir + '/data'):
        shutil.rmtree(base_dir + '/data')
        os.mkdir(base_dir + '/data')
    if os.path.isdir(base_dir + '/source'):
        shutil.rmtree(base_dir + '/source')
        os.mkdir(base_dir + '/source')

    # 复制 testdata 到 data
    for (name, pro) in problems.items():
        # 新建目标目录
        dst = base_dir + '/data/' + name
        os.mkdir(dst)

        src = base_dir + '/' + pro + '/testdata'
        files = list(filter(lambda f: (f.find('in') != -1) or (f.find('out') != -1) , os.listdir(src)))
        for f in files:
            # print(src + '/' + f, dst)
            shutil.copy(src + '/' + f, dst)

    # 复制 solution.cpp 到 source/GD-J00001
    dst = base_dir + '/source/GD-J00001'
    os.mkdir(dst)
    for (name, pro) in problems.items():
        src = base_dir + '/' + pro + '/additional_file/solution.cpp'
        shutil.copy(src, dst + '/' + name + '.cpp')

    # 复制 solution_std.cpp 到 source/GD-J00002
    dst = base_dir + '/source/GD-J00002'
    os.mkdir(dst)
    for (name, pro) in problems.items():
        src = base_dir + '/' + pro + '/additional_file/solution_std.cpp'
        if os.path.isfile(src):
            shutil.copy(src, dst + '/' + name + '.cpp')

gao()