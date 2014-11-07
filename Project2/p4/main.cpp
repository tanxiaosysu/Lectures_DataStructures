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
	bool land_used = false;
	bool takeoff_used = false;
	bool third_used = false;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway small_airport(queue_limit);
    for (int current_time = 0; current_time < end_time; current_time++) {
		land_used = false;
		takeoff_used = false;
		third_used = false;
        // loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);
        // current arrival requests
		for(int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			/*if (!land_used && small_airport.land_queue_full()) { //有需要进着陆队列，先从着陆跑道着陆一架
				Plane moving_plane;
				switch (small_airport.land_activity(current_time, moving_plane)) {
					case land:
						moving_plane.land(current_time, "LANDING");
						land_used = true;
				}
			}
			if (!takeoff_used && small_airport.land_queue_full()) { //着陆队列已使用，从起飞跑道着陆一架
				Plane moving_plane;
				switch (small_airport.sp_takeoff_activity(current_time, moving_plane)) {
					case land:
						moving_plane.land(current_time, "TAKEOFF");
						takeoff_used = true;
				}
			}*/
            if (small_airport.can_land(current_plane) != success) { //仍然不能入队列，拒绝
                current_plane.refuse();
			}
        }
        int number_departures = variable.poisson(departure_rate);
        // current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }
        Plane moving_plane;
		if (!land_used) 
        switch (small_airport.land_activity(current_time, moving_plane)) {
            // Let at most one Plane onto the Runway at current_time.
            case land:
                moving_plane.land(current_time, "LANDING");
				land_used = true;
				break;
			case landidle:
				land_run_idle(current_time);
		}//从着陆跑道着陆
		if (!third_used)
			switch (small_airport.third_landing_activity(current_time, moving_plane)) {
			case land:
				moving_plane.land(current_time, "The THIRD");
				third_used = true;
		}//从第三跑道着陆
		if (!takeoff_used)
		switch (small_airport.takeoff_activity(current_time, moving_plane)) {
            // Let at most one Plane onto the Runway at current_time.
            case takeoff:
                moving_plane.fly(current_time, "TAKEOFF");
				takeoff_used = true;
				break;
			case takeoffidle:
				takeoff_run_idle(current_time);
		}//从起飞跑道起飞
		if (!third_used)
			switch (small_airport.third_takeoff_activity(current_time, moving_plane)) {
					case takeoff:
						moving_plane.fly(current_time, "The THIRD");
						break;
					case thirdidle:
						third_run_idle(current_time);
		}//从第三跑道起飞
    }
    small_airport.shut_down(end_time);
}
