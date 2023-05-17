**Erik Dziekonski Bautista - MAA207 Homework 2**

---


#### Exercise 1
We have $f:\mathbb{R}\rightarrow\mathbb{R}$ unique, odd, $2\pi$-periodic function such that $f(x)=\frac{\pi-x}{2}$ for $x\in(0,\pi)$. Let $g$ be the function given by $g(x)=f(x+1)-f(x-1)$

##### 1.
We recall $f$ is $2\pi$ periodic *and* piecewise continuous. Therefore, by *Proposition 2.11* of the lecture notes we have that:
> If $f$ is odd, then for all $n\in\mathbb{N}, a_n(f)=0\text{ and } c_n(f)=-c_{-n}(f)$

Hence, 
$$\begin{align*}
 b_n &= \frac{1}{\pi}\int_0^{2\pi}sin(nx)f(x)dx\\
 &= \frac{1}{\pi}\int_0^{2\pi} \sin(nx)(\frac{\pi-x}{2})dx\\
 &=-\frac{1}{\pi}\left(\left[-\frac{x\cos(nx)}{2n}\right]_0^{2\pi}+\int_0^{2\pi}\frac{1}{2n}\cos(nx)dx\right)\\
 &= (1/\pi)(\pi/n)\\
 &=\frac{1}{n}
\end{align*}$$

Therefore, we get that the Fourier serires of $f$ is $\sum_{n\ge1}\frac{\sin(nx)}{n}$

<br>

##### 2.

Let us now compute the Fourier series of $g$. First, we show that $g$ is even.
$$g(-x)=f(-x+1)-f(-x-1)=-f(x-1)+f(x+1)=g(x)$$.
Now we show that $g$ is also $2\pi$-periodic.
$$g(x+2\pi)=f(x+2\pi+1)-f(x+2\pi-1)=f(x+1)-f(x-1)=g(x)$$
Again, using *Proposition 2.11* of the lecture notes we have that:
> If $f$ is even, then for all $n\in\mathbb{N}, b_n(f)=0\text{ and } c_n(f)=c_{-n}(f)$

Since we have that $g(x)=f(x+1)-f(x-1)$, then we get that:
$$g(x)=\begin{cases}
   \pi-1 &\text{ for } x\in[0,1)\\ 
   -1 &\text{ for } x\in[1,2\pi-1)\\
   \pi-1 &\text{ for } x\in[2\pi-1,2\pi)
\end{cases}$$

We calculate $a_0$,
$$a_0=\frac{1}{\pi}\int_0^{2\pi} g(x)dx=0$$
We calculate $a_n$,
$$\begin{align*}
   a_n&=\frac{1}{\pi}\int_0^{2\pi}g(x)\cos(nx)dx\\
    &=\frac{1}{\pi}\int_0^{1}(\pi-1)\cos(nx)dx+\frac{1}{\pi}\int_1^{2\pi-1}(-1)\cos(nx)dx+\frac{1}{\pi}\int_{2\pi-1}^{2\pi}(\pi-1)\cos(nx)dx\\
    &= \frac{2\sin(n)}{n}
\end{align*}$$

Therefore we find that the Fourier series of $g$ is $\sum_{n\ge1}\frac{2\sin(n)}{n}\cos(nx)$

<br>

##### 3.

Let us show that
$$\sum_{n\ge1}\frac{\sin(n)}{n}=\sum_{n\ge1}\frac{\sin(n)^2}{n^2}$$

Well, we have that $\sum_{n\ge1}\frac{\sin(n)}{n}=f(1)=\frac{\pi-1}{2}$.

We recall that the Fourier series of $g$ is $\sum_{n\ge1}\frac{2\sin(n)}{n}\cos(nx)$. Moreover, from *Theorem 3.4* we have that:
> $$\sum_{n=-\infty}^\infty|c_n(f)|^2=\frac{1}{2\pi}\int_0^{2\pi}|f(x)|^2dx$$

Therefore, we get that:
$$\frac{1}{2}\sum_{n\ge1}\frac{4\sin^2(n)}{n^2}=2\sum_{n\ge1}\frac{\sin^2(n)}{n^2}=\frac{1}{2\pi}\int_0^{2\pi}|g(x)|^2$$
Before we proceed, we see that
$$g^2(x)=\begin{cases}
    (\pi-1)^2 &\text{ for } x\in[0,1)\\ 
    1 &\text{ for } x\in[1,2\pi-1)\\
    (\pi-1)^2 &\text{ for } x\in[2\pi-1,2\pi)
