time(ncount,1) = ncount;

disp(['fAccX = ' num2str(fAcc(ncount,1))...
    '  fAccY = ' num2str(fAcc(ncount,2))...
    '  fAccZ = ' num2str(fAcc(ncount,3))]);

set(plotHandleX,'YData',fAcc(:,1),'XData',time);
set(plotHandleY,'YData',fAcc(:,2),'XData',time)
set(plotHandleZ,'YData',fAcc(:,3),'XData',time);
set(figureHandleX,'Visible','on');
set(figureHandleY,'Visible','on');
set(figureHandleZ,'Visible','on');

drawnow;