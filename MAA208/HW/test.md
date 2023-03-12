We have that $S(V^1)=Id-2\frac{V^1(V^1)^T}{\|V^1\|^2}$, $\|V^1\|=1$ with $V^1=\begin{pmatrix}a\\W\end{pmatrix}$  and $C^1=\begin{pmatrix}b\\X\end{pmatrix}$

Therefore, 
$$\begin{align*}
   S(V^1)C^1&=\begin{pmatrix}
    \alpha\\
    0\\
    \vdots\\
    0
   \end{pmatrix} \\
    &\iff\\
    C^1-2\frac{V^1(V^1)^T}{\|V^1\|^2}C^1&=\begin{pmatrix}
       \alpha\\
       0\\
       \vdots\\
       0 
    \end{pmatrix}\\
    &\iff\\
    \begin{pmatrix}
    b - 2a^2b-2aW^TX\\
    X - 2Wab - 2WW^TX
    \end{pmatrix}&=\begin{pmatrix}
       \alpha\\
       0\\
       \vdots\\
       0  
    \end{pmatrix}
\end{align*}$$
Which gives us the equations

$$
\begin{align*}
&\begin{cases}
b - 2 a^2 b - 2 a W^T X &= \alpha \\
X - 2 abW - 2 W W^T X &= 0
\end{cases} \\
\iff &
\begin{cases}
W^T X &= \frac{b - 2a^2b - \alpha}{2a} \\
X &= 2abW + 2W W^T X
\end{cases} \\
\iff &
\begin{cases}
W^T X &= \frac{b - 2a^2b - \alpha}{2a} \\
X &= 2abW + 2 (\frac{b - 2a^2b = \alpha}{2a}) W
\end{cases} \\
\iff &
\begin{cases}
W^T X &= \frac{b - 2a^2b - \alpha}{2a} \\
X &= \frac{b - \alpha}{2a} W
\end{cases}
\end{align*}
$$

So $(2 \cdot \frac{(1 - 2a^2)b -\alpha}{2a} + 2ab ) W = \frac{b -\alpha}{a}  W = X$ meanning $W = \frac{a}{b -\alpha}X$, so $W = kX$ is proportional to $X$ ($b - \alpha \neq 0$).

c) 
We put together the two expressions from above and we get
$$a=\frac{1-2k^2X^2}{2}=k(b-\alpha)$$, thus
$$a=k(b-\alpha)=\frac{1-2k^2X^2}{2}\\\text{hence, } k=\frac{1-2k^2X^2}{2(b-a)}$$ and we can write this as
$$2X^2k^2+2(b-\alpha)k-1=0$$


---
We know that $S(V)C^2=C^2-2\frac{\sum v_i C_i}{\sum v_i^2}V=C^2-2\frac{V^T C^2}{V^T V}V$, the only vector operations we need are for the computation of $V^T C^2$, $V^T V$ and the linear operation $C^2 - 2\frac{V^T C^2}{V^T V}V$ so $3$ in total
