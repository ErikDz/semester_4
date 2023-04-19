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
- [ ] **7**
- [ ] **8**
- [ ] **9**
- [ ] **10**
- [ ] **11**
- [ ] **12**
- [ ] **13**
- [ ] **14**
- [ ] **15**
- [ ] **16**
- [ ] **17**