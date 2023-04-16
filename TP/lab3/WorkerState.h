#pragma once
#include "Worker.h"
class WorkerState : public Worker
{
	int mounthCash;
public:
	WorkerState();
	~WorkerState();
	int cash();
};
