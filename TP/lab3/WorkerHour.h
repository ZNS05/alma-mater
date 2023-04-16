#pragma once
#include "Worker.h"
class WorkerHour : public Worker
{
	int hours;
	int traf;
public:
	WorkerHour();
	~WorkerHour();
	int cash();
};
