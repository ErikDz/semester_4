> Desde theo 3.6
> Hasta "A formula for the orthogonal projection"

#### 3.2 Orthogonal spaces
- **Def 3.7 - Orthogonal Space:** Let $A\subset E$. The *orthogonal space* of $A$ or *orthogonal* of $A$ is the set
$$A^\bot = \{x\in E| \langle x,y \rangle = 0, \forall y\in A\}$$

- **Prop 3.8:** Let $(E,\langle,\rangle)$ be a Euclidean space. Let $A\subset E$. Then:
  1. $\{0\}^\bot=E$ 
  2. $E^\bot=\{0\}$
  3. $A^\bot$ is a linear subspace of $E$.
  4. $A^\bot=(\text{Span}A)^\bot$
  5. For any subset $B\subset E$, if $A\subset B$, then $B^\bot\subset A^\bot$

- **Prop 3.9:** Let $(E,\langle,\rangle)$ be a Euclidean space. Let $\Phi:E\rightarrow E^*$ be the isomorphism induced by $\langle,\rangle$. Let $A\subset E$ be a subset of E. Then
    $$A^\bot=\Phi^{-1}(A^0)$$

- **Theo 3.10:** Let $(E,\langle,\rangle)$ be a Euclidean space. Let $F$ be a vector subspace of $E$. Then:
  1. $\dim F + \dim F^\bot = \dim E$
  2. $E=F\bigoplus F^\bot$
  3. $(F^\bot)^\bot = F$

#### 3.3 Orthogonal projections
- **Def 3.11 - projection:** Given a vecor space $E$ and two vector subspaces $F,G\subset E$ such that $E=F\bigoplus G$, the *projection onto $F$ along $G$* is the linear map
$$\begin{align*}
p: E &\rightarrow E\\
x &\mapsto x_F
\end{align*}$$
    where $x=x_f+x_G$ with $x_F\in F$ and $x_G\in G$

- **Def 3.12:** Let $F$ be a linear subspace of $E$. The *orthogonal projection onto $F$* is the projection onto $F$ along $F^\bot$
- **Prop 3.12:** Let $F$ be a linear subspace of $E$ and let $p_F$ and $p_{F^\bot}$ deonte the orthogonal projections onto $F$ and $F^\bot$ respectively. Then
$$id_E=p_F+p_{F^\bot}$$
    Moreover, for any $x\in E$
    $$\langle p_F(x), p_{F^\bot}(x)\rangle=0$$

- **Prop 3.14:** Let $F$ be a linear subspace of $E$. For any $x,y\in E$, one has
$$\langle x,p_F(y)\rangle = \langle p_F(x), y\rangle$$

- **Prop 3.15:** Let $F\subset E$ be a linear subspace of dimension $m$. Let $e_1,\ldots,e_m$ be an orthogonal basis of $F$. Then, for any $x\in $, one has
$$p_F(x)=\sum_{i=1}^m \frac{\langle e_i, x\rangle}{\|e_i\|^2}e_i \text{  and  } p_{F^\bot}(x) = x-\sum_{i=1}^m\frac{\langle e_i,x\rangle}{\|e_i\|^2}e_i$$
    In particular, if the basis $\mathcal B$ is morever orthonormal *then one has*:
$$p_F(x)?\sum_{i=1}^m \langle e_i, x\rangle e_i \text{   and   } p_{F^\bot}(x)=x-\sum_{i=1}^m \langle e_i, x\rangle e_i$$

> Desde aquí para abajo no estaba en lec 5

- **Def 3.16 - distance:**  Let $F$ be a linear subspace of $E$. Let $u\in E$. The distance from $u$ to $F$ is defined t obe
$$d(u,F):=\inf_{v\in F}\|u-v\|$$

- **Prop 3.17:** Let $F$ be a *linear subspace* of $E$. Let $u\in E$. For any $v\in F$, one has:
$$d(u,F)=\|u-v\|\iff v=p_F(u)$$
    in particular
$$d(u,F)=\|u-p_F(u)\|=\|p_{F^\bot}(u)\|$$


#### 3.4 The Gram-Schmidt orthonormalization process 
- **Theo 4.18 - Gram Schmidt orthonormalization process:** Let $(E,\langle,\rangle)$ be a Euclidean space of dimension $n\lt+\infty$. Let $\mathcal{B}:=(e_1,\ldots,e_n)$ be a basis of $E$. Then there exists an orthonormal basis $\varepsilon_1,\ldots,\varepsilon_n$ of $E$ such that for every $i\in\{1,\ldots,n\}$ one has
$$\text{Span}(e_1,\ldots,e_i)=\text{Span}(\varepsilon_1,\ldots,\varepsilon_i)$$
In particular, $(E,\langle,\rangle)$ admits an orthonormal basis.