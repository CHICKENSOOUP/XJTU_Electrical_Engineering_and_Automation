clc;
clear;
close all;
alpha = [30,50,70];
ui = [30.432,30.432,30.432];
uo = [10.0,14.7,21.6];
uoui = ui./uo;
a = [30:0.1:70];
the = 100./a;

figure(1)
hold on
plot(alpha,uoui,'k.-','linewidth',1.5);
plot(a,the,'r.-','linewidth',1.5);
hold off
xlabel('ռ�ձ�\it\fontname{times new roman}\alpha\rm(%)')
ylabel('�����ѹ�����������ѹ֮�� \it\fontname{times new roman}U_{i}/U_{o} ')
legend('ʵ��������','����ֵ');
title('ռ�ձ������������ѹ֮�ȵĹ�ϵ')
grid on

fs = [5,10,20];
iopp = [0.217,0.151,0.107];

figure(2)
plot(fs,iopp,'k.-','linewidth',1.5);
xlabel('Ƶ��\it\fontname{times new roman}f_{s} (\rmkHz)')
ylabel('�������ֵ \it\fontname{times new roman}i_{o(p-p)} \rm(A) ')
legend('ʵ��������');
title('Ƶ����������ֵ֮��Ĺ�ϵ')
grid on