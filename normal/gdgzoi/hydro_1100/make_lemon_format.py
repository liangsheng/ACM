import os, sys, shutil
import subprocess

# 将 source 目录下的选手答案, 转换成 lemon 可以评测的格式
# 使用方法:
# 1、将本文件(make_lemon_format.py) 复制到选手提交的答案目录
# 2、填写 problems = ["hotel", "feb", "xpy", "sequence"]
# 3、运行 python make_lemon_format.py
def gao():

    # 当前题目目录
    base_dir = os.path.dirname(os.path.abspath(__file__))

    problems = ["hotel", "feb", "xpy", "sequence"]

    ## ['GD-J00001', 'GD-J00002']
    stu = list(filter(lambda f: f != "make_lemon_format.py", os.listdir(base_dir)))

    # 统计最后每个学生的提交情况
    res = {}
    for s in stu:
        res[s] = list()

    for s in stu:
        url = base_dir + '/' + s

        # ['hotel', 'feb', 'xpy', 'sequence']
        for pro in os.listdir(url):
            pro_dir_url = url + '/' + pro

            # GDJ-J00001 目录下, 如果不是文件夹直接删除
            if not os.path.isdir(pro_dir_url):
                if not (pro in problems):
                    os.remove(pro_dir_url)
                    print('失败:', s, '在考号目录下建立了文件, 而不是文件夹', pro)
                else:
                    print('报警:', s, '在考号目录下建立无关的文件', pro)
            else:
                # 确实建立了文件夹
                # 文件名写错了, 直接完蛋, 删除
                if not (pro in problems):
                    shutil.rmtree(pro_dir_url)
                    print('失败:', s, '在考号目录, 写错了文件夹的名字', pro)
                else:
                    # 到这里确实是建立的正确的文件夹
                    # 找到正确的 .cpp 文件, 文件名写错的不要
                    cpp_file = url + '/' + pro + '/' + pro + '.cpp'
                    if os.path.isfile(cpp_file):
                        mv_cmd = 'mv ' + url + '/' + pro + '/' + pro + '.cpp ' + url + '/'
                        shutil.move(url + '/' + pro + '/' + pro + '.cpp ', url + '/')
                        del_cmd = 'rm -rf ' + url + '/' + pro
                        res[s].append(pro)
                        print('成功:', s, '成功提交了', pro)
                    else:
                        print('失败:', s, '写错了 cpp 文件的名字, 或没有作答', pro)
                    shutil.rmtree(url + '/' + pro)

    # 输出最后的提交情况
    print('整体提交情况如下:')
    for s, p in res.items():
        print(s, p)

gao()
