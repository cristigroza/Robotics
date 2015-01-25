#define ANALOG_READER
#ifndef ANALOG_READER

void init_analog_reader();
int analog_reader_get_value_from_channel(unsigned char channel);
#endif