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

- **Def 4.1 - semi definite & positive definite:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a summetric matrix
  1. We say that $A$ is **positive semi-definite** if for any $x\in\mathbb{R}^n$, one has
  $$\phantom{}^txAx\ge0$$
  2. We say that $A$ is positive definite if for any $x\in\mathbb{R}^n\setminus \{0\}$, one has
   $$\phantom{}^txAx\gt0$$

- **Prop 4.2:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix. Consider the function
$$\varphi\begin{align*}
  \mathbb{R}^n\times\mathbb{R}^n &\rightarrow \mathbb{R}\\
  (x,y) &\mapsto \phantom{}^txAy
\end{align*}$$
Then $A$ is positive iff $\varphi$ is an inner product

- **Prop 4.3:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix. Let us denote by $\lambda_1,\ldots,\lambda_n$ the eigenvalues of $A$. Then,
$$A \text{ is positive semi-definite} \iff \lambda_i\ge0\forall i\in \{1,\ldots,n\}$$
and
$$A \text{ is positive definite} \iff \lambda_i\gt0 \forall i\in\{1,\ldots,n\}$$

- **Corollary 4.4:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix
  1. If $A$ is positive semi-definite **then**
  $$\operatorname{tr} A \ge 0\text{ and }\operatorname{det}A\ge0$$
  2. If $A$ is positive definite, **then**
  $$\operatorname{tr} A\gt 0\text{ and } \operatorname{det}\gt 0$$

- **Corollary 4.5:** Let $A\in\operatorname{Mat}_2(\mathbb{R})$ be a symmetric matrix of size two
  1. Then $A$ is poistive semi-definite **iff**
  $$\operatorname{tr}A\ge0\text{ and } \operatorname{det}A\ge 0$$
  2. and $A$ is positive definite **iff**
  $$\operatorname{tr}A\gt0\text{ and } \operatorname{det}A\gt0$$

- **Theo 4.6:** Let $A=(a_{i,j})_{1\le i,j\le p}\in\operatorname{Mat}_p(\mathbb{R})$
  Then $A$ is positive definite iff $\operatorname{det} A_p\gt 0 \forall p\in\{1,\ldots,n\}$