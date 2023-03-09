### Chapter III - Iterative methods

#### 1. Principle of the iterative methods

##### 1.1 Description

Consider a linear equation
$$AV=b$$
The iterative methods are based on a convergence loop which stops when a desired accuracy is obtained

> One constucts a sequence $(V^n)_{n\in\mathbb{N}}$ which needs to converge to the desired solution
$$V^{n+1}=f^n(V^n)\xrightarrow[n\rightarrow\infty]{} V^\infty, s.t. AV^\infty=b$$

We differentiate two types of iterative methods
- **Stationary methods:** the sequence $V^n$ is constructed recursively as a linear combination (with fixed coefficients $f^n=f$) of the previous step and of $b$, i.e.
$$MV^{n+1}=NV^n+Lb$$
- **Non-stationary methods:** the construction of the sequence $V^{n+1}$ uses information that change from an iteration $n$ to the next one $f^{n+1}\ne f^n$

###### 1.2 Stopping Criteria
1. Control the *number of operations*
   - Stop if $n\gt N_{\text{max}}$
2. Control the *error*: Define an error criteria
    **Residual** $r^n=AV^n-b$
    **Evolution** $r^n=V^n-V^{n-1}$
    - Stop if:
      - Error $\|r^n\|<TOL$
      - Relative $\frac{\|r^n\|}{\|V^n\|}\lt TOL$

> The computation is stopped if the norm of the residual vector $|r^n|$ falls below a specified tolerance level $TOL$.
> The evolution error measures the rate of change of the computed solution. It is defined as the difference between the current and previous solutions, i.e., $r^n=V^n-V^{n-1}$. The computation is stopped if the norm of the evolution error vector $|r^n|$ falls below a specified relative tolerance level $TOL$, which is scaled by the norm of the current solution $|V^n|$.

#### 2 Convergence result through the induced norm
Most of th iterative methods can be interpreted as the search for a fixed point of a certain function.

- **Def 2.1 - fixed point:** A fixed point $V$ of a function is a point satisfying
$$V=f(V)$$

- **Def 2.1.1 - contraction:** The function $f$ is a contraction in over $\mathbb{R}^N$ if there exists $0\le k\lt 1$ such that
$$\forall V,W\in\mathbb{R}^N, \|f(V)-f(W)\|\lt k\|V-W\|$$

- **Theo 2.1:** Consider a contraction $f$ over $\mathbb{R}^n$. Then $f$ has a unique fixed point $V^*\in S$.
  Furthermore, for all $V^0\in S$, the sequence defined itratively by $V^{n+1}=f(V^n)$ converges to $V^*$

- **Def 2.2 - matrix norm:** The matrix norm induced by the vctor norm $\|\cdot\|$, commonly written $|||\cdot|||$, is the norm defined by
$$|||A|||=\sup_{V\in\mathbb{R}^N, \|V\|=1}\|AV\|=\sup_{V\in\mathbb{R}^n, \|V\|\ne0}\frac{\|AV\|}{\|V\|}$$

- **Prop 2.2:** If $|||A|||\lt 1$, then the sequence defined iteratively by
$$V^{n+1}=AV^n+b$$
    converges toward $V^\infty = (I-A)^{-1}b$


#### 3 Converges result through the spectral radius
##### 3.1 Eigenvectors and eigenvalues

- **Def 3.1:**
  - A pair $(\lambda, V)\in\mathbb{K}\times\mathbb{K}^N\setminus\{0_{\mathbb{K}^N}\}$ is a pair of eigenvalue-egienvector of a matrix $A\in\mathbb{K}^{N\times N}$ if and only if
    $$AV=\lambda V$$
  - The spectrum of $A$ is the set of all eigenvalues
  $$Sp(A)=\{\lambda\in\mathbb{K}:\exists0_{\mathbb{K}^N}\ne V\in\mathbb{K}^N, AV=\lambda V\}$$
  - The spectral radius $\rho(A)$ is the biggest of the eigenvalues in the norm
    $$\rho(A)=\max_{\lambda\in Sp(A)}|\lambda|$$

- **Def 3.2 - char poly:** The characteristic polynomial of $A$ is the polynomial $p_A$ defined by
$$p_A(x)=\det(xI-A)$$

- **Prop 3.1:** The eigenvalues of $A$ fit with the zeroes of $p_A$
$$Sp(A)=Z(p_A)$$

##### 3.2 Diagonalization and trigonalization

- **Def 3.3:**
  - Two matrices $A$ and $B$ are **similar** if there exists an invertible matrix $P$ such that $A=PBP^{-1}$. The matrix $P$ is a change of basis matrix.
  - A matrix $A$ is **diagonalizable** if it is similar to a diagonal matrix, i.e. if there exists an invertible matrix $P$ such that $P^{-1}AP=D=Diag(\lambda_1,\ldots,\lambda_N)$ is diagonal.

- **Prop 3.2:** A matrix $A\in\mathbb{K}^{N\times N}$ is diagonalizable in $\mathbb{K}$ if and only if there exists a basis of $\mathbb{K}^N$ composed of eigenvectors of $A$

- **Prop 3.3:** If a matrix $A\in\mathbb{N\times N}$ is diagonalizable, then its characteristic polynomial is aproduct of $N$ polynomials of degree 1
$$p_A(x)=\prod_{i=1}^N(x-\lambda_i)$$

---

- **Prop 3.5:** Suppose that the matrix $A\in\mathbb{K}^{N\times N}$ has $N$ different eigenvalues $(\lambda_i)_{i,\ldots,N}$. Then $A$ is diagonalizable

- **Prop 3.6:** A matrix $A\in\mathbb{K}^{N\times N}$ is diagonalizable if and only if it has $L$ eigenvalues $(\lambda_i)_{i=1,\ldots,L}$ the geometric multiplicity of which satisfy $\sum_{i=1}^L \mu_i = N$

- **Corollary 3.1:** If $A\in\mathbb{K}^{N\times N}$ is diagonalizable then the multiplicity of its eigenvalues satisfy $\mu_i=m_i$

- **Algorithm 3.1 (Diagonalization):**
  1. Compute the characteristic polynomial $p_A$.
  2. Find all the $L$ roots $\lambda_i$ of $p_A$
  3. For all the roots $\lambda_i$, find $\mu_i$ linearly independent eigenvectors $V^i$, i.e. find the non-trivialsolutions of
   $$(\lambda_i I-A)V=0_{\mathbb{R}^N}$$
  4. If $\sum\limits_{i=1}^L \mu_i$ for all $i$, then write $P=(V^1,\ldots,V^N)$ and $D=Diag(\lambda_1,\ldots,\lambda_N)$ then $A=PDP^{-1}$