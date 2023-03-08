**The algorithm**
Aim: For $k=1,\ldots,n$ either show $\varphi$ not positive definite **or** write 
$$q_\varphi(x)=l_1(x_1,\ldots,x_n)^2+\ldots+l_k(x_k,\ldots,x_n)^2+q_k(x_{k+1},\ldots,x_n)$$
With 
$$q_k(x_{k+1},\ldots,x_n)= \sum_{i=k}^n a_{ii}^{(k)}x_i^2 +2\sum_{i=k}^n\sum_{j=i+1}^n a_{i,j}^{(k)}x_ix_j$$

**(k=0)**
$$
\begin{align*}
\varphi(x,x)&=\sum_{i,j}a_{i,j}=\sum_{i=j=1}^n a_{ii}x_i^2 + \sum_{i\ne j}^n a_{ij}x_ix_j\\
&=\sum_{i=j}a_{ii}x_i^2+\sum_{i\lt j} a_{ij}x_ix_j + \sum_{j\lt i} a_{ij}x_ix_j\\
&=\sum_{i=j}a_{ij}x_i^2 + 2\sum_{i\lt j} a_{ij}x_ix_j
\end{align*}
$$
> Note: $\varphi$ symmetric $\implies a_{ij}=\varphi(e_i,e_j)=\varphi(e_j,e_i)=a_{j}$ 

**k=1** 
$a_{11}\le0\implies q_\varphi(e_1)=q_\varphi(1,0,\ldots,0)=a_{11}\le0$
If $\lt 0\implies \varphi$ not positive
If $=0\implies\varphi$ not definite

---
#### Exercise 2
$(x,y)\mapsto x_1y_1-2x_2y_2+4x_3y_3-x_1-x_2y_1+x_1y_3+x_3y_1$
In the algorithm at step $k$ even if $a_{i,i}^{(k)}\le0$ for any $i\in\{k,\ldots,n\}$
(not just $i=k$) then we can conclude that $\varphi$ is not positive definite!

#### Exercise 3
$$\varphi:
\begin{align*}
\mathbb{R}^3\times\mathbb{R}^3&\rightarrow\mathbb{R}^\\
(x,y)&\mapsto x_1y_1+2_2y_2+4x_3y_3-x_1y_2x_2y_1+x_1y_3+x_3y_1
\end{align*}$$
$$q_\varphi(x)=x_1^2+2x_2^2+4x_3^2-2x_1x_2+x_1x_3$$
> Since all coefficients are positive we go on with the algorithm
$$=x_1^2+2x_1(-x_2+x_3)+(-x_2+x_3)^2 + 2x_2^2+4x_3^2-(-x_2+x_3)^2$$
> Because we want the form $(a+b)^2$
> We see that 
> - $x_1^2=a^2$
> - $2x_1(-x_2+x_3)=2\cdot a\cdot b$
> - $b^2 = (-x_2+x_3)^2$
$$(x_1-x_2+x_3)^2+2x_2^2+4x_3^2-(x_2^2+x_3^2-2x_2x_3)$$
> We see that $l_1^2=(x_1-x_2+x_3)^2$
> and $q_2=x_2^2+3x_3^2+2x_2x_3$
> Since coefficients of square terms are $\gt 0$, we continue!
$$\begin{align*}
& x_2^2+3x_3^2+2x_2x_3\\
&= (x_2^2+2x_2x_3+x_3^2) -x_3^2+3x_3^2\\
&= (x_2+x_3)^2 +2x_3^2
\end{align*}$$

> $l_2=(x_2+x_3)^2$
> $q_3=2x_3^2$
> Since $2\gt0$ we continue!
> but $2x_3^2=(\sqrt{2}x_3)^2=l_3$

SUppose twe end the 
