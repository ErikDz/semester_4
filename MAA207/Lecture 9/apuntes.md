> Hasta theo 2.13

- **Prop 2.9:** Let $\sum_{n\in\mathbb{Z}}c_ne^{inx}$ be a trigonometric series that converges uniformly on $\mathbb{R}$ and let $f(x)=\sum_{n=-\infty}^\infty c_ne^{inx}$ be its sum. Then, the Fourier series of $f$ is the same trigonometric series $\sum_{n\in\mathbb{Z}}c_ne^{inx}$ (i.e. $c_n(f)=c_n \forall n$) and therefore $f$ is equal to its Fourier series everywhere

- **Prop 2.11:** The Fourier coefficient satisfy the following properties:
  1. If $f$ is real valued, then for all $n\in\mathbb{N}, \ a_n(f),b_n(f)\in\mathbb{R}$ and $c_{-n}(f)=\bar{c_n(f)}$
  2. If $f$ is even, then $\forall n\in\mathbb{N},\ b_n(f)=0$ and $c_n(f)=c_{-n}(f)$
  3. If $f$ is odd, then $\forall n\in\mathbb{N}$, $a_n(f)=0$ and $c_n(f) = -c_{-n}(f)$ 

#### 2.3 Approximation of conntinuous functions by trigonometric polynomials

- **Theo 2.13 - Fejer's theorem:** Let $f:\mathbb{R}\rightarrow\mathbb{C}$ be a continuous $2\pi$ periodic function. Then, there exists a sequence $(C_n)_n$ of trigonometric polynomials such that $(C_n)_n$ converges to $f$ uniformly