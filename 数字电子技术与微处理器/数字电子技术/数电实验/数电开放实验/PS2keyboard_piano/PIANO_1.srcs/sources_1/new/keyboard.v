`timescale 1ns / 1ps
//�������ģ��
module keyboard(
  input clk_100,//����ʱ��100HZ
  input [3:0] col,//���ź�
  output reg [3:0] row_scan,//��ɨ���ź�
  output reg [4:0] key_value//��ֵ����޺�
    );
   
 
  wire key_pressed;//0Ϊ�м�����
  wire [7:0] data;//��������״̬����
  reg [3:0] col_filter;//ȥ��������ź�
  assign data={row_scan[3:0],col_filter[3:0]};
  assign key_pressed=col_filter[3]&col_filter[2]&col_filter[1]&col_filter[0];//���źŵĹ���
  //�Ĵ��������ĳ�ʼ��
  initial
    begin
      col_filter<=4'b1111;//��ʼ��Ϊ�޼�����
      row_scan<=4'b1111;//��ʼ����ɨ��
      key_value<=5'd22;//��ʼ��Ϊ��Ч��ֵ     
    end
      
  //����ɨ��ģ��(ȥ��)
  //���ź�ȥ��
  always @(posedge clk_100)
    begin
      col_filter<=col;    
    end
  //��ɨ��  
  always @(negedge clk_100)
    begin
      if(key_pressed)
        begin
          case(row_scan)
            4'b1110:row_scan<=4'b1101;
            4'b1101:row_scan<=4'b1011;
            4'b1011:row_scan<=4'b0111;
            4'b0111:row_scan<=4'b1110;
            default:row_scan<=4'b1110;
          endcase
        end
    end
    
  //��ֵ����ģ��
  always @(posedge clk_100)
    begin
      case(data)
        8'b1110_1110:key_value<=5'd0;
        8'b1110_1101:key_value<=5'd1;
        8'b1110_1011:key_value<=5'd2;
        8'b1110_0111:key_value<=5'd3;
        8'b1101_1110:key_value<=5'd4;
        8'b1101_1101:key_value<=5'd5;
        8'b1101_1011:key_value<=5'd6;
        8'b1101_0111:key_value<=5'd7;
        8'b1011_1110:key_value<=5'd8;
        8'b1011_1101:key_value<=5'd9;
        8'b1011_1011:key_value<=5'd10;
        8'b1011_0111:key_value<=5'd11;
        8'b0111_1110:key_value<=5'd12;
        8'b0111_1101:key_value<=5'd13;
        8'b0111_1011:key_value<=5'd14;
        8'b0111_0111:key_value<=5'd15;
        default:key_value<=5'd22;
      endcase
    end
endmodule
