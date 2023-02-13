#### 2.2 Uniform convergence and continuity

- **Theo 2.4:** Let $f_n:\Omega\rightarrow\mathbb{K}$ a sequence of functions s.t. $f_n$ converges uniformly to $f$. If the $f_n$ are continuous at $x_0$ then $f$ continuous at $x_0$

- **Corollary 2.5:** Let $f_n:\Omega\rightarrow\mathbb{K}$ a sequence of functions s.t. it converges unif to $f$. If the $f_n$ are continuous on $\Omega$ then $f$ continuous in $\Omega$.

#### 2.3 Uniform Cauchy Criterion

- **Theo 2.6:** A sequence of functions $f_n:\Omega\rightarrow\mathbb{K}$ converges uniformly on $\Omega$ iff $\forall \varepsilon>0, \exists N \in\mathbb{N}:\forall m \ge n\ge$ and $\forall x\in\Omega$
$$|f_n(x)-f_m(x)|\le \varepsilon$$

#### 2.4 Normal convergence of series
- **Def 2.7 - Normally Convergent:** Let $\sum f_n$ a series of functions $\Omega\rightarrow\mathbb{K}$. We say $\sum f_n$ **normally convergent** if there exists a convergent numerical series of non negative numbers $\sum a_n$ such that $|f_n(x)|\le a_n \ \ \forall n\in\mathbb{N}, \forall x\in\Omega$

- **Theo 2.8:** A series $\sum f_n$ which is normally convergent is uniformly convergent an thus, pointwise convergent

- **Prop 2.9:** Let $g_n\Omega\rightarrow\mathbb{R}$ be a sequence of functions s.t $0\le_{n+1}(x)\le g_n(x)\forall n\in\mathbb{N}$ and $x\in\Omega$. Assume that $\exist a_n$  with $\lim_{n\rightarrow\infty}a_n=0$ s.t. $g_n(x)\le a_n \forall n\in\mathbb{N}, \forall x\in\Omega$. thn, the series of the function $\sum (-1)^n g_n$ is uniformly convergent on $\Omega$
4
- **Prop 2.10:** Let $(a_n)_{n\in\mathbb{N}}$  a decresing sequence of positie real numbers converging to zero. Then, $\sum (-1)^n a_n$ is convergent. Furthermore, if we denote by $S_N=\sum{n\le N} (-1)^n a_n$ the sequence of partial sums, and by $S=\sum_{n=0}^\infty (-1)^n a_n$ the sum of the series, then $\forall n, S$ is between $S_n$ and $S_{n+1}$ and we have $|S-S_n|\le a_{n+1}$

#### 2.5 Exchange of limits

- **Theo 2.11:** Let $f_n:\Omega\rightarrow\mathbb{K}$ a sequence of functions that converges uniformly to a limit $f$. Let $x_0\in\bar{\Omega}$ where $\bar{\Omega}$ denotes the adherence of $\Omega$ or let $x_0=\plusmn\infty$. in the case where $\Omega=[a,\infty)\text{ or }(-\infty, b]$. Assume that $\forall n\in\mathbb{N}$ the limit
$$\lim_{x\rightarrow x_0} f_n(x)$$
exists and denote it by $\alpha_n$. Then, the two limits
$$\lim_{n\rightarrow \infty}\alpha_n\text{ and }\lim_{x\rightarrow x_0} f(x)$$
exists and we have the equality
$$\lim_{n\rightarrow\infty}\alpha_n = \lim_{x\rightarrow x_0}f(x)$$


### 3. Integration and derivation
#### 3.1 Uniform convergence and integration
- **Prop 3.1:** Let $(f_n)_n$ a sequence of functions on a **compact** interval $I$ of $\mathbb{R}$. Assume that $f_n$ convergers uniformly to $f$. Then
$$\int_I f_n \rightarrow \int_I f$$

#### 3.2 Normal convergence and integration

- **Prop 3.2:** Let $a\in\mathbb{R}, b\in\mathbb{R}\cup\{+\infty\}$ and let $f_n:[a,b)\rightarrow\mathbb{R}$ a sequence of continuous functions, all integrable on $[a,b)$. Assume:
  1. $\sum_n f_n$ normally convergent on all segment $[a,u]\subset [a,b)$
  2. $\sum_n \int_a^b |f_n(t)|dt$ is convergent
  Then, the integral $\int_a^b\sum_{n=0}^\infty f_n(t)dt$ is convergent and we have
    $$\int_a^b(\sum_{n=0}^\infty f_n(t))dt = \sum_{n=0}^\infty \int_a^b f_n(t)dt$$

    