\end{cases}$$

Hence,
$$\begin{align*}
\frac{1}{2\pi}\int_0^{2\pi}|g(x)|^2dx&= \frac{1}{2\pi}\left(\int_0^1(\pi-1)^2dx+\int_1^{2\pi-1}dx+\int_{2\pi-1}^{2\pi}(\pi-1)^2\right)\\
&= \frac{1}{2\pi}\left(2(\pi-1)^2+(2\pi-2)\right)\\
&= \frac{1}{\pi}\left((\pi-1)^2+\pi-1\right)\\
&= \pi-1
\end{align*} $$

We conclude that 
$$\sum_{n\ge1}\frac{\sin(n)}{n}=\sum_{n\ge1}\frac{\sin^2(n)}{n^2}=\frac{\pi-1}{2}$$

<br>

#### Exercise 2
We let $0\lt u \lt 1$ and $f:\mathbb{R}\rightarrow\mathbb{R}$ be the $2\pi$-periodic function such that $f(x)=\cos(ux)$ for $x\in[-\pi,\pi]$

##### 1.
Let us find the Fourier series of $f$.
Well, we know that $f$ is even and $2\pi$-periodic. Hence, from *Proposition 2.11* of the lecture notes we have that:
> If $f$ is even, then for all $n\in\mathbb{N}, b_n(f)=0\text{ and } c_n(f)=c_{-n}(f)$

Hence the Fourier series of $f$ is 
$$\frac{a_0}{2}+\sum_{n\ge1}a_n\cos(nx)$$

We have that
$$a_0=\frac{1}{\pi}\int_{-\pi}^\pi\cos(ux)dx=\frac{1}{\pi}\left[\frac{\sin(ux)}{n}\right]_{-\pi}^\pi=\frac{2\sin(u\pi)}{u\pi}$$

For $n\ge1$ we have that
$$\begin{align*}
a_n&=\frac{1}{\pi}\int_{-\pi}^\pi\cos(ux)\cos(nx)dx\\
&= \frac{1}{\pi}\int_{-\pi}^\pi\frac{1}{2}\left(\cos((u+n)x)+\cos((u-n)x)\right)dx\\
&= \frac{1}{2\pi}\left(\left[\frac{\sin((u+n)x)}{u+n}\right]_{-\pi}^\pi+\left[\frac{\sin((u-n)x)}{u-n}\right]\right)\\
&= \frac{1}{\pi}\frac{(u-n)\sin((u+n)\pi)+(u+n)\sin((u-n)\pi)}{u^2-n^2}\\
&= \frac{(-1)^n2u\sin(u\pi)}{\pi(u^2-n^2)}
\end{align*}
$$

Therefore, we have that the Fourier series of $f$ is
$$\frac{\sin(u\pi)}{u\pi}+\sum_{n\ge1}\frac{2(-1)^nu\sin(u\pi)}{\pi(u^2-n^2)}\cos(nx)$$

##### 2.

We note that $f$ is piecewise $C^1$ on $[-\pi,\pi]$. Therefore, by Corollary 4.2, we have that:
> If $f$ is $2\pi$ periodic and piecewise $C^1$, then the Fourier series of $f$ converges for all $x$ toward $\frac{f(x-)+f(x+)}{2}$

What's more, we have that $\forall u\in(0,1)$, the limit of $f$ at $x=\pi$ is $\lim_{x\xrightarrow[>]{}\pi}f(x)=\cos(-u\pi)=\cos(u\pi)$ and also $\lim_{x\xrightarrow[<]{}\pi}f(x)=\cos(u\pi)$. Hence, we have that $\frac{f(\pi-)+f(\pi+)}{2}=\cos(u\pi)$ so from this we hather that $f(\pi-)=f(\pi+)=f(\pi)$. Same proof applies for $-\pi$. Hence $f$ is continuous on all $x\in\mathbb{R}$. Going back to the mentioned Corollary, we find that the Fourier series of $f$ converges *pointwise* to $\frac{f(\pi-)+f(\pi+)}{2}$ at $x=\pi$.

