`timescale 1ns / 1ps
//ps2����
module ps2_keyboard(
    input rst,//��λ��
    input ps2_clk,//����ʱ����
    input ps2_data,//����������
    input sys_clk,//FPGAʱ��
    output reg[4:0] key_out//��ֵ���
    );
    
    reg [1:0] key_loosen;//1��2��ʾ�������ɿ���0��ʾ������
    reg PS2CF,PS2DF;//�˲���ļ���ʱ�Ӻ�����
    reg [7:0] ps2c_filter,ps2d_filter;//����ʱ�Ӻ������˲���
    reg [7:0] data_temp;//��ǰ���ܵ�����
    reg [3:0] num;//��λ����
    reg [7:0] key_value;//��Ч��ֵ   
    reg [1:0] error;//1��2��3Ϊ���̷�����������
    wire flag;//1Ϊ����ʱ�������ر��
    
    assign flag=(ps2c_filter[1])&(~ps2c_filter[0]);
    //�Ĵ������ͱ�����ʼ��
    initial
      begin
        key_out<=5'd22;//��ʼ��Ϊ��Ч��ֵ
        key_loosen<=1'b0;//��ʼ��Ϊ��������
        PS2CF<=1'b1;
        PS2DF<=1'b1;
        ps2c_filter<=8'b11111111;
        ps2d_filter<=8'b11111111;
        data_temp<=8'b00000000;     
        num<=4'b0;
        key_value<=5'd0;
        error<=1'b0;//��ʼ��Ϊ�����ݴ���      
      end
      
   //����ʱ�Ӻ������˲�
    always @(posedge sys_clk or posedge rst)
      begin
        if(rst==0)
          begin    
            ps2c_filter<=8'b11111111;
            ps2d_filter<=8'b11111111;
            PS2CF<=0;
            PS2DF<=0;
          end
        else 
          begin
            ps2c_filter[7]<=ps2_clk;
            ps2c_filter[6:0]<=ps2c_filter[7:1];
            ps2d_filter[7]<=ps2_data;
            ps2d_filter[6:0]<=ps2d_filter[7:1];
            if(ps2c_filter==8'b11111111)
              begin
                PS2CF<=1;//ȥʱ��ë��
              end
            else if(ps2c_filter==8'b00000000)
              begin
                PS2CF<=0;
              end
            if(ps2d_filter==8'b11111111)
              begin
                PS2DF<=1;//ȥ����ë��
              end
            else if(ps2d_filter==8'b00000000)
              begin
                PS2DF<=0;
              end
          end
      end
    //���ݽ���  
    always @(negedge PS2CF or posedge rst)
      begin
        if(rst==0)
          begin
            num<=4'd0;
            data_temp<=8'd0;
          end
        else 
          begin
            if(num==0) 
              begin
                num<=num+1'b1;//������ʼλ
              end         
            else if(num<=8)//����λ��ֵ
              begin
                data_temp[num-1]<=PS2DF;
                num<=num+1'b1;   
              end
            else if(num==9)
              begin
                num<=num+1'b1;//����У��λ
              end
            else 
              begin
                num<=4'd0;  //ֹͣλ����         
              end
          end
      end
    //�����������£��ɿ�������ֵ���  
    always @(posedge sys_clk or posedge rst)
      begin
        if(rst==0) 
          begin
            key_loosen<=2'b0;
          end
        else if(num==4'd10)//ÿ���ܵ����������ݰ�
          begin
            if(data_temp==8'hF0)//�ж��Ƿ�Ϊ����
              begin
                if(error==1)
                  begin
                    error<=2'd2;
                  end
                else if(error==3)
                  begin
                    error<=2'd1;
                  end
                else
                  begin
                    key_loosen<=2'b1;//�����ʶ��
                  end
              end
            else
              begin
                if(key_loosen==2'b1)//�ж��Ƿ��ɿ���Ӧ����
                  begin
                    if(data_temp==key_value&&flag==1)
                      begin
                        key_loosen<=2'b0;
                        key_out<=5'd22;
                      end
                  end
               else if(key_loosen==2'b0&&flag==1&&(error==2'b00||error==2'b11))
                 begin
                   case(data_temp)//�ж��Ƿ���Ч��ֵ
                     8'h15:error=0;
                     8'h1D:error=0;
                     8'h24:error=0;
                     8'h2D:error=0;
                     8'h2C:error=0;
                     8'h35:error=0;
                     8'h3C:error=0;
                     8'h1C:error=0;
                     8'h1B:error=0;
                     8'h23:error=0;
                     8'h2B:error=0;
                     8'h34:error=0;
                     8'h33:error=0;
                     8'h3B:error=0;
                     8'h1A:error=0;
                     8'h22:error=0;
                     8'h21:error=0;
                     8'h2A:error=0;
                     8'h32:error=0;
                     8'h31:error=0;
                     8'h3A:error=0;
                     default:error=2'b01;
                   endcase
                   if(error==0)//��Ч��ֵת�����
                     begin
                       key_value=data_temp;             
                       case(key_value)
                         8'h15:key_out<=5'd0;
                         8'h1D:key_out<=5'd1;
                         8'h24:key_out<=5'd2;
                         8'h2D:key_out<=5'd3;
                         8'h2C:key_out<=5'd4;
                         8'h35:key_out<=5'd5;
                         8'h3C:key_out<=5'd6;
                         8'h1C:key_out<=5'd7;
                         8'h1B:key_out<=5'd8;
                         8'h23:key_out<=5'd9;
                         8'h2B:key_out<=5'd10;
                         8'h34:key_out<=5'd11;
                         8'h33:key_out<=5'd12;
                         8'h3B:key_out<=5'd13;
                         8'h1A:key_out<=5'd14;
                         8'h22:key_out<=5'd15;
                         8'h21:key_out<=5'd16;
                         8'h2A:key_out<=5'd17;
                         8'h32:key_out<=5'd18;
                         8'h31:key_out<=5'd19;
                         8'h3A:key_out<=5'd20;
                         default:key_out<=5'd22;
                       endcase  
                     end           
                 end
               else if(error==2'd2)
                 begin
                   error<=2'd3;
                 end
             end 
           end
      end
endmodule
    
    
    
