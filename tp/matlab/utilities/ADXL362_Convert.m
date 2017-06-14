function fdata = ADXL362_Convert(udata)

fdata = bitshift(udata,4, 'int32')/1000;

end 