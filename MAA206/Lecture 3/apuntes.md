> Hasta prop 1.8

### Inner products
- **Def 1.1 - inner product:** An inner product on $E$ is a map $$\varphi:E\times E\rightarrow \mathbb{R}$$ which is:
    1. Bilinear:
       1. For all $x_1,x_2\in E$, for all $y\in E$ and for all $\lambda\in\mathbb{R}$
            $$\varphi(x_1+\lambda x_2, y)=\varphi(x_1,y)+\lambda\varphi(x_2,y)$$
       2. For all $x\in E$, for all $y_1,y_2\in E$ and for all $\lambda\in\mathbb{R}$
            $$\varphi(x,y_1+\lambda y_2)=\varphi(x,y_1)+\lambda\varphi(x,y_2)$$
    2. Symmetric: $\forall x,y\in E, \varphi(x,y)=\varphi(y,x)$
    3. Positive: $\forall x \in E, \varphi(x,x)\ge 0$
    4. Definite: $\forall x\in E, \varphi(x,x)=0\iff x=0$

> The notation to denote an inner product are the following:
> $$x\cdot y, (x|y), \langle x|y \rangle \text{ or } \langle x,y\rangle$$

- **Def 1.2 - real inner product space (real pre-Hilbert space):** A pair $(E,\langle,\rangle)$ composed of vector space $E$ and an inner product $\langle,\rangle$ on $E$ is called a *real inner product space* or *real pre-Hilbert space*. If moreover $E$ is finite dimensional, then $(E,\langle\cdot,\cdot\rangle)$ is called a Euclidean space.

### 1.2 How to recognize an inner product in finite dimension

#### 1.2.1 Bilinearity
- **Prop 1.3:** $\varphi$ is bilinear iff $\forall i,j\in\{1,\ldots,n\}$ there exists $a_{ij}\in\mathbb{R}$ such that for any $x=\sum_{i=1}^n x_ie_i\in E$ and for any $y=\sum_{j=1}^ny_je_j\in E$ one has
$$\varphi(x,y)=\sum_{i=1}^n\sum_{j=1}^n a_{ij}x_iy_j$$
Moreover, in that case, for all $i,j\in\{1,\ldots,n\}$ one has
$$a_{ij}=\varphi(e_i,e_j)$$

#### 1.2.2 Symmetry
- **Prop 1.4:** Suppose that $\varphi$ is a bilinear map and that for any $x=\sum_{i=1}^n x_ie_i\in E$ and for all $y=\sum_{j=1}^n y_je_j\in E$ one has
$$\varphi(x,y)=\sum_{i=1}^n\sum_{j=1}^n a_{ij}x_iy_j$$
for some $a_{ij}\in\mathbb{R}$. Then $\varphi$ is symmetric iff for all $i,j\in\{1,\ldots,n\}$ one has
$$a_{ij}=a_{ji}$$

#### 1.2.3 Positivity and definiteness

- **Lemma 1.5:** Let $\varphi:E\times E\rightarrow\mathbb{R}$ be a linear map. Suppose that there exists $n=\dim(E)$ linearly independent linear forms $l_1,\ldots,l_n\in E^*$ such that for all $x\in E$ one has
$$\varphi(x,x)=l_1(x)^2+\ldots+l_n(x)^2$$
Then $\varphi$ is an inner product

> **The algorithm**
> > (We either terminate writing $\varphi(x,x)=l_1(x)^2+\ldots+l_n(x)^2$) as above
> > Or it terminates proving that $\varphi$ is not positive definite
>
> Let $\varphi:E\times E\rightarrow\mathbb{R}$ be a bilinear symmetric map which with respect to the basis $\mathcal{B}=(e_1,\ldots,e_n)$ of $E$ is given above by
> $$\varphi(x,y)=\sum_{i,j=1}^n a_{ij}x_iy_j$$
> Write
> $$q_1:=\varphi(x,x):=\sum_{i=1}^n a_{ii}^{(1)}x_i^2+2\sum_{i=1}^n\sum_{j=i+1}^na_{ij}^{(1)}x_ix_j$$
> For $k$ from $1$ to $n$ do
> - If there exists $i\in\{k,\ldots,n\}$ such that
>    $$a_{ii}^{(k)}\le0$$
> - Otherwise, if for all $i\in\{k,\ldots,n\}$ one has
>    $$a_{ii}^{(k)}\gt 0$$
>   then one writes
>  $$\begin{align*}
    q_k(x) &= (a_{kk}^{(k)}x_k^2+x_kA(x_{k+1},\ldots,x_n)) + B(x_{k+1},\ldots,x_n)\\
    &=(\sqrt{a_{kk}^{(k)}}x_k+\frac{A(x)}{2\sqrt{a_{kk}^{(k)}}})^2 - \frac{A(x_{k+1},\ldots,x_n)^2}{4a_{kk}^{(k)}} + B(x_{k+1},\ldots,x_n)\\
    &= l_k(x_k,\ldots,x_n)^2 + q_{k+1}(x_{k+1},\ldots,x_n)
\end{align*}$$
> where
> $$q_{k+1}(x):= -\frac{A(x_{k+1},\ldots,x_n)^2}{4a_{kk}^{(k)}} + B(x_{k+1},\ldots,x_n)$$
> The define cofficients $a_{ij}^{(k+1)}$ with $j\ge i\gt k$ by requiring the following equality
> $$q_{k+1}(x)=\sum_{i=k+1}^na_{ii}^{(k+1)}x_i^2 + 2\sum_{i=k+1}^n\sum_{j=i+1}^n a_{ij}^{(k+1)}x_ix_j$$
> If the algorithm did not give a negative answer at one of the $n$ steps, then $\varphi$ is an inner product since
> $$\varphi(x,x)=l_1(x_1,\ldots,x_n)^2+l_2(x_2,\ldots,x_n)^2+\ldots+l_{n-1}(x_{n-1},x_n)^2 + l_n(x_n)^2$$


### 1.3 Matrix associated to an inner product
Let $(E,\langle,\rangle)$ be an Euclidean space of dimension $n$.
- **Def 1.6:** Let $\mathcal{B}:=(e_1,\ldots,e_n)$ be the basis of $E$. The matrix of $\langle,\rangle$ in the basis $\mathcal{B}$ is the matrix
$$M(\langle,\rangle)_\mathcal{B}:=\begin{pmatrix}
     \langle e_1,e_1 \rangle & \ldots & \langle e_1, e_n \rangle \\
     \vdots & & \vdots\\
     \langle e_n,e_1\rangle & \ldots & \langle e_n, e_n \rangle
\end{pmatrix}\in Mat_n(\mathbb{R})$$

- **Prop 1.7:** Let $\mathcal{B}:= (e_1,\ldots,e_n)$ be a basis of $E$. Then for all $x,y\in E$ one has
$$\langle x,y \rangle = \hphantom{}^t M(x)_\mathcal{B}M(\langle,\rangle)_\mathcal{B}M(y)_\mathcal{B}$$

### 1.4 Relation with duality
- **Prop 1.8:** The inner product $\langle,\rangle$ induces an isomorphism
$$\begin{equation}
\Phi:
    \begin{cases}
        E & \rightarrow E^*\\
        x & \mapsto \langle x,\cdot\rangle
    \end{cases}
\end{equation}$$
     Moreover, under this isomorphism, the inner product coresponds to the duality bracket: for all $l\in E^*$ and all $y\in E$ one has
$$\langle l,y \rangle = \langle \Phi^{-1}(l),y\rangle$$