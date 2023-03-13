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
and produce $\hat{f}$. The problem is: *we do not have infinite samples; so the equivalence doesn't hold*. i.e. we are minimizing the wrong quantity.

#### 4.4 Bias-Variance Decomposition
Suppose we have chosen $L$ as squared error. Then, our uncertainty is around $Y$ and $\hat{F}$ .
We can decompose the expected loss into three parts:
$$\begin{align*}
 \mathbb{E}_{Y,\hat{F}}[L(Y,\hat{F})|X=x] &= \sigma^2+(\mathbb{E}[f-\hat{F}])^2+\mathbb{V}[\hat{F}]\\
\end{align*}
$$
Where $\sigma^2$ is the irreducible, or *noise* variance. The second term is the *bias* and the third term is the *variance*.
- **Bias (precision):** The amount by which we are systematically off target $f$; associated with *under-fitting*.
- **Variance (accuraccy):** The randomness in our preductions, inherited form the data; associated with *over-fitting*.
This is the expresssion of the *bias-varieance tradeoff*.


- Ridge regression and lasso regression are techniques for regularization to mitigate overfitting.
- Regularization restricts the magnitude of the weight vector w in order to control overfitting.
- Ridge regression adds a penalty $λw^2$ to the loss function, while lasso regression adds penalty $λ|w|$.
- The difference between the two methods lies in the norm used to regularize:
  - Lasso uses the absolute-value norm (L1-norm), $\|w\|_1=|w|$
  - Ridge uses Euclidean norm (L2 norm), $\|w\|_2 = w^2$

#### Sources of Overfitting and Underfitting
- **Underfitting; Bias:**
  - Poor modelling of decision surfaces
  - Model is took weak
  - Incorrect assumptions
  - Training data set is too small

- **Overfitting; Variance**
  - Too-local decisions
  - Model tends towards memorization
  - Model too complex
  - High randomization
  - Unstable algo (small change to data $\implies$ big change to $\hat{f}$)
  - Training data set too smalll
  - Training set has noise/errors/outliers

#### Collinearity as a Source of Overfitting
**Collinearity** is when one input variable can be linearly predicted from the others e.g.
$$X_2^{(i)}=\beta_0+\beta_1X_1^{(i)}$$
> For example, if $X_1$ gives weight in kilos, and $X_2$ weight in pounds then
> $$X_2=2.2X_1$$
>
In OLS regression, $(X^TX)$ cannot be inverted if the matrix is not full rank. This means that there exist linear dependencies among the predictor variables, making it impossible to estimate unique coefficients for each variable.

#### Failed Assumptions as Source of Underfitting
Recall assumptions for least squares regresson: output is a linear combination of inputs. If not met, our model may be too weak.
For example, **additivity** is a fundamental assumption of **linearity**
$$Y=w_0+w_1X_1+w_2X_2$$

#### Adressing Underfitting: More Power/Non-linearity

Possible solutions:
  - polynomial regression (non-linearity via basis functions)
  - k- nearest neighbors (non-linearity via local decisions)

> When a linear model is not able to capture the underlying patterns in the data, it may result in underfitting. In such cases, one approach to address underfitting is by increasing the power or complexity of the model, typically by introducing non-linearity. Two possible solutions for this are polynomial regression and k-nearest neighbors.

For example,
$$\phi(x)=[1,x^1,\ldots,x^k]$$

Higher k = more basis functions = more predictive power

#### Motivation for Regularization
> Regularization is a technique in machine learning that addresses overfitting by adding a penalty term to the model's loss function.
 
Regularization helps prevent overfitting and promote generalization beyond the training set. It is needed when:

- The model is complex or has high capacity
- The dataset is small
- The number of features is greater than the number of examples
- There is collinearity or feature correlation
- There is a possibility for numerical overflow

The main goal of regularization is to avoid poor predictions for unseen data, with other goals including interpretation and efficiency. Techniques for regularization include L1 and L2 regularization and Elastic Net regularization. The choice of technique depends on the problem at hand.

#### Kinds of Regularization
- Ridge (aka $L_2$ regularization)
    $$w=(X^TX+\lambda I_d)^{-1}X^Ty$$
    where $\lambda$ puts a **ridge** along the diagonal of the covariance matrix
    - $\lambda\in[0,\infty]$ controls the amount of regularization
    - How to find a good $\lambda$? **Cross validation**

- Lasso Regularization
    $$E_{\text{lasso}}(w)=\sum_{i=1}^n\left(y_i-\left[w_0 + \sum_{j=1} w_jx_j^{(i)}\right]\right)^2+\lambda\sum_{j=1}^d |w_j|$$
    - **No closed form;** a quadratic programming problem, can be tackled by methods such as
      - Incremental Foward Stepwise Regression
      - Least Angle Regression

    - Can gie a **sparse solution:** some coefficients become 0.

#### Ridge vs Lasso
- Ridge has a nice form (continuous, easy derivative)
- Lasso gives sparse results (can be seen as feature selection)
- In both cases: **increase bias** of the estimator (but **reduce variance**)!

#### Validation Sets and Cross Validation
- A **validation set:** use training data as test data
- k-fold cross validation: obtain $k$ train/validation sets:
> It involves dividing the data into k equally sized subsets or "folds". The model is trained on k-1 folds and evaluated on the remaining fold. This process is repeated k times, with each fold serving as the validation set once, and the results are averaged to obtain an estimate of the model's performance.
- Useful for tuning hyperparameters (e.g., $\lambda$ of regularization)