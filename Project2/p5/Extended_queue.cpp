#include "Extended_queue.h"


Extended_queue::Extended_queue(int n) : queue<Plane>() , limit(n) {
}
bool Extended_queue::empty() const {
	return queue<Plane>::empty();
}
int Extended_queue::size() const {
	return queue<Plane>::size();
}
Error_code Extended_queue::append(const Plane a) {
	if (size() == limit) return overflow;
	else queue<Plane>::push(a);
	return success;
}
Error_code Extended_queue::serve() {
	return success;
}
Error_code Extended_queue::retrieve(Plane & a) {
	if (size() <= 0) return overflow;
	a = queue<Plane>::front();
	queue<Plane>::pop();
	return success;
}
