% =========================================================================
% CLOSE SERIAL PORT
% =========================================================================
disp('Closing Serial Port.');

flushinput(objCom);
fclose(objCom);
% Clean up all objects.
delete(objCom);
clear objCom
disp('------------------ END OF APPLICATION ------------------');