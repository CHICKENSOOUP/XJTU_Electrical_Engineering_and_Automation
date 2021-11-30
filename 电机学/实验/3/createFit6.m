function [fitresult, gof] = createFit6(IK, lamda2)
%CREATEFIT(IK,LAMDA2)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : IK
%      Y Output: lamda2
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 16-Nov-2020 21:51:38 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( IK, lamda2 );

% Set up fittype and options.
ft = fittype( 'smoothingspline' );
opts = fitoptions( 'Method', 'SmoothingSpline' );
opts.SmoothingParam = 0.999607275026491;

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'untitled fit 6' );
plot( fitresult, xData, yData );
legend('ʵ��ֵ', '���ֵ');
title('��·����\it\fontname{Times new roman}cos\phi_{K }=f(U_{K })')
xlabel('�����ߵ���ƽ��ֵ\it\fontname{Times new roman}I_{K }(A)');
ylabel('��������\it\fontname{Times new roman}cos\phi_{K }');
axis([-inf,inf,0,1])
grid on;


