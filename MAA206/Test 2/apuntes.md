### CH 4

In complex setting, the standard inner product is:
$$\langle,\rangle : \begin{cases}
   \mathbb{C}^2\times\mathbb{C}^2 &\rightarrow \mathbb{C}\\
   \left( \begin{pmatrix}
   z_1\\
   \vdots\\
   z_n 
   \end{pmatrix}\right)
   ,
   \begin{pmatrix}
   w_1\\
   \vdots\\
   w_n 
   \end{pmatrix} &\mapsto \sum_{k=1}^n \bar{z}_kw_k
\end{cases}$$

- **Def 2.11 - inner prod:**:
  1. Sesquilinear: 
     1. Anti-linear in the first argument: $\forall z_1,z_2\in E, \forall w\in E, \forall \lambda\in\mathbb{C}$
     $$\langle z_1+\lambda z_2,w\rangle=\langle z_1,w\rangle+\bar{\lambda}\langle z_2,w\rangle$$
     2. Linear in the second argument: $\forall z\in E, \forall w_1,w_2\in E, \forall \lambda\in\mathbb{C}$
     $$\langle z,w_1+\lambda w_2\rangle=\langle z,w_1\rangle+\lambda\langle z,w_2\rangle$$
  2. Symmetric: $\forall z,w\in E, \langle z,w\rangle=\overline{\langle w,z\rangle}$
  3. Positive: $\forall z\in E, \langle z,z\rangle\ge0$
  4. Definite: $\forall z\in E, \langle z,z\rangle=0\iff z=0$

> Complex vector spaces and inner prod called Hermitian spaces

- $a+\bar{a} = 2\operatorname{Re} (a)$ 
- $$|z+w|^2=\overline{(z+w)}(z+w)=\bar zz + \bar zw +\bar wz+\bar ww = |z|^2+2\operatorname{Re}(\bar zw)+|w|^2$$

#### Hermitian matix

- **Def 2.8 - adjoint/conjugate of $A$:** $A^*:=\phantom{}^t\bar{A}$
- **Def 2.9 - Hermitian:** $A$ is hermitian if $A^*=A$
> If $A$ hermitian, all eigenvalues of $A$ real and it is diagonalizable

- **Def 2.10:** 
  1. **Positive semi-definite:** $z^*Az\ge0$
  2. **Positive definite:** $z^*Az\gt0$
- $$f \text{ is an isomorphism } \iff \operatorname{ker}(f)=\{0\}$$

#### Hermitian norms
We consider the map
$$\|\cdot\|:\begin{cases}
   E&\rightarrow\mathbb{R}^+\\
   z&\mapsto\sqrt{\langle z,z \rangle}
\end{cases}$$

- **Theo 3.1 - Cauchy Schwarz ineq:** $$|\langle z,w\rangle|\le\|z\|\cdot\|w\|$$

- **Theo 4.6 - Grand Schidt:** $e_k'=e_k-\sum_{i=1}^{k-1}\frac{\langle e_i'ze_k\rangle}{\|e_i'\|^2}e_i'$


#### Unitary endomorphism
- **Def 6.1 - Unitary endomorphism:** $\langle f(z),f(w)\rangle=\langle z,w \rangle$
> $f$ unitary then $$\det f = 1$$ and $$f^{-1}=f^*$$

- **Def 6.4 - unitary matrix:** $A^*A=I_n$
> Set of all unitary matrices denoted:
> $$U_n(\mathbb{R})=\{A\in\operatorname{Mat}_n(\mathbb{C})|A^*A=I_n\}$$

- **Corollary 6.7:** $A$ is unitary *iff* the columns of $A$ form an orthonormal basis of $\mathbb{C}^n$ endowed with the standard inner product.

#### The Rayleigh quotient

- **Def 7.5 - Rayleigh quotient:** $$R_f:\begin{cases}
   E\setminus\{0\}&\rightarrow\mathbb{R}\\
   u &\mapsto \frac{\langle f(u), u \rangle}{\|u\|^2} = \frac{z^*Az}{z^*z}
\end{cases}$$

- **Theo 7.7 - Raileigh-Ritz:** $f$ a self-adjoint endo.
We denote: 
$$\lambda_1\le\ldots\le\lambda_n$$
Then
  1. $\lambda_1\le R_f(u) \le \lambda_n$
  2. $\lambda_1=\min\limits_{\|u\|=1}\langle f(u), u\rangle$
  3. $\lambda_n=\max\limits_{\|u\|=1}\langle f(u), u\rangle$

- **Prop 7.8:** Let $A$ hermitian matrix. Then 
$$A\text{ is positive semi-definite}\iff \lambda_i\ge0
\\A\text{ is positive definite}\iff \lambda_i\gt0$$

- **Corollary 7.9:** Let $A$ be hermitian.
  1. The trace and the determinant of $A$ are real
  2. If A is positive semi-definite then
$$\operatorname{tr}A\ge0\text{ and }\operatorname{det}A\ge0$$
  3. If $A$ is positive definite then $$\operatorname{tr}A\gt0\text{ and }\operatorname{det}A\gt0$$