/*
 * stdafx.h
 *  Created on: 2014年11月4日
 *      Author: TanXiao
 */

#ifndef SRC_STDAFX_H_
#define SRC_STDAFX_H_

#include <iostream>

void initialize(int &end_time, int &queue_limit, double &arrival_rate,
        double &departure_rate)
        /*
         Pre: The user specifies the number of time units in the simulation, the
         maximal queue sizes permitted, and the expected arrival and departure
         rates for the airport.
         Post: The program prints instructions and initializes the parameters
         end_time, queue_limit, arrival_rate, and departure_rate to the
         specified values.
         Uses: utility function user_says_yes
         */
        {
    std::cout << "This program simulates an airport with only one runway.\n"
            << "One plane can land or depart in each unit of time.\n";
    std::cout << "Up to what number of planes can be waiting to land "
            << "or take off at any time? " << std::flush;
    std::cin >> queue_limit;
    std::cout << "How many units of time will the simulation run?"
            << std::flush;
    std::cin >> end_time;
    bool acceptable;
    do {
        std::cout << "Expected number of arrivals per unit time?" << std::flush;
        std::cin >> arrival_rate;
        std::cout << "Expected number of departures per unit time?"
                << std::flush;
        std::cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            std::cerr << "These rates must be nonnegative.\n";
        else
            acceptable = true;
        if (acceptable && arrival_rate + departure_rate > 1.0)
            std::cerr
                    << "Safety Warning: This airport will become saturated. \n";
    } while (!acceptable);
}

void land_run_idle(int time)
/* Post: The specified time is printed with a message that the runway is idle.*/
{
    std::cout << time << ": LANDING Runway is idle.\n";
}

void takeoff_run_idle(int time)
/* Post: The specified time is printed with a message that the runway is idle.*/
{
    std::cout << time << ": TAKEOFF Runway is idle.\n";
}

#endif /* SRC_STDAFX_H_ */
