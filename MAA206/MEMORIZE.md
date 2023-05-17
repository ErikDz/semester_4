### Previous
- **Def - linear subspace:**
  1. Closed under addition
  2. Closed under scalar mult
  3. 0 in the subset
### CH 1
- **Def 4.1 - transpose/dual of map:** 
For $f:E\rightarrow F$
$$\begin{align*}
\phantom{}^t f: F^*&\rightarrow E^*\\
l&\mapsto l\circ f
\end{align*}$$

- **Def 8.1 - annihilator:** For $A\subset E$, the annihilator of $A$ is
$$A^\circ := \{l\in E^* | \langle l,x \rangle = 0 \forall x\in A\}$$
    For $B\subset E^*$
$$\phantom{}^\circ B:= \{x\in E | \langle l,x \rangle = 0\forall l\in B \}$$

> Toda la verga q funciona con $\phantom{}^\circ B$ funciona igual con $A^\circ$
- **Prop 8.3:** 
  1. $A_1\subset A_2 \implies A_2^\circ \subset A_1^\circ$
  2. $B_1\subset B_2 \implies \phantom{}^\circ B_2 \subset \phantom{}^\circ B_1$
  3. $A^\circ = (Span(A))^\circ$
  4. $\phantom{}^\circ (A^\circ) = A$

- **Theo 8.5:** $\dim F + \dim F^\circ = \dim E$

### CH 2
- **Def - inner product:**
  1. Bilinear
  2. Symmetric
  3. Positive
  4. Definite

- **Theo 2.1 - Cauchy-Schwarz ineq:** We consider $(E,\langle,\rangle)$ an inner product space with the norm $\|\cdot\|:x\mapsto \sqrt{\langle x,x \rangle}$. Then
$$\left|\langle x,y \rangle\right|\le \|x\|\|y\|$$

- **Def 3.11 - $p_F$:** Let $E=F\oplus G$. The *projection onto $F$ along $G$ is the linear map
$$p: x\mapsto x_F$$
where $x=x_F+x_G$ with $x_F\in F$ and $x_G\in G$

- **Def - orthogonal projection:** A projection onto $F$ along $F^\top$ ($x=x_F+x_{F^\top}$)

- **Theo 3.18 - Gram Schmidt process:** (gives orthonogal base to a base)
$$e_k'=e_k-\sum_{i=1}^{k-1}\frac{\langle e_i', e_k \rangle}{\|e_i'\|^2}e_i'$$

- **Prop 3.15:** $F\subset E$ a linear subspace of dim $m$. Let $e_1,\ldots,e_m$ be an orthogonal basis of $F$. Then, for any $x\in E$, one has
$$p_F(x)=\sum_{i=1}^m\frac{\langle e_i,x \rangle}{\|e_i\|^2}e_i\text{ and } p_{F^\top}(x)=x-p_f(x)$$

- **Prop 3.17:** Let $F$ be a linear subspace of $E$. Let $u\in E$. For any $v\in F$, one has
$$d(u,F)=\|u-v\|\iff v=p_F(u)$$
  In particular
  $$d(u,F)=\|u-p_F(u)\|=\|p_{F^\bot}(u)\|$$

- **Normalization:** Divide each new vector by its norm

- $\operatorname{dist}(x^2,\mathbb{R}_1[x]) = \left\Vert x^2-p_{\mathbb{R}_1[x]}(x^2)\right\Vert,$
> If you have the orthonormal basis for $\mathbb{R}_2[x]$ simply remove the last element of the basis to get the orthonormal basis for $\mathbb{R}_1$ and from there get the projections

- $\|u-v\|^2=\|u\|^2-\langle u,v \rangle + \|v\|^2$

### CH 3
- **Prop 2.1:** $f\in\operatorname{End}(E)$. $A:=M(f)_\mathcal{B}$ then
$$M(f^*)_\mathcal{B}=\phantom{}^tA$$

- **Def 2.1 - orthogonal endomorphism/transformation:** Let $f\in \operatorname{End}(E).\ f$ is an *orthogonal endomorphism* if for any $x,y\in E$, one has
$$\langle f(x), f(y)\rangle = \langle x,y \rangle$$

- **Prop 2.3:** $f\in \operatorname{End}(E)$ an orthogonal transformation. Then,
$$f^{-1}=f^*$$

- **Corollary 2.8:** $A\in\operatorname{Mat}_n(\mathbb{R})$. Then $A$ orthogonal iff the columns of $A$ form an orthonormal basis of $\mathbb{R}^n$ endowed with the standard inner product.

- **Prop 1.1:** $f\in End(E)$, there exists a unique endomorphism $f^*\in End(E)$ such that for any $x,y\in E$,
$$\langle f(x),y \rangle = \langle x, f^*(y)\rangle$$
  $f^*$ is called the **adjoint endomorphism** of $f$

- **Def 2.9 - Orthogonal symmetry:** Let $F\subset E$ a linear space. Then one defines orthogonal symmetry wrt $F$ as the linear map
$$\begin{align*}
s_F: E&\rightarrow E\\
x&\mapsto x_F-x_{F^\bot}
\end{align*}$$
  Where $x_F\in F$ and $x_{F^\bot}\in F^\bot$  and $x_F+x_{F^\bot}=x$
  Equivalently,
$$s_F:=p_F-p_{F^\bot}$$

- **Theo 3.4:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a **symmetric** matrix. Then it is diagonalizable.

- **Prop 4.3:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ symmmetric. Then,
$$A\text{ is positive semi-definite }\iff \lambda_i\ge0\ \forall i\in\{1,\ldots,n\}\\
A\text{ is positive definite} \iff \lambda_i\gt0\ \forall i\in\{1,\ldots,n\}
$$

- **Corollary 4.4:** $A\in\operatorname{Mat}_n(\mathbb{R})$ symmetric.
  1. If $A$ is positive semi-definite, then 
  $$\operatorname{tr}A\ge0\text{ and } \operatorname{det}A\ge0$$
  2. If $A$ positive definite, then
  $$\operatorname{tr}A\gt0\text{ and }\operatorname{det}A\gt0$$


- **Def 3.1 - Self adjoint:** $f$ self-adjoint if $f^*=f$
- **Def 3.5 - Rayleigh:** Let $f\in\operatorname{End}(E)$ be self-adjoint and $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix.

$$R_A:\begin{cases}
 \mathbb R^n\setminus\{0\} &\rightarrow\mathbb{R}\\
 x&\mapsto \frac{\phantom{}^txAx}{\phantom{}^txx}=\frac{\langle Ax,x\rangle}{\|x\|^2}
\end{cases}\\R_f:\begin{cases}
 E\setminus\{0\} &\rightarrow\mathbb{R}\\
 u&\mapsto \frac{\langle f(u), u\rangle}{\|u\|^2}
\end{cases}
$$

- **Theo 3.7:** Let $f\in\operatorname{End}(E)$ self-adjoint. Then,
$$\lambda_1\le\ldots\le\lambda_n$$

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

- **Theo 4.6 - Grand Schidt:** $e_k'=e_k-\sum_{i=1}^{k-1}\frac{\langle e_i'e_k\rangle}{\|e_i'\|^2}e_i'$


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