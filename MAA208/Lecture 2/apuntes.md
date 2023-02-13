## CH 2 - Direct Methods

### 1. Back and foward substitiutions

#### 1.1 Principle

Consider a lower invertible triangular matrix $L\in\mathbb{R}^{N\times N}$. We seek the solution for 
$$LV=b$$

- **Algorithm 1.1 - Forward substitution:**
  - Iterations: From $i$ from $1$ to $N$, do
        $$V_i = \frac{b_i - \sum_{j=1}^{i-1}L_{i,j}V_j}{L_{i,i}}$$
> This method can be adapted to solve upper triangular systems. Algorithm 1.1 is the renamed back substitiution.
#### 1.2 Complexity

- **Prop 1.1:** The number of operations required to solve a triangular system with this method is $C_N = O(N²)$

### 2 Gaussian elimination

#### 2.1 Principle
The principle is to eliminate the terms below and above the diagonal until obtaining a diagonal matrix. For this purpose, we use elementary matrix $E_k$. Hence, the solution to $AV=b$ is equivalent to $E_kAV=E_kb$. We seek elementary matrices $E_k$ such that $\prod_{k=1}^M E_k A = Id$ and compute in parallel $\prod_{k=1}^M E_k b$
> An elementary matrix is a square matrix that can be obtained from the identity matrix by performing a single elementary row operation

The method is as follows:
1. Eliminating the terms below the diagonal
2. Eliminating the terms above the diagonal
3. Solving the diagonal system

#### 2.2 Domain of validity and pivoting
During the first step of the algorithm, the coefficients on the diagonal of $A$ need to be non-zero. Otherwise, we cannot eliminate the terms below the diagonal. If one of these terms is zero, we can interchange the rows of $A$ and $b$ to obtain a non-zero coefficient. This is called **pivoting**.

- **Prop 2.1:** Define the submatrices $B^k\in \mathbb{R}^{k\times k}$ such that $B_{i,j}^k := A_{i,j}$ (i.e. these are the top left corner of $A$). Then, after the elimination of the subdiagonal terms on the first $k-1$ columns, the diagonal coefficient $A_{k+1,k+1}\ne 0 \iff \det(B^k)\ne 0$ 

- **Remark 2.3:**
  - This implies that the algorithm without pivot is valid iff all the determinants of the submatrices $B^k$ are non-zero
  - The algorithm with pivoting is valid as long as the determinant $\det(A)\ne 0$

- **Algorithm 2.1 - Gaussian elimination with pivot:** 
  Consider a matrix $A\in\mathbb{R}^{N\times N}$. We aim to solve the problem $AB=b$
    - **Initialization:** Fix $A$ and $b$.
    - $1.$  **Iterations over the columns:**
        For $j$ from $1$ to $N-1$ do
        - Choose a pivot, i.e. a row $i'\ge i$ such that $A_{i',i}\ne 0$, and exchange the rows $i$ and $i'$ of $A$ and $b$.
        Writing $R^i\in\mathbb{R}^N$ the i-th row of $A$ (s.t. $R^{i}_j = A_{i,j}$)
        $$(R^i,R^{i'})\rightarrow(R^{i'},R^i)$$
        *Eliminate the coefficients below the diagonal*
        For $i$ from $j+1$ to $N$ do
            $$R^i \rightarrow R^i - \frac{A_{i,j}}{A_{j,j}}R^j, \ \ b_i\rightarrow b_i - \frac{A_{i,j}}{A_{j,j}}b_j$$
  - $2.$ **Iterations over the columns:**
  For $j$ from $N$ to 2, do
  *Eliminate the coefficients above the diagonal*
  $$R^I\rightarrow R^i - \frac{A_{i,j}}{A_{j,j}}R^j, \ \ b_i\rightarrow b_i - \frac{A_{i,j}}{A_{j,j}}b_j$$
  - $3.$ **Scale:**
  For $i$ from $1$ to $N$, do
  $$R^i\rightarrow \frac{1}{A_{i,i}}R^i,\ \ b_i\rightarrow \frac{1}{A_{i,i}}b_i$$

- **Remark 2.2 - choice of the pivot:**  One can choose the pivot such that the diagonal coefficient is the largest in norm.
$$i'=\argmax_{i'\gt i}|A_{i',i}|$$

- **Remark 2.5 - Partial or complete pivoting:** Pivoting is equivalent to multiplying both sides of the equation $AV=b$ by a transpoisiton matrix. THis is called **partial pivoting**.  One can also exchange the columns in order to put the largest value of the remaining rows AND columns at the location $(i,i)$ in the matrix. This is calld **complete pivoting**.
- **Proposition 2.2:** The number of operations required to solve a system with this method is $C_N = O(N³)$