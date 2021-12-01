`timescale 1ns / 1ps
//����ģ��
module TOP(
  input sys_clk,//100MHZ
  input rst,//��λ��
  input keyboard_select,//����ѡ��������orPS2����
  input ps2_clk,//ps2����ʱ��
  input ps2_data, //ps2����������
  input [3:0] col,//�������������
  input auto_en,//�Զ�����ʹ��
  input [2:0] song_num,//����ѡ��
  input SD,//��ͨ�˲���ʹ��
  output sd,//��ͨ�˲���ʹ��
  output audio_out,//��Ƶ���
  output [3:0] scan,//���������ɨ��
  output reg [15:0] led,//LED���
  output [1:0] digital_en,//�����Ƭѡ
  output [7:0] digital_data//����ܶ�ѡ
    );
  
  wire clk_100;//100HZ
  wire clk_sel;//����ʱ��
  wire [4:0] value1;//���ռ��̼�ֵ
  wire [4:0] value2;//��������ģ�������ֵ
  wire [4:0] value;//���������ֵ
  wire [4:0] key1;//������̼�ֵ
  wire [4:0] key2;//ps2���̼�ֵ
  assign value1=keyboard_select?key2:key1;//����ʹ�ܿ���
  assign value=auto_en?value2:value1;//�˹�or�Զ�ģʽ����
  //ʵ����
  clk_control clk1(sys_clk,song_num,clk_100,clk_sel);
  keyboard k1(clk_100,col,scan,key1);
  ps2_keyboard ps2_1(rst,ps2_clk,ps2_data,sys_clk,key2);
  audio_port a1(sys_clk,SD,value,sd,audio_out);
  auto_display auto1(clk_sel,auto_en,song_num,value2);
  scan_led_hex_disp d1(sys_clk,rst,value,digital_en,digital_data);
  //LED����
  always @(value)
    begin
      case(value)
        5'd0:led<=16'b1;
        5'd1:led<=16'b10;
        5'd2:led<=16'b100;
        5'd3:led<=16'b1000;
        5'd4:led<=16'b10000;
        5'd5:led<=16'b100000;
        5'd6:led<=16'b1000000;
        5'd7:led<=16'b10000000;
        5'd8:led<=16'b100000000;
        5'd9:led<=16'b1000000000;
        5'd10:led<=16'b10000000000;
        5'd11:led<=16'b100000000000;
        5'd12:led<=16'b1000000000000;
        5'd13:led<=16'b10000000000000;
        5'd14:led<=16'b100000000000000;
        5'd15:led<=16'b1000000000000000;
        default:led<=16'b0;
      endcase
    end 
endmodule
