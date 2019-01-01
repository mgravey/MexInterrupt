% Copyright © 2019 Mathieu Gravey <gravey.mathieu@gmail.com>
% This program is free software. It comes without any warranty, to
% the extent permitted by applicable law. You can redistribute it
% and/or modify it under the terms of the Do What The Fuck You Want
% To Public License, Version 2, as published by Sam Hocevar. See
% http://www.wtfpl.net/ for more details.

%%
% -lut is mendatory, libut has all the function liked to code interuption.

% simple version
%mex textExample.cpp -lut

% with MATLAB_COMPILE_VERSION
mex('testExample.cpp','-lut',strcat('-DMATLAB_VERSION=0x',version('-release')));
drawnow;
testExample