Therefore, we have that
$$f(\pi)=\frac{\sin(n\pi)}{u\pi}+\sum_{n\ge1}\frac{2(-1)^nu\sin(u\pi)}{\pi(u^2-n^2)}\cos(n\pi)\\
\iff\\
\cos(u\pi) = \frac{\sin(n\pi)}{u\pi}+\sum_{n\ge1}\frac{2u\sin(u\pi)}{\pi(u^2-n^2)}(-1)^n\\
\iff\\
\cos(u\pi) = \frac{\sin(u\pi)}{\pi}\left(\frac{1}{u}+\sum_{n\ge1}\frac{2u}{u^2-n^2}\right)\\
\iff\\
\sum_{n\ge1}\frac{2u}{u^2-n^2}=\frac{\pi}{\tan(u\pi)}-\frac{1}{u}$$

<br>

##### 3.

We let $t\in(0,1)$. Then
$$\int_0^t\frac{\pi}{\tan(\pi u)} - \frac{1}{u}du=\lim_{u\rightarrow\infty}\int_0^t\frac{\cos(\pi u)}{\sin(\pi u)}-\frac{1}{u}du= \lim_{u\rightarrow0^+}\left[\ln|\sin(\pi u)|- \ln|u|\right]^t_u$$

We recall that $u\in(0,1)$, since $u\gt0$ we have that $\sin(\pi u)\gt0$ therefore
$$\int_0^t\frac{\pi}{\tan(\pi u)}-\frac{1}{u}du=\ln(\frac{\sin(\pi t)}{\pi t})-\lim_{u\rightarrow0^+} \ln(\frac{\sin(\pi u)}{\pi u})=\ln(\frac{\sin(\pi t)}{\pi t})$$


We define $f_n:u\rightarrow\frac{2u}{u^2-n^2}$

Since $\forall n\ge1$, $\ln$ is continuous, we have that it is integrable on $[0,t]$. Also,
$$\forall u\in[0,t]\ \ \left|\frac{2u}{u^2-n^2}\right|\le\frac{2t}{n^2-t^2}$$
Since we know that $\sum_{n\ge1}\frac{2t}{n^2-t^2}$ converges, we can conclude that $\sum_{n\ge1}\frac{2u}{u^2-n^2}$ is *normally* convergent on $[0,t]$.

We now consider 
$$
\begin{align*}
 \int_0^t\left|\frac{2u}{u^2-n^2}\right|du&=\int_0^t\frac{2u}{u^2-n^2}du\\
 &= -\left[\ln(n^2-u^2)\right]^t_0\\
    &= -\ln(n^2-t^2)+\ln(n^2)\\
    &= -\ln(1-\frac{t^2}{n^2})
\end{align*}
$$   

As $n\rightarrow\infty$, we have that $-\ln(1-\frac{t^2}{n^2})=\frac{t^2}{n²}+o(\frac{t^2}{n^2})$

Ssince we have that $\sum_{n\ge1}\frac{t^2}{n^2}$ converges, we conclude that $\sum_{n\ge1}\int_0^t\left|\frac{2u}{u^2-n^2}\right|$ converges.

We then have that
$$\int_0^t\sum_{n\ge1}\frac{2u}{u^2-n^2}du=\sum_{n\ge1}\int_0^t\frac{2u}{u^2+n^2}du=\sum_{n\ge1}\ln(1-\frac{t^2}{n^2})$$

Finally, we obtain that
$$\ln\left(\frac{\sin\pi t}{\pi t}\right)=\sum_{n\ge1}\ln(1-\frac{t^2}{n^2})$$

##### 4. 

Well, we have that $\forall ŧ\in(0,1), 1-\frac{t^2}{n^2}\lt1$, then $\prod_{n=1}^\infty(1-\frac{t^2}{n^2})\lt\infty$

Thus, we can write that
$$
\sum_{n=1}^\infty\ln(1-\frac{t^2}{n^2})=\ln\left(\prod_{n=1}^\infty\left(1-\frac{t^2}{n^2}\right)\right)\\
\iff\\
\ln\left(\frac{\sin\pi t}{\pi t}\right)=\ln\left(\prod_{n=1}^\infty\left(1-\frac{t^2}{n^2}\right)\right)\\
\iff\\
\frac{\sin\pi t}{\pi t}=\prod_{n=1}^\infty\left(1-\frac{t^2}{n^2}\right)
$$

Now, let us show this is indeed true for all $t\in\mathbb{R^*}$. We let $t\in\mathbb{R^*}$. We can find $m\in\mathbb{N}$ s.t. $\forall n\ge m, \frac{t^2}{n^2}\in (0,1)$ so we have that 
$$0\lt 1-\frac{t^2}{n^2}\lt 1$$

