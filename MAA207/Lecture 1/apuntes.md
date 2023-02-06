In this course, $E$ denotes a normed vector space, $\|.\|$ the norm on $E$ and $\Omega$ a subset of $E$. The functions considered are $\Omega\rightarrow \mathbb{K}$ where $\mathbb{K}=\mathbb{R}$ or $\mathbb{C}$

---

### CHAPTER 1 - Sequences and series of functions
#### 1. Pointwise convergence and the problem of interchanging limits.

- **Def 1.1 - Pointwise convergent:** 
    1. $(f_n)_{n\in\mathbb{N}}\in\Omega^\mathbb{N}$. We say $(f_n)_{n\in\mathbb{N}}$ is pointwise convergent if $\forall x \in \Omega, (f_n(x))_{n\in\mathbb{N}}$ is a convergent sequence. We can then define $f:\Omega\rightarrow\mathbb{K}$ by 
    $$f(x) = \lim_{n\rightarrow\infty}f_n(x)$$
    > We say that $f$ is the pointwise **limit** of the sequence $(f_n)_{n\in\mathbb{N}}$

    2. Let $(g_n)_{n\in\mathbb{N}}\in\Omega^\mathbb{N}$. We say $\sum g_n$ is *pointwise convergent* if $\forall x \in \Omega$, the numerical series $\sum g_n(x)$ is convergent. Then, we can define
    $$g(x)=\sum_{n=0}^\infty g_n(x),\ x\in\Omega $$
    > we call $g$ the **sum** of the series $\sum g_n$

- **Prop 1.2:** Let $f_n:J\rightarrow \mathbb{R}$ a sequence of functions defined on an interval $J$ of $\mathbb{R}$, which converges pointwise to a function $f$.
    1. If for all $n$ the function $f_n$ is increasing (resp. decreasing), the function $f$ is increasing (not nec. strictly) (resp. decreasing).
    2. Assume $J$ is centered at 0. If $\forall n, \ f_n$ are even, (resp odd), then $f$ is even (resp odd).
    3. Assume $J=\mathbb{R}$ and let $T>0$. If $\forall n$, the function $g_n$ is $T$-periodic, then $g$ is $T$-periodic.


#### 2. Uniform convergence

- **Def 2.1 - converges uniformly:**
    1. $(f_n)_{n\in\mathbb{N}}$ converges uniformly to $f$ if $\forall \varepsilon>0,\ \exists N : \forall n\ge N$ and $\forall x\in\Omega$ we have
$$|f_n(x)-f(x)|\le\varepsilon$$
    2. $\sum f_n$ is *uniformly convergent* if the sequence of partial sums $(\sum_{n\le N} f_n)_N$ is uniformly convergent

- **Prop 2.3:** A sequence of $(f_n)_n$ of functions $\Omega\rightarrow\mathbb{K}$ converges uniformly to $f$ if and only if $\|f-f_n\|_{\infty}\xrightarrow[n\rightarrow\infty]{} 0$ and is finite.