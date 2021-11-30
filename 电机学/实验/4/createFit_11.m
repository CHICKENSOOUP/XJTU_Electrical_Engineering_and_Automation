function [fitresult, gof] = createFit_11(P_2, eta)
%CREATEFIT(P_2,ETA)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : P_2
%      Y Output: eta
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 14-Dec-2020 20:09:59 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( P_2, eta );

% Set up fittype and options.
ft = fittype( 'poly3' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
xlabel('���� \it\fontname{Times new roman}P_{2} (W)')
ylabel('Ч�� \it\fontname{Times new roman}\eta')
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}\eta=f(P_{2})');
set(findobj('Type','line'),'LineWidth',1.5);
set(gca,'FontName','Times New Roman','FontName','����');
grid on;