Thus, we can write that

$$\prod_{n=1}^\infty\left(1-\frac{t^2}{n^2}\right)=\left(\prod_{n=1}^m\left(1-\frac{t^2}{n^2}\right)\right)\left(\prod_{n=m+1}^\infty\left(1-\frac{t^2}{n^2}\right)\right)$$

Since we have that $\prod_{n=1}^m(1-\frac{t^2}{n^2})\lt\infty$ and $\prod_{n=m+1}^\infty(1-\frac{t^2}{n^2})\lt\infty$, we conclude that $\prod_{n=1}^\infty(1-\frac{t^2}{n^2})\lt\infty$.

Therefore,  we have that
$$\frac{\sin(\pi t)}{\pi t} = \prod_{n=1}^\infty(1-\frac{t^2}{n^2}),\ \forall t\in\mathbb{R}\setminus\{0\}$$

<br>

#### Exercise 3

Let $\sum_n a_nz^n$ a power series with radius of convergence $R\gt0$. We let $z\in\mathbb{C}$ s.t. $|z|\lt R$. We denote $f(z)=\sum_{n=0}^\infty a_nz^n$

We let $0<r<R$. And we define
$$g_r:\begin{cases}
   \mathbb{R} &\rightarrow \mathbb{C}\\
   \theta&\mapsto f(re^{i\theta})
\end{cases}$$

##### 1.
Since we have that $\forall \theta\in\mathbb{R}$, $|re^{i\theta}|=r\lt R$, by the definition of $\mathbb{R}$, $\sum_{n=0}^\infty a_nr^ne^{in\theta}$ is absolutely convergent. Thus uniformly. We then agree that
$$g_r(\theta)=\sum_{n=0}^\infty a_nr^ne^{in\theta}$$
By proposition 2.10, we have that the Fourier series of $g_r$  is its series representation. Therefore the Fourier sereis of $g_r$ is 
$$\sum_{n=0}^\infty a_nr^ne^{in\theta}\text{ and }g_r(\theta)=\sum_{n=0}^\infty a_nr^ne^{in\theta}$$ 

##### 2.

Let $g_r(\theta)$ be a function that is periodic with a period of $2\pi$. We can represent $g_r(\theta)$ using its Fourier series as follows: $g_r(\theta) = \sum_{n=0}^\infty a_n r^n e^{in\theta}$, where $a_n$ is a coefficient.

Using this representation, we can find the value of $c_0$ by evaluating the integral of $g_r(\theta)$ over the period $[0, 2\pi]$ using the formula for the constant term of a Fourier series. Thus,

$\frac{1}{2\pi}\int_0^{2\pi}g_r(\theta)d\theta = \frac{1}{2\pi}\int_0^{2\pi}g_r(\theta)e^{-i\cdot0\cdot\theta}d\theta=c_0$

We can define a function $f(z)$ as $a_0 + \sum_{n=1}^\infty a_n z^n$. Since $a_0$ is the constant term of the Fourier series, it is equal to $c_0$. Hence, $f(0) = a_0 = c_0$.

We can apply Parseval's equality to $g_r(\theta)$ to find the integral of its squared magnitude over the period $[0, 2\pi]$. This is equivalent to summing the squares of its Fourier coefficients, as follows:

$$\frac{1}{2\pi}\int_0^{2\pi}|g_r(\theta)|^2d\theta = \sum_{n=-\infty}^\infty |c_n|^2 = \sum_{n=0}^\infty |a_n|^2r^{2n}$$

This is because the square of the $n$-th Fourier coefficient $c_n$ is given by $|c_n|^2 = |a_n|^2r^{2n}$ for $n\ge0$, and $0$ for $n<0$.


##### 3.

We define $f(z) = \sum_{n \ge 0} \frac{z^n}{n!}$, which converges absolutely for all $z \in \mathbb{C}$.

Let $\alpha = \lim_{n \to \infty} \left(\frac{1}{n!}\right)^{\frac{1}{n}}$. Then we have

$$\begin{align*}
\alpha &= \lim_{n \to \infty} (n!)^{-\frac{1}{n}} \
&= \lim_{n \to \infty} e^{-\frac{1}{n} \ln(n!)} \
\end{align*}$$

