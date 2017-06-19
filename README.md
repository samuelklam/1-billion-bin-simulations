# 1 Billion Balls & Bins

This repo simulates the throwing of one billion balls into one billion bins (independently and uniformly at random). The implementation takes advantage of the fact that all buckets with the same number of balls are indistinguishable. Thus, a vector A can be used such that A[i] denotes the number of bins with i balls. Appropriate algebra can be done for one billion steps to simulate the one billion ball throws. By doing so, a significant amount of space is saved.

The `struct-range` files contain a slightly more complex solution than the solution in `main.cpp`, where A[i] stores a struct as versed to a number.
