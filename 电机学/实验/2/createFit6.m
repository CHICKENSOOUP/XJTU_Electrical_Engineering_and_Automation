function [fitresult, gof] = createFit6(ifn, n2)
%CREATEFIT(IFN,N2)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : ifn
%      Y Output: n2
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 02-Nov-2020 14:57:59 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( ifn, n2 );

% Set up fittype and options.
ft = fittype( 'poly2' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
h = plot( fitresult, xData, yData );
legend('ʵ������ı����ŵ������ٽ��', '��Ͻ��' );
% Label axes
xlabel( '\itI_{f}(mA)');
ylabel( '\itn(r/min)');
title('����ֱ���綯����������\itn=f(I_{f})')
grid on


