/*
 * Plane.cpp
 *  Created on: 2014年11月3日
 *      Author: TanXiao
 */

#include "Plane.h"
#include "Runway.h"
Plane::Plane() {
    flt_num = -1;
    clock_start = -1;
    state = null;
	fuel = 0;
}

Plane::Plane(int flt, int time, int f, Plane_status status) {
    flt_num = flt;
    clock_start = time;
    state = status;
	fuel = f;
    std::cout << "Plane number " << flt << " ready to ";
    if (status == arriving)
        std::cout << "land.";
    else
        std::cout << "take off.";
	std::cout << "It has " << fuel << " units FUEL." << std::endl;
}

void Plane::refuse() const
/* Post: Processes a Plane wanting to use Runway, when the Queue is full. */
{
    std::cout << "Plane number " << flt_num;
    if (state == arriving)
        std::cout << " directed to another airport" << std::endl;
    else
        std::cout << " told to try to takeoff again later" << std::endl;
}

void Plane::land(int time, bool &fall) const
/* Post: Processes a Plane that is landing at the specified time. */
{
    int wait = time - clock_start;
	if (fuel < wait) {
		fall = true;
		std::cout << time << ": Plane number " << flt_num << " FALL at "
            << clock_start + fuel << " time (" << time - (clock_start + fuel) << " unit time(s) BEFORE, use "<< fuel
			<< " unit time(s) fuel, wait "<< wait <<" unit time(s)) in LANDING queue!!! program END."
			<< std::endl;
		return;
	}
    std::cout << time << ": Plane number " << flt_num << " landed after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the LANDING queue." << fuel << " unit time FUEL left." << std::endl;
}

void Plane::fly(int time) const
/* Post: Process a Plane that is taking off at the specified time. */
{
    int wait = time - clock_start;
    std::cout << time << ": Plane number " << flt_num << " took off after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the TAKEOFF queue." << std::endl;
}

int Plane::started() const
/* Post: Return the time that the Plane entered the airport system. */
{
    return clock_start;
}
