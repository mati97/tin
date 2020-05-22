/*
 * commands.c
 *
 *  Created on: Jun 6, 2019
 *      Author: matt
 */
#include "commands.h"





void Camera(char *args){
    if(strcmp(args, "on") == 0){
        // turn the camera on
  	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);
  	  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, 0);
  	  HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, 0);
  	  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 0);
  	  HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, 0);
    } else if(strcmp(args, "off") == 0){
        // turn the camera off
    	GPIOC->ODR = 0x7b00;
    } else {
        USART_WriteString("Unrecognized argument. Available arguments are \"on\" and \"off\"\n\r");
    }
}

void Write(char *args){
	//USART_WriteString(args);

    	int address=0;
    	int data=0;
    	sscanf(args, "%x%*c%x", &address, &data);
    	write((uint32_t)address,(uint8_t)data);

}

void Read(char *args){
//	USART_WriteString(args);

	    	int address=0;
	     	uint8_t data;
	     	char str[100];
	     	sscanf(args, "%x", &address);
	     	data = read((uint32_t)address);
	     	sprintf(str, "0x%02x\r\n", data);
	     	USART_WriteString(str);
}


void init_commands(void)
{
//***********************************************************************
	static CLI_CommandItem item_CAMERA = {.callback = Camera,
											.commandName = "camera",
											.description = NULL};
	if(CLI_AddCommand(&item_CAMERA) == false){
		USART_WriteString("ERROR in adding new item.\n\r");
	}
//***********************************************************************
	static CLI_CommandItem item_write = {.callback = Write,
											.commandName = "write",
											.description = NULL};
	if(CLI_AddCommand(&item_write) == false){
		USART_WriteString("ERROR in adding new item.\n\r");
	}
//***********************************************************************
	static CLI_CommandItem item_read = {.callback = Read,
											.commandName = "read",
											.description = NULL};
	if(CLI_AddCommand(&item_read) == false){
		USART_WriteString("ERROR in adding new item.\n\r");
	}
//***********************************************************************


}
