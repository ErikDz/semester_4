### Ch 7 - Neural Networks: Deep Learning

#### 7.1 Learning in Deep Networks

1. Design the network architecture
2. Draw the computational graph for the network
3. Figure out all necessary derivatives
4. For each iteration of gradient descent:
   1. Propagate the input all the way through to the error calculation
   2. Track error signals recursively all the way down to the input layer
   3. Do the gradient-descent updates 'as usual'

#### 7.2 Generalising to $L$-layers
Let $l$ be the $l$-th layer of the network. A network goes rom $l=0,1,\ldots,L$ where the 0th layer simply imputes the training sample as input, and the $L$-th layer provides the output:
$$(x_0,x_L)\leftarrow(x_i,y_i)$$
where $(x_i,y_i)$ a training pair from the training set.
In a dense network (i.e. fully connected) we have weight matrices $W_1,\ldots,W_L$ and activation functions $f_1,\ldots,f_L$ we may now set $L>1$ arbitrarily. The network is then defined by the following equations:
$$
x_l=f_l(x_{l-1}W_l)\\
E_L=E(x_L,y)
$$
we may denote
> $a_l=x_{l-1}W_l$ Output of transfer unction
> $x_l=_l(a_l)=f_l$ Output of ctivation function

And backpropagation is defined as follows:
$$ \delta_L=e\bigodot f_L'(a_L)\\
\delta_l=\delta_{l+1}W_{l+1}^\top\bigodot f_l'(a_l)\\
G_l=\nabla_{W_l}E_L=\delta_{l}x_{l-1}^\top$$
$$

#### 7.3 Generalising to Multi-class and Multi-label Data
- For multi-class problems with more than two classes, one-hot-encoding should be used to represent the outputs as an m-length vector.
- Softmax function should be applied on top of the output to produce a categorical distribution that can be used to produce yb using argmax.
- For multi-label problems, sigmoid activation and threshold per-label can be used, where yb can have more than one class-label activated simultaneously for a single input.

#### 7.4 Generalising to Mini Batch Updates 
- In stochastic gradient descent, we don't calculate gradients based on the entire data set at once due to its high expense for large n.
- Instead, a random subset of instances is chosen, and special handling is given to the case of a single instance $(x_i,y_i) = (x_0,x_L)$.
Mini-batch $X_0$ and $Y_L$, containing nb-instances randomly selected from the dataset, can also be used in SGD.
The algorithm/implementation should be adjusted to ensure proper matrix dimensions, such as $X_0 ∈ \mathbb{R}^{n_b\times d}$.