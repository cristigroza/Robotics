#include <pololu/orangutan.h>
#include "../serial/serial.h"

#include "digital_IO.h"

void init_digital_IO(){
	init_serial();
	set_digital_input(IO_B0,HIGH_IMPEDANCE); 
}

void test_if_pin_B0_is_high_and_send_on_uart(){
	
	if(is_digital_input_high(IO_B0))
	{
		serial_send_string("H\r\n");
	}
	else{
		serial_send_string("L\r\n");
	}
	delay_ms(1000);
	
}