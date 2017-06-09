function objCom = openSerialPort(portCom)

% =========================================================================
% COM port configuration
% =========================================================================
% input : none
%
% output :
%       objCom : object serial port com21


% Delete a serial port object in case of already existing
delete(instrfind('Type', 'serial', 'Port', portCom, 'Tag', ''))

%Open the serial port com 3
objCom                    = serial(portCom);
%objCom.BaudRate           = 921600;
objCom.BaudRate           = 115200;
objCom.InputBufferSize    = 4096;
objCom.OutputBufferSize   = 4096;
objCom.Timeout            = 50;

% Connect to board.
fopen(objCom);

end

