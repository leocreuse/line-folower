function [A, varargout] = sread(obj, size, precision)
% SWRITE
% Writes binary data to the device connected to the serial port object.
%
% Intput: 
%   obj         : serial port object
%   size        : maximum number of values to read
%   precision   : number of bits written for each value 
%                 int8, int16, int32, uint8, uint16, uint32, 
%                 float32 (float), float64 (double) 
% mode          : asynchronous ('async') or synchronous ('sync') write

%
% Ouptut: None
%   A           : data to be read
%   count       : number of values read (optional)
%   msg         : warning message if the read operation was unsuccessful (optional)
%
% Rq: Works with Matlab R2013a and R2015a

[A, count, msg] = fread(obj,size,precision);

varargout{1} = count;
varargout{2} = msg;

% Wait until asynchronous read operation finishes
while (strcmp(obj.TransferStatus,'read'))
end

end
