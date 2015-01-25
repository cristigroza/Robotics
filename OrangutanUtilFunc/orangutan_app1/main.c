#include <pololu/orangutan.h>
#include "serial/serial.h"

void test_char();
void test_string();
void test_num();
int main()
{
	init_serial();
	while(1)
	{
		test_char();
		//test_string();
		//test_num();
	}
	return 0;
}

void test_num(){
	serial_send_number(100);
}
void test_string(){
	char *merge="Merge\r\n";
	serial_send_string(merge);
}
void test_char(){
	//serial_send_char('\r');
	//serial_send_char('\n');
	serial_send_char('t');
	delay_ms(1000);
	//serial_send_char('e');
	//delay_ms(1000);
	//serial_send_char('s');
	//delay_ms(1000);
	//serial_send_char('t');
	//delay_ms(1000);
	
	//log_char('\r');
	//log_char('\n');
	//delay_ms(1000);
}