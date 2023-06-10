### Things used

#### TD 1-4
- Las def de convergence
- Prop 1.3
- Theo 2.4
- Theo 2.6
- Prop 3.1
- Weierstrass

#### TD 5-7
- Ratio test
- root test
- prop 3.1
> $$\sum_{k=0}^\infty  x^k= \frac{1}{1-x}\text{ for } |x|<1$$

- prop 3.5
- expansion formulas

- prop 2.4

#### TD 8-10
- Fourier coefficients
- def 2.6 piecewise
- **Heine's theorem:** $f:M\rightarrow N$ continuous and $M$ compact (closed and bounded) $\implies$ $f$ uniformly continuous

- prop 2.3
- Theo 3.3  (CH1)
- theo 3.4 (Parserval's equality)
- prop 2.4
- Lemma 4.3
- Corollary 3.3 - bessel's inequality

#### TD 11
- Def of Lipschitz
- Corollary 2.8





---

#### TD 1

- **Exercise 2:** Use inequality $2ab\le a^2+$
- **Exercise 4:** Recordar que finite dimension spaces tienen equivalent norms, por lo tanto elegir el norm que me ayude más.
- **Exercise 6:** Continuous functions bounded

#### TD 2

- **Exercise 1:** Si te dan una función q es continua no es por las risas, usa el hecho y usa q tiene bound. 

#### TD 4

- **Exercise 1:** $\int_{-\infty}^\infty e^{-x^2} = \sqrt{\pi}$
> Part 5 recheck
- **Exercise 3:** 
**PQNS:** Estaba intentando sustituir $f$ con $P_n$ pero me daba un resultado el cual no me ayudaba mucho
**CA:** Cuando en una suma tienes $x^k$ en una integral, con cualquier $k$ por linearity, lo puedes cambiar por cualquier polynomial
- **Exercise 4:** SKIPPED

#### TD 5
- **Exercise 4:**
> Part 2, why is $1-x$ a power series?
> Part 3: Se botaron (skip) pero revisar?
>

- **Exercise 5:** Polynomial => finite $a_n$ => $\limsup_{n\rightarrow\infty}|a_n|=0$

#### TD 7
- **Exercise 1:** $\int \operatorname{arctan} = \frac{1}{1+x^2}$
- **Exercise 3:** Cuando tienes $\sum_{i+j=n}$ convertir a $\sum_{j=0}^n$ con $i=n-j$
> Recordar bin theo : $(x+y)^n = \sum_{k=0}^\infty\binom{n}{k}x^ky^{n-k} $
> $e^{i\theta}=\cos\theta + i\sin\theta$
>

- **Exercise 5:** SALTADO (diff eq)

- **Exercise 6:** Ver última parte otra ve  z


#### TD 8
- **Exercise 1:** 
>$$\sin(a)\cos(b)=\frac{\sin(a+b)-\sin(b-a)}{2}$$

- **Exercise 2:** Skipped last part
> On last part used Cauchy criterion for uniform convergence
>

- **Exercise 3:**
**PQNS:** No usé el infinity norm
Como $e^x\ge1$
> $|c_n(f')|\le\frac{1}{2\pi}\int_0^{2\pi}|f'(x)|dx\le\|f'\|_\infty$
>

- **Exercise 4:**
  - 1: Usar def exacta de piecewise cont
  - 2: Me faltó provear q funciona con periodicity (fácil) 

- **Exercise 5:**
  - 1: Algo raro hicieron (re-ver)??
  - 3: **PQNS:** No sabía cómo relacionar (2) con la inequality que me habían dado
    **CA:** Darse cuenta que coger $x,y$ aleatorio no va a hacer nada y que en la expresión de antes te dieron algo dentro de $f$ lo cual podía ser cualquier número que quisies

- **Exercise 6:** Use prop2.3 to show convergence, theo 3.3 (ch1) to compute derivative

- **Exercise 7:** *SKIPPED* (hablaba de characteristic func y todo eso)

- **Exercise 8:**
  - 1. Se botaron
  - 3. Aquí pillaron el $P_n$ de la última pregunta ya que valía pa todos. (pensaba q era lo q tenía que provear pero era la assumption)
  - 4. Aquí usaron d una manera inteligente la def de $c_n$

#### TD 9
- **Exercise 1:**
> $e^{\plusmn in\pi} = (-1)^n$
Recordar q con $|\cdot|^2$  siempre hacer primero el conjugado y luego el producto
> $$\sin x = \frac{e^{ix} - e^{-ix}}{2i},\ \cos x = \frac{e^{ix}+e^{-ix}}{2}$$

- **Exercise 2:** 
  1. Recordar que $$O(g(n))=\{f(n): \exists c,n_0 : 0\le f(n) \le c\cdot g(n),\  \forall n\ge n_0\}$$

- **Exercise 4:**
> $c_n(f) = \frac{1}{2L}\int_{-L}^L e^{i\frac{n\pi}{L}x}f(x)dx$ for a $2L$ periodic function


#### TD 10 
- **Exercise 1:**
> Cuando no sabes computar una suma, escríbela en términos de una que ya sabes (dieron en ejercisio)

- **Exercise 2:**
2. Hicieron $ab\le\frac{a^2+b^2}{2}$ y luego con corollary 3.5 hicieron q convirgese. No puedo usar theo 4.4 (ver parte 3) (asumi q era $C^1$)
3. Al hacer la cosa de $-\int_a^b = \int_b^a$ no olvidarse de hacer el cambio de variables $x'=-x$

#### TD 11

- **Exercise 2:**
> Variation of constant method:
>
> When you have an eq of the form $y'+p(t)y = g(t)$
> 1. Find a solution to $y'+p(t)y=0$
> This is of the form $y=C\exp(-\int^tp(s)ds)$
> 2. The constant $C$ is replaced by a function $C(t)$. So we get
> $$y=C(t)\exp(-\int^t p(s)ds)$$

- **Exercise 3:** Tener en cuenta el domain de la eq cuando haces el de la solució  n

- **Exercise 4:** Para enseñar q no es lipshitz, es más fácil demostrar q $$\frac{\|F(x)-F(y)\|}{\|x-y\|}\rightarrow\infty$$
  3. Revisit?

#### TD 12
- **Exercise 1:**
Cuando integras en el sep de variables, hacer $\int_{y(t_0)}^{y(t)}$ para la función y $\int_{t_0}^t$ para lo de la derecha
Usar sust de funciones cuando tienes algo raro ($z(t)=y'(t)$)

> Estás en ex2 parte 2

- **Exercise 2:**
  1. PQ COJONES $z' = z-t$

- **Exercise 3:**
  2. Ver solution
  3. > $y=\frac{1}{3}e^{2x}+\frac{2}{3}e^{-x}-\frac{1}{2}e^x$
  
- **Exercise 4:**
  1. > https://people.maths.bris.ac.uk/~maajh/ODEs/chap4.pdf
  2. Variation of constant method?


#### MIDTERM
- Revisar última pregunta última dos partes

#### HW2
- **Exercise 2:**
  2. Si para una equality Parserval's equality no funciona, usar Jordan Dirichlet. 
  4. Para provear que una equality funciona para toda $t$ y $t$ está boundeada, intentar encontrar periodicity (uno de los extremos será lo mismo)
  > Hugo lo hico proveando q para cualquier $t$ la parte de la derecha converge

- **Exercise 3:**
  3. $|e^{\cos\theta + i\sin\theta}|=e^{\cos \theta}$

- **Exercise 4:**
  1. PQNS: Expresé directamente como su fourier
     CA: Ver q $f$ es una función, calc fourier, usar prop 2.10 y corollary 3.5


#### FINAL 21
- **Exercise 1:**
  1. b) Encontré para (a) $\sinh(2T)$ pero para esta creo q es como un ejercicio q hicimos deduciendo splitteando en odd y even

- **Exercise 2:** Contenido no dado
- **Exercise 3:** No dado no?

#### FINAL 22
- **Exercise 1:**
  1. Ver cómo provear que en efecto no converge uniform (ya visto q convere pointwise a 0)
  2. Mi proof:
  $$\|n(x^2-x)^{n-1}\cdot (2x-1)\|\le \|n(x^2-x)^{n-1}\|\le n(\frac{1}{2})^{n-1}$$

- **Exercise 2:**
  1. Lo hice poniendo q $x=1$ y enseñando q se iba a tomar x
  2. Llego hasta resolver la integral de la suma con sustitución $u=x^2+1$. Entonces
    $$\int_2^3 (n-1)x(\frac{1}{x²+1})^n=-\frac{1}{2}(10^{1-n}-5^{1-n})$$

- **Exercise 4:**
  1. $y=\frac{1}{2}(x+2)+ Ce^{-2x}-\frac{1}{4} $
  2. $y=C(x+1)^2-(x+1)$