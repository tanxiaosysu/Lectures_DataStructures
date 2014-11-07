/*
 * Plane.h
 *  Created on: 2014Äê11ÔÂ3ÈÕ
 *      Author: TanXiao
 */

#ifndef PLANE_H_
#define PLANE_H_

#include <iostream>
#include "Error_code.h"
#include "Random.h"
enum Plane_status {
    null, arriving, departing
};

class Plane {
    public:
    Plane();
    Plane(int flt, int time, int fuel_, Plane_status status);
    void refuse() const;
    void land(int time, bool & fall) const;
    void fly(int time) const;
    int started() const;
	int fuel;
    private:
    int flt_num;
    int clock_start;
    Plane_status state;
};

#endif /* PLANE_H_ */
