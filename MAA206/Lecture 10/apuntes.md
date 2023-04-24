> hasta prop 2.3

#### Inner Products

Let $E$ be an $\mathbb{C}$-vector space

- **Def 2.1 - inner product:** An inner product on $E$ is a map
$$\varphi:E\times E\rightarrow\mathbb{C}$$
which is:
1. Sesquilinear:
   1. It is *anti-linear* in the first argument: For all $z_1,z_2\in E$, for all $w\in E$ and for all $\lambda\in\mathbb{C}$
   $$\varphi(z_1+\lambda z_2,w)=\varphi(z_1,w)+\bar{\lambda}\varphi(z_2,w)$$
   
   2. It is linear in the second argument: For all $z\in E$, for all $w_1,w_2\in E$ and for all $\lambda\in\mathbb{C}$,
   $$\varphi(z,w_1+\lambda w_2)=\varphi(z,w_1)+\lambda(z,w_2)$$

2. Symmetric: $\forall z,w\in E, \varphi(z,w)=\overline{\varphi(w,z)}$
3. Positive: $\forall z\in E, \varphi(z,z)\ge0$
4. Definite: $\forall z\in E, \varphi(z,z)=0\iff z=0$

- **Def 2.2 - Complex inner product space:** A pair $(E,\langle,\rangle)$ composed of complex vector space $E$ and an inner product $\langle,\rangle$ on $E$ is called a complex inner product space, or a complex pre-Hilbert space or just an inner product space. If moreover $E$ is finite dimensional, then $(E,\langle,\rangle)$ is called a hermitian space.

#### 2.3 How to recognize an inner product in finite dimension

- **Prop 2.3:** With the aboce notation, $\varphi$ is sesquilinear iff for all $i,j\in\{1,\ldots,n\}$ there exists $a_{ij}\in\mathbb{C}$  such that for any $z=\sum_{i=1}^n z_ie_i \in E$ and for any $w=\sum_{j=1}^n w_je_j\in E$ one has
$$\varphi(z,w)=\sum_{i=1}^n\sum_{j=1}^n a_{ij}\bar{z}_iw_j$$
Moreover, in that case, for all $i,j\in\{1,\ldots,n\}$ one has
$$a_{ij}=\varphi(e_i,e_j)$$