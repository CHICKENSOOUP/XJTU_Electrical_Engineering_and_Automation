function [fitresult, gof] = createFit_23(U2, cosfai2)
%CREATEFIT(U2,COSFAI2)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : U2
%      Y Output: cosfai2
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 14-Dec-2020 21:08:24 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( U2, cosfai2 );

% Set up fittype and options.
ft = fittype( 'exp2' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [0.395197328753708 -0.00207426936353757 -9.00145549324374 -0.0425218658477465];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
xlabel('�����ߵ�ѹƽ��ֵ \it\fontname{Times new roman}U_{0} (V)')
ylabel('�������� \it\fontname{Times new roman}cos\phi')
legend('ʵ��ֵ', '���ֵ');
title('��������\it\fontname{Times new roman}cos\phi=f(U_{0})');
set(findobj('Type','line'),'LineWidth',1.5);
set(gca,'FontName','Times New Roman','FontName','����');
grid on



