function [fitresult, gof] = createFit1(I0p, U0p)
%CREATEFIT(I0P,U0P)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : I0p
%      Y Output: U0p
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 16-Nov-2020 21:00:36 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( I0p, U0p );

% Set up fittype and options.
ft = fittype( 'exp2' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [0.95108439789539 0.22875131743043 -0.722820513009501 -4.36117806288428];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}U_{0 }^{*}=f(I_{0 }^{*})')
xlabel('����ֵ\it\fontname{Times new roman}I_{0 }^{*}');
ylabel('����ֵ\it\fontname{Times new roman}U_{0 }^{*}');
grid on;


