import os
import subprocess

base_dir = os.getcwd() + '/'
in_file = list(filter(lambda x: x[-3: ] == "txt", os.listdir(base_dir)))
for i, f_in in enumerate(sorted(in_file)):
    os.system('mv ' + f_in + ' ' + str(i + 1) + '.in') 

in_file = list(filter(lambda x: x[-2: ] == "in", os.listdir(base_dir)))
for i, f_in in enumerate(sorted(in_file)):
    f_out = f_in[: -3] + '.out'
    with open(base_dir + f_in, 'r') as o_in:
        res = subprocess.run('./a.out', stdin=o_in, capture_output=True, text=True)
        with open(base_dir + f_out, 'w') as o_out:
            o_out.write(res.stdout)