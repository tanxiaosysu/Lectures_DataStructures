/*
 * Runway.h
 *  Created on: 2014年11月3日
 *      Author: TanXiao
 */

#ifndef RUNWAY_H_
#define RUNWAY_H_

#include <iostream>
#include "Extended_queue.h"

enum Runway_activity {
    idle, land, takeoff, landidle, takeoffidle, thirdidle
};

class Runway {
    public:
    Runway(int limit);
    Error_code can_land(const Plane &current);
    Error_code can_depart(const Plane &current);
//    Runway_activity activity(int time, Plane &moving);
	Runway_activity land_activity(int time, Plane &moving);
	Runway_activity takeoff_activity(int time, Plane &moving);
	Runway_activity sp_landing_activity(int time, Plane &moving);//landing跑道用于起飞
	Runway_activity sp_takeoff_activity(int time, Plane &moving);//takeoff跑道用于降落
	Runway_activity third_landing_activity(int time, Plane &moving);//p4 第三跑道用于着陆
	Runway_activity third_takeoff_activity(int time, Plane &moving);//p4 第三跑道用于起飞
    void shut_down(int time) const;
	bool land_queue_full(); //p3判断着陆队列是否满
    private:
	Extended_queue landing;
    Extended_queue _takeoff;
    int queue_limit;
    int num_land_requests;      // number of planes asking to land
    int num_takeoff_requests;   // number of planes asking to take off
    int num_landings;           // number of planes that have landed
    int num_takeoffs;           // number of planes that have taken off
    int num_land_accepted;      // number of planes queued to land
    int num_takeoff_accepted;   // number of planes queued to take off
    int num_land_refused;       // number of landing planes refused
    int num_takeoff_refused;    // number of departing planes refused
    int land_wait;              // total time of planes waiting to land
    int takeoff_wait;           // total time of planes waiting to take off
   // int idle_time;              // total time runway is idle
	int land_idle_time;
	int takeoff_idle_time;
	int third_idle_time;
};

#endif /* RUNWAY_H_ */
