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
This means that there exists $(a_n)_{n\in\mathbb{N}}$ convergent s.t.
$$\frac{\ln(x)}{\ln(n)}\cdot\frac{1}{x^n}\le a_n,\ \ \forall x\in[1,\infty), \forall n\in \mathbb{N}\setminus\{0,1\}\\
\iff\\
\frac{\ln(x)}{x^n}\le \ln(n)a_n
$$
Now let us find the point at which $\frac{\ln(x)}{x^n}$ is at a maximum.
To do so, we derive it and set it equal to $0$.
$$\frac{\partial}{\partial x}\frac{\ln(x)}{x^n}=-x^{-(n+1)}(n\ln(x)-1)=0$$
Since $x\ne0$
$$n\ln(x)=1\implies x=e^{\frac{1}{n}}$$
Thus, we have that 
$$\frac{1}{n\cdot e}\le \ln(n)a_n\\
\iff\\
\frac{1}{n\cdot e\cdot \ln(n)}\le a_n$$
Let's now check whether $\sum_{n\ge2}\frac{1}{n\ln(n)}$ converges or not. We do the integral test
$$\int_2^\infty \frac{1}{n\ln(n)} = +\infty$$


Then since $\sum_{n\ge2}\frac{1}{n\ln(n)\cdot e}$ is divergent; by the comparison test this would imply that $\sum_{n\ge 2} a_n=+\infty$ which is a contradiction with the fact that $a_n$ is normally convergent