> Hasta prop 2.4
- **Prop 1.1:** For any endomorphism $f\in End(E)$, there exists a unique endomorphism $f^*\in End(E)$ such that for any $x,y\in E$
$$\langle f(x), y\rangle = \langle x, f^*(y)\rangle$$
    The endomorphism $f^*$ is called the adjoint endomporhism of $f$.

- **Prop 1.2:** Let $f\in End(E)$ and let $\mathcal{B}$ be an orthonormal basis of $(E,\langle,\rangle)$. If one denotes $A:=M(f)_\mathcal{B}$ then
$$M(f^*)_\mathcal{B}=\phantom{}^t A$$

- **Prop 1.3:** For any endomorphisms $f,g\in End(E)$ and for any $\lambda\in\mathbb{R}$ one has
  1. $id_E^*=id_E$
  2. $f^{**}=f$
  3. $(f+\lambda g)^*=f^*+\lambda g^*$
  4. $(f\circ g)^*=g^*\circ f^*$
  5. $\det f^*=\det $
  6. $rank f^*=rank f$

#### 2 Orthogonal transformations
- **Def 2.1 - orthogonal endomorphism:** Let $f\in End(E)$. One says that $f$ is an *orhtogonal endomorhpism* (or an orthogonal transformation) if for any $x,y\in E$, one has
$$\langle f(x),f(y) \rangle = \langle x,y\rangle$$

- **Prop 2.2:** Let $f\in End(E)$. The following are equivalent:
  1. $f$ is orthogonal
  2. for all $x\in E, \|f(x)\|=\|x\|$
  3. $f^*\circ f=id_E$

- **Prop 2.3:** Let $f\in End(E)$ be an orthogonal tranformation. Then 
$$det f \in \{-1,1\}$$
    and in particular, $f$ is invertile. Moreover, one has
$$f^{-1}=f^*$$

- **Prop 2.4:** Let $f\in End(E)$. The following are equivalent
  1. $f$ is an orthogonal endomorphism,
  2. For any orthonormal basis $\mathcal{B}$ of $E$, $f(\mathcal{B})$ is an orthonormal basis of $E$.
  3. There exists an orthonormal basis $\mathbb{B}$ of E such that $f(\mathcal{B})$ is an orthonormal basis of $E$.