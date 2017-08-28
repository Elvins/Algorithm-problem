/**
Problem C. Blackhole
Problem
Alice is trying to prevent dangerous black holes from threatening Earth. Right now, there are three black holes that are different points in 3-D space. Alice will create exactly three containment spheres, and all three must have the same radius. Spheres do not interfere with each other, so they may overlap.
Alice must place these spheres so that each black hole is covered by at least one sphere. Moreover, to ensure stability, the total set of points covered by at least one sphere must form a single connected area.
Alice wants to solve this critical problem as inexpensively as possible. What is the minimum radius that she can use?

Input
The input starts with one line with one integer T: the number of test cases. T test cases follow. Each test case consists of three lines. The i-th of those lines consists of three integers Xi, Yi, and Zi, representing the 3-D coordinates of the i-th black hole.

Output
For each test case, output one line Case #x: y, where x is the test case number (starting from 1) and y is a rational representing the minimum radius that Alice can use to solve the problem. y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits
1 ≤ T ≤ 100.
-1000 ≤ Xi ≤ 1000, for all i.
For all j ≠ k, (Xj, Yj, Zj) ≠ (Xk, Yk, Zk). (No two of the points have the same coordinates.)

Small dataset
Yi = 0, for all i.
Zi = 0, for all i.
Large dataset
-1000 ≤ Yi ≤ 1000, for all i.
-1000 ≤ Zi ≤ 1000, for all i.

Sample
Input 
4
0 0 0
1 0 0
-1 0 0
4 0 0
5 0 0
-2 0 0
0 0 0
1 1 1
-1 -1 -1
-4 2 -2
5 1 -4
0 4 -9

Output 
Case #1: 0.3333333333
Case #2: 1.1666666667
Case #3: 0.5773502692
Case #4: 2.1373179212

Note that the last two sample cases would not appear in the Small dataset.
In Sample Case #1, the smallest radius we can use is 1/3. Our three spheres should be centered at (-2/3, 0, 0), (0, 0, 0), and (2/3, 0, 0).
**/
/**
思路：

**/
