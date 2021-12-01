function [fitresult, gof] = createFit1(D, delta_uC, delta_uC_cal)
%CREATEFIT(D,DELTA_UC)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : D
%      Y Output: delta_uC
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 22-Nov-2020 12:01:16 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( D, delta_uC );

% Set up fittype and options.
ft = fittype( 'exp1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [188.632179365306 4.19747074498863];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
hold on
% ��ͼ������Դ
plot( fitresult, xData, yData );
plot();
hold off
xlabel('Duty Ratio') % ������
ylabel('capacitor voltage ripple (V)') % ������
axis([-inf,inf,-inf,inf]);
set(gca,'FontName','Times New Roman');
set(findobj('Type','line'),'LineWidth',1.5)
legend('simulation result','result fit','the theoretical result'); % ͼ��
title('the relationships between duty ratio and capacitor voltage ripple') % ����
grid on
save(gca,'1.jpg'); % ����ͼƬ


