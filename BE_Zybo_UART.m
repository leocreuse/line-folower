clear variables; clc; close all;
addpath(genpath('utilities'));


% =========================================================================
% PARAMETERS AND VARIABLE
% =========================================================================

%--------------------------------------------------------------------------
% User parameters
%--------------------------------------------------------------------------
portCom     = 'COM4';
comTimeout  = 30;  % (s)

% =========================================================================
% STARTING COMMUNICATION WITH BOARD
% =========================================================================

disp('------------------------------------------------------------- ')
disp('*                 STARTING APPLICATION                   *')
disp('------------------------------------------------------------- ')
disp(' ')

%--------------------------------------------------------------------------
% Open Serial Port
%--------------------------------------------------------------------------
disp('Opening serial comPort.');
objCom          = openSerialPort(portCom);
objCom.Timeout  = comTimeout;

% =========================================================================
% Handshake with board
% =========================================================================
disp('Sending handshake 8 bit Data ...');
CMD = hex2dec('10');
disp('Waiting for communication with Zybo')
waitCount = 0;
while (waitCount < 4)
    swrite(objCom, CMD, 'uint8','async');
    [data, count, msg] = sread(objCom,1,'uint8');

    if (count == 0)
        disp('Time out. Trying again ...')
        waitCount = waitCount + 1;
    else
        waitCount = 4;
    end
end

clear waitCount;

% =========================================================================
% Application
% =========================================================================

if ((count > 0) && (data == hex2dec('A')))
    
    
end

closeSerialPort;


