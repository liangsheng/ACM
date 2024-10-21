import os, sys, shutil
import subprocess

# 使用方法:
# 1、将本文件放到 testdata 目录
# 2、将 atcoder 的压缩包解压
# 3、运行 python 将atcoder的testcase转换.py

# 用于将 atcoder 的 testcase 转换成能用的
def gao():

    # in 是输入文件, out 是输出文件
    suf = ['in', 'out']

    # 当前题目目录
    base_dir = os.path.dirname(os.path.abspath(__file__))

    for s in suf :
        url = base_dir + '/' + s
        test_file = list(filter(lambda f: f.find('test') != -1, os.listdir(url)))
        
        # test_01.txt -> 1.in
        for f in test_file:
            l, r = f.find('_') + 1, f.find('.')
            case_id = str(int(f[l: r]))
            # test_01.txt => 1.in
            shutil.move(url + '/' + f, base_dir + '/' + case_id + '.' + s)

        shutil.rmtree(url)

gao()
