#### Propositions used

> **FROM CH2**
> - **Theo 3.18 - Gram Schmidt process:** (gives orthonogal base to a base)
> $$e_k'=e_k-\sum_{i=1}^{k-1}\frac{\langle e_i', e_k \rangle}{\|e_i'\|^2}e_i'$$
> 
> - **Prop 3.15:** $F\subset E$ a linear subspace of dim $m$. Let $e_1,\ldots,e_m$ be an orthogonal basis of $F$. Then, for any $x\in E$, one has
> $$p_F(x)=\sum_{i=1}^m\frac{\langle e_i,x \rangle}{\|e_i\|^2}e_i\text{ and } p_{F^\top}(x)=x-p_f(x)$$


<br>

- **Prop 1.1:** $\forall f\in\operatorname{End}(E), \exists! f^*\in\operatorname{End}(E)$ s.t
$$\langle f(x), y\rangle = \langle x,f^*(y)\rangle$$
$f^*$ is called the **adjoint endomorphism of $f$**
<br>

- **Def 2.1 - orthogonal endo:** $f\in\operatorname{End}(E)$. $f$ is orthogonal if $$\langle f(x),f(y)\rangle = \langle x,y\rangle$$

- **Prop 2.6:** $f\in\operatorname{E}$. Let $\mathcal{B}$ be an orthonormal basis of $E$. Then $f$ orthogonal **iff**
$$M(f)_\mathcal{B}\in O_n(\mathbb{R})$$
> $O_n(\mathbb{R})$ is the set of all orthogonal matrices ($\phantom{}^tAA=I_n$)

- **Def 3.1 - self adjoint:** $f\in\operatorname{End}(E)$. $f$ is self adjoint if $$f(x)=f(x)^*$$

- **Theo 3.3:** $f\in\operatorname{End}(E)$ self-adjoint. Then 
$$f\text{ is diagonalizable}$$
Moreover, orthonormal basis $\exists \mathcal{B}$ of $E$ such that $M(f)_\mathcal{B}$ is diagonal

- **Theo 3.4:** $A\in\operatorname{Mat}_n(\mathbb{R})$ **symmetric**. Then, $A$ diagonalizable $\implies \exists D\text{ and} P\in O_n(\mathbb{R}) such that$
$$D=\phantom{}^tPAP$$

- **Def 3.5 - Rayleigh quotient of $f$:** Let $f\in\operatorname{End}(E)$ be self-adjoint. Then, the Rayleigh quotient of $f$ is the function
$$
\begin{align*}
 \varphi: E\setminus\{0\} &\rightarrow \mathbb{R}\\
 x &\mapsto \frac{\langle f(x),x\rangle}{\langle x,x\rangle}
\end{align*}
$$

- **Def 3.6 - Rayleigh quotient of $A$:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be symmetric. Then, the Rayleigh quotient of $A$ is the function
$$
\begin{align*}
 \varphi: \mathbb{R}^n\setminus\{0\} &\rightarrow \mathbb{R}\\
 x &\mapsto \frac{\phantom{}^txAx}{\phantom{}^txx}
\end{align*}  
$$

- **Theo 3.7 - Raileigh Ritz:** Let $f\in\operatorname{End}(E)$ be self-adjoint. Let us denote the eigenvalues of $f$ by $\lambda_1,\ldots,\lambda_n$ such that
$$\lambda_1\le\ldots\le\lambda_n$$
Then, one has:
  1. For any $u\in E\setminus\{0\}$
  $$\lambda_1\le R_f(u)\le\lambda_n$$
  2. One has
  $$\lambda_1=\min_{u\in E\setminus\{0\}}R_f(u)=\min_{\|u\|=1}\langle f(u),u\rangle$$
  3. One has
  $$\lambda_n = \max_{u\in E\setminus\{0\}}R_f(u)=\max_{\|u\|=1}\langle f(u),u\rangle$$

- **Prop 4.2:** Let $A\in\operatorname{Mat}_n(\mathbb{R})$ be a symmetric matrix. Consider the function:
$$\varphi: \begin{align*}
 \mathbb{R}^n\times\mathbb{R}^n &\rightarrow \mathbb{R}\\
 (x,y) &\mapsto \phantom{}^txAy
\end{align*}$$

**Prop 4.3 + 4.4:** $A\in\operatorname{Mat}_n(\mathbb{R})$ symmetric. 
  - $A$ is positive semi-definite $\implies \lambda_i\ge0\forall i\in\{1,\ldots,n\}$, $\operatorname{tr}A\ge0$ and $\operatorname{det}A\ge0$
  - $A$ is positive definite $\implies \lambda_i\gt0\forall i\in\{1,\ldots,n\}$, $\operatorname{tr}A\gt0$ and $\operatorname{det}A\gt0$
----

#### Exercises 
- [x] **1**
- [x] **2**
- [x] **3**
- [x] **4**
  Recordar: $\|a-b\|^2=\|a\|^2-2\langle a,b \rangle+\|b\|^2$
  *Part 4* El concepto era fácil pero encontrar el valor suputa
- [ ] **5**
   Por ahora me lo salto pq parece muchos pasos
- [x] **6**
Creo q lo hice bien. Paso sus: $\langle f(y),x\rangle = \langle f(y), f(x)\rangle\implies\langle f(y),x-f(x)\rangle$
- [x] **7**
- [ ] **8**
Mas de lo mismo
- [x] **9**
- [x] **10**
Usar prop 4.2
- [x] **11**
Usar theo 3.4 (hice a la primi)
- [x] **12**
Recordar q $\text{A invertible} \iff \operatorname{det}A=\{0\}$
- [x] **13**
**PQNS:** Estaba muy pegado con las prop. Intentaba enseñar que $\phantom{}^tDD=Id$ que ni siquiera estaba seguro q enseñaba q las bases eran orthogonal (esto solo demuestra D)
**CA:** Escribir lo que quiero demostrar más formalmente y seguro
- [ ] **14**
No entiendo pq no funciona: symmetric $\implies$ self-adjoint $\implies$ diagonalisable
- [x] **15**
- [x] **16**
 Usar rayleigh
- [ ] **17**
SUputa