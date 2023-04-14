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

- **Def 2.1 - orthogonal endomorphism/transformation:** Let $f\in \operatorname{End}(E).\ f$ is an *orthogonal endomorphism* if for any $x,y\in E$, one has
$$\langle f(x), f(y)\rangle = \langle x,y \rangle$$

- **Prop 2.3:** $f\in \operatorname{End}(E)$ an orthogonal transformation. Then,
$$f^{-1}=f^*$$

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