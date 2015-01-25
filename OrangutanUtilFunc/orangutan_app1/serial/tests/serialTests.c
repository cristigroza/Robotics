#include "serialTests.h"
#include "../serial.h"
#include <pololu/orangutan.h>

void write_chars_on_serial();
void write_string_on_serial();
void write_num_on_serial();

void run_serial_tests(){
	write_chars_on_serial();
	write_string_on_serial();
	write_num_on_serial();
}

void write_num_on_serial(){
	serial_send_number(100);
}
void write_string_on_serial(){
	char *merge="Merge\r\n";
	serial_send_string(merge);
	delay_ms(10);
}
void write_chars_on_serial(){
	
	serial_send_char('\r');
	serial_send_char('\n');
	
	serial_send_char('t');
	delay_ms(1000);
	serial_send_char('e');
	delay_ms(1000);
	serial_send_char('s');
	delay_ms(1000);
	serial_send_char('t');
	delay_ms(1000);
	
	serial_send_char('\r');
	serial_send_char('\n');
	delay_ms(1000);
}