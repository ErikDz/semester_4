
#### Question 1
- **Def - Diagonally strictly dominant:** A matrix $A$ s.t. $\forall i, |A_{i,i}|>\sum_{j\ne i}|A_{}|$

For an elementary proof, assume there exists a vector $x \ne 0$ such that $Ax = 0$. This implies $\sum_{j=1}^n a_{ij}x_j = 0, \forall i \in \{1, \ldots, n\}$. Let $x_k = \|x\|_\infty \ne 0$, i.e. $x_k$ is the the largest entry of x by absolute value.

We have:

$0 = \sum_{j=1}^n a_{kj}x_j \implies a_{kk}x_k = -\sum_{j\ne k} a_{kj}x_j \implies a_{kk} = -\sum_{j\ne k} a_{kj}\frac{x_j}{x_k}$

By taking the absolute value we get:

$|a_{kk}| = \left|\sum_{j\ne k} a_{kj}\frac{x_j}{x_k}\right| \leq \sum_{j\ne k} |a_{kj}|\underbrace{\left|\frac{x_j}{x_k}\right|}_{\leq 1} \leq \sum_{j\ne k} |a_{kj}|$

This is a contradiction since A is strictly diagonally dominant.

This means that $0\notin \sigma(A)$, hence A is invertible.
> Aquí lo que hacen es muy similar al proof de linear independence. Primero, asumen que existe un vector $x$ tal que $Ax=0$. De esta manera, seleccionan cualquier row y encuentran un contradiction (pq si es invertible todas las columnas son l.i.)