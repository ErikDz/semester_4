#### Things used

- **Theo 1.5:** Let $\sum a_nz^n$ be a power series. $\alpha=\lim\sup_{n\rightarrow\infty}|a_n|^\frac{1}{n}$ and $R=\frac{1}{\alpha}$ (with the conention that $R=+\infty$ if $\alpha=0$ and $R=0$ if $\alpha=+\infty$). Then, the series $\sum a_nz^n$ is absolutely convergent for $|z|\lt R$ and divergent for $|z|\gt R$

- **Corollary 3.3:** Let $f$ be function on $(-R,R)$ defined by a power series $\sum_{n=0}^\infty a_nx^n$. Then, for every $n$ we have $a_n=\frac{f^{(n)}(0)}{n!}$

- **Ratio test:** $$\lim_{n\rightarrow\infty}\left|\frac{a_{n+1}}{a_n}\right|$$

- Diff equations 
---

#### Exercise 1
2. Es más fácil pillar la formula para geo y a partir de ahi diff

#### Exercise 2
2. **PQNS:** No entendía cómo conseguir $\frac{x^n}{2n+1}$
    **CA:** Tienes la definición de g a partir de $f$ y la derivativa de $g$. Cuando tienes alguna derivativa y quieres la función real recuerda el truco de
    $$g(x)=g(0)+\int g'(x)$$
    > Esto claro si g(0) es 0
    Recordar hacer parcial fractions cuando las cosas se ponen complicadas

#### Exercise 3
1. Induction
2. - Use corollary 3.3

#### Exercise 4
> $$\lim_{n\rightarrow+\infty}\left|\frac{a_{n+1}}{a_n}\right|=\lim_{n\rightarrow\infty}\left|\frac{\alpha(\alpha-1)\ldots(\alpha-n)}{(n+1)!}-\frac{n!}{\alpha(\alpha-1)(\alpha-n+1)}\right|=\lim_{n\rightarrow\infty}\left|\frac{\alpha-n}{n+1}\right|=1$$
1. Use ratio convergence $lim_{n\rightarrow\infty}\left|\frac{a_{n+1}}{a_n}\right|$

**PQNS:** No sabía cómo asociar la $z$ con el $\alpha$, estaba derivando etc...
**CA:** Cuando hay una frac $(a+b)$ al lado de una suma... expande!!!
> Hacer el resto
#### Exercise 5
1. **PQNS:** No sabía por dónde empezar
**CA:** Cuando te dan un equality no siempre es que tienes que trabajar con la suma. Si tienes una frac pasa uno de los lados de la fraction a la suma y expande