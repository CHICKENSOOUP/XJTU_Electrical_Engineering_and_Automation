function [fitresult, gof] = createFit1(power2, n)
%CREATEFIT(POWER2,N)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : power2
%      Y Output: n
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 02-Nov-2020 14:30:32 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( power2, n );

% Set up fittype and options.
ft = fittype( 'poly1' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
legend('ʵ������ת�ٽ��', '��Ͻ��' );
% Label axes
xlabel( '\itP_{2}(W)');
ylabel( '\itn(r/min)');
title('����ֱ���綯��\itn=f(P_{2})')
grid on


