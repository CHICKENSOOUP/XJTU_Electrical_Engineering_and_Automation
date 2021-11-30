function [fitresult, gof] = createFit4(IK, UK)
%CREATEFIT(IK,UK)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : IK
%      Y Output: UK
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 16-Nov-2020 21:36:15 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( IK, UK );

% Set up fittype and options.
ft = fittype( 'poly1' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 4' );
plot( fitresult, xData, yData );
legend('ʵ��ֵ', '���ֵ');
title('��·����\it\fontname{Times new roman}U_{K }=f(I_{K })')
xlabel('�����ߵ���ƽ��ֵ\it\fontname{Times new roman}I_{K }(A)');
ylabel('�����ߵ�ѹƽ��ֵ\it\fontname{Times new roman}U_{K }(V)');
grid on;

