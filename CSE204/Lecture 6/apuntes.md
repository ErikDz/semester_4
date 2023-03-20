### Lecture 6 - Neural Networks: Backpropagation

**Backpropagation** is a fundamental concept for fitting neural networks of arbitrary depth. We obtain a gradient for all these parameters; such that they may be updated bu a gradient descent algorithm.

Let's suppose the networks depicted in this figure:

![fig 5.2](../images/fig%205.2.png)

Taking inputs $x=[x_1,\ldots,x_5]^\top$, and producing outputs $\sigma=[\sigma_1,\ldots,\sigma_3]^\top$. The network is specified by weight matrices $W_1\in\mathbb{R}^{4\times5}$ (layer 1) and $W_2\in\mathbb{R}^{3\times4}$ (layer 2) and classes of activation function $f_1$ (layer 1) and also $f_2$ (layer 2). Let us use the squared error metric:

$$E(y,\sigma)=\|y-\sigma\|_2^2=e^\top e$$

i.e., $e\in\mathbb{R}^3$ (the residual errors for each output separately, respetive of the input $x$ and corresponding true *target* outputs $y$), and $E\in\mathbb{R}_+ (overall error associated with the network output for this input$.

#### 6.1 Forward Propagation

We need to start by calculating an error, which infolves a forward pass/forward propagation of the input

> $x\leftarrow x_i$ Load/input training instance
> $z=f_1(W_1x)$ 
> $\sigma=f_2(W_2z)$
> $\hat{y}=[|\sigma\ge0.5|]$
> $y\leftarrow y_i$ Load/input training label, corresponding to input $x_i$
> $E(y,\sigma)=\|y-\sigma\|_2^2$

Note that the training error is evaluated on $\sigma$ and *not* $\hat{y}$

#### 6.2 Backpropagation
Now that forward propagation has produced for us $z,\sigma, E$, we now wish to propagate $E$ back down through the network providing a gradient for all trainable parameteres.

$$\begin{align*}
G_2 &= \nabla w_2E\\
&= \delta_2 z^\top
\end{align*}$$

We have gradient $G_2\in\mathbb{R}^{3\times4}$
Continuation of backpropagation (for $G_1$)

$$\begin{align*}
G_1 = \nabla w_1E &=\delta_2\nabla w_1 [W_2f_1(W_1x)^\top] \\
&= \delta_1 x^\top
\end{align*}$$
