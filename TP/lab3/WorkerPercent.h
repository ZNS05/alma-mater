#pragma once
#include "Worker.h"
class WorkerPercent : public Worker
{
	int mounthSells;
	int percent;
public:
	WorkerPercent();
	~WorkerPercent();
	int cash();
};