As $n$ tends towards infinity, so does $\frac{\ln(n!)}{n}$. Thus, $\lim_{n \to \infty} \left(\frac{1}{n!}\right)^{\frac{1}{n}} = 0$.

Therefore, the radius of convergence of $f$ is $R = \infty$, which implies that $f$ converges for all $z \in \mathbb{C}$.

We see that

$$\begin{align*}
g_r(\theta) &= \sum_{n=0}^\infty \frac{r^n}{n!}e^{in\theta} \
&= e^{re^{i\theta}}
\end{align*}$$

in which we obtain $g_r(\theta) = e^{re^{i\theta}}$ through the Taylor series expansion of the exponential function.

We have
$$\begin{align*}
   \sum_{n\ge0}\frac{r^{2n}}{(n!)^2} &= \frac{1}{2\pi}\int_0^{2\pi}|g_r(\theta)|^2d\theta \\
    &= \frac{1}{2\pi}\int_0^{2\pi}|e^{re^{i\theta}}|^2d\theta \\
    &= \frac{1}{2\pi}\int_0^{2\pi}\left|e^{r\cos\theta + ir\sin\theta}\right|^2d\theta \\
    &= \frac{1}{2\pi}\int_0^{2\pi}e^{2r\cos\theta}d\theta \\
\end{align*}$$

We notice that for $r=1$,
$$\sum_{n\ge0}\frac{1}{(n!)^2}=\frac{1}{2\pi}\int_0^{2\pi}e^{2\cos\theta}d\theta$$

We can also observe that $f(0)=1$, thus

$$\begin{align*}
   2\pi &= \int_0^{2\pi}g_r(\theta)d\theta\\
    &= \int_0^{2\pi}e^{r\cos\theta}e^{ir\sin\theta}d\theta\\
    &= \int_0^{2\pi}e^{r\cos\theta}(\cos(r\sin\theta)+i\sin(r\sin\theta))d\theta\\
\end{align*}$$

Now for $r=1$,
$$2\pi=\int_0^{2\pi}e^{\cos\theta}\cos(\sin\theta)d\theta+i\int_0^{2\pi}e^{\cos\theta}\sin(\sin\theta)d\theta$$
We deduce that
$$\int_0^{2\pi}e^{\cos\theta}\sin(\sin\theta)d\theta=0\\
\int_0^{2\pi}e^{\cos\theta}\cos(\sin\theta)d\theta=2\pi$$

#### Exercise 4

##### 1.
Let $f:\mathbb{R}\rightarrow\mathbb{C}$ be a continuous $2\pi$-periodic function. We will prove that $f$ is trigonometric if and only if it has only finitely many non-zero coefficients.

$\implies$
Assume $f$ is a trigonometric polynomial. Then, $f(x)=\sum_{n=-N}^Nc_n(f)^{inx}$. This implies that $f$ is its own Fourier expansion. Hence, the Fourier coefficients are 0 if $|n|>N$.

$\impliedby$
If the Fourier coefficients of $f$ are zero if $|n|\gt N$ for some $N\in\mathbb{N}$, $f$ has a Fourier series $\sum_{n=-N}^{N}c_n(f)e^{inx}$.
We denote $P(x)=\sum_{n=-N}^Nc_n(f)e^{inx}$.
We have that $f$ and $P$ have the same Fourier coefficients. Then, by Parseval's equality,
$$\frac{1}{2\pi}\int_0^{2\pi}|f(x)-P(x)|^2dx=0$$
Since $f$ and $P$ are continuous, we conclude that $f\equiv P$.


#### Exercise 5

We consider the fourier series $\sum_{n\ge0}\binom{2n}{n}z^n=\sum_{n\ge0}\frac{(2n)!}{(n!)^2}z^n$

We have that 
$$\alpha=\limsup_{n\rightarrow\infty}\binom{2n}{n}^{\frac{1}{n}}$$

We have that
$$\begin{align*}
   \binom{2n}{n}^{\frac{1}{n}} &= \left(\frac{(2n)!}{(n!)^2}\right)^{\frac{1}{n}} \\
   &= \exp\left(\frac{1}{n}\left[\ln((2n)!)-2\ln(n!)\right]\right)\\
   &= \exp\left(\frac{1}{n}\left[\sum_{k=1}^{2n}\ln(k)-2\sum_{k=1}^{n}\ln(k)\right]\right)\\
   &= \exp\left(\frac{1}{n}\left[\sum_{k=n+1}^{2n}\ln(k)- \sum_{k=1}^n\ln(k)\right]\right)\\
    &= \exp\left(\frac{1}{n}\left[\sum_{j=1}^{n}\ln(j+n)- \sum_{k=1}^nj\right]\right)\\
    &=\exp\left(\frac{1}{n}\sum_{j=1}^n\ln(1+\frac{n}{j})\right)
