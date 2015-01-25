#include <pololu/orangutan.h>
#include "serial/serial.h"
#include "serial/tests/serialTests.h"
#include "digital_IO/digital_IO.h"
#include "encoders/encoders.h"



int main()
{
	init_serial();
	//init_analog_reader();
	//init_digital_IO();
	init_encoders();

	while(1)
	{
		show_m1_encoder_value();
		//test_if_pin_B0_is_high_and_send_on_uart();
		//run_serial_tests();
		//run_analog_reader_tests();
	}
	return 0;
}
