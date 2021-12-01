`timescale 1ns / 1ps
//ʱ�ӷ�Ƶģ��
module clk_control(
  input sys_clk,//100MHZ
  input [2:0] sel,//����ѡ��
  output reg clk_100,//�������ʱ��100HZ
  output reg clk_select//����ʱ�ӣ���ͬ�������ܲ�ͬ
    );
    
  reg [19:0] count1;//����ʱ�ӷ�Ƶ��������
  reg [25:0] count2;//����ʱ�ӷ�Ƶ��������
  reg [25:0] COUNT;//���ķ�ƵԤ��������
  //�Ĵ������ͱ�����ʼ��
  initial 
    begin
      clk_100<=1'b0;
      clk_select<=1'b0;
      count1<=1'b0;
      count2<=1'b0;
      COUNT<=1'b0;
    end
  //100HZʱ�ӷ�Ƶ
  always @(posedge sys_clk)
    begin
      if(count1>=20'd500000)
        begin
          count1<=20'b0;
          clk_100<=~clk_100;
        end
      else
        begin
          count1<=count1+1'b1;
        end
    end
  //��������ѡ��
  always @(sel)
    begin
      case(sel)
        3'b100:COUNT<=26'd3125000;
        3'b010:COUNT<=26'd12500000;
        default:COUNT<=26'd12500000;
      endcase
    end
  //����ʱ�ӷ�Ƶ  
  always @(posedge sys_clk)
    begin
      if(count2>=COUNT)
        begin
          count2<=1'b0;
          clk_select<=~clk_select;
        end
      else
        begin
          count2<=count2+1'b1;
        end
    end
endmodule
