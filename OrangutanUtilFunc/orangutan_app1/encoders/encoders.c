#include <pololu/orangutan.h>
#include "../serial/serial.h"

#include "encoders.h"

void init_encoders(){
	
	init_serial();
	set_digital_input(IO_C0,HIGH_IMPEDANCE);
	set_digital_input(IO_C1,HIGH_IMPEDANCE);
	set_digital_input(IO_C2,HIGH_IMPEDANCE);
	set_digital_input(IO_C3,HIGH_IMPEDANCE);
	encoders_init(IO_C0, IO_C1, IO_C2, IO_C3);
}

void show_m1_encoder_value(){
	int count = 0, m1;
	for (count = 0; count<50;count++)
	{
		m1 = encoders_get_counts_m1();
		serial_send_number(count);
		serial_send_string(": ");
		serial_send_number(m1);
		serial_send_string("\r\n");
		delay_ms(1000);
	}
	
	encoders_get_counts_and_reset_m1();
}