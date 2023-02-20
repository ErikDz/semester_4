### 3. LU decomposition

#### 3.1 Principle
It consists in writing a matrix $A$ as the product of a lower triangular matrix $L$ and upper triangular matrix $U$
$$A=LU$$
> The LU decomposition method is useful for solving systems of linear equations because it reduces the amount of computation needed to find the solution.
Computing the componentso $f$ the product $LU$ reads
$$A_{i,j}=\sum_{k=1}^N L_{i,k}U_{k,j}$$

#### i. First row of $U$ and first column of $L$
As $U$ upper triangular and $L$ lower triangular, we compute 
$$A_{1,1}=L_{1,1}U_{1,1}$$
*Hypothesis:* We assume $L_{1,1}=1$
Then computing the first row of $A$ reads
$$A_{1,i}=L_{1,1}U_{1,i}=U_{1,i}$$
i.e. we obtain directly the first row $U$.
Computing the first column of $A$ reads
$$A_{i,1}=L_{i,1}U_{1,1}=L_{i,1}\implies\frac{A_{i,1}}{U_{1,1}}$$
i.e. we obtain the first column of L

#### ii. Second row of $U$ and second column of $L$
*Hypothesis:* As for the frist row, let us assume that $L_{2,2}=1$. Then computing the second row of $A$ reads
$$A_{2,i}=L_{2,1}U_{1,i}+L_{2,2}U_{2,i}=L_{2,1}U_{1,i}+U_{2,i}$$
Since $L_{2,1}$ and $Y_{1,i}$ are already computed, then we have
$$U_{2,i}=A_{2,i}-L_{2,1}U_{1,i}$$
i.e. we obtain the second row of $U$.
Then, computing the scond column of $A$ reads
$$A_{i,2}=L_{i,1}U_{1,2}+L_{i,2}U_{2,2}$$
then we have
$$L_{i,2}=\frac{A_{i,2}-L_{i,1}U_{1,2}}{U_{2,2}}$$

#### iii. Doolittle algorithm
We may perform these operations again and again until computing all the components of the matrices $L$ and $U$
*Hypothesis:* for each column $i$, we make the hypothesis tat $L_{i,i}=1$

- **Initialization** Write $L_{j,j}=1$ for all $j$
- **Iteration** For $i$ from $1$ to $N$ do
  - Compute
    $$U_{i,j}=A_{i,j}-\sum_{k=1}^{i-1} L_{i,k}U_{k,j} \text{ for all } j\ge i$$ 
  - Compute
    $$L_{j,i}=\frac{A_{j,i}-\sum_{k=1}^{i-1}L_{i,k}U_{k,i}}{U_{i,i}}\text{ for all } j\ge i$$

#### 3.3 Domain of validity
LU decomposition is only valid if the diagonal coefficients $U_{i,i}$ computed are all non-zero. These are non-zero iff the same submatrices $B^i$ are non-singular. 

> The algorithm has a complexity of $O(N^3)$

### 4. Cholesky decomposition
It is a particular case of LU decomposition

#### 4.1 Principle
It is based on the following assumption:
*Hypothesis:* A **symmetric positive definite**
> A symmetric positive definite (SPD) matrix is a square matrix that is symmetric (i.e., it is equal to its transpose) and has all positive eigenvalues. In other words, a matrix A is SPD if it satisfies the following conditions:
> 1. A is a square matrix, i.e., it has the same number of rows and columns.
> 2. A is symmetric, i.e., A[i,j] = A[j,i] for all i and j.
> 3. All of the eigenvalues of A are positive.
Cholesky algorithm is an LU decomposition, where we choose the diagonal of $U$ to be the same as the diagonal of $L$.
*Hypothesis:* $L$ and $U$ have the same diagonal coefficients

- **Algorithm 4.1 (Cholesky decomposition):**
  - *Iteration* For $i$ from $1$ to $N$, do
    $$L_{i,i}=\sqrt{A_{i,i}-\sum_{k=1}^{i-1}L_{i,k}^2}$$
  - For $j$ from $j$ to $N$, compute
    $$L_{j,i}=\frac{A_{j,i}-\sum_{k=1}^{i-1} L_{i,k}L_{j,k}}{L_{i,i}}$$

#### 4.2 Domain of validity
- **Prop 4.1:** Consider $A\in\mathbb{R}^{N\times N}$ with $N\gt 1$. There exists a Cholesky decomposition $A=LL^T$ with non-zero diagonal coefficients $L_{i,i}$ iff $A$ is symmetric positive definite

- **Lemma 4.1:** If $A\in \mathbb{R}^{(N+1)\times (N+1)}$ is SPD then its submatrix $B^N\in\mathbb{R}^{N\times N}$ s.t. $B_{i,j}^N = A_{i,j}$ is SPD and $A_{N+1,N+1}\gt0$

- The complexity is $C_N=O(N^3)$