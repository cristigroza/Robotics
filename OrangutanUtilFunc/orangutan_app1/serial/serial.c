#include "serial.h"
#include <pololu/orangutan.h>
#include "../util/util.h"

char is_serial_init = 0;
char receive_buffer[32];
unsigned char receive_buffer_position = 0;
char send_buffer[32];

void wait_for_sending_to_finish()
{
	while(!serial_send_buffer_empty());
}

void init_serial(){
	if (!is_serial_init)
	{
		is_serial_init = 1;
		serial_set_baud_rate(9600);
		serial_receive_ring(receive_buffer, sizeof(receive_buffer));
	}
}



void serial_send_string(char *str)
{
	while (*str != 0x00)
	{
		serial_send_char(*str);
		str++;
	}
}


void serial_send_char(char ms_char){
	if (is_serial_init)
	{
		send_buffer[0] = ms_char;
		serial_send(send_buffer,1);
		wait_for_sending_to_finish();
	}
}

void serial_send_number(int num){
	if (is_serial_init)
	{
		char aux[32];
		itoa_c(num,aux);
		serial_send_string(aux);
	}
}

