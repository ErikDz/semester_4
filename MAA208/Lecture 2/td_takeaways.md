- **Interpolation Polynomial:** An interpolation polynomial is a polynomial function that passes through a set of given data points. The goal of interpolation is to approximate a function or a set of data points using a simpler function that can be easily evaluated.

#### Exercise 1

>$\{1,x,\ldots,x^{n-1}\}$ is the canoncial basis (the default for polys)

We have a bunch of equations
$$\lambda_1 x_1 + \ldots + \lambda_nx_1^{N-1}=y_1\\
\vdots\\
\lambda_1 x_N + \ldots + \lambda_nx_N^{N-1}=y_N
$$

So we can write this as a matrix equation
$$M = \begin{bmatrix}
   1 & x_1 & \ldots & x_1^{N-1}\\
   \vdots & \vdots & \ddots & \vdots\\ 
   1 & x_N & \ldots & x_N^{N-1}
\end{bmatrix}
,\ \lambda = \begin{bmatrix}
    \lambda_1\\
    \vdots\\ 
    \lambda_N
\end{bmatrix}$$

#### Exercise 2
- $C_n =  C_n - x_1C_{n-1}$ 
> Lo hacemos con las columnas en vez de las rows (checkear si eso siempre funciona)
$$\begin{pmatrix}
1 & x_1 & \ldots & 0\\
\vdots & \vdots & \ldots &  x_2^{n-1}-x_1x_2^{n-2}\\
\vdots & \vdots & \vdots & \vdots
\end{pmatrix}$$

-  $x_1C_{n-2}+C_{n-1} = C_{n-1}$
And so on...

#### Exercise 4
> No tengo ni puta idea de lo que esta señora estaba escribiendo, estaba cagando lol
 
$$P_j(x)=\prod_{1\le i \le N,\  i\ne j} \frac{x-x_i}{x_j-x_i}$$
$$
\begin{align*}
P(x)=&\sum_{i=1}^N y_i P_i(x)\\
=& \sum_{i=1}^N \lambda_{can}D_{can}(x)
\end{align*}
$$
$M_{can}=\lambda_{can}=y\\ \lambda_{can}=M_{can}^{-1}y$
$Y(bLag)^\top=M_{can}^{-1}y_x(bcan)^\top$