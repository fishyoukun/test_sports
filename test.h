
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef short int16_t;
typedef char int8_t;

//uint8_t config_32_from_model[32] ={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};


uint8_t config_32_to_model[32]   ={0,16,1,17,2,18,3,19,4,20,5,21,6,22,7,23,8,24,9,25,10,26,11,27,12,28,13,29,14,30,15,31};


uint8_t config_16[16] = {0,8,1,9,2,10,3,11,4,12,5,13,6,14,7,15};


#define NUM_CHANNEL (32)
#define FRAME_SIZE (32)
#define DATA_SIZE (NUM_CHANNEL * FRAME_SIZE)

uint32_t data_src[DATA_SIZE];
uint32_t data_target[DATA_SIZE];
uint32_t data_temp[DATA_SIZE];




uint8_t prepare_data(void);
uint32_t convert_model_to_sports(void* model, void* sports, uint32_t frame_size, uint8_t* config, uint32_t config_len);
uint32_t convert_sports_to_model(void* sports, void* model, uint32_t frame_size, uint8_t* config, uint32_t config_len);
uint8_t verify_data(void);