\end{align*}$$

Hence,
$$\alpha = \limsup_{n\rightarrow\infty}\exp\left(\frac{1}{n}\sum_{j=1}^n\ln(1+\frac{n}{j})\right)$$

The expression $\lim_{n\rightarrow\infty}\frac{1}{n}\sum_{j=1}^n\ln(1+\frac{n}{j})$ can be seen as the discrete version of the integral $\int_0^1\ln(1+\frac{1}{x})dx$.

Let us compute it!

$$
\begin{align*}
   \int_0^1\ln(1+\frac{1}{x}) &= \int_0^1\ln(x+1)dx - \int_0^1\ln(x)dx\\
   &= \int_0^1\ln(x+1)dx - \lim_{\epsilon\rightarrow0}\int_\epsilon^1\ln(x)dx\\
    &= \int_0^1\ln(x+1)dx - \lim_{\epsilon\rightarrow0}\left[x\ln(x)-x\right]_\epsilon^1\\
    &=\left[(x+1)\ln(x+1)-x\right]_0^1 - \lim_{\epsilon\rightarrow0}\left[x\ln(x)-x\right]_\epsilon^1\\
    &= 2\ln(2)-\lim_{\epsilon\rightarrow0}\left[\epsilon\ln(\epsilon)\right]\\
    &= \ln(4)
\end{align*}$$

Hence, $\alpha=\exp(\ln(4))=4$
Thus, the radius of convergence of the series is 1/4.

##### 2. 

Since $R=\frac{1}{4}$, we consider
$$f:\begin{cases}
    (-\frac{1}{4}, \frac{1}{4}) &\rightarrow \mathbb{R}\\
    x &\mapsto \sum_{n\ge0}\binom{2n}{n}x^n
\end{cases}$$

Let $x\in(-\frac{1}{4}, \frac{1}{4})$. We have that $f(x)$ convergess absolutely, hence it convergges uniformly.

By proposition 3.1:
> Let $(f_n)_n$ a sequence of functions on a **compact** interval $I$ of $\mathbb{R}$. Assume that $f_n$ convergers uniformly to $f$. Then

Thus we have
$$f'(x)=\sum_{n\ge1}\binom{2n}{n}nx^{n-1}$$

Again, let $x\in( -\frac{1}{4}, \frac{1}{4})$. We see that:
$$\begin{align*}
   (1-4x)f'(x) &= \sum_{n\ge1}\binom{2n}{n}nx^{n-1}-4\sum_{n\ge1}\binom{2n}{n}nx^n\\
    &= \sum_{n\ge0}\binom{2n}{n}(n+1)x^n-4\sum_{n\ge1}\binom{2n}{n}nx^n\\
    &= 2 + \sum_{n\ge1}\binom{2n+2}{n+1}x^n-4\binom{2n}{n}nx^n\\
    &= 2 + \sum_{n\ge1}\frac{2n!}{n!(n-1)!}\left(\frac{(2n+2)(2n+1)}{(n+1)n}-4\right)x^n\\
    &= 2 + \sum_{n\ge1}\frac{2n!}{n!n!}2x^n(2n+1-2n)\\
    &= 2 + 2\sum_{n\ge1}\binom{2n}{n}x^n\\
    &= 2f(x)
\end{align*}$$

We just showed $(1-4x)f'(x)=2f(x)$

Let us solve this differential equation. We have

$$
\frac{1}{f(x)}f'(x)=\frac{2}{1-4x}\\
\int_0^t\frac{1}{f(x)}dx=\int_0^t\frac{2}{1-4x}dx
$$

We recall what we mentioned earlier: $f(0)=1$. With this, we have that

$$\ln\left|\frac{f(t)}{f(0)}\right|=-\frac{1}{2}\ln(1-4t)\\
\ln\left|f(t)\right|=\ln(\frac{1}{\sqrt{1-4t}})\\
f(t)=\frac{1}{\sqrt{1-4t}}
$$

We conclude that $f(x)=\frac{1}{\sqrt{1-4x}}$ for all $x\in(-\frac{1}{4}, \frac{1}{4})$.