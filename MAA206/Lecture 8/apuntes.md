#### 2.4 Orthogonal transformation in dimension two

- **Prop 2.11:** Let $A\in O_2(\mathbb{R})$
  1. If $\det A = 1$, then there exists $\theta\in\mathbb{R}$ such that
$$A=\begin{pmatrix}
\cos\theta & -\sin\theta\\
\sin\theta & \cos\theta
\end{pmatrix}$$
    and $A$ is the matrix of the rotation fo angle $\theta$
  2. If $\det A=-1$, then there exists $\theta\in\mathbb{R}$ such that
$$A=\begin{pmatrix}
\cos\theta & \sin\theta\\
\sin\theta & -\cos\theta
\end{pmatrix}$$
    and $A$ is the matrix of the orthogonal symmetry with respect to the polar line of angle $\frac{\theta}{2}$, namely
$$E_1(f)=\operatorname{Span}\begin{pmatrix}
\cos\frac{\theta}{2}\\
\sin\frac{\theta}{2}
\end{pmatrix}$$

#### 2.5 Orthogonal transformations in dimension 3

- **Prop 2.12:** Let $A\in O_3(\mathbb{R})$ be such that $\det A=1$ and let us denote by $f\in\operatorname{End}(\mathbb{R}^3)$ the associated endomorphism. Then there exists an orthonormal basis $\mathcal{B}$ of $\mathbb{R}^3$ and a real number $\theta$ such that
$$M(f)_\mathcal{B}=\begin{pmatrix}
   1 & 0 & 0\\
   0 & \cos\theta & -\sin\theta\\
   0 & \sin\theta & \cos\theta 
\end{pmatrix}$$
    Moreover, $\theta$ satisfies
$$tr A = 1+2\cos\theta$$

- **Prop 2.13:** Let $A\in O_3(\mathbb{R})$ such that $\det A = -1$ and let us denote by $f\in\operatorname{End}(\mathbb{R}^3)$ the associated endomorphism. Then there exists an orthonormal basis $\mathcal{B}$ of $\mathbb{R}^3$ and a real number $\theta$ such that
$$M(f)_\mathcal{B}=\begin{pmatrix}
-1 & 0 & 0\\
0 & \cos\theta & -\sin\theta\\
0 & \sin\theta & \cos\theta
\end{pmatrix}$$
    Moreover, $\theta$ satisfies
$$tr A = -1+2\cos\theta$$

### Self-adjoint endomorphisms
- **Def 3.1 - Self-adjoint:** An endomorphism $f\in End(E)$ is said to be self-adjoint if
$$f^*=f$$

- **Prop 3.2:** Let $f\in End(E)$ and let $\mathcal{B}$ be an orthonormal basis. Set $A:=M(f)_\mathcal{B}$. Then $f$ is self adjoint iff $A$ is symmetric i.e.
$$\phantom{}^tA=A$$

- **Theo 3.3:** Let $(E,\langle,\rangle)$ be a Euclidean space and let $f\in End(E)$ be a self-adjoint endomorphism. Then
$$f\text{ is diagonalizable}$$
  Moreover, there exists an orthonormal basis $\mathcal{B}$ of $E$ such that $M(f)_\mathcal{B}$ is diagonal.

- **Theo 3.4:** Let $A\in \operatorname{Mat}_n(\mathbb{R})$ be a summetric matrix. Then $A$ is diagonalizable in an orthonormal basis of $\mathbb{R}^n$ endowed with the standard inner product. Equivalently, there exists a diagonal matrix $D$, and an orthonormal matrix $P\in O_n(\mathbb{R})$ such that
$$D=\phantom{}^tPAP$$