function [fitresult, gof] = createFit4(t2, n)
%CREATEFIT(T2,N)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : t2
%      Y Output: n
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 02-Nov-2020 14:42:10 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( t2, n );

% Set up fittype and options.
ft = fittype( 'poly1' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
h = plot( fitresult, xData, yData );
legend(  'ʵ������ת������', '�������' );
% Label axes
xlabel( '\itT_{2}(N*m)' );
ylabel( '\itn(r/min)' );
title('����ֱ���綯��\itn=f(T_{2})')
grid on


