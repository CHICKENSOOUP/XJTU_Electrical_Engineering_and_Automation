a=[1,2,50];
b=[1,0];
sys=tf(b,a);
t=0:0.1:10;
h=impulse(sys,t);
h1=step(sys,t);
plot(h,'r');
hold on
plot(h1,'b');
xlabel('t');
title('�弤��Ӧ�ͽ�Ծ��Ӧ����');
legend('�弤��Ӧ','��Ծ��Ӧ');