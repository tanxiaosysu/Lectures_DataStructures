/*
 * Plane.cpp
 *  Created on: 2014年11月3日
 *      Author: TanXiao
 */

#include "Plane.h"

Plane::Plane() {
    flt_num = -1;
    clock_start = -1;
    state = null;
}

Plane::Plane(int flt, int time, Plane_status status) {
    flt_num = flt;
    clock_start = time;
    state = status;
    std::cout << "Plane number " << flt << " ready to ";
    if (status == arriving)
        std::cout << "land." << std::endl;
    else
        std::cout << "take off." << std::endl;
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

void Plane::land(int time, string r) const
/* Post: Processes a Plane that is landing at the specified time. */
{
    int wait = time - clock_start;
    std::cout << time << ": Plane number " << flt_num << " landed from "<< r << " RUNWAY after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the LANDING queue." << std::endl;
}

void Plane::fly(int time, string r) const
/* Post: Process a Plane that is taking off at the specified time. */
{
    int wait = time - clock_start;
    std::cout << time << ": Plane number " << flt_num << " took off from " << r << " RUNWAY after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the TAKEOFF queue." << std::endl;
}

int Plane::started() const
/* Post: Return the time that the Plane entered the airport system. */
{
    return clock_start;
}
