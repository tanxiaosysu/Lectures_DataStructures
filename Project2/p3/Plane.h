/*
 * Plane.h
 *  Created on: 2014Äê11ÔÂ3ÈÕ
 *      Author: TanXiao
 */

#ifndef PLANE_H_
#define PLANE_H_

#include <iostream>
#include <string>
using std::string;
enum Plane_status {
    null, arriving, departing
};

class Plane {
    public:
    Plane();
    Plane(int flt, int time, Plane_status status);
    void refuse() const;
    void land(int time, string runway_) const;
    void fly(int time, string runway_) const;
    int started() const;
    private:
    int flt_num;
    int clock_start;
    Plane_status state;
};

#endif /* PLANE_H_ */
