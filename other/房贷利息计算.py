def cal_pmt(n = 300, pv = 1230000, iy = 5.2):
    iy = iy / 100 / 12
    ans = pv * ((1.0 + iy) ** n)
    d, t = 0.0, 1.0
    for i in range(n):
        d += t
        t *= 1 + iy
    print(ans, d, ans / d)
    return ans / d

def cal_pv(n = 300, pmt = 7334.51, iy = 5.2):
    iy = iy / 100 / 12
    d, t = 0.0, 1.0
    for i in range(n):
        d += t
        t *= 1 + iy
    return pmt * d / t

N, pv, iy = 300, 1230000, 5.2
pmt = cal_pmt(N, pv, iy)
now_a, now_b = 0.0, 0.0
for i in range(N):
    id = i + 1
    after_pv = cal_pv(N - id, pmt, iy)
    a = pv - after_pv - now_a
    b = pmt - a
    now_a += a
    now_b += b
    print("%02d, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f" % (id, pmt, a, b, now_a, now_b, pv - now_a))