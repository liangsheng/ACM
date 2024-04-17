### 0、前言

- n 阶多项式 $p(x) = p_{n-1}x^{n-1} + p_{n-2}x^{n-2}+...+p_1x + p_0$，的最高位是 $x^{n-1}$
- 计算 2 个 n 阶多项式的乘积，时间复杂度 o(n^2)
- FFT 和 NTT 可以在 o(nlog(n)) 的时间实现 2 个 n 阶多项式相乘
- 大致思路：
  - 一个 n 阶多项式除了用 $[p_{n-1},p_{n-2},...,p_0]$ 来表示（系数表达法）
  - 也可以用 n 个点来确定（比如 2 点确定一条直线方程，点值表达法）
  - **FFT 可以用 o(nlog(n)) 时间将 系数表达法 转换成 点值表达法**
  - **IFFT 可以用 o(nlog(n)) 时间将 点值表达法 转换成 系数表达法**
- 参考资料：
  - [b 站: 快速傅里叶变换(FFT)——有史以来最巧妙的算法？](https://www.bilibili.com/video/BV1za411F76U/?spm_id_from=333.337.search-card.all.click&vd_source=a66c6ecbceb56b86672d3acb4784ff39)
  - [oiwiki: 复数](https://oi-wiki.org/math/complex/)
  - [oiwiki: 快速傅里叶变换](https://oi-wiki.org/math/poly/fft/)
  - [oiwiki: 快速数论变换](https://oi-wiki.org/math/poly/ntt/)
  - [知乎: 快速数论变换](https://zhuanlan.zhihu.com/p/347726949)
  - [atcoder 上 wygz 的 NTT 模板](https://atcoder.jp/contests/abc278/submissions/36656665)
  - [atcoder 上 jiangly 的 NTT 模板](https://atcoder.jp/contests/abc278/submissions/36743107)
  - [usaco 上的 fft](https://usaco.guide/adv/fft?lang=cpp#tutorial)

### 1、多项式系数表达式转成点值表达式

* 考虑多项式 $p(x) = p_{7}x^{7} + p_{6}x^{6} + p_{5}x^{5} + p_{4}x^{4} + p_{3}x^{3} + p_{2}x^{2} + p_{1}x^{1} + p_{0}$
* 我们希望求出  $p(x_0)$，$p(x_1)$，$p(x_2)$，$p(x_3)$，$p(x_4)$，$p(x_5)$，$p(x_6)$，$p(x_7)$这 8 个点的值
* 将多项式按奇偶项拆分，奇数项提出一个 x
* $p(x)$ = $\color{blue}p_6x^6+p_4x^4+p_2x^2+p0$+$\color{red}x(p_7x^6+p_5x^4+p_3x^2+p_1)$
* $p(x)$ = $\color{blue}p_6(x^2)^3+p_4(x^2)^2+p_2(x^2)+p0$+$\color{red}x(p_7(x^2)^3+p_5(x^2)^2+p_3(x^2)+p_1)$
* 偶数项部分看做关于 $x^2$ 的函数，记为 ${p_{1,e}(x)}$ ，奇数项部分同理记为 $p_{1,o}(x)$

$$
\left\{ 
    \begin{array}{lc}
        \color{blue}p_{1,e}(x) = p6x^3+p4x^2+p2x+p0 \\
        \color{red}p_{1,o}(x) = p7x^3+p5x^2+p3x+p1\\
    \end{array}
\right.
$$

* 那么多项式 $p(x)$ 可以表示为

$$
\left\{ 
    \begin{array}{lc}
        \color{blue}p(x_0) = p_{1,e}(x_0^2) + x_0*p_{1,o}(x_0^2) \\
        \color{red}p(-x_0) = p_{1,e}(x_0^2) - x_0*p_{1,o}(x_0^2)\\
    \end{array}
\right.
$$

* **我们如果知道 $p(x_0)$ 的值，那么 $p(-x_0)$ 的值也就是知道了**
* **考虑将要计算的 8 个点换成 4 对相反数 $p(\pm x_0)$,  $p(\pm x_1)$, $p(\pm x_2)$,  $p(\pm x_3)$, 只用计算 4 次！！**
* **考虑将这个过程递归下去**！！
* **需要计算 ${p_{1,e}(x)}$ 和 ${p_{1,o}(x)}$ 在 $x_0^2$ , $x_1^2$ , $x_2^2$ , $x_3^2$ 的值**
* **但问题来了，$x_0^2$ , $x_1^2$ , $x_2^2$ , $x_3^2$ 都是正数，不可能是 2 对相反数，$x_0^2 \neq -x_1^2$ , $x_2^2 \neq -x_3^2$**

### 2、在复空间内让 $x_0^2 = -x_1^2$

* 实数范围内是搞不定了
* 在复空间内取 $x_1=cos(2\pi / 8) + i*sin(2\pi / 8)$， 也就是 $x^8=1$ 的单位复根，得到 FFT 算法
* 我们定义形如 $a+bi$ ，其中 $a, b \in R$  的数叫做复数，其中 $i$ 成为单位虚根，满足 $i^2=-1$
* 实数对应 x 轴，复数对应整个二维平面
* 复数的加法

$$
(a + bi) + (c + di) = (a + c) + (d + n)i
$$

* 复数的乘法

$$
(a + bi) * (c + di) = (ac - bd) + (ad + bc)i
$$

* 复数的模

$$
|a + bi| = \sqrt{a^2+b^2}
$$

* 复数的指数运算

$$
exp(a+bi)=e^a(cos(b) + i * sin(b))
$$

* 设 x 轴正方向是单位 1，y 轴正方向是单位 i，将复数对应到坐标系上的向量
* 也可以用 模长 和 角度（与 x 轴正方向）来表示复数

$$
z_1=r*(cos\theta +isin\theta)
$$

* ![image](file://单位复向量.png)
* 把模长 **$r=1$** 的 复向量，称为 **单位复向量**
* **重点来了，单位复向量有如下几个重要特征：**
* **（1）单位复向量的乘法，相当于把复向量按逆时针旋转**

$\ \ \ \ \ (cos\theta+isin\theta)*(cos\beta+isin\beta)$
$= \ (cos\theta*cos\beta-sin\theta*sin\beta) + i(cos\theta*sin\beta+cos\theta*sin\beta)$
$= \ cos(\theta+\beta)+isin(\theta+\beta)$

* **(2) $x^n=1$ 在复平面上有 n 个解**
  * 记 $\omega_n=cos(2\pi/n)+isin(2\pi/n)=exp(\frac{2\pi i}{n})$
  * 那么 $(\omega_n^1)^n=exp(\frac{2\pi i}{n}*n)=exp(2\pi i)=cos(2\pi)+isin(2\pi)=1$
  * 同理 $(\omega_n^2)^n=exp(\frac{2\pi i}{n}*2n)=exp(4\pi i)=cos(4\pi)+isin(4\pi)=1$
  * $(\omega_n^k)^n=exp(\frac{2\pi i}{n}*kn)=exp(2k\pi i)=cos(2k\pi)+isin(2k\pi)=1$
  * **所以 $[(w_n)^0, (w_n)^1, (w_n)^2,...,(w_n)^{n-1}]$ 是 $x^n=1$ 的 n 个的解**

![image](file://n次单位复根.png)

* **(3) $\omega_n^k=\omega_{2n}^{2k}$， 幅角都是 $\frac{2\pi i}{n} * k$**
  
  * 可以理解为，把 $2\pi$ 分 4 份取 1 份，和分 8 份取 2 份是一样的
* **(4) $\omega_{2n}^{k+n}=-\omega_{2n}^{k}$**
  
  * 可以理解为，转半圈相当于取反
  * 比如$\omega_8^5=\omega_8^{1+4}=-\omega_8^1,\omega_8^1+\omega_8^5=0$，可以想象下向量相加
* **神奇的事情来了**
  
  * **这个是我们奇偶拆分多项式的情况**
  * **$p_8(x)$表示 8 阶多项式，也就是原始多项式**
  * **$p_{4,e}(x)$ 表示是拆分 8 阶多项式的得到的 4 阶多项式的偶数项（even）**
  * **$p_{4,o}(x)$ 表示是拆分 8 阶多项式的得到的 4 阶多项式的奇数项（odd）**

| $p_8(x) = p_0 + p_1x + p_2x^2 + p_3x^3 + p_4x^4 + p_5x^5 + p_6x^6 + p_7x^7$ |
| ----------------------------------------------------------------------------- |

| $p_{4,e}(x)=p_0+p_2x+p_4x^2+p_6x^3$ | $p_{4,o}(x)=p_1+p_3x+p_5x^2+p_7x^3$ |
| ------------------------------------- | ------------------------------------- |

| $p_{2,ee}(x)=p_0+p_4x$ | $p_{2,eo}(x)=p_2+p_6x$ | $p_{2,oe}(x)=p_1+p_5x$ | $p_{2,oo}(x)=p_3+p_7x$ |
| ------------------------ | ------------------------ | ------------------------ | ------------------------ |

| $p_{1,eee}=p_0$ | $p_{1,eeo}=p_4$ | $p_{1,eoe}=p_2$ | $p_{1,eoo}=p_6$ | $p_{1,oee}=p_1$ | $p_{1,oeo}=p_5$ | $p_{1,ooe}=p_3$ | $p_{1,ooo}=p_7$ |
| ----------------- | ----------------- | ----------------- | ----------------- | ----------------- | ----------------- | ----------------- | ----------------- |

* **这个是每一行的多项式需要计算的点 x 的值**

| $\textcolor{red}{\omega_8^0}=1$ | $\textcolor{red}{\omega_8^4}=-1$ | $\textcolor{red}{\omega_8^2}=i$ | $\textcolor{red}{\omega_8^6}=-i$ | $\textcolor{red}{\omega_8^1}=exp(\frac{2\pi i}{8})$ | $\textcolor{red}{\omega_8^5}=exp(\frac{2\pi i}{8}*5)$ | $\textcolor{red}{\omega_8^3}=exp(\frac{2\pi i}{8}*3)$ | $\textcolor{red}{\omega_8^7}=exp(\frac{2\pi i}{8}*7)$ |
| --------------------------------- | ---------------------------------- | --------------------------------- | ---------------------------------- | ----------------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------- |

| $\textcolor{red}{\omega_4^0}=(\omega_8^0)^2=1$ | $\textcolor{red}{\omega_4^2}=(\omega_8^2)^2=-1$ | $\textcolor{red}{\omega_4^1}=(\omega_8^1)^2=i$ | $\textcolor{red}{\omega_4^3}=(\omega_8^3)^2=-i$ |
| ------------------------------------------------ | ------------------------------------------------- | ------------------------------------------------ | ------------------------------------------------- |

| $\textcolor{red}{\omega_2^0}=(\omega_4^0)^2=1$ | $\textcolor{red}{\omega_2^1}=(\omega_4^1)^2=-1$ |
| ------------------------------------------------ | ------------------------------------------------- |

| $\textcolor{red}{\omega_1^0}=(\omega_2^0)^2=1$ |
| ------------------------------------------------ |

* **这个是执行 fft 算法时存储的点值得变化情况**
* **第一步：8 个 1 阶多项式在 $x=1$ 的值是 $h_1[0..8] = [p_0, p_4, p_2, p_6, p_1, p_5, p_3, p_7]$**
* **第二步：4 个 2 阶段多项式在 $x=[\omega_2^0=1, \omega_2^1=-1]$ 的值是**
  * **$h_2[0]=p_{2,ee}(1) = p_0 + 1 * p_4=h_1[0]+1*h_1[1]$**
  * $h_2[1]=p_{2,ee}(-1) = p_0- 1 * p_4=h_1[0]-1*h_1[1]$
  * **$h_2[2]=p_{2,eo}(1)= p_2 + 1 * p_6=h_1[2]+1*h_1[3]$**
  * $h_2[3]=p_{2,eo}(-1) = p_2- 1 * p_6=h_1[2]-1*h_1[3]$
  * **$h_2[4]=p_{2,oe}(1) = p_1 + 1 * p_5=h_1[4]+1*h_1[5]$**
  * $h_2[5]=p_{2,oe}(-1) = p_1- 1 * p_5=h_1[4]-1*h_1[5]$
  * **$h_2[6]=p_{2,oo}(1) = p_3 + 1 * p_7=h_1[6]+1*h_1[7]$**
  * $h_2[7]=p_{2,oo}(-1) = p_3- 1 * p_7=h_1[6]-1*h_1[7]$
* 原理就是这个公式

$$
\left\{ 
    \begin{array}{lc}
        \color{blue}p(x_0) = p_{1,e}(x_0^2) + x_0*p_{1,o}(x_0^2) \\
        \color{red}p(-x_0) = p_{1,e}(x_0^2) - x_0*p_{1,o}(x_0^2)\\
    \end{array}
\right.
$$

* **第三步：2 个 4 阶段多项式在 $x=[\omega_4^0=1, \omega_4^1=i, \omega_4^2=-1, \omega_4^3=-i]$ 的值是**
* **$\color{red}h_4[0]=p_{4,e}(\omega_4^0=1)=p_{2,ee}(1) + 1 * p_{2,eo}(1)=h_2[0]+1*h_2[2]$**
* **$\color{blue}h_4[1]=p_{4,e}(\omega_4^1=i)=p_{2,ee}(-1) + i * p_{2,eo}(-1)=h_2[1]+i*h_2[3]$**
* **$\color{red}h_4[2]=p_{4,e}(\omega_4^2=-1)=p_{2,ee}(1) - 1 * p_{2,eo}(1)=h_2[0]-1*h_2[2]$**
* **$\color{blue}h_4[3]=p_{4,e}(\omega_4^3=-i)=p_{2,ee}(-1) - i * p_{2,eo}(-1)=h_2[1]-i*h_2[3]$**
* **$h_4[4]=p_{4,o}(1)=p_{2,oe}(1) + 1 * p_{2,oo}(1)=h_2[4]+1*h_2[6]$**
* **$h_4[5]=p_{4,o}(i)=p_{2,oe}(-1) + i * p_{2,oo}(-1)=h_2[5]+i*h_2[7]$**
* **$h_4[6]=p_{4,o}(-1)=p_{2,oe}(1) - 1 * p_{2,oo}(1)=h_2[4]-1*h_2[6]$**
* **$h_4[7]=p_{4,o}(-i)=p_{2,oe}(-1) - i * p_{2,oo}(-1)=h_2[5]-i*h_2[7]$**
* **第四步：1 个 8 阶段多项式在 $x=[\omega_8^0,\omega_8^1,\omega_8^2,\omega_8^3,\omega_8^4,\omega_8^5,\omega_8^6,\omega_8^7]$ 的值是**
* **$\color{red}h_8[0]=p_8(\omega_8^0)=p_{4,e}(1) + \omega_8^0*p_{4,o}(1)=h_4[0]+\omega_8^0h_4[4]$**
* **$\color{blue}h_8[1]=p_8(\omega_8^1)=p_{4,e}(i) + \omega_8^1*p_{4,o}(i)=h_4[1]+\omega_8^1h_4[5]$**
* **$\color{cyan}h_8[2]=p_8(\omega_8^2)=p_{4,e}(-1) + \omega_8^2*p_{4,o}(-1)=h_4[2]+\omega_8^2h_4[6]$**
* **$\color{brown}h_8[3]=p_8(\omega_8^3)=p_{4,e}(-i) + \omega_8^3*p_{4,o}(-i)=h_4[3]+\omega_8^3h_4[7]$**
* **$\color{red}h_8[4]=p_8(\omega_8^4)=p_8(-\omega_8^0)=p_{4,e}(1) - \omega_8^0*p_{4,o}(1)=h_4[0]-\omega_8^0h_4[4]$**
* **$\color{blue}h_8[5]=p_8(\omega_8^5)=p_8(-\omega_8^1)=p_{4,e}(i) - \omega_8^1*p_{4,o}(i)=h_4[1]-\omega_8^1h_4[5]$**
* **$\color{cyan}h_8[6]=p_8(\omega_8^6)=p_8(-\omega_8^2)=p_{4,e}(-1) - \omega_8^2*p_{4,o}(-1)=h_4[2]-\omega_8^2h_4[6]$**
* **$\color{brown}h_8[7]=p_8(\omega_8^7)=p_8(-\omega_8^3)=p_{4,e}(-i) - \omega_8^3*p_{4,o}(-i)=h_4[3]-\omega_8^3h_4[7]$**
* **大功告成**
* **最后来看下代码**

```c++
// 同样需要保证 len 是 2 的幂
// 记 rev[i] 为 i 翻转后的值
void change(Complex y[], int len) {
  // 可以理解为, 想得到 6(110) 的翻转, 可以先得到 6 >> 1 也就是 3(011) 的翻转
  // 在把 3 的翻转 110 右移一位, 得到 011, 这个就是 6 的翻转
  // 这样做会忽略最低位的 1(如果有的话), 需要最后 + (len / 2)
  for (int i = 0; i < len; ++i) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1) {  // 如果最后一位是 1，则翻转成 len/2
      rev[i] |= len >> 1;
    }
  }
  for (int i = 0; i < len; ++i) {
    if (i < rev[i]) {  // 保证每对数只翻转一次
      swap(y[i], y[rev[i]]);
    }
  }
  return;
}

/*
 * 做 FFT
 * len 必须是 2^k 形式
 * on == 1 时是 DFT，on == -1 时是 IDFT
 */
void fft(Complex y[], int len, int on) {
  // 位逆序置换
  // 由 [p0, p1, p2, p3, p4, p5, p6, p7] 得到 [p0, p4, p2, p6, p1, p5, p3, p7]
  // 实际上是可以由 二进制翻转 得到, 记住低位在前, 高位在后 !!!!
  // 比如: p0 由于原来的 0 号位置, 换到了 0 号位置, 000 -> 000
  // 比如: p1 由于原来的 1 号位置, 换到了 4 号位置, 001 -> 100
  // 比如: p2 由于原来的 2 号位置, 换到了 2 号位置, 010 -> 010
  // 比如: p3 由于原来的 3 号位置, 换到了 6 号位置, 011 -> 110
  // 比如: p4 由于原来的 4 号位置, 换到了 1 号位置, 100 -> 001
  // 比如: p5 由于原来的 5 号位置, 换到了 5 号位置, 101 -> 101
  // 比如: p6 由于原来的 6 号位置, 换到了 3 号位置, 110 -> 011
  // 比如: p7 由于原来的 7 号位置, 换到了 7 号位置, 111 -> 111
  change(y, len);
  
  // 模拟合并过程, 2 阶 -> 4 阶 -> 8 阶, 上面的 change(y, len) 就是 1 阶
  for (int h = 2; h <= len; h <<= 1) {
    // wn：当前单位复根的间隔：w^1_h
    Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
    // 合并，共 len / h 次。
    for (int j = 0; j < len; j += h) {
      // 计算当前单位复根，一开始是 1 = w^0_n，之后是以 wn 为间隔递增： w^1_n
      // ...
      Complex w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        // 左侧部分和右侧是子问题的解
        Complex u = y[k];
        Complex t = w * y[k + h / 2];
        // 这就是把两部分分治的结果加起来
        y[k] = u + t;
        y[k + h / 2] = u - t;
        // 后半个 「step」 中的ω一定和 「前半个」 中的成相反数
        // 「红圈」上的点转一整圈「转回来」，转半圈正好转成相反数
        // 一个数相反数的平方与这个数自身的平方相等
        w = w * wn;
      }
    }
  }
  // 如果是 IDFT，它的逆矩阵的每一个元素不只是原元素取倒数，还要除以长度 len。
  if (on == -1) {
    for (int i = 0; i < len; i++) {
      y[i].x /= len;
    }
  }
}
```

### 3、IFFT：将点值表达式转化成系数表达式

#### 3-1、用矩阵的观点来解释 IFFT

* **我们首先用矩阵的观点来看下，FFT 解决的问题**

$$
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
=
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^1 & \omega^2 & \omega^3 \\
1 & \omega^{2} & \omega^{2*2} & \omega^{2*3} \\
1 & \omega^{3} & \omega^{3*2} & \omega^{3*3}
\end{array}\right]
*
\left[\begin{array}{c}
p_0 \\
p_1 \\ 
p_2 \\
p_3 
\end{array}\right]
$$

* **以 4 阶多项式为例子，$\omega=exp(\frac{2\pi i}{4})$，我们已知系数来求值**
* **下面是核弹级别的结论！！！**
  
  * **我们在等式 的两边左乘上 中间矩阵的 逆**

$$
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^1 & \omega^2 & \omega^3 \\
1 & \omega^{2} & \omega^{2*2} & \omega^{2*3} \\
1 & \omega^{3} & \omega^{3*2} & \omega^{3*3}
\end{array}\right]^{-1}
*
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
=
\left[\begin{array}{c}
p_0 \\
p_1 \\ 
p_2 \\
p_3 
\end{array}\right]
$$

$$
\frac{1}{4}
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^{-1} & \omega^{-2} & \omega^{-3} \\
1 & \omega^{-2} & \omega^{-2*2} & \omega^{-2*3} \\
1 & \omega^{-3} & \omega^{-3*2} & \omega^{-3*3}
\end{array}\right]
*
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
=
\left[\begin{array}{c}
p_0 \\
p_1 \\ 
p_2 \\
p_3 
\end{array}\right]
$$

* **把等式两边换下位置**

$$
\left[\begin{array}{c}
p_0 \\
p_1 \\ 
p_2 \\
p_3 
\end{array}\right]
=
\frac{1}{4}
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^{-1} & \omega^{-2} & \omega^{-3} \\
1 & \omega^{-2} & \omega^{-2*2} & \omega^{-2*3} \\
1 & \omega^{-3} & \omega^{-3*2} & \omega^{-3*3}
\end{array}\right] *
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
$$

* **这个和 FFT 的矩阵形式惊人相似！！！，只有 2 个区别**
  * **$\omega^1 \Rightarrow \omega^{-1}$**
  * **最后的结果 $*\frac{1}{n}$**
* **最后在看上面的代码，你已经完成了 FFT 和 IFFT**

#### 3-2、用推公式的观点来解释 IFFT

* 这个是 FFT 的矩阵表达，我们有
  * $p(\omega^0)=p_0+p_1+p_2+p_3$
  * $p(\omega^1)=p_0+\omega^1p_1+\omega^2p_2+\omega^3p_3$
  * $p(\omega^2)=p_0+\omega^2p_1+\omega^4p_2+\omega^6p_3$
  * $p(\omega^3)=p_0+\omega^3p_1+\omega^6p_2+\omega^9p_3$

$$
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
=
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^1 & \omega^2 & \omega^3 \\
1 & \omega^{2} & \omega^{2*2} & \omega^{2*3} \\
1 & \omega^{3} & \omega^{3*2} & \omega^{3*3}
\end{array}\right] *
\left[\begin{array}{c}
p_0 \\
p_1 \\ 
p_2 \\
p_3 
\end{array}\right]
$$

* 接下来我们来计算下下面这个公式中的 $y_0, y_1, y_2, y_3$

$$
\left[\begin{array}{c}
y_0 \\
y_1 \\ 
y_2 \\
y_3 
\end{array}\right]
=
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^1 & \omega^2 & \omega^3 \\
1 & \omega^{2} & \omega^{2*2} & \omega^{2*3} \\
1 & \omega^{3} & \omega^{3*2} & \omega^{3*3}
\end{array}\right] *
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
$$

* $y_0=p(\omega^0)+p(\omega^1)+p(\omega^2)+p(\omega^3)$
* $y_0=4p_0+p_1(1+\omega^1+\omega^2+\omega^3)+p_2(1+\omega^2+\omega^4+\omega^6)+p_3(1+\omega^3+\omega^6+\omega^9)$
* $y_0=4p_0+p_1*\frac{\omega^4-1}{\omega^1-1}+p_2*\frac{\omega^8-1}{\omega^2-1}+p_1*\frac{\omega^{12}-1}{\omega^3-1}$
  * 由于 $\omega^4-1=1-1=0, \omega^8-1=1-1=0,\omega^8-1=1-1=0$
  * 所以 $y_0=4p_0$
* $y_1=p(\omega^0)+\omega^1p(\omega^1)+\omega^2p(\omega^2)+\omega^3p(\omega^3)$
* $y_1=p_0+p_1+p_2+p_3+\omega^1(p_0+\omega^1p_1+\omega^2p_2+\omega^3p_3)+\omega^2(p_0+\omega^2p_1+\omega^4p_2+\omega^6p_3)+\omega^3(p_0+\omega^3p_1+\omega^6p_2+\omega^9p_3)$
* $y_1=p_0(1+\omega^1+\omega^2+\omega^3)+p_1(1+\omega^2+\omega^4+\omega^6)+p_2(1+\omega^3+\omega^6+\omega^9)+p_3(1+\omega^4+\omega^8+\omega^{12})$
* $y_1=4p_3$
* 同理 $y_2=4p_2, y_3=4p_1$
* 那么我们可以得到：

$$
\left[\begin{array}{c}
4p_0 \\
4p_3 \\ 
4p_2 \\
4p_1 
\end{array}\right]
=
\left[\begin{array}{c}
1 & 1 & 1 & 1 \\
1 & \omega^1 & \omega^2 & \omega^3 \\
1 & \omega^{2} & \omega^{2*2} & \omega^{2*3} \\
1 & \omega^{3} & \omega^{3*2} & \omega^{3*3}
\end{array}\right] *
\left[\begin{array}{c}
p(\omega^0) \\
p(\omega^1) \\ 
p(\omega^2) \\
p(\omega^3) 
\end{array}\right]
$$

* 所以我们可以在原来 FFT 的代码上
  * 把结果的后 $n-1$项翻转
  * 然后除上 $n$
  * 就得到 IFFT
* 代码如下：

```c++
/*
 * 做 FFT
 * len 必须是 2^k 形式
 * on == 1 时是 DFT，on == -1 时是 IDFT
 */
void fft(Complex y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {             // 模拟合并过程
    Complex wn(cos(2 * PI / h), sin(2 * PI / h));  // 计算当前单位复根
    for (int j = 0; j < len; j += h) {
      Complex w(1, 0);  // 计算当前单位复根
      for (int k = j; k < j + h / 2; k++) {
        Complex u = y[k];
        Complex t = w * y[k + h / 2];
        y[k] = u + t;  // 这就是把两部分分治的结果加起来
        y[k + h / 2] = u - t;
        // 后半个 「step」 中的ω一定和 「前半个」 中的成相反数
        // 「红圈」上的点转一整圈「转回来」，转半圈正好转成相反数
        // 一个数相反数的平方与这个数自身的平方相等
        w = w * wn;
      }
    }
  }
  if (on == -1) {
    // 如果是 IFFT, 则翻转最后 n-1 项, 然后除上 len
    reverse(y + 1, y + len);
    for (int i = 0; i < len; i++) {
      y[i].x /= len;
    }
  }
}
```

### 4、在 mod(998244353) 空间实现 $x_0^2=-x_1^2$

#### 4-1、欧拉定理，费马小定理，原根的概念

* **$\color{red}{欧拉函数}$：$\varphi(n)$ 表示 $[1..n]$ 中与 n 互素的数的个数**
  
  * 比如 $\varphi(10) = 4$，因为 [1, 3, 7, 9] 和 10 互素
  * 我们把 $[1, 3, 7, 9]$ 成为 10 的 $\color{red}{简化剩余系}$
  * 简化剩余系里面的数，无论怎么做乘法，结果还在简化剩余系里
    * 比如：$3*7=21\equiv1(\bmod 10)$
    * 比如：$7*9=63\equiv3(\bmod 10)$
* **$\color{red}{欧拉定理}$：设 $a, m$ 是正整数， 切 $gcd(a, m) = 1$，那么 $a^{\varphi(m)}\equiv1(\bmod m)$**
  
  * 比如 $a=3, m=10$，那么 $3^{\varphi(10)}=3^4=81\equiv1(\bmod 10)$
  * 证明：
    * 设 $[x_1, x_2, ..., x_{\varphi(m)}]$ 是 $[1..m-1] 中 \varphi(m)$ 个**与 m 互素且不相同的数**
    * 我们给每个数都乘上 a 得到 $[ax_1, ax_2, ..., ax_{\varphi(m)}]$
    * 这 $\varphi(m)$ 个新的数都与 $m$ 互素，且两两不同余（在 mod m 意义下）
      * 如果 $ax_i - ax_j=a(x_i-x_j)\equiv0(\bmod m)$，那么 $x_i, x_j$ 必同余（因为 $gcd(a,m)=1$），矛盾
    * 既然两两不同，那 $[ax_1, ax_2, ..., ax_{\varphi(m)}]$ 只能是 $[x_1, x_2, ..., x_{\varphi(m)}]$ 的重新排列
      * 比如对于 $a = 13, m = 10$, $[1, 3, 7, 9]$ 变成 $[3, 9, 1, 7]$
    * 那么

$$
(\prod_{i=1}^{i=\varphi(m)}ax_i)=(a^{\varphi(m)}\prod_{i=1}^{i=\varphi(m)}x_i)\equiv\prod_{i=1}^{i=\varphi(m)}x_i(\bmod m)
$$

$$
(a^{\varphi(m)}-1)\prod_{i=1}^{i=\varphi(m)}x_i\equiv0(\bmod m)
$$

* $\prod_{i=1}^{i=\varphi(m)}x_i 肯定是和 m 互素的，那么只能$：

$$
a^{\varphi(m)}-1\equiv0(\bmod m)
$$

* **$\color{red}{费马小定理}$：当 $p$ 是一个质数，且整数 $a$ 不是 $p$ 的倍数，则有 $a^{p-1}\equiv1(\bmod p)$**
  
  * 证明：欧拉定理取 $m$ 是素数
* **$\color{red}{阶}$：若正整数 $a, p$ 互素且满足 $p > 1$ ，则对于 $a^n\equiv1(\bmod p)$ 最小的正整数 $n$ ，我们称之为 $a$ 模 $p$ 的阶，记做 $\delta_p(a)$**
  
  * 比如：$3^4=81\equiv1(\bmod 10)$，那么 3 模 10 的阶 $\delta_{10}(3)=4$（$3^1, 3^2, 3^3$ 都不满足条件）
* **$\color{red}{原根}$：设 $n$ 是正整数，$g$ 是整数，$gcd(g,n)=1$，当 $g$ 模 $n$ 的阶 $\delta_g(n)=\varphi(n)$时，我们称 $g$ 是 $n$ 的原根。**
  
  * 比如 $3$ 是 $10$ 的原根，因为$\delta_{10}(3)=4=\varphi(10)$
  * 原根的几个重要性质（暂时没看懂证明。。。。。）：
  * **$\color{red}{素数必有原根}$**
  * 素数原根一般都很小（一般不会超过300），可枚举判断，见习题 [51nod 1135 求素数原根](https://www.51nod.com/Challenge/Problem.html#problemId=1135)
  * **设 $g$ 是质数 $p$ 的原根，那么 $[g^0, g^1,...,g^{p-2}]$ 是 $[1, 2,...,p-1]$ 的一个排列（模 $p$ 的简化剩余系）**
    * 比如 $2$ 是 $5$ 的原根，那么 $[2^0, 2^1, 2^2, 2^3]$ 在 $\bmod p$ 意义下是 $[1, 2, 4, 3]$

#### 4-2、回忆下 n 次单位复根的性质

* **n 次单位复根的 3 个重要性质**
  * $\omega_n^n=1$
  * **$(\omega_{2n}^k)^2=\omega_n^k$**
  * **$\omega_{2n}^{k+n}=-\omega_{2n}^{k}$，逆时针转半圈相当于取相反数
* **有上面三条性质就可以得到互为相反数的 2 个平方数**
  * **$(\omega_{2n}^k)^2=\omega_{2n}^{2k}=\omega_n^k$**
  * ****$(\omega_{2n}^{k+\frac{n}{2}})^2=\omega_{2n}^{2k+n}=-\omega_{2n}^{2k}=-\omega_n^k$**

#### 4-3、新的答案

* **我们令 $n$ 是大于 1 的 2 的幂，$p$ 是素数，且满足 $n|(p-1)$ , $g$ 是 $p$ 的一个原根**
* **我们设：**

$$
g_n=g^{\frac{p-1}{n}}
$$

* **我们会发现 $g_n$ 满足 $\omega_n$的上述 3 性质**
  * **$g_n^n=g^{n.\frac{p-1}{n}}=g^{p-1}\equiv1(\bmod p)$，费马小定理**
  * **$(g_{2n}^k)^2=g^{\frac{p-1}{2n}2k}=(g^{\frac{p-1}{n}})^k=g_n^k$**
  * $g_{2n}^{k+n}=g^{\frac{p-1}{2n}(n+k)}=g^{\frac{p-1}{2}}*g^{\frac{k}{2n}}=-g^{\frac{k}{2n}}$
    * 其中 $g^{\frac{p-1}{2}}\equiv-1(\bmod p)$ 的证明如下：
    * 设 $g^{\frac{p-1}{2}}\equiv c(\bmod p)$
    * 那么 $c^2 = g^{p-1}\equiv1(\mod p)$（大家注意这里不能直接开方，$4*4\equiv1(\bmod 15)$）
    * 那么 $c^2-1=(c-1)(c+1)\equiv0(\bmod p)$，则 $p|(c-1)(c+1)$
    * 如果 $c \neq \pm1$，必然有 $1 < c < p - 1$
    * 那么$1 \le c-1 < p-2$，且 $1 < c + 1 \le p - 1$
    * 那么 $c - 1, c + 1$ 都是和 $p$ 互素的，不可能有 $p|(c-1)(c+1)$，矛盾
    * 所以 $c = \pm1$
    * 又由于 $c$ 不能是 $1$
      * 否则$g^{\frac{p-1}{2}}\equiv 1(\bmod p), \frac{p-1}{2}$是比 $p$更小的数，与 $g$ 是原根的定义矛盾
    * 所以 $g^{\frac{p-1}{2}}\equiv-1(\bmod p)$
* **重点来了！！！**
  * 那么用 $g_n$ 替换 $\omega_n$
  * 用逆元替换除法
  * 就从 FFT 得到了 NTT！！

### 5、模板

* 最后给大家提供 [洛谷P3803](https://www.luogu.com.cn/problem/P3803)的 FFT 和 NTT 两个模板
* [NTT 模板](https://www.luogu.com.cn/paste/yf3gcy02)
* [FTT 模板](https://www.luogu.com.cn/paste/b4vqr8wh)

### 6、习题

* [小视野：高精度求积](http://gdgzoi.com/problem.php?cid=2207&pid=1)
* [51nod 1135 求素数原根](https://www.51nod.com/Challenge/Problem.html#problemId=1135)
  * [答案](https://www.luogu.com.cn/paste/jtluqt7m)
* [小视野：A*B problem](http://gdgzoi.com/problem.php?cid=2207&pid=0)，[loj 6156](https://loj.ac/p/6156)
* [小视野：九个太阳](http://gdgzoi.com/problem.php?cid=2207&pid=3)
  * 答案在这里面 [oiwiki: 快速数论变换](https://oi-wiki.org/math/poly/ntt/)
* [# P3321 [SDOI2015] 序列统计](https://www.luogu.com.cn/problem/P3321)
* [abc123_h](https://atcoder.jp/contests/abc213/tasks/abc213_h)
* [codechef](https://www.codechef.com/problems/LUCASTH)
* [abc234_f](https://blog.csdn.net/messywind/article/details/122395769)
