## Lecture 1: Duality in Vector Spaces

- **Def 2.1 - linear form:** A linear form or $\mathbb{K}$-linear form on $E$ is a $\mathbb{K}$ linear map from $E$ to $\mathbb{K}$

- **Def 2.2 - dual:** The set of all linear transformations on $E$ is called *the dual* of $E$ and it is denoted by $E^*$

- **Proposition 2.3:** If $\dim E = n < +\infty$, then
$$\dim E^* = n$$
> Only applicable in **finite** dimension

---
#### 3 - Dual Basis
Let $E$ be a $\mathbb{K}$ vector space of finite dimension $n$.

- **Proposition 3.1:** Let $\mathcal{B}:=(e_1,\ldots,e_n)$ a basis of $E$. Then $!\exists$ a unique basis $(e_1^*,\ldots,e_n^*)$ of $E^*$ such that $\forall i,j\in\{1,\ldots,n\}$ one has
$$e_i^*(e_j)=\delta_{ij}:=    \begin{cases}
        0 & \text{if } i\ne j\\
        1 & \text{if } i=j 
    \end{cases}$$
The basis $(e_1^*,\ldots,e_n^*)$ is denoted $\mathcal{B}^*$ and is called the **dual basis** of $\mathcal{B}$
> Aquí nos fijamos que $e_i^*\in E^*$  lo que signfica que es un linear map.

- **Proposition 3.2:** Let $\mathcal{B}=(e_1,\ldots,e_n)$ be a basis of $E$. Then for any  $x\in E$ and any $l\in E^*$ one has
$$l(x)=\hphantom{}^tM(l)_{\mathcal{B}^*}\cdot M(x)_{\mathcal{B}}$$
where we identified $\text{Mat}_{1,1}(\mathbb{K})$ with $\mathbb{K}$ 

- **Proposition 3.3:** Let $\mathcal{B}$ and $\mathcal{D}$ two bases for $E$. Let us denote the transition matrix from $\mathcal{B}$ to $\mathcal{D}$ by $P$. Then the transition matrix from $\mathcal{B}^*$ to $\mathcal{D}^*$ is
$$\hphantom{}^tP^{-1}$$


- **Proposition 3.4:** Let $\mathcal{L}:=(l_1,\ldots, l_n)$ be a basis of $E^*$. Then, there exists a unique basis $\mathcal{D}=(u_1,\ldots,u_n)$ of $E$ such that
$$\mathcal{D}^*=\mathcal{L}$$
The base $\mathcal{D}$ is called **pre-dual basis** of $\mathcal{L}$

---

#### 4 - Transpose of a linear map
- **Def 4.1 - transpose of map:** For any linear map $f:E\rightarrow F$, the transpose of the map $f$ or **dual** of the map $f$ is the map $\hphantom{}^tf\in\mathcal{L}(F^*,E^*)$ defined by
$$\begin{align*}
\hphantom{}^tf:F^* & \rightarrow E^*\\
l & \mapsto l\circ f
\end{align*}$$


- **Propostion 4.2:** Let $G$ be a $\mathbb{K}$-vector space.
  1. $\hphantom{}^t id_E = id_{E^*}$
  2. $\forall f,g\in \mathcal{L}(E,F)$ and any $\lambda\in\mathbb{K}$, one has $\hphantom{}^t(f+\lambda g)= \hphantom{}^t f + \lambda^t g$
  3. $\forall f \in \mathcal{L}(E,F)$ and any $g\in\mathbb{L}(F,G)$ one has $\hphantom{}^t(g\circ f)=\hphantom{}^tf\circ\hphantom{}^t g$
  4. If $f\in\mathcal{L}(E,F)$ an isomorphism, then $\hphantom{}^t f\in\mathcal{L}(F^*,E^*)$ is an isomorphism, and moreover
   $$(\hphantom{}^t f)^{-1}=\hphantom{}^t(f^{-1})$$

- **Prop 4.3:** Suppose $\dim E=n\lt +\infty$ and $\dim F = m \lt +\infty$. Let $f\in\mathcal{L}(E,F)$. Let $\mathcal{B}=(e_1,\ldots,e_n)$ a basis of $E$ and let $\mathcal{D}=(\varepsilon_1,\ldots,\varepsilon_m)$ be a basis of $F$. Let us denote by
$$A=M(f)_{\mathcal{B},\mathcal{D}}\in Mat_{m,n}(\mathbb{K})$$
the matrix of $f$ in those bases. Then the matrix of $\hphantom{}^tf$ in the dual bases is given by
$$M(\hphantom{}^tf)_{\mathcal{D}^*,\mathcal{B}^*}=\hphantom{}^tA$$


#### Addons
- To show linear independence, simply show that the matrix composed of the vectors is not invertible (hence $\det A\ne0$)