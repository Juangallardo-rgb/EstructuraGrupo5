close all
clear all
clc 
load TiempoDeEjecucion.txt
x = TiempoDeEjecucion(:,1);
y = TiempoDeEjecucion(:,2);

figure()
plot(x,y,'b', 'linewidth' ,2)
gride on
title ('Tiempo de ejecucion de un algoritmo')
xlabel('x')
ylabel('y')