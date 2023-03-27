###### Erik Dziekonski Bautista 

---
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
Proving that it converges uniformly.

##### 4.
We take the limits from the inequality on (3) and through the "squeeze theorem" we get that
$$0\le \lim_{n\rightarrow\infty}R_n(x)\le 0\implies \lim_{x\rightarrow\infty}R_n(x)=0$$

#### Exercise 2.
For every $n\ge1$, we define $f_n:\mathbb{R}\rightarrow\mathbb{R}, x\mapsto (-1)^n(\ln(x^2+n+1)-\ln(x^2+n))$
##### 1. 
Let us show $\sum_{n\ge1}f_n$ converges uniformly but not normally on $\mathbb{R}$
We define 
$$g_n(x)=\ln(x^2+n+1)-\ln(x^2+n)$$
We have that $g_n(x)=\ln(\frac{x^2+n+1}{x^2+n})=\ln(1+\frac{1}{x^2+n})$ which we can clearly see is decreasing and it's $\ge0$
Let $a_n:=\ln(1+\frac{1}{n})$. We can see that $\lim_{x\rightarrow\infty}a_n=0$ and 
$$g_n(x)\le a_n \forall n\in\mathbb{N}, \forall x\in\mathbb{R}$$
Hence, using Proposition 2.9 from the book, we have that $\sum f_n = \sum(-1)^ng_n$ is uniformly convergent which implies uniform convergence for $f_n$
Let us now show that it is not normally convergent.
We define $a_n:=\ln(1+\frac{1}{n})$. We note that $a_n\le f_n$ and since $\sum a_n$ diverges, we have that $f_n$ is not normally convergent.

##### 2. 
Let us prove $f=\sum_n f_n$ is $C^1$. Let $a\in\mathbb{R}$
- We have that $0\in [-a,a]$, such that $(\sum_n f_n(0))$ converges

