- **Theo 2.13 - Fejer's theorem:** Let $f:\mathbb{R}\rightarrow\mathbb{C}$ be a continuous $2\pi$ periodic function. Then, there exists a sequence $(C_n)_n$ of trigonometric polynomials such that $(C_n)_n$ converges to $f$ uniformly

- **Corollary 3.5:** 
  1. If $f$ is $2\pi$-periodic, continuous and $c_n(f)=0$ for all $n\in\mathbb{Z}$ then $f=0$.
  2. If $f$ is $2\pi$-periodic, piecewise continuous then $c_n(f)\rightarrow0$ as $|n|\rightarrow\infty$
  3. If $f$ is $2\pi$-periodic and continous and if the Fourier series associated to $f$ converges uniformly, thn $f(x)=\sum_{n=-\infty}^\infty c_n(f)e^{inx}$ for all $x\in\mathbb{R}$


####  4. Pointwise and uniform convergence of Fourier series

- **Theo 4.1 - Jordan Dirichlet theorem:** Let $f:\mathbb{R}\rightarrow\mathbb{C}$ be a $2\pi$-periodic, piecewise continuous function such that for all $t_0\in\mathbb{R}$, the function
$$\mathbb{R}\setminus\{0\}\rightarrow\mathbb{C}, h\mapsto\frac{f(t_0+h)+f(t_0-h)-f(t_0+)-f(t_0-)}{h}$$
    isbounded in a nieghborhood of zero. Then the Fourier series $\sum_{n\in\mathbb{Z}}c_n(f)e^{inx}$ converges pointwise and we have
    $$\sum_{n=-\infty}^{+\infty}c_n(f)e^{inx}=\frac{f(x-)+f(x+)}{2}$$
    for every $x\in\mathbb{R}$

- **Corollary 4.2:** If $f$ is $2\pi$ periodic and piecewise $C^1$, then the Fourier series of $f$ converges for all $x$ toward $\frac{f(x-)+f(x+)}{2}$

- **Lemma 4.3:** Let $f$ be a continuous, pieceiwse $C^1$, $2\pi$ periodic function. We define $\varphi:\mathbb{R}\rightarrow\mathbb{C}$ by $\varphi(t)=f'(t)$ if $f$ is differentiable at $t$, and $\varphi(t)=\frac{f'(t+)+f'(t-)}{2}$ otherwise. THen, we have $c_n(\var)=in$ for all $n\in\mathbb{Z}$.

- **Theo 4.4:** Let $f$ be a continuous, piecewise $C^1$, $2\pi$ periodic function. Then the Fourier series of $f$ converges uniformly to $f$ on $\mathbb{R}$. 