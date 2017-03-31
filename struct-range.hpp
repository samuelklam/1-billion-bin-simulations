//
//  struct-range.hpp
//  bin-simulations
//

#ifndef struct_range_hpp
#define struct_range_hpp

#include <stdio.h>
#include <iostream>
#include <random>
#include <vector>
#include <time.h>

using namespace std;

#define NUM_BALL_THROWS 1000000000
#define NUM_BINS        1000000000

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<long> dis(1, NUM_BINS);

typedef struct {
    long start = 1;
    long end = 0;
} bin_node;

/*
 * Function returns a random long between [1, 1 NUM_BINS]
 */
long random_generator_1bill();

/*
 * Function returns the # of balls the bin it falls into has
 * @param n : # bin selected
 * @param ball_counts : reference to vector containing ball counts
 */
long check_num_interval(long n, vector<bin_node> &ball_counts);

/*
 * Function updates the bin count intervals
 * @param bin_index : bin index ball was thrown into
 * @param ball_counts : reference to vector containing ball counts
 */
void update_bin_values(long bin_index, vector<bin_node> &ball_counts);

/*
 * Function returns the largest number of balls in an existing bin from a vector
 * @param ball_counts : reference to vector containing ball counts
 */
long retrieve_max_bin(vector<bin_node> &ball_counts);

/*
 * Function returns the largest number of balls in any bin
 * @param n : # of ball throws
 * @param ball_counts : reference to vector containing ball counts
 */
long ball_simulations(long n, bool algo_flag);

#endif /* struct_range_hpp */
