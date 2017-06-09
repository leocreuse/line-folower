function swrite(obj, A, precision, mode)
% SWRITE
% Writes binary data to the device connected to the serial port object.
%
% Intput: 
%   obj         : serial port object
%   A           : data to write
%   precision   : number of bits written for each value 
%                 int8, int16, int32, uint8, uint16, uint32, 
%                 float32 (float), float64 (double) 
% mode          : asynchronous ('async') or synchronous ('sync') write

%
% Ouptut: None
%
% Rq: Works with Matlab R2013a and R2015a



fwrite(obj, A, precision, mode);

% Wait until asynchronous write operation finishes
while (strcmp(obj.TransferStatus,'write'))
end

end
