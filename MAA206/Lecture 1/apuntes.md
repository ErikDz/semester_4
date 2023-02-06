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