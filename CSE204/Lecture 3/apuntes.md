### Lecture 3 - Classification

We look to a different sort of model; used to make qualitative decisions
> Refers to a decision made by a model that is based on a categorical or qualitative outcome, rather than a numerical one.

Classification can be approached as a regression problem:
$$f(x)=P(Y=y|X=x)$$
Then, we can make a *classification* as:
$$\begin{align*}
\hat{y} &= h(x) = \argmax_{y\in\{0,1\}}P(Y=y|X=x)\\
&= \llbracket f(x)\ge 0.5 \rrbracket\\
&=
\begin{equation*}
    \begin{cases}
        1 & f(x)\lt 0.5\\
        0 & f(x) \ge 0.5
    \end{cases}
\end{equation*}
\end{align*}$$

#### 3.1 Logistic Regression
In *logistic regression*, we approach the problem similarly to ordinarry regression:
1. Assume a linear combination of attributes and weights
2. Identify an error function
3. Obrain the gradient of the error function wrt some parameters $w$
4. Apply gradient descent
We do the same here, *but* we wrap a *non-linearity* around the linear combination such that
$$f(x)=\sigma(w^\top x)$$
>  We need to make sure that the output is between 0 and 1, so we can interpret it as a probability. This is where the sigmoid function comes in.

$\sigma$ refers to the *sigmoid* function such that:
$$\sigma(a) = \frac{1}{1 + exp(-a)}$$
Generally we are interested in evaluating a *classifier* under classification accuracy: $\frac{1}{n}\sum_{i=1}^n \llbracket \hat{y}_i=y_i$. However this function is non-differentiable. Insted, we use the *surrogate* metric.
A common surrogate error metric is **log loss**:
$$E(w)=-\sum_{i=1}^n \{y_i \log(\sigma_i) + (1-y_i)\log(1-\sigma_i)\}$$
where $\sigma_i \equiv \sigma(w^\top x_i)$
We find the gradient of it wrt $w$ as:
$\nabla_w E(w) = X(\sigma - y)^\top$

#### 3.1.1 0/1 Loss in Classification (skipped)

#### 3.2 k-Nearest Neighbors (kNN)
The **k nearest neighbors** method (kNN) is *lazy* and *non-parametric*. We do *not* learn parameters $w$. To make a prediction for test point $x$, we simply find the $k$ points in the training set which are closest to it. Then:
$$P(Y=y|X=x)=\frac{1}{k}\sum_{k=1}^k y_k$$
where $y_1,\ldots, y_k$ are the labels of the $k$ closest instances we found; known as the neighborhood of $x$.

The kNN method can be applied to regression also. Our prediction $\hat{y}$ is the right hand side of the equation above. 