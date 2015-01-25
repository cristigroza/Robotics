#ifndef INIT_SERIAL
#define INIT_SERIAL

void init_serial();
void serial_send_char(char message);
void serial_send_string( char* message);
void serial_send_number(int num);
#endif