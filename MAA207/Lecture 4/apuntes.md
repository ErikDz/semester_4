> Hasta theo 1.8

## Chapter 2 - Power series
#### 1. First definitons

- **Def 1.1 - power series:** A series of functions $\mathbb{C}\rightarrow\mathbb{C}$ of the form $\sum a_nz^n$ where $(a_n)_n$ be a sequence of complex numbers. The $a_n$ are called the coefficients of the powers series

- **Prop 1.2 - Cauchy rule or root test:** Consider a series of complex numbers $\sum b_n$ and set $\beta=\lim\sup_{n\rightarrow\infty}(|b_n|)^\frac{1}{n}\in\mathbb{R}_+\cup\{+\infty\}$. Then
  1. If $\beta\lt1$ the series $\sum b_n$ is absolutely convergent.
  2. If $\beta\gt1$ the series $\sum b_n$ is divergent

- **Remark 1.3:** In the case $\beta=1$, we can't say anything : for instance we have $\beta=1$ for both $\sum\frac{1}{n}$ and $\sum\frac{1}{n^2}$

- **Prop 1.4 - D'Alembert rule or radio test:** Let $\sum a_n$ be a numerical series
  1. If $\lim\sup_{n\rightarrow\infty}\left|\frac{a_{n+1}}{a_n}\right|\lt1$, the series $\sum a_n$ is absolutely convergent
  2. If $\lim\sup_{n\rightarrow\infty}\left|\frac{a_{n+1}}{a_n}\right|$, the series $\sum a_n$ is divergent.

#### 1.2 Radius of convergence

- **Theo 1.5:** Let $\sum a_nz^n$ be a power series. $\alpha=\lim\sup_{n\rightarrow\infty}|a_n|^\frac{1}{n}$ and $R=\frac{1}{\alpha}$ (with the conention that $R=+\infty$ if $\alpha=0$ and $R=0$ if $\alpha=+\infty$). Then, the series $\sum a_nz^n$ is absolutely convergent for $|z|\lt R$ and divergent for $|z|\gt R$

- **Def 1.6 - Radius of convergence:** $R$ is called the **radius of convergence** of the power series $\sum a_nz^n$.
- **Prop 1.7:** Consider a power series $\sum a_nz^n$ and let $R$ be its radius of convergence. Then $R$ is the supremum of the $r\ge0$ such that the sequence $|a_n|r^n$ is bounded

- **Theo 1.8:** Let $\sum a_nz^n$ be a ower series and $R$ be its radius of convergence. Then, for every $\epsilon\gt0 $ the series $\sum_n a_nz^n$ converges normally on the closed ball $\bar{B}_{R-\epsilon}=\{z\in\mathbb{C}: |z|\lt R-\epsilon\}$. In particular, the sum $f(z)=\sum_n a_nz^n$ defines a continuous function on the open ball $B_R=\{z\in\mathbb{C}:|z|<R\}$