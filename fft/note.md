<h3>Catalogue</h3>

* [Fourier Transform](#1)

    * [Definition of Fourier Transform](#1.1)

    * [property of Fourier Transform](#1.2)

<h2 id="1">Fourier Transform</h2>

<h3 id="1.1">定义</h3>

**傅里叶变换**(Fourier Transform), 是一种线性积分变换, 用于信号在时域(或空域)和频域之间的变换, 在物理学和工程学中有许多的应用.

一般情况下, 傅里叶变换指的是**连续傅里叶变换**, 亦即连续函数的傅里叶变换, 其定义如下:

(连续)傅里叶变换将可积函数$f:\mathbb{R}\rightarrow\mathbb{C}$表示成复指数函数的积分或级数形式.

$\hat{f}(\xi)=\int_{-\infty}^{\infty}f(x)e^{-2\pi ix\xi}dx$, $\xi$为任意实数.

其中, 自变量x表示时间(以s为单位), 变换变量$\xi$表示频率(以Hz为单位).

在适当条件下, $\hat{f}$可由**逆变换**(inverse Fourier Transform)由下式决定$f$:

$f(x)=\int_{-\infty}^{\infty}\hat{f}(\xi)e^{2\pi i\xi x}d\xi$, x为任意实数.

$f$和$\hat{f}$常被称为**傅里叶积分对**或**傅里叶变换对**.

<h3 id="1.2">性质</h3>

* 线性性质

两函数之和的傅里叶变换等于各自变换之和

* 平移性质



* 微分关系

* 卷积特性

* 帕塞瓦尔特性

