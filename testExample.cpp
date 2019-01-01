/* Copyright © 2019 Mathieu Gravey <gravey.mathieu@gmail.com>
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details. */

#define MATLAB
#include "mexInterrupt.hpp"
#include <mex.h>

void mexFunctionWork(int nlhs, mxArray *plhs[],
	int nrhs, const mxArray *prhs[],std::atomic<bool> &done){

	int iter=0;
	while(!done && iter<50){
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		iter++;
	}
	done=true;
}



void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	std::atomic<bool> done(false);
	auto myFuture = mexInterrupt::startInterruptCheck(done);
	mexFunctionWork(nlhs, plhs,  nrhs, prhs,done); // MATLAB APIs need to be exactuted in the main thread
	myFuture.wait();
	
}

