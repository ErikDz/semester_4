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

\end{align*}
$$