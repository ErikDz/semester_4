> Empezar prop 3.2 hasta theo 4.6

#### 3.3 Uniform convergence and derivation.
> The fact that a sequence of $C^1$ functions $f_n$ converge uniformly to a function $f$ is **not** sufficient to ensure that $f$ is also $C^1$

- **Theo 3.3:** Let $f_n$ a sequence of functions which are derivable on the segment $[a,b]$. We assume that
  - $\exists x_0\in[a,b]$ such that the numerical sequence $(f_n(x_0))$ converges,
  - the sequence of functions $(f'_n)_n$ is unifromly convergent on $[a,b]$
  Then, $(f_n)$ converges uniformly to a function $f$ which is derivable and we have
    $$f'(x)=\lim_{n\rightarrow\infty}f'_n(x)$$
    for every $x\in[a,b]$

#### 4. More involved topics

- **Theo 4.1 - Dini's theorem:** Let $K$ be a compact subset of $E$ and assume that
  1. $(f_n)$ is a sequence of continuous functions $K\rightarrow\mathbb{R}$
  2. $(f_n)$ converges pointwise to a continuous function $f$
  3. $(f_n)$ is decreasing in the sense that $f_n(x)\ge f_{n+1}(x)$ for every $n$ and $x\in K$
   Then the sequence $(f_n)$ converges uniformly to $f$ on $K$

> We note $B(\Omega)$ the space of ounded functiosn $\Omega\rightarrow\mathbb{K}$. It is a vector space and we can define it  on the norm
> $$\|f\|_\infty = \sup_{x\in\Omega}|f(x)|$$

- **Prop 4.2:** Let $N:B(\Omega)\rightarrow\mathbb{R}^+, f\mapsto \sup_{x\in\Omega}|f(x)|$. $N$ is a norm on the vector space $B(\Omega)$.

- **Prop 4.3:** A sequence of functions $(f_n)$ of $B(\Omega)$ converges uniformly to a function $f\in B(\Omega)$ iff $\|f_n-f\|_\infty$ tends to zero

- **Corollary 4.4:** Th space of bounded functions is a closed subspace of $B(\Omega)$

- **Theo 4.5:** $B(\Omega)$ is a complete normed vector space

- **Theo 4.6 - The Weierstrass theorem:** Let $f:[a,b]\rightarrow\mathbb{C}$ be a continuous function. There exists a sequence of polynomials $P_n$ which converges unifromly to $f$ on $[a,b]$. Moreover, if $f$ is real valued, one can choose polynomials $P_n$  with real coefficients.