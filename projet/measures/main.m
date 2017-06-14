%% R�ponse de l'asservissement � des cr�neau
% On cherche � caract�riser la qualit� de nos asservissements. Pour cela on
% s'int�resse au temps de r�ponse � 5% et � l'erreur statique.
% 
% Lien vers le r�pertoire GitHub de notre projet <https://github.com/patouf35/line-folower>
% 
% On g�n�re la r�ponse � un cr�neau pour deux commandes diff�rentes


%% Cr�neau 20-25cm
clc;clear all; close all;
load('measures.mat');

figure; hold on; grid on;
plot(temps25_ms, pos25_mm);
plot(temps25_ms, cmd25_mm);
title('R�ponse � un cr�neau 20-25cm');
xlabel('Temps (ms)');
ylabel('Position (mm)');
legend('Position r�elle','Commande');
hold off;

%%
% Le temps de r�ponse mesur� est de 680ms. En revanche l'erreur statique
% d�pend de la position : en position proche, les frottements solides
% provoquent une erreur statique de 4.0 mm tandis qu'en position �loign�e,
% elle n'est que de 1.0 mm en moyenne. Dans le pire des cas l'erreur
% relative est de 2% ce qui est tout a fait acceptable.

%% Cr�neau 20-30cm
figure; hold on; grid on;
plot(temps30_ms, pos30_mm);
plot(temps30_ms, cmd30_mm);
title('R�ponse � un cr�neau 20-30cm');
xlabel('Temps (ms)');
ylabel('Position (mm)');
legend('Position r�elle','Commande');
hold off;

%%
% Le temps de r�ponse mesur� est de 780 ms. L'erreur statique
% d�pend toujours de la position mais l'effet est amoindri : en position 
% proche, l'erreur statique est de 2.0 mm tandis qu'en position �loign�e,
% elle n'est que de 1.0 mm en moyenne. Dans le pire des cas l'erreur
% relative est de 1% ce qui est tout a fait acceptable.