> Hasta prop 3.5

#### 2. Basic operations on power series

- **Prop 2.1:** Let $\sum a_nz^n$ be a power series with radius of convergence $R$, and $\sum b_nz^n$ a power series with radius of convergence $R'$. Let $R''$ be the radius of convergence of the power series $\sum (a_n+b_n)z^n$. We have $R''\ge min(R,R')$. Moreover, if $R\ne R'$ then $R''=min(R,R')$

- **Def 2.2 - product:** The **product** of the numerical series $\sum u_n$ and $\sum v_n$ is the series $\sum w_n$ defined by
$$w_n=u_0v_n+u_1v_{n-1}+\ldots+u_nv_0=\sum_{i+j=n}u_iv_j$$

- **Prop 2.3:** If the series $\sum u_n$ and $\sum v_n$ are absolutely convergent, then their product $\sum w_n$ is also absolutely convergent and we have
  $$\sum_{n=0}^\infty w_n = \left(\sum_{n=0}^\infty u_n\right)\left(\sum_{n=0}^\infty v_n\right)$$

- **Prop 2.4:** Let $\sum a_nz^n$ be a power series with radius of convergence $R$, and $\sum b_nz^n$ be a power series with radius of convergence $R'$. Set 
$$c_n=\sum_{i+j=n}a_ib_j$$
    for every $n\ge0$. Then, the radius of convergence $R''$ of the power series $\sum b_nz^n$ satisfies $R''\ge min(R,R')$ and for every $|z|\lt min(R,R')$ we have
$$\sum_{n=0}^\infty c_nz^n=\left(\sum_{n=0}^\infty a_nz^n\right)\left(\sum_{n=0}^\infty b_nz^n\right)$$

#### 3. Functions defined by a power series on $\mathbb{R}$

- **Prop 3.1:** Let $\sum a_nz^n$ be a power series of radius of convergence $R\gt0$. Then, the function
$$f:(-R,R)\rightarrow\mathbb{C},\ x\mapsto \sum_{n=0}^\infty a_nx^n$$
is $C^\infty$ and for every $k\gt0$ and $x\in(-R,R)$, we have
$$f^{(k)}(x)=\sum_{n=k}^\infty n(n-1)\ldots(n-k+1)a_nx^{n-k}$$
Moreover, the primitive of $f$ which is equal to 0 for $x=0$ is the function $F:(-R,R)\rightarrow\mathbb{R}$ given by
$$F(x)=\sum_{n=0}^\infty\frac{a_n}{n+1}x^{n+1}$$

- **Lemma 3.2:** For every sequence $(a_n)_n$ of complex numbers, the power series $\sum a_nz^n$ and $\sum_{n\ge1}na_nz^{n-1}$ have the same radius of convergence.

- **Corollary 3.3:** Let $f$ be function on $(-R,R)$ defined by a power series $\sum_{n=0}^\infty a_nx^n$. Then, for every $n$ we have $a_n=\frac{f^{(n)}(0)}{n!}$

- **Remark 3.4:** Let $f$ be a function on $(-R, R)$ defined by a power series $\sum_{n=0}^\infty a_nx^n$. Then for all $n$, the Taylor expansion of order $n$ of $f$ at $x=0$ is given by
$$f(x)=a_0+a_1x+\ldots+a_nx^n+o(x^n)$$

- **Prop 3.5:** Let $\sum a_nx^n$ be a power series with radius of convergence $R\gt0$ and let $f:(-R,R)\rightarrow\mathbb{C}$ be the function defined by its sum. Let $x_0\in(-R,R)$ and set $R_0=R-|x_0|$. Then, for every $x\in(x_0-R_0,x_00+R_0)$, we have
$$f(x)=\sum_{n=0}^\infty \frac{f^{(n)}(x_0)}{n!}(x-x_0)^n$$
    In othre words, $f$ can be written as a power series centered at $x_0$ on the segment $(x_0-R_0,x_0+R_0)$ with coefficients equal to those of the Taylor expansions of $f$ at $x_0$

