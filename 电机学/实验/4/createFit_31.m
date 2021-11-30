function [fitresult, gof] = createFit_31(UK, IK)
%CREATEFIT(UK,IK)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : UK
%      Y Output: IK
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  ������� FIT, CFIT, SFIT.

%  �� MATLAB �� 14-Dec-2020 21:28:50 �Զ�����


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( UK, IK );

% Set up fittype and options.
ft = fittype( 'poly1' );

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft );

% Plot fit with data.
figure( 'Name', 'untitled fit 1' );
plot( fitresult, xData, yData );
xlabel('�����ߵ�ѹƽ��ֵ \it\fontname{Times new roman}U_{K} (V)')
ylabel('�������ƽ��ֵ \it\fontname{Times new roman}I_{K} (A)')
legend('ʵ��ֵ', '���ֵ');
title('��ת����\it\fontname{Times new roman}I_{K}=f(U_{K})');
set(findobj('Type','line'),'LineWidth',1.5);
set(gca,'FontName','Times New Roman','FontName','����');
grid on