Now let us show $(\sum_n f_n')_n$ is uniformly convergent in $[-a,a]$.
We have that $\sum f_n'=\sum (-1)^n2x\left(\frac{1}{x^2+n+1}-\frac{1}{x^2+n}\right)$
We define $g_n(x) := 2x(\frac{1}{x^2+n+1}-\frac{1}{x^2+1})$
We can clearly see it's a decreasing function which is $\ge0$. We define $a_n := \frac{2}{n(n+1)}$ and as we can see $\lim_{n\rightarrow}a_n=0$ and $g_n(x)\le a_n$ for every $n\in\mathbb{N}$ and $x\in[-a,a]$. Then by Proposition 2.9 $\sum_n f_n'(x) = \sum_n (-1)^n g'n(x)$ is uniformly convergent on $[-a,a]$
So
- We have that the sequence of functions $\sum_n f_n'$ is uniformly convergent on $[-a,a]$

From Theorem 3.3, we have that $(\sum_n f_n)$ converges uniformly uniformly to a uniformly $f$ which is derivable and we have 
$$f'(x)=\lim_{n\rightarrow\infty}\sum_n f_n'(x)$$
With this in mind, we see that $\sum_n f_n'(x)$ converges uniformly to $f'(x)$ and since $f_n'(x)$ is continuous, from a proposition from the book, we have that $f'(x)$ is continous proving $f(x)$ is $C^1$.
We have that $f'(0)=\sum_n f_n'(0) = 0$
Finally, 
$$\lim_{x\rightarrow\infty}f'(x)=\lim_{x\rightarrow\infty}\sum_n (-1)^n 2x\left(\frac{1}{x^2+n+1}-\frac{1}{x^2+n}\right)$$

Let's find a bound by finding the maximum of the $f_n'(x)$. We derive it and get
$$f_n''(x) = \frac{2 (-1)^n (3x^4 + (2n+1)x^2-n^2-n)}{(x^2+n)^2(x^2+n+1)^2}$$
We now solve
$$3x^4+(2n+1)x^2-n^2-n=0\\\iff\\x=\plusmn\sqrt{\frac{\sqrt{16n^2+16n+1}-2n-1}{6}}$$
And we find that it is bounded by $n^{-\frac{3}{2}}$.
Hence we get that 
$$0 \le |\sum_n f_n'(x)|\le n^{-\frac{3}{2}}$$
Taking the limit, and by the squeeze theorem we get
$$\lim_{x\rightarrow\infty}f'(x)=0$$


#### Exercise 3


Let us show that the series of functions
\[
    \sum_{n \geq 1} \frac{1}{n} - \frac{1}{n+x}
\]
converges pointwise on \(]-1, +\infty[\).

We can rewrite the series as:
$$\begin{align*}
    \sum_{n \geq 1} \frac{1}{n} - \frac{1}{n+x} & = \sum_{n \geq 1} \frac{(n+x) - n}{n(n+x)} \\
    & = \sum_{n \geq 1} \frac{x}{n^2 + nx} \\
\end{align*}$$

We can then split the interval \(]-1, +\infty[\) into the interval \([0, +\infty[\) and the interval \(]-1, 0[\). We will show that the series converges pointwise on both of these intervals.

On the \([0, +\infty]\) interval, we have that:
\[
    \sum_{n \geq 1} \frac{x}{n^2 + nx} \leq \sum_{n \geq 1} \frac{x}{n^2}
\]
Which we know is pointwise convergent. On the \(]-1, 0[\) interval, we have that:
$$\begin{align*}
    \sum_{n \geq 1} \frac{-1}{n^2 + nx} & \leq \sum_{n \geq 1} \frac{x}{n^2 + nx} \leq \sum_{n \geq 1} \frac{0}{n^2 + nx} \\
    \sum_{n \geq 1} \frac{-1}{n^2 + nx} & \leq \sum_{n \geq 1} \frac{x}{n^2 + nx} \leq 0 \\
    \sum_{n \geq 1} \frac{-1}{n^2} \leq \sum_{n \geq 1} \frac{-1}{n^2 + nx} & \leq \sum_{n \geq 1} \frac{x}{n^2 + nx} \leq 0
\end{align*}$$
We have shown that the series converges pointwise on both the intervals $[0, +\infty[$ and $]-1, 0[$, since $\sum_{n \geq 1} \frac{-1}{n^2}$ converges pointwise. Therefore, it follows that the series converges pointwise on the interval $[0, +\infty[$.

We now want to prove that it converges uniformly on the interval \(]-1, M]\) for every \(M > -1\). Let us call \(M_0 = \max{(1, |M|)}\).

Let  \(S_n(x) = \sum_{k=1}^n (\frac{1}{k} - \frac{1}{k+x})\). We will prove that \((S_n)_n\) converges uniformly using the Uniform Cauchy Criterion. Let us fix \(\varepsilon > 0\). Let \(N = \lfloor \frac{M_0}{\varepsilon} \rfloor + 1\).

Let \(1 \leq N \leq n > m_1\). For all \(x \in ]-1, M]\), we have that:
$$\begin{align*}
    | S_m(x) - S_n(x) | & = | \sum_{k=n+1}^m \frac{x}{k(k+x)} \\
    & \leq |x| \sum_{k=n+1}^m \frac{1}{k(k+x)} \\
    & \leq M_0 \sum_{k=n+1}^m \frac{1}{k(k+x)}
\end{align*}$$
Since we have that \(x > -1\), it implies that \(k(k+x) > k(k-1)\), for all \(k \in \{n+1, m\}\).

Therefore:
$$\begin{align*}
    |S_m(x) - S_n(x)| & \leq M_0 \sum_{k=n+1}^{m} \frac{1}{k(k-1)} \\
    & = M_0 (\frac{1}{n} - \frac{1}{m}) \\
    & \leq M_0 \frac{1}{n} \\
    & \leq \frac{M_0}{\frac{M_0}{\varepsilon}} \\
    & = \varepsilon
\end{align*}$$
Therefore, since \(\varepsilon\) was arbitrarily chosen, we can conclude that \(\sum_{n \geq 1} \frac{1}{n} - \frac{1}{n+x}\) converges uniformly on the interval \(]-1, M]\) for every \(M > -1\).

We denote by \(S(x) = \sum_{n \geq 1} \frac{1}{n} - \frac{1}{n+x}\). For \(x > -1\) the sum of this series.

Let us define:
$$\begin{align*}
    f_n: ]-1, +\infty[ & \to \mathbb{R} \\
    f(x)& \mapsto \frac{1}{n} - \frac{1}{n+x}
\end{align*}$$
We can find its derivative to be:
\[
    f_n'(x) = \frac{1}{(n+x)^2}
\]
Let \(F_n(x) := \sum_{k=1}^n f_n'(x)\). We want to show that \(\sum_{n > 1} f_n'\) is normally convergent on every segment \([a,b] \subset ]-1, +\infty[\).

Let \([a,b] \subset ]-1, +\infty[\) be an arbitrarily chosen segment.

For \(n=1\), \(\|f_1'\| = \sup_{x \in [a,b]} \frac{1}{(1+x)^2}\), which is finite since \(f_n'\) is continuous on \([a,b]\).

For \(n > 1\), \(n+x > n-1 > 0\) which implies that \(\frac{1}{(n+x)^2 \leq \frac{1}{(n-1)^2}}\), for all \(x \in [a, b]\) which impies that \(\|f_n'\| \leq \frac{1}{(n-1)^2}\).

Since \(\sum_{n \geq 2} \frac{1}{(n-1)^2}\) converges, we have shown that \(\sum_{n \geq 1} f_n'\) is normally convergent, which implies that it is also uniformly convergent.

From part 1 of this question we know that for all \(x \in [a,b]\) the sequence \((f_n(x))_n\) is convergent.

Using the theorem 3.3 of the course, we conclude that \((F_n)_n\) converges uniformly to S on \([a,b]\). \(S\) is derivable and:
$$\begin{align*}
    S'(x) & = \lim_{n \to \infty} F_n(x) \\
    & = \sum_{n \geq 1} f_n'(x) \\
    & = \sum_{n \geq 1} \left( \frac{1}{n+x} \right)^2
\end{align*}$$
Since \(\sum_{n \geq 1} f_n'\) converges normally to \(S'\) and \((f_n')_{n \geq 1}\) are continuous on \([a,b]\), we can conclude that \(S\) is \(\mathcal{C}^1\) on \([a,b]\).

We can conclude that $S$ is differentiable on the interval $]-1, +\infty[$ and its derivative is given by $S'(x) = \sum_{n \geq 1} \frac{1}{(n+x)^2}$ for all $x \in ]-1, +\infty[$. Since $\frac{1}{(n+x)^2}>0$ for all $n\geq 1$ and $x \in ]-1, +\infty[$, it follows that $S$ is strictly increasing and has a limit of $+\infty$ as $x$ approaches infinity. This can be shown using the formula $$\lim_{x \to \infty} S(x) = \lim_{x \to \infty} \left(\sum_{n \geq 1} \frac{1}{n} - \frac{1}{n+x} \right) = \lim_{x \to \infty} \sum_{n \geq 1} \frac{1}{n} - \sum_{n \geq 1} \frac{1}{n+x} = \lim_{x \to \infty} \sum_{n \geq 1} \frac{1}{n} = +\infty.$$

##### 3. 
As $x\xrightarrow[>]{}-1, x\in(-1,0]$
$$S(x)=\sum_{n\ge1}(\frac{1}{n}-\frac{1}{n+x})=-\frac{1}{x+1}+\sum_{n\ge1}(\frac{1}{n}-\frac{1}{n+x+1})$$
Now since $-1\lt x\le0$, it follows that $n\lt n+x+1\le n+1$, from which we get $$0\lt \frac{1}{n}-\frac{1}{n+x+1}\le\frac{1}{n}-\frac{1}{n+1}\ ;\ \forall n\ge1$$.
We also have that 
$$0\lt \sum_{k=1}^n(\frac{1}{k}-\frac{1}{k+x+1})\le 1 - \frac{1}{n+1}, \forall n\ge1$$
Thus, $0\lt\sum_{n\ge1}(\frac{1}{n}-\frac{1}{n+x+1})\le1$
We also note that
$$-\frac{1}{x+1}\lt S(x) \le 1-\frac{1}{x+1}\implies -1\lt S(x)(x+1)\le (x+1)-1$$
Finally since $\lim_{x_\rightarrow-1+}(x+1)-1=-1$, we get from the squeeze theorem that 
$$\lim_{x\rightarrow-1+}(x+1)S(x)=-1$$

##### 4. 
Let $x\gt0$
$$
\begin{align*}
\sum_{n\ge1}\frac{1}{(n+x)(n+1+x)}&=\sum_{n\ge1}\frac{(n+1+x)-(n+x)}{(n+x)(n+1+x)}\\&=\sum_{n\ge1}\left(\frac{1}{n+x}-\frac{1}{n+x+1}\right)\\&=\sum_{n\ge1}\frac{1}{n+x}-\sum_{n\ge2}\frac{1}{n+x}\\&=\frac{1}{1+x}
\end{align*}
$$
$$S'(x)=\sum_{n\ge1}\frac{1}{(n+x)^2}$$
We have that
$$\forall n\ge1, \forall x>0,\ \ (n-1+x)(n+x)\ge(n+x)^2\le(n+x)(n+x+1)$$
From this it follows that $\frac{1}{(n-1+x)(n+x)}\ge\frac{1}{(n+x)^2}\ge\frac{1}{(n+x)(n+x+1)}$.
Hence,
$$\begin{align*}
   \sum_{n\ge1}(\frac{1}{(n-1+x)(n+x)})&\ge \sum_{n\ge1}\frac{1}{(n+x)^2}\\
   &\ge \sum_{n\ge1}\frac{1}{(n+x)(n+x+1)}\\
   \iff\\
   \frac{1}{x(x+1)}+\sum_{n\ge1}\frac{1}{(n+x)(n+x+1)} &\ge S'(x)\\
   &\ge \sum_{n\ge1}\frac{1}{(n+x)(n+x+1)}
\end{align*}$$
But $\sum_{n\ge1}\frac{1}{(n+x)(n+x+1)}=\frac{1}{1+x}$, then
$$\frac{1}{1+x}\le S'(x)\le \frac{1}{x(x+1)}+\frac{1}{x+1}=\frac{1}{x}$$

##### 5.
We have that
$$\lim_{x\rightarrow\infty} S(x)=\lim_{x\rightarrow\infty}\ln(x)=+\infty$$
Since $\frac{1}{1+x}\le S'(x)\le \frac{1}{x}$, we have that
$$\frac{x}{x+1}\le x\cdot S'(x)\le1$$
From this, it follows that $\lim_{x\rightarrow\infty}x\cdot S'(x)=1$. Which is the same as $\lim_{x\rightarrow\infty}\frac{X'(x)}{(\ln(x))'}=1$
From l'Hospital's rule, we haave that the limit of $\frac{S(x)}{\ln(x)}$ exists and it is $\lim_{x\rightarrow\infty}\frac{S'(x)}{(\ln(x))'}$
We conclude that
$$\lim_{x\rightarrow\infty}\frac{S(x)}{\ln(x)}=1$$

#### Exercise 4

$$(\sum_{n \geq 1} n^{\sqrt{n}} z^n).$$

In order to calculate the radius of convergence \(R\), we first calculate:

$$\begin{align*}
    \alpha & = \limsup_{n \to \infty} |n^{\sqrt{n}}|^{\frac{1}{n}} \\
    & = \limsup_{n \to \infty} e^{\frac{\ln{(n)\sqrt{n}}}{n}} \\
    & = \limsup_{n \to \infty} e^{\frac{\ln{(n)}}{\sqrt{n}}} \\
    & = \lim_{n \to \infty} e^{\frac{\ln{(n)}}{\sqrt{n}}} \\
    & = e^0 \\
    & = 1
\end{align*}$$

Therefore, we have our radius of convergence $$(R = \frac{1}{\alpha} = 1)$$.

$$\left(\sum_n \frac{\sqrt{n}}{2^n + 1} z^n\right)$$

In order to calculate the radius of convergence \(R\), we first calculate:

$$\begin{align*}
    \alpha & = \lim_{n \to \infty} | \frac{a_{n+1}}{a_n} | \\
    & = \lim_{n \to \infty} | \frac{\sqrt{n+1}}{2^{n+1} + 1} \cdot \frac{2^n + 1}{\sqrt{n}} | \\
    & = \lim_{n \to \infty} \frac{2^{n+1} + 1}{2^n + 1} \\
    & = 2
\end{align*}$$

Therefore, we have our radius of convergence $(R = \frac{1}{\alpha} = \frac{1}{2})$.

$(\sum_n (1 + \cos^2{(n)}) z^n)$

In order to calculate the radius of convergence \(R\), we first calculate:

$$\begin{align*}
    \alpha & = \limsup_{n \to \infty} |1 + \cos^2{(n)}|^{\frac{1}{n}} \\
    & = \limsup_{n \to \infty} e^{\frac{\ln{(1 + \cos^2(n))}}{n}}
\end{align*}$$

We can bound \(1 \leq 1 + \cos^2(n) \leq 2\), giving us by then using squeeze theorem:

$$\begin{align*}
    \lim_{n \to \infty} e^{\frac{\ln{(1)}}{n}} \leq \alpha & \leq \lim_{n \to \infty} e^{\frac{\ln{(2)}}{n}} \\
    e^0 \leq \alpha & \leq e^0  \\
    1 \leq \alpha & \leq 1 \\
    \alpha & = 1
\end{align*}$$

#### Exercise 5

We let $(\alpha = \frac{1}{R})$

$$(\sum_n a_n e^{\sqrt{n}} z^n)$$

Since the radius of convergence of \(\sum_n a_n z^n = R\), we have that
\[
    \lim_{n \to \infty} |\frac{a_{n+1}}{a_n}| = R
\]
Let \(R_1 = \frac{1}{\alpha_1}\) we have that the radius of convergence of \(\sum_n a_n e^{\sqrt{n}} z^n\). Hence:
$$\begin{align*}
    \alpha_1 & = \lim_{n \to \infty} |\frac{a_{n+1} e^{\sqrt{n+1}}}{a_n e^{\sqrt{n}}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n} e^{\sqrt{n+1} - \sqrt{n}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n} e^{\frac{(\sqrt{n+1} + \sqrt{n})(\sqrt{n+1} + \sqrt{n})}{\sqrt{n+1} + \sqrt{n}}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n} e^{\frac{(n+1) - n}{\sqrt{n+1} + \sqrt{n}}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n} e^{\frac{1}{\sqrt{n+1} + \sqrt{n}}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n} \lim_{n \to \infty} e^{\frac{1}{\sqrt{n+1} + \sqrt{n}}}| \\
    & = \lim_{n \to \infty} |\frac{a_{n+1}}{a_n}| \cdot 1 \\
    & = \alpha
\end{align*}$$
Therefore the radius of convergence of \(\sum_n a_n e^{\sqrt{n}} z^n\) is \(R_1 = \frac{1}{\alpha_1} = \frac{1}{\alpha} = R\).

\(\sum_n a_n z^{2n}\).

We can rewrite this series as:
\[
    \sum_n a_n z^{2n} = \sum_n b_n z^n \qquad \text{where \(b_n = a_n\) if \(n\) is even and \(b_n = 0\) if \(n\) is odd}
\]
We then have:
$$\begin{align*}
    \alpha_2 & = \limsup_{n \to \infty} |b_n|^{\frac{1}{n}} \\
    & = \limsup_{n \to \infty} |a_n|^{\frac{1}{2n}} \\
    & = \limsup_{n \to \infty} (|a_n|^{\frac{1}{n}})^{\frac{1}{2}} \\
    & = \left(\limsup_{n \to \infty} |a_n|^{\frac{1}{n}}|\right)^{\frac{1}{2}} \\
    & = \sqrt{\alpha}
\end{align*}$$
So therefore \(R_2 = \frac{1}{\alpha_2} = \frac{1}{\sqrt{\alpha}} = \sqrt{R}\).

\(\sum_n a^2_n z^n\).

$$\begin{align*}
    \alpha_3 & = \limsup_{n \to \infty} |a_n^2|^{\frac{1}{n}} \\
    & = \left(\limsup_{n \to \infty} |a^n| \right)^2 \\
    & = \alpha^2
\end{align*}$$
Hence \(R_3 = \frac{1}{\alpha_3} = \frac{1}{\alpha^2} = R^2\).

\(\sum_n (1 + |a_n|) z^n\).

We split the sum into two parts
\[
    \sum_n (1 + |a_n|) z^n = \sum_n z^n + \sum_n |a_n| z^n
\]
We have that the first sum has radius of convergence of \(1\) and the second one has radius of convergence \(R\) according to the question. From the lecture, we have that if \(R \neq 1\):
\[
    R_4 = \min{(1, R)}
\]
If $R=1$, then let us prove $R_4=1$. We already know that $R_4\ge1$, so we just have to prove that $\alpha_4\ge1$. We know that $a_n$ has a subsequence $(a_{\varphi(i)})_{i\in\mathbb{N}}$ such $\lim_{n\rightarrow\infty}|a_{\varphi(n)}|^{1/n}=1$.
$$\left(\frac{|a_{\varphi(n)}|+1}{2}\right)^{1/n}\ge \frac{1+|a_n|^{1/n}}{2}$$
from this we get
$$\limsup_{n\rightarrow\infty}|a_{\varphi(n)+1}|^{1/n}\ge \left(\lim_{n\rightarrow\infty}2^{1/n}\right)\left(\lim_{n\rightarrow\infty }\frac{1+\left|a_{\varphi(n)}\right|^{1/n}}{2}\right)=1\cdot1=1$$

Thus, there is a subsequence $1+|a_n|$ whose limsup is at least 1, which gives $\alpha_4\ge1$ thus $R_4=1$.
So in general, we always have that 
$$R_4=\min(R,1)$$

