% configure_plots

AccX = 0;
AccY = 0;
AccZ = 0;

% Set up the figure window
%time = now;
figureHandleX = figure('NumberTitle','off',...
    'Name','Acceleration X',...
    'Color',[0 0 0],'Visible','off');
% Set axes
axesHandleX = axes('Parent',figureHandleX,...
    'YGrid','on',...
    'YColor',[0.9725 0.9725 0.9725],...
    'XGrid','on',...
    'XColor',[0.9725 0.9725 0.9725],...
    'Color',[0 0 0]);
hold on;
plotHandleX = plot(axesHandleX,time,AccX,'Marker','.','LineWidth',1,'Color',[0 1 0]);
xlim(axesHandleX,[0 nbSamp]);
ylim([-2,2]);
% Create xlabel
xlabel('Samples','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create ylabel
ylabel('AccX in [g]','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create title
title('Acceleration X','FontSize',15,'Color',[1 1 0]);

figureHandleY = figure('NumberTitle','off',...
    'Name','Acceleration Y',...
    'Color',[0 0 0],'Visible','off');
% Set axes
axesHandleY = axes('Parent',figureHandleY,...
    'YGrid','on',...
    'YColor',[0.9725 0.9725 0.9725],...
    'XGrid','on',...
    'XColor',[0.9725 0.9725 0.9725],...
    'Color',[0 0 0]);
hold on;
plotHandleY = plot(axesHandleY,time,AccY,'Marker','.','LineWidth',1,'Color',[0 1 0]);
xlim(axesHandleY,[0 nbSamp]);
ylim([-2,2]);
% Create xlabel
xlabel('Samples','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create ylabel
ylabel('AccY in [g]','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create title
title('Acceleration Y','FontSize',15,'Color',[1 1 0]);


figureHandleZ = figure('NumberTitle','off',...
    'Name','Acceleration Z',...
    'Color',[0 0 0],'Visible','off');
% Set axes
axesHandleZ = axes('Parent',figureHandleZ,...
    'YGrid','on',...
    'YColor',[0.9725 0.9725 0.9725],...
    'XGrid','on',...
    'XColor',[0.9725 0.9725 0.9725],...
    'Color',[0 0 0]);
hold on;
plotHandleZ = plot(axesHandleZ,time,AccZ,'Marker','.','LineWidth',1,'Color',[0 1 0]);
xlim(axesHandleZ,[0 nbSamp]);
ylim([-2,2]);
% Create xlabel
xlabel('Samples','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create ylabel
ylabel('AccZ in [g]','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
% Create title
title('Acceleration Z','FontSize',15,'Color',[1 1 0]);