### Lecture 5: Trigonalizability, convergence of iterative methods and stationary methods

#### iii. Trigonalizability
- **Def 3.5 - trigonalizable:** A matrix $A\in\mathbb{K}^{N\times N}$ is trigonalizable, or triangularizable, if there exists an invertible matrix $P$ such that $P^{-1}AP=U$ is upper triangular.
- **Prop 3.7:** A matrix $A\in\mathbb{K}^{N\times N}$ is trigonalizable iff it has $L$ eigenvalues $(\lambda_i)_{i=1,\ldots,L}$ the algeraic multiplicity of which satisfy $\sum_{i=1}^L m_i=N$

#### 3.3 Application to iteration matrices
- **Def 3.6 - irreducible:** A poly $p$ is irreducible in $\mathbb{K}$ if it can not be written as the product of two non-constant polynomials
- **Theo 3.1 - Fundamental theo of Algebra:** A polynomial $p$ is irreducible in $\mathbb{C}$ iff $deg(p)\le1$

- **Corollary 3.2:** Any complex matrix $A\in\mathbb{C}^{N\times N}$ has a characteristic polynomial of the form
$$p_A(x)=\prod_{i=1}^N(x-\lambda_i)$$
    Especially, any square complex matrix is trigonalizable in $\mathbb{C}$

- **Theo 3.2:** The powers of a complex matrix $A\in\mathbb{C}^{N\times N}$ tends to zero iff
$$A^k\xrightarrow[k\rightarrow\infty]{}0_{\mathbb{C}^{N\times N}}\iff \rho(A)\lt1$$
    Furthermore, if $\rho(A)\gt1$, then the power sequence $(A^k)_{k\in\mathbb{N}}$ diverges

- **Lemma 3.1:** Consider two matrices $U\in\mathbb{R}^{N\times N}$ and $V\in\mathbb{R}^{N\times N}$ such that
$$U_{i,j}=0\forall i\gt j-K,\ \ \ \text{ and } \ \ \ V_{i,j}=0\forall i\gt j-L$$
    then the product $UV\in\mathbb{R}^{N\times N}$ satisfies
$$(UV)_{i,j}=0 \forall i\gt j-K-L$$
    Especially if $K+L\ge N$, then $UV=0_{\mathbb{R}^{N\times N}}$


- **Corollary 3.3:** The sequence defined iteratively by V^{n+1}=AV^{n}+b$ convergs for all initialization $V^0\in\mathbb{R}^N$ iff $\rho(A)\le1$
    In such case, $\lim_{n\rightarrow\infty}V^n=(I-A)^{-1}b$


#### 3.4 Estimating the spectral radius
- **Theo 3.3 - Gershgorin circles:**  Consider a matrix $A\in\mathbb{K}^{N\times N}$ and define Gershgorin circles as
$$D_i=\left{z\in\mathbb{K}, s.t \left|A_{i,i}-z\right|\le \sum_{j=1, j\ne i}^N |A_{i,j}\right}$$
    Then, the spectrum of $A$ is included in these circles
    $$Sp(A)\subset\bigcup_{i=1}^N D_i$$
    Especially, this means that any  eigenvalue $\lambda\in Sp(A)$ satisfies
    $$|\lambda-A_{i,i}|\le \sum_{j=1, j\ne i}^N |A_{i,j}|$$
    for at least one index i.

- **Corollary 3.4:** Consider a square matrix $A\in\mathbb{K}^{N\times N}$ such that
 $$\forall i, -1 \lt |A_{i,i}|-\sum_{j=1, j\ne i}^N |A_{i,j}|\le |A_{i,i}|+\sum_{j=1,j\ne i}^N|A_{i,j}|\lt 1$$

#### 4 Sationary iterative methods
The present algorithms are based on a decomposition of the matrix $A=M-R$ into two parts. If $V$ solves the problem, then:
$$AV=MV-RV=b$$
Especially, we have 
$$V=M^{-1}(b+RV)$$
as long as $M$ is invertible
- **Prop 4.1:** If $M$ and $A$ are invertible, then there exists a unique solution  for 
$$V=M^{-1}(b+RV)$$

- **Algorithm 4.1 - Stationary iiterative method:** Consider an invertible matrix $A\in\mathbb{R}^{N\times N}$. We aim to solve the problem $AV=b$ with $A=M-R$ such that $A$ and $M$ are invertible
  - **Initialization:** Provide $V^0$
  - **Iterations:** Compute
    $$V^{n+1}=M^{-1}(b+RV^n)$$
    until $\epsilon^n\gt TOL$

- **Corollary 4.1:** For all initialization $V^0\in\mathbb{R}^N$, teh sequence $V^{n+1}=M^{-1}(b+RV^n)$ converges iff
$$\rho(M^{-1}R)\lt1$$

#### 4.2 Jacobi algorithm

- **Algorithm 4.2 - Jacobi algorithm:** Consider an invertible matrix $A\in\mathbb{R}^{N\times N}$. We aim to solve the problem $AV=v$
  - **Initialization:** Proide $V^0$
  - **Iterations:** Compute for all $i$
    $$V^{n+1}=M_jV^n+D^{-1}b, \text{ with } M_J = D^{-1}R$$
    or equivalently
    $$V^{n+1}_i=\frac{b_i-\sum_{j\ne i}A_{i,j}V_j^n}{A_{i,i}}$$
    while $\epsilon^n\gt TOL$

- For the sequence $V^n$ to be well-defined, one only needs the idagonal matrix $D$ to be invertible i.e. iff $D_{i,i}=A_{i,i}\ne0$ for all i
- We also need it to converge

#### 4.3 Gauss-Seidel
- **Algorithm 4.3 - Gauss Seidel algorithm:** Consider an invertible matrix $A\in\mathbb{R}^{N\times N}$. We want to solve the problem $AV=b$
  - **Initialization:** Provide $V^0$
  - **Iterations:** Compute for $i$ from $1$ to $N$
  $$V_i^{n+1}=\frac{b_i-\sum_{i\gt i}A_{i,j}V_j^n}{A_{i,i}}$$
  while $\epsilon^n\gt TOL$

- For the sequence $V^n$ to be well-defined, one needs the matrix $D-L$ to be invertible. As with Jacobi method, this holds iff $D_{i,i}=A_{i,i}\ne0$ for all $i$.
  
#### Alternating Gauss-Seidel
- **Algorithm 4.4 - Alternating Gauss Seiel algorithm:** Consider an invertible matrix $A\in\mathbb{R}^{N\times N}$. We aim to solve the problem $AV=b$
  - Initiali
> Muy puto largo q cojones