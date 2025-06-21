# Monte-Carlo-Simulation for estimation of Pi.
 A Monte Carlo simulation is a computational technique that uses random sampling to model and analyze complex systems or processes. This project explores the use of Monte Carlo simulation to estimate the value of Pi using random numbers
 

# Concept
A region in the Cartesian plane is defined—ideally, a square for simplicity. Within this region, a circle and a square are placed using inequalities. The side length of the square is equal to the radius of the circle. The circle and the square do not overlap; they are positioned independently, so they don’t intersect.
We then randomly pick a point (𝑥,𝑦) from within the overall region.

Let P(C) be the probability that the point falls inside the circle, and P(S) be the probability that it falls inside the square. Given this setup, we have:

$$P(C) = \frac{\text{Number of coordinates within circle}}{\text{Total number of random coordinates picked}} = \frac{Nc}{\Sigma N}$$

$$P(S) = \frac{\text{Number of coordinates within square}}{\text{Total number of random coordinates picked}} = \frac{Ns}{\Sigma N}$$

Taking the ratio between the probabilities, we have:

$$ \frac{P(C)}{P(S)} = \frac{N_c / \Sigma N}{N_s / \Sigma N} = \frac{N_c}{N_s} $$

P(C) and P(S) are proportional to the area of the circle and square, respectively. Thus, they can be calculated as follows:

$$P(C) = \frac{\text{Area of Circle}}{\text{Total area of the region}}= \frac{πr^2}{A}$$

$$P(S) = \frac{\text{Area of Square}}{\text{Total area of the region}}= \frac{r^2}{A}$$

The ratio of the probabilities can also be written as:

$$\frac{P(C)}{P(S)} = \frac{((πr^2) / A)}{ (r^2 / A)} = \frac{(πr^2)}{(r^2)} = π$$

Therefore, with more iterations, the value of Pi can be estimated:

$$\frac{P(C)}{P(S)} = \frac{N_c}{N_s} = π$$
# Implementation
The implementation is in C++ and is quite simple. First, a few constants are defined: the radius and center of the circle, the vertices of the square, the number of iterations, and the width of the region. In the main function, random coordinates (x,y) are picked within the region. Two functions ```bool insideSquare()``` and ```bool insideCircle()``` check whether the points picked are within the square or the circle, respectively. Two variables keep count of the total points within the square and circle. Once the iterations are complete, Pi is estimated as the number of points within the circle divided by the number of points within the square.
