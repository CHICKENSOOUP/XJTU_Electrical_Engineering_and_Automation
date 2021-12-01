`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/03/31 08:39:52
// Design Name: 
// Module Name: uart_tx
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
//���ڷ���ģ�����
module uart_tx(
    input [7:0] data_o,
    output reg txd,
    input clk,
    input receive_ack
    );
//���ڷ���״̬����Ϊ�ĸ�״̬���ȴ���������ʼλ���������ݡ��������
    localparam IDLE = 0,
               SEND_START = 1,
               SEND_DATA = 2,
               SEND_END = 3;
    
    reg [3:0] current_state, next_state;
    reg [4:0] count;
    reg [7:0] data_o_tmp;
    
    always @(posedge clk)
        current_state <= next_state;
    
    always @(*)
    begin
//        next_state<=current_state;           //����������߼���ʹ�÷�������ֵ    
        next_state = current_state;
        case (current_state)
            IDLE: if (receive_ack) next_state = SEND_START;
            SEND_START: next_state = SEND_DATA;
            SEND_DATA: if (count == 7) next_state = SEND_END;
            SEND_END: if (receive_ack) next_state = SEND_START;
            default: next_state = IDLE;
        endcase
    end
    
    always @(posedge clk)
    begin
        if (current_state == SEND_DATA)
            count <= count + 1;
        else if (current_state == IDLE | current_state == SEND_END)
            count <= 0;
    end
    
    always @(posedge clk)
        if (current_state == SEND_START)
            data_o_tmp <= data_o;
        else if (current_state == SEND_DATA)
            data_o_tmp[6:0] <= data_o_tmp[7:1];         //��Ҫ���͵�����λ���� data_o_tmp[0]
    
    always @(posedge clk)
        if (current_state == SEND_START)
            txd <= 0;                                   //������ʼλ
        else if (current_state == SEND_DATA)
            txd <= data_o_tmp[0];                       //�������ݵ�λ���ȣ���λ�ں�
        else if (current_state == SEND_END)
            txd <= 1;                                    //����ֹͣλ
endmodule
