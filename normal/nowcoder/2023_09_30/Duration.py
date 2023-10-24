import time

def date_to_timestamp(s):
    s = "2023-09-30 " + s
    return int(time.mktime(time.strptime(s, "%Y-%m-%d %H:%M:%S")))

a = input()
b = input()
x, y = date_to_timestamp(a), date_to_timestamp(b)
print(abs(x - y))