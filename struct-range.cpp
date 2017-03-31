//
//  struct-range.cpp
//  bin-simulations
//
//

#include "struct-range.hpp"

long random_generator_1bill() {
    return dis(gen);
}

long check_num_interval(long n, vector<bin_node> &ball_counts) {
    
    // we set the bin_index to 0 for the case of the first ball being thrown
    long bin_index = 0;
    
    // find which bin count the ball fell into
    for (long i = 0; i < ball_counts.size(); i++) {
        if (n >= ball_counts[i].start && n <= ball_counts[i].end) {
            bin_index = i;
            break;
        }
    }
    return bin_index;
}

void update_bin_values(long bin_index, vector<bin_node> &ball_counts) {
    
    // handle the case where we hit a bin of 0 ball count
    if (bin_index == 0) {
        // remove a bin of 0 ball count
        ball_counts[bin_index].start++;
        
        // if there are no bins currently with a ball count of 1, add new bin
        if ((bin_index + 1) == ball_counts.size()) {
            bin_node new_bin;
            new_bin.start = 1;
            new_bin.end = 1;
            ball_counts.push_back(new_bin);
        }
        else {
            // add a bin of 1 ball count
            ball_counts[bin_index + 1].end++;
            bin_index += 2;
            // increment all the rest of the ranges accordingly
            for (long j = bin_index; j < ball_counts.size(); j++) {
                ball_counts[j].start++;
                ball_counts[j].end++;
            }
        }
    }
    // handle the cases where we hit a bin of x (where x > 0) ball count
    else {
        // remove 1 bin of x ball count
        ball_counts[bin_index].end--;
        
        // if there are no bins currently with ball count of (x + 1), add new bin
        if ((bin_index + 1) == ball_counts.size()) {
            bin_node new_bin;
            new_bin.start = ball_counts[bin_index].end + 1;
            new_bin.end = new_bin.start;
            ball_counts.push_back(new_bin);
        }
        else {
            // add 1 bin with ball count of (x+1)
            ball_counts[bin_index + 1].start--;
        }
    }
}

long retrieve_max_bin(vector<bin_node> &ball_counts) {
    return ball_counts.size()-1;
}

long ball_simulations(long n, bool algo_flag) {
    vector<bin_node> ball_counts(1);
    ball_counts[0].end = NUM_BINS;
    
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
