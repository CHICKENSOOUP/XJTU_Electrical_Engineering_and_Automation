function createfigure(xvector1, yvector1)
%CREATEFIGURE(xvector1, yvector1)
%  XVECTOR1:  bar xvector
%  YVECTOR1:  bar yvector

%  �� MATLAB �� 12-Dec-2020 16:24:57 �Զ�����

% ���� figure
figure1 = figure('Name','FFT Analysis Results');

% ���� axes
axes1 = axes('Parent',figure1,...
    'Position',[0.117216117216117 0.11530064072437 0.815018315018315 0.805896805896806]);
hold(axes1,'on');

% ���� bar
bar(xvector1,yvector1,'EdgeColor','none','BarWidth',0.5);

% ���� ylabel
ylabel('Mag (% of Fundamental)');

% ���� xlabel
xlabel('Frequency (Hz)');

% ���� title
title('Fundamental (50Hz) = 47.58 , THD= 368.69%');

% ȡ�������е�ע���Ա����������� X ��Χ
% xlim(axes1,[-3750 75000]);
% ȡ�������е�ע���Ա����������� Y ��Χ
% ylim(axes1,[0 109.791910175718]);
box(axes1,'on');
grid(axes1,'on');
% ������������������
set(axes1,'XMinorGrid','on','YMinorGrid','on','ZMinorGrid','on');
