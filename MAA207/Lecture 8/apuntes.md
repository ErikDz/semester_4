> Hasta prop 2.9

### CH 3 - Fourier Series

#### Trigonometric series

- **Def 2.1:**
1. **Trigonometric polynomial:** A function of the form $x\mapsto\sum_{n=-N}^N c_ne^{ixn}$ or equivalently a function the form $x\mapsto \frac{a_0}{2} + \sum_{n=1}^N a_n\cos(nx) + b_n\sin(nx)$, for some integer $N\ge0$ and coefficients $c_n\in\mathbb{C}$ (respectively $a_n,b_n\in\mathbb{C}$)
2. **Trigonometric series:** series of functions of the form $c_0+\sum_{n\ge1}c_n e^{inx}+c_{-n}e^{-inx}$ or, equivalently, a series of functions of the form $\frac{a_0}{2}+\sum_{n\ge1}(a_n\cos(nx)+b_n\sin(nx))$ for some coefficients $c_n\in\mathbb{C}$. In the former case, we also denote such series by $\sum_{n\in\mathbb{Z}}c_ne^{inx}$

- **Prop 2.3:** If the series $\sum_{n\in\mathbb{N}}|c_n|$ and $\sum_{n\in\mathbb{N}}|c_{-n}|$ are both convergent, then the trigonometric series $\sum_{n\in\mathbb{Z}}c_ne^{inx}$  is normally convergent on $\mathbb{R}$ and the function $x\in\mathbb{R}\mapsto \sum_{n=-\infty}^\infty c_ne^{inx}$ is a continuous and $2\pi$-periodic

- **Prop 2.4:** If the squencees $(c_n)_{n\in\mathbb{N}}$ and $(c_{-n})_{n\in\mathbb{N}}$ are real, decreasing, and tend to $0$ at infinity, then the trigonometric series $\sum_{n\in\mathbb{Z}} c_ne^{inx}$ converges pointwise on $\mathbb{R}\setminus 2\pi\mathbb{Z}$, and uniformly on every interval of the form $[2k\pi+\alpha,2(k+1)\pi-\alpha]$ where $k\in\mathbb{Z}$ and $0<\alpha<2\pi$

- **Lemma 2.5:** Let $f_n$ and $g_n$ be two sequences of functions $\Omega\rightarrow\mathbb{K}$ such that
  - The partial sums $\sum_{n=1}^N f_n$ are uniformly bounded
  - The sequence $(g_n)_n$ converges uniformly to zero on $\Omega$
  - For all $x\in\Omega$, the sequence $(g_n(x))_n$ is decreasing
    Then the series $\sum f_ng_n$ converges uniformly on $\Omega$

- **Def 2.6 - piecewise $C^m$:** Let $m\in\mathbb{N}\cup\{\infty\}$. A function $f:[a,b]\rightarrow\mathbb{C}$ is **piecewise $C^m$**if there exists an integer $k\ge1$ and a sequence $a=x_0<x_1<...<x_k=b$ such taht for every $0\le i \le k-1$, the restriction of $f$ to $(x_i,x_{i+1})$ is $C^m$, and can be extended by continuity to a $C^m$ function on $[x_i,x_{i+1}]$
> A function $f:\mathbb{R}\rightarrow\mathbb{C}$ is piecewise $C^m$ if it is piecewise $C^m$ on every segment $[a,b]$
> Piecewise $C^0$ functions will aslo be called **piecwise continuous** functions.

- **Def 2.7 - Fourier coefficients:** Let $f:\mathbb{R}\rightarrow\mathbb{R}$ be a piecewise continuous function which is $2\pi$-periodic. We define the **Fourier coefficients** of $f$ by
$$c_n(f)=\frac{1}{2\pi}\int_0^{2\pi}e^{-inx}f(x)dx,\ \ \text{for } n\in\mathbb{Z}$$

- **Prop 2.9:** Let $f$ be a trigonometric polynomial. then, there exists $N\gt0$ such that $c_n(f)=0$ for $|n|\gt N$ and we have $f(x)=\sum_{n\in\mathbb{Z}}c_n(f)e^{inx}$ for all $x\in\mathbb{R}$