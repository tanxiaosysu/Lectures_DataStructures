/*
 * main.cpp
 *  Created on: 2014年11月3日
 *      Author: TanXiao
 */

#include "stdafx.h"
#include "Plane.h"
#include "Runway.h"
#include "Random.h"

int main() // Airport simulation program
/*
 Pre: The user must supply the number of time intervals the simulation is to run
 , the expected number of planes arriving, the expected number of planes
 departing per time interval, and the maximum allowed size for runway queues.
 Post: The program performs a random simulation of the airport, showing the
 status of the runway at each time interval, and prints out a summary of airport
 operation at the conclusion.
 Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
 */
{
    int end_time;       // time to run simulation
    int queue_limit;    // size of Runway queues
    int flight_number = 0;
	bool used = false;
	bool fall = false;
    double arrival_rate, departure_rate, fuel_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate, fuel_rate);
    Random variable;
    Runway small_airport(queue_limit);
    for (int current_time = 0; current_time < end_time; current_time++) {
		used = false;
		fall = false;
        // loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);
		//int number_arrivals;
		//std::cout << current_time <<":input ARRIVALS plane number:";
		//std::cin >> number_arrivals;
		//std::cout << std::endl;
        // current arrival requests
        for(int i = 0; i < number_arrivals; i++) {
			int fuel = variable.poisson(fuel_rate);
            Plane current_plane(flight_number++, current_time, fuel, arriving);
            if (small_airport.can_land(current_plane, used, current_time) != success)
                current_plane.refuse();
        }
		//int number_departures;
		//std::cout << current_time << ":input DEPARTURES plane number:";
		//std::cin >> number_departures;
		//std::cout << std::endl;
        int number_departures = variable.poisson(departure_rate);
        // current departure requests
        for (int j = 0; j < number_departures; j++) {
			int fuel = variable.poisson(fuel_rate);
            Plane current_plane(flight_number++, current_time, fuel, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }
        Plane moving_plane;
		if (!used)
        switch (small_airport.activity(current_time, moving_plane)) {
            // Let at most one Plane onto the Runway at current_time.
            case land:
				fall = false;
                moving_plane.land(current_time, fall);
				if (fall) {
					small_airport.shut_down(current_time);
					return 0;
				}
				used = true;
				break;
            case takeoff:
                moving_plane.fly(current_time);
				used = true;
                break;
            case idle:
                run_idle(current_time);
        }
    }
    small_airport.shut_down(end_time);
}
