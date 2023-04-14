
#### Used porpositions & theos
- **Prop 8.3**
- **Corollary 8.6**
---
### Exercises takeaways
#### Chapter 1
##### Exercise 12
1. Usamos el hecho de que $B_1\subset B_2\subset E^* \implies \phantom{}^\circ B_2\subset\phantom{}^\circ B_2 \subset E$ y $\phantom{}^\circ(F^\circ)=F$
2. Usar el rank-nullity theorem y $dim \phantom{}^\circ F + dim F =dim E$ 

##### Exercise 13
Se botaron

#### Exercise 17
Usamos otra vez lo del cambio de subset con el annhilator
Para segunda parte, se usa dimensions con lo de $\dim A\cup B = \dim A + \dim B - \dim A\cap B$


#### Exercise 20
Linear map injective $\implies \ker A = \{0\}$ 

> Hasta el 20 llegaste
----
#### Chapter 2

#### Exercise 11
Se usa algo similar que los anhilators: $A\subset B \implies B^\top\subset A^\top$ y $(F^\top)^\top = F$


#### Exercise 12
1. Re-hacer. No entiendo pq $tr(\phantom{}^tE_{ij}E_{kl})=tr(\delta_{ik}E_{jl})$
2. Re-hacer

#### Exercise 13
To compute the projection $p_F(\textbf{v})$ of a vector $\textbf{v}=(x,y,z)$ onto the subspace $F$, we need to find the closest point $\textbf{w}$ to $\textbf{v}$ in $F$, and then set $p_F(\textbf{v})=\textbf{w}$.
To do so, imagine $f_1,f_2$ is our basis for F and $g_1$ is our basis for $G$
Since its WRT the canonical basis, to find the matrix we need to find $p_F(1,0,0), p_F(0,1,0), p_F(0,0,1)$.
Since we are looking for the closest point on $F$ for each of them, we minimize the distance:
$$\|(1,0,0)-a\cdot f_1 -b\cdot f_2\|$$ by doing partial derivatives and setting equal to 0.
After that, we have the coordiantes of our closest point. 
3. To compute the distance from a coordinate $(v_1)$ to our $F$,
we minimize again 
$$\|v_1 - a\cdot f_1 -b\cdot f_2\|$$ and we substitute the found values of $a,b$ into the equation to get the distance (from the closest point)

> Vas por el 14, pero desde aqui smooth riding

#### Exercise 15
Primero, encontramos el orthonogonal base de $F$ con el Gram-Schmidt process. Luego, usamos las fórmulas en **prop 3.15** para calcular la cosa.

2 - REDOOOO

> Hasta 23