/*
 * Random.h
 *  Created on: 2014Äê11ÔÂ3ÈÕ
 *      Author: TanXiao
 */


#ifndef RANDOM_H_
#define RANDOM_H_

#include <ctime>
#include <limits>
#include <cmath>

class Random {
    public:
    Random(bool pseudo = true);
    // Declare random-number generation methods here.
    double random_real();
    int random_integer(int low, int high);
    int poisson(double mean);
    private:
    int reseed();                 // Re-randomize the seed.
    int seed, multiplier, add_on; // constants for use in arithmetic operations
};

#endif /* RANDOM_H_ */
