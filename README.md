# MexInterrupt

This small code show how to integrate code interruption in C++ MATLAB Mex files. The code uses undocumented APIs that can naturally change at any moment ( more between releases ) the code proposed here is designed to work asynchronously.
Like visible in the test/example code, after the interruption an atomic boolean switch to `true` to stop the execution. This approach allows separating the interruption mechanism from Matlab in the main code.
The current code is tested to be compiled on MATLAB R2018b, older version of Matlab probably don't handle the current mechanism. For previous version refer to this [article](https://undocumentedmatlab.com/blog/mex-ctrl-c-interrupt). And for an asynchronous version [here](https://www.advanpix.com/2016/07/02/devnotes-3-proper-handling-of-ctrl-c-in-mex-module)

The current code as the motivation to be very portable between platforms that the reason for using C++11 future. I designed the code to be able to handle old version of MATLAB after compilation, and in some proportion at compilation time. At compilation time is only possible if the current MATLAB release is informed in the mex command line.

## How to Start

Copy the `testExample.cpp` and implemented in the function `mexFunctionWork` regarding your needs.