#### 3.3 The Rayleigh quotient

- **Def 3.5 - The Rayleigh quotient:** Let $f\in\operatorname{End}(E)$ be a self-adjoint endomorphism of $(E,\langle,\rangle)$. The Rayleigh quotient of $f$ is the application
$$R_f:\begin{align*}
   E\setminus\{0\} &\rightarrow \mathbb{R}\\
   u &\mapsto \frac{\langle f(u),u\rangle}{\|u\|^2}
\end{align*}$$

- **Def 3.6 - The raileigh quotient (Matrix):** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix. The *Rayleigh quotient* of $A$ is the application
$$R_A:\begin{align*}
   \mathbb{R}^n\setminus \{0\} &\rightarrow \mathbb{R}\\
   x &\mapsto \frac{\phantom{}^txAx}{\phantom{}^txx} = \frac{\langle Ax,x\rangle}{\|x\|^2}
\end{align*}$$

- **Theo 3.7 - Rayleigh-Ritz:** Let $f\in\operatorname{End}(E)$ be a self-adjoint endomorphism. Let us denote the eigenvalues of $f$ by $\lambda_1,\ldots,\lambda_n$ such that
$$\lambda_1\le\ldots\le\lambda_n$$
Then one has
  1. For any $u\in E\setminus\{0\}$
    $$\lambda_1\le R_f(u)\le\lambda_n$$
  2. One has
    $$\lambda_1=\min_{u\in E\setminus\{0\}}R_f(u)=\min_{\|u\|=1}\langle f(u), u \rangle$$
  3. One has
    $$\lambda_n=\max_{u\in E\setminus\{0\}}R_f(u)=\max_{\|u\|=1}\langle f(u), u \rangle$$

- **Theo 3.8 - Courant Fischer:** Let $f\in\operatorname{End}(E)$ be a self-adjoint endomorphism and let $\lambda_1\le\ldots\le\lambda_n$ denote the eigenvalues of $f$. Let us denote by $(v_1,\ldots,v_n)$ an orthonormal basis of $E$ such that $v_i$ is and eigenvector associated to the eigenvalue $\lambda_i$ for all $i\in[|1,\ldots,n|]$. Let us also define,
$$E_i=\operatorname{Span}\{v_1,\ldots,v_n\}$$
and set $E_0=\{0\}$. Lastly, for any $i\in\{1,\ldots,n\}$ consider the set of all subspaces of dimension $i$ of $E$.
$$Gr_i=\{F\subset E | \dim F=i\}$$
Then, for any $i\in\{1,\ldots,n\}$ one has
$$\begin{algin*}
\lambda_i &= R_f(v_i)\\
&= \max_{u\in E_i\setminus\{0\}}R_f(u)\\
&=\min_{u\in E_{i-1}\setminus\{0\}^\bot}R_f(u)\\
&= \min_{F\in Gr_i}\max_{u\in F\setminus \{0\}}R_f(u)\\
&= \max_{F\in Gr_{i-1}}\min_{u\in F^\bot\setminus\{0\}}R_f(u)
\end{algin*}$$

- **Corollary 3.9:** Let $f,g\in\operatorname{End}(E)$ be self-adjoint endomorphisms. Let us denote by $\lambda_1(f)\le\ldots\le\lambda_n(f), \lambda_1(g)\le\ldots\le\lambda_n(g)$ and $\lambda_1(f+g)\le\ldots\le\lambda_n(f+g)$, the eigenvalues of $f,g$ and $f+g$ respectively. Then, for any $i\in\{1,\ldots,n\}$ one has
$$\lambda_1(f)+\lambda_i(g)\le \lambda_i(f+g) \le \lambda_n(f)+\lambda_i(g)$$

> Creo q positivity for matrices (ult parte ch3) sera siguiente lecture