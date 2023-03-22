> Hizo la última parte de CH2 (hecho en apuntes del lec 5) hasta prop 2.2 del chapter 3

### Chapter III: Adjoints in Euclidean Spaces and Orthogonal Transformations

#### 1 Adjoint of an endomorphism
- **Prop 1.1:** For any endomorphism $f\in End(E)$, there exists a unique endomorphism $f^*\in End(E)$ such that for any $x,y\in E$,
$$\langle f(x), y \rangle = \langle x, f^*(y)\rangle$$
    The endomorhphism $f^*$ is called the *adjoint endomorphism* of $f$.

- **Prop 1.2:** Let $f\in End(E)$ and let $\mathcal{B}$ be an orthonormal basis of $(E,\langle,\rangle)$ If one denotes $A:=M(f)_\mathcal{B}$, then
$$M(f^*)_\mathcal{B}=\phantom{}^tA$$

- **Prop 1.3:** For any endomorphisms $f,g\in End(E)$ and for any $\lambda\in\mathbb{R}$ one has
  1. $id_e^*=id_E$
  2. $f**=f$
  3. $(f+\lambda g)^*=f^*+\lambda g^*$
  4. $(f\circ g)^*=g^*\circ f^*$
  5. $det f^* = det f$
  6. $rank f^* = rank f$

#### Orthogonal transformations

- **Def 2.1 - orthogonal endomorphism:** Let $f\in End(E)$. One says that $f$ is an *orthonormal endomorphism* (or an *orthogonal transformation*) if for any $x,y\in E$, one has
$$\langle f(x), f(y)\rangle = \langle x,y \rangle$$

- **Prop 2.2:** Let $f\in End(E)$. The following are equivalent:
  1. $f$ is orthogonal
  2. for all $x\in E, \|f(x)\|=\|x\|$
  3. $f^*\circ f=id_E$