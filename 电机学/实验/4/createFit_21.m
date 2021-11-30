function [fitresult, gof] = createFit_21(U2, I2)
%CREATEFIT(U2,I2)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : U2
%      Y Output: I2
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 14-Dec-2020 21:01:37 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( U2, I2 );

% Set up fittype and options.
ft = fittype( 'poly3' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
xlabel('�����ߵ�ѹƽ��ֵ \it\fontname{Times new roman}U_{0} (V)')
ylabel('�������ƽ��ֵ \it\fontname{Times new roman}I_{0} (A)')
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}I_{0}=f(U_{0})');
set(findobj('Type','line'),'LineWidth',1.5);
set(gca,'FontName','Times New Roman','FontName','����');
grid on


