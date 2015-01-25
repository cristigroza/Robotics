#include <pololu/OrangutanAnalog.h>

#include "analogReader.h"

void block_until_conversion_finishes();

void init_analog_reader(){
	set_analog_mode(MODE_8_BIT);
}

int analog_reader_get_value_from_channel(unsigned char channel){
	start_analog_conversion(channel);
	block_until_conversion_finishes();
	return analog_conversion_result();
}

void block_until_conversion_finishes(){
	while (analog_is_converting()){}
}