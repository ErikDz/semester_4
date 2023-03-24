#### Exercise 1
For every $n\ge2$, we define the function $f_n:[1,+\infty)\rightarrow\mathbb{R}, x\mapsto\frac{\ln(x)}{\ln(n)}x^{-n}$
##### 1.
Let us show $\sum_{n\ge2}f_n$ converges pointwise on $[1,\infty)$
We fix $x$.
We first see that if $x=1, \sum_{n\ge2}f_n = 0\\$
So we assume $x>1$
Let $N\in\mathbb{N}:\forall n\ge N, \ln(x)<\ln(n)$.
We then split the sum into two parts
$$\sum_{n\ge2}\frac{\ln(x)}{\ln(n)}x^{-n}=\sum_{n=0}^{N-1}\frac{\ln(x)}{\ln(n)}x^{-n}+\sum_{n\ge N}\frac{\ln(x)}{\ln(n)}x^{-n}$$
From this, we denote $\lambda:= \sum_{n=0}^{N-1}\frac{\ln(x)}{\ln(n)}x^{-n}$ where $\lambda$ is a constant.

We then have that
$$\sum_{n\ge2}\frac{\ln(x)}{\ln(n)}x^{-n} =\lambda + \sum_{n\ge N}\frac{\ln(x)}{\ln(n)}x^{-n}\le \lambda + \sum_{n\ge N} x^{-n} \lt+\infty$$
Proving that $\sum_{n\ge2}f_n$ converges pointwise on $[1,\infty)$

##### 2.
Let us show that $\sum_{n\ge2}f_n$ does not converge normally on $[1,+\infty)$

We prove by contradiction so we assume that $\sum_{n\ge2}f_n$ converges normally on $[1,+\infty)$
This means that there exists nonnegative $(a_n)_{n\in\mathbb{N}}$ such that $\sum_2^\infty a_n$  is convergent
$$\frac{\ln(x)}{\ln(n)}\cdot\frac{1}{x^n}\le a_n,\ \ \forall x\in[1,\infty), \forall n\in \mathbb{N}\setminus\{0,1\}\\
\iff\\
\frac{\ln(x)}{x^n}\le \ln(n)a_n
$$
Now let us find the point at which $\frac{\ln(x)}{x^n}$ is at a maximum.
To do so, we derive it and set it equal to $0$.
$$\frac{\partial}{\partial x}\frac{\ln(x)}{x^n}=-x^{-(n+1)}(n\ln(x)-1)=0$$
Let us prove it's a maximum by taking the second derivative.
$$\frac{\partial}{\partial x}-x^{n+1}\cdot(n\ln(x)-1)=-x^n\cdot((n^2+n)\ln(x)-1)$$
Since $x\ne0$
$$n\ln(x)=1\implies x=e^{\frac{1}{n}}$$
Thus, we have that 
$$\frac{1}{n\cdot e}\le \ln(n)a_n\\
\iff\\
\frac{1}{n\cdot e\cdot \ln(n)}\le a_n$$
Let's now check whether $\sum_{n\ge2}\frac{1}{n\ln(n)}$ converges or not. We do the integral test
$$\int_2^\infty \frac{1}{n\ln(n)} = +\infty$$


Then since $\sum_{n\ge2}\frac{1}{n\ln(n)\cdot e}$ is divergent; by the comparison test this would imply that $\sum_{n\ge 2} a_n=+\infty$ which is a contradiction with the fact that $a_n$ is normally convergent

##### 3.
Let $n\ge2$ and set $R_n(x)=\sum_{k\ge n+1}f_k(x)$ for $x>1$.
We have that 
$$\sum_{k\ge n+1}\frac{\ln(x)}{\ln(k)}\frac{1}{x^k}\le \frac{1}{\ln(n+1)}\cdot\frac{1}{x}\sum_{k\ge2}\frac{1}{x^{k-1}}=\frac{1}{\ln(n+1)}\frac{1}{1-\frac{1}{x}}\cdot\frac{1}{x}=\frac{1}{\ln(n+1)}\cdot\frac{1}{x-1}\le\frac{1}{\ln(n+1)}\cdot\frac{\ln(x)}{x-1}$$
It is trivial that $R_n(x)\ge0$

Let us now show that it converges uniformly.
To do so, we use the Cauchy criterion. Let us show that $\forall \epsilon>0, \exists N : \forall m\ge n\ge N$ and $\forall x\in[1,+\infty)$. We have $$|R_n(x)-R_m(x)|\le \epsilon$$
Well, we have that 
$$\left|R_n(x)-R_m(x)\right|\le \left|\sum_{k=m+1}^\infty f_k(x) \right|\le \frac{1}{\ln(m+2)}\frac{\ln(x)}{x-1}$$

Let us bound $\frac{\ln(x)}{x-1}$
Since it's a decreasing, continuous function let's explore as it approaches 1 from the right.
We have that 
$$\lim_{x\rightarrow1+}\frac{\ln(x)}{x-1}=\lim_{y\rightarrow0+}\frac{\ln(y+1)}{y}=1$$
Therefore,
$$\frac{1}{\ln(m+1)}\frac{\ln(x)}{x-1}\le\frac{1}{\ln(m+1)}$$
Thus, we choose 
$$N=e^{2/\varepsilon}-1$$
And we get that
$$\left|R_n(x)-R_m(x)\right|\le\frac{\varepsilon}{2}$$