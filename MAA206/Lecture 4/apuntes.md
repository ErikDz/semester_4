### 2 Euclidean norms
#### 2.1 The Cauchy-Shwarz inequality

Let $(E,\langle,\rangle)$ be an inner product space. Then we consider the map
$$\begin{align*}
  \|\cdot\|:E &\rightarrow\mathbb{R}^+\\
  x &\mapsto \sqrt{\langle x, x \rangle}  
\end{align*}$$
> This defines a norm

- **Theo 2.1 - Cauchy Schwarz ineq:** For any $x,y\in E$ one has
$$|\langle x,y\rangle|\le \|x\|\|y\|$$
    Moreover, the inequality is an equality iff $x$ and $y$ are colinear.

> Example
> 1. For any $n\in\mathbb{N}^*$, and any real $x_1,\ldots,x_n,y_1,\ldots,y_n\in\mathbb{R}$, one has
> $$(\sum_{i=1}^n x_iy_i)^2\le (\sum_{i=1}^n x_i^2)(\sum_{i=1}^n y_i^2)$$
> 2. For any $f,g\in\mathcal{L}^0([0,1],\mathbb{R})$ one has
> $$(\int_0^1 f(t)g(t)dt)^2\le(\int_0^1 f(t)^2dt)(\int_0^1g(t)^2dt)$$

#### 2.2 Norm associated to an inner product
Let $\mathbb{K}=\mathbb{R}$ and let $E$ be a $\mathbb{R}$-vector space. Recall:
- **Def 2.2 - norm:** A norm on $E$ is an application
    $$\|\cdot\|:E\rightarrow\mathbb{R}^+$$
    such that
    1. $\forall\lambda\in\mathbb{R}$ and $\forall x\in E$, one has $\|\lambda x\| = |\lambda|\|x\|$
    2. $\forall x\in E, \|x\|=0 \iff x=0$ 
    3. $\forall x,y\in E,$
        $$\|x+y\|\le \|x\| + \|y\|$$

<br>

Suppose that $(E,\langle,\rangle)$ is an inner-product space.
- **Prop 2.3:** The map $\|\cdot\|$ is a norm on $E$. The norm $\|\cdot\|$ is called thenorm associated to the inner product $\langle,\rangle$.

- **Def 2.4:** An Euclidean norm on $E$ is a norm associated to some inner product on $E$.

- **Prop 2.5:** Let $\|\cdot\|$ the norm associated to the inner product $\langle,\rangle$ on $E$. Then for any $x,y\in E$, one has
    $$\|x+y\|^2+\|x-y\|^2=2(\|x\|+\|y\|^2)$$


### 3 Orthogonality

- **Def 3.1 - Orthogonal:** Let $x,y\in E$. One says that $x$ and $y$ are orthogonal if
                $$\langle x,y\rangle =0$$
            This is sometimes denoted by $x\bot y$

- **Theo 3.2 - Pythagoras:** For any $x,y\in E$, one has
       $$x\bot y \iff \|x+y\|^2=\|x\|^2+\|y\|^2$$ 

- **Def 3.3 - Orthogonal (family):** Let $\mathcal{F}\subset E$ family of vectors of $E$. The family $\mathcal{F}$ is said to be orthogonal if for any $x,y\in\mathcal{F}$ one has $x\bot y$

- **Prop 3.4:** Let $\mathcal{F}$ be an orthogonal family of vecotrs of $E$. If every element of $\mathcal{F}$ is non-zero, then $\mathcal{F}$ is a linearly independent family.

- **Def 3.5:** Let $(E,\langle,\rangle)$ be an Euclidean space of dimension $n$. Let $\mathcal{B}=(e_1,\ldots,e_n)$ be a basis of $E$. One says that:
  1. $\mathcal{B}$ is an orthogonal basis if the family $\mathcal{B}$ is orthogonal, namely if for any $i,j\in\{\1,\ldots,n\}$ such that $i\ne j$ one has
    $$\langle e_i, e_j \rangle =0$$
  2. $\mathcal{B}$ is an orthonormal basis if $\mathcal{B}$ is orthonogonal and if moreover $\|e_i\|=1$ for all $i\in\{1,\ldots,\}$, one has
            $$\langle e_i,e_j \rangle=\delta_{ij}$$

> **Remark**:
> 1. Observe that if $\mathcal{B}=(e_1,\ldots,e_n)$ is an orthogonal basis, then for any $\lambda_1,\ldots,\lambda_n\in\mathbb{R}^\times$, the family 
> $$(\lambda_1 e_1,\ldots, \lambda_n e_n)$$
> is also an orthogonal basis.
> 2. More importantly, if $\mathcal{B}=(e_1,\ldots,e_n)$ is an orthogonal basis, then
> $$(\frac{e_1}{\|e_1\|},\ldots,\frac{e_n}{\|e_n\|})$$
> is an *orthonormal* basis.
> 3. Whether a basis is orthogonal or orthonormal can beverified immediately on the matrix on the inner prouduct in the given basis. Indeed:
> $$\mathcal{B} \text{ is orthogonal } \iff M(\langle,\rangle)_\mathcal{B}\text{ is diagonal}$$
> and
> $$\mathcal{B}\text{ is orthonormal }\iff M(\langle,\rangle)_\mathcal{B}=I_n$$

- **Theo 3.6:** Let $(E,\langle,\rangle)$ be an Euclidean space. There exists an *orthonormal* basis of $(E,\langle,\rangle)$