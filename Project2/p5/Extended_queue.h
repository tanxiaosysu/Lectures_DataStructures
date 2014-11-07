#ifndef EXTENDED_QUEUE_H_
#define EXTENDED_QUEUE_H_
#include <queue>
using std::queue;
#include "Error_code.h"
#include "Plane.h"
class Extended_queue : public queue<Plane> {
public:
	Extended_queue(int n = 1000);
	bool empty() const;
	int size() const;
    Error_code append(const Plane a);
    Error_code serve();
    Error_code retrieve(Plane &a);
private:
	int limit;
};
#endif

