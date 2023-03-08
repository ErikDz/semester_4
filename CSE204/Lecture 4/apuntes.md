Due to the use of $\mathbb{E}$ for expectation, we discuss a *loss function* $L$ as an equivalent term for *error function*

#### 4.1  Rational Agents & Unity
A *rational agent* is one that minimizes expected loss where uncertainty is modeled by an expectation $\mathbb{E}$

#### 4.2 Conditional Expected Loss

In machine learning we build $\hat{f}$. Given some instance it should return a prediciton
$$\hat{y}=\hat{f}(x)$$
The value $\hat{y}$ should take is that which minimizes the loss hence
$$\min_{\hat{y}}L(y,\hat{y})$$

A rational agent would choose $\hat{y}$ which minimizes the *conditional expected loss*; the expecation of $Y$:
$$\mathbb{E}_{Y\sim P(Y|x)}[L(Y,\hat{y})]=\sum_{y\in\{0,1\}}L(y,\hat{y})P(y|x)$$
where $Y$ is discrete. 
In the continuous case,
$$\mathbb{E}_{Y\sim P(Y|x)}[L(Y,\hat{y})]=\int L(y,\hat{y})p(y|x)dy$$
with probability density function $p$ (*a regression problem*)
Recall we wanted to minimize this, therefore (taking the example of discrete-valued $Y$):
$$\hat{y}^*=\argmin_{\hat{y}\in\{0,1\}}[\sum_{y\in\{0,1\}}L(y,\hat{y})P(y|x)]$$
where $\hat{y}^*$ is our best prediciton, under this minimzation.


#### 4.3 Minimizing Empirical Loss
Because we do not have access to the true $P(Y|x)$, we cannot discretely minimize the expected loss. Anoter option is to instead minimize the *empirical loss* using our training data:
$$L(w)=L(\{y_i,\hat{f}(x_i)\}_{i=1}^n)=\frac{1}{n}\sum_{i=1}^{n}L(y_i,\hat{f}(x_i))$$
In other words, we select,
$$\hat{w}=\argmin_{w} L(w)$$
