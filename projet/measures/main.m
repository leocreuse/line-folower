%% Réponse de l'asservissement à des créneau
% On cherche à caractériser la qualité de nos asservissements. Pour cela on
% s'intéresse au temps de réponse à 5% et à l'erreur statique.
% 
% Lien vers le répertoire GitHub de notre projet <https://github.com/patouf35/line-folower>
% 
% On génère la réponse à un créneau pour deux commandes différentes


%% Créneau 20-25cm
clc;clear all; close all;
load('measures.mat');

figure; hold on; grid on;
plot(temps25_ms, pos25_mm);
plot(temps25_ms, cmd25_mm);
title('Réponse à un créneau 20-25cm');
xlabel('Temps (ms)');
ylabel('Position (mm)');
legend('Position réelle','Commande');
hold off;

%%
% Le temps de réponse mesuré est de 680ms. En revanche l'erreur statique
% dépend de la position : en position proche, les frottements solides
% provoquent une erreur statique de 4.0 mm tandis qu'en position éloignée,
% elle n'est que de 1.0 mm en moyenne. Dans le pire des cas l'erreur
% relative est de 2% ce qui est tout a fait acceptable.

%% Créneau 20-30cm
figure; hold on; grid on;
plot(temps30_ms, pos30_mm);
plot(temps30_ms, cmd30_mm);
title('Réponse à un créneau 20-30cm');
xlabel('Temps (ms)');
ylabel('Position (mm)');
legend('Position réelle','Commande');
hold off;

%%
% Le temps de réponse mesuré est de 780 ms. L'erreur statique
% dépend toujours de la position mais l'effet est amoindri : en position 
% proche, l'erreur statique est de 2.0 mm tandis qu'en position éloignée,
% elle n'est que de 1.0 mm en moyenne. Dans le pire des cas l'erreur
% relative est de 1% ce qui est tout a fait acceptable.