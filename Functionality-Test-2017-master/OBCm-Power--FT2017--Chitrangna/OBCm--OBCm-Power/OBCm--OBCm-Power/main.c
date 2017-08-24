/*
 * OBCm--OBCm-Power.c
 *
 * Created: 01-08-2017 21:45:03
 * Author : Chitrangna Bhatt
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "common.h"
#include "timer.h"
#include "uart.h"
#include "spi.h"
#include "i2c.h"
#include "led_tests.h"


int main(void)
{
	// Initializations 
	init_UART0();
	TWI_init_master();
	// Variables 
	
	
	//sei();
	
    while (1) 
    {
		// Loop 
		led_test_m_config();
		led_test_m_a();
		led_test_m_b();
		led_test_m_c();
		led_test_m_d();
		led_test_m_e();
		led_test_m_f();
		led_test_m_g();
		led_test_m_h();
		
		//uint8_t data= 0xFF;
		uint8_t data=receive_UART0();
		TWI_start();
		TWI_write_address(0x20);
		TWI_write_data(data);
		_delay_ms(100);
		TWI_stop();
    }
}

