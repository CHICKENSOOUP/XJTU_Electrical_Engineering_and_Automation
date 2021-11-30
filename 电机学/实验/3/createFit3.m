function [fitresult, gof] = createFit3(U0, lamda1)
%CREATEFIT(U0,LAMDA1)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : U0
%      Y Output: lamda1
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 16-Nov-2020 21:18:19 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( U0, lamda1 );

% Set up fittype and options.
ft = fittype( 'gauss2' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.Lower = [-Inf -Inf 0 -Inf -Inf 0];
opts.StartPoint = [0.466027001662013 111.266666666667 25.7745022291243 0.30331212491098 164.7 27.728207262118];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'untitled fit 3' );
plot( fitresult, xData, yData );
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}cos\phi_{0}=f(U_{0 })')
xlabel('�����ѹ\it\fontname{Times new roman}U_{0 }(V)');
ylabel('��������\it\fontname{Times new roman}cos\phi_{0 }');
grid on;


