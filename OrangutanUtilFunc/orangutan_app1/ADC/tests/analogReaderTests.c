#include "analogReaderTests.h"
#include "../analogReader.h"
#include "../../serial/serial.h"
#include <pololu/orangutan.h>
#include <pololu/OrangutanAnalog.h>

void read_sensor();

void run_analog_reader_tests(){
	
	read_sensor("Trimpot: ", TRIMPOT);
	delay_ms(1000);
	read_sensor("IR: ", PC0);
	delay_ms(1000);
}

void read_sensor(char* message, int channel){
	int irValue;
	irValue = analog_reader_get_value_from_channel(channel);
	serial_send_string(message);
	serial_send_number(irValue);
	serial_send_string("\r\n");
}

