function [fitresult, gof] = createFit_15(P_2, P_1)
%CREATEFIT(P_2,P_1)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : P_2
%      Y Output: P_1
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 14-Dec-2020 20:55:42 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( P_2, P_1 );

% Set up fittype and options.
ft = fittype( 'poly1' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
xlabel('���� \it\fontname{Times new roman}P_{2} (W)')
ylabel('���� \it\fontname{Times new roman}P_{1} (W)')
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}P_{1}=f(P_{2})');
set(findobj('Type','line'),'LineWidth',1.5);
set(gca,'FontName','Times New Roman','FontName','����');
grid on


