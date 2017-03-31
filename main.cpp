//
//  main.cpp
//  bin-simulations
//
//  Driver function to run simulations of tossing a large # of balls into a large # of bins
//

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

/*
 * Function returns a random long between [1, 1 NUM_BINS]
 */
long random_generator_1bill() {
    return dis(gen);
}

/*
 * Function returns the # of balls the bin it falls into has
 * @param n : # bin selected
 * @param ball_counts : reference to vector containing ball counts
 */
long check_num_interval(long n, vector<long> &ball_counts) {
    
    long bin_index = 0;
    long bin_count = 0;
    
    // find which bin count the ball fell into
    for (long i = 0; i < ball_counts.size(); i++) {
        bin_count += ball_counts[i];
        if (n <= bin_count) {
            bin_index = i;
            break;
        }
    }
    return bin_index;
}

/*
 * Function updates the bin count intervals
 * @param bin_index : bin index ball was thrown into
 * @param ball_counts : reference to vector containing ball counts
 */
void update_bin_values(long bin_index, vector<long> &ball_counts) {
    ball_counts[bin_index]--;
    if (bin_index + 1 >= ball_counts.size()) {
        ball_counts.push_back(0);
    }
    ball_counts[bin_index + 1]++;
}

/*
 * Function returns the largest number of balls in an existing bin from a vector
 * @param ball_counts : reference to vector containing ball counts
 */
long retrieve_max_bin(vector<long> &ball_counts) {
    return ball_counts.size() - 1;
}

/*
 * Function returns the largest number of balls in any bin
 * @param n : # of ball throws
 * @param algo_flag : 0 to run simulation 1, 1 to run simulation 2
 */
long ball_simulations(long n, bool algo_flag) {
    vector<long> ball_counts(1);
    ball_counts[0] = NUM_BINS;
    
    if (algo_flag == 0) {
        for (long i = 0; i < n; i++) {
            long rand_num = random_generator_1bill();
            long bin_index = check_num_interval(rand_num, ball_counts);
            update_bin_values(bin_index, ball_counts);
        }
    }
    
    else if (algo_flag == 1) {
        for (long i = 0; i < n; i++) {
            long rand_num1 = random_generator_1bill();
            long rand_num2 = random_generator_1bill();
            long bin_index1 = check_num_interval(rand_num1, ball_counts);
            long bin_index2 = check_num_interval(rand_num2, ball_counts);
            
            long bin_index = min(bin_index1, bin_index2);
            update_bin_values(bin_index, ball_counts);
        }
    }
    
    return retrieve_max_bin(ball_counts);
}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    int num_trials = 1;
    bool algo_flag = 0;
    
    for (int i = 0; i < num_trials; i++) {
        cout << "Largest # of Balls in any Bin: " << ball_simulations(NUM_BALL_THROWS, algo_flag) << endl;
    }
    
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time spent: " << time_spent << endl;
    return 0;
}
