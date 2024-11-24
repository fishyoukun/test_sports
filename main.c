#include "test.h"
int main()
{
	printf("Hello world!\n");
	prepare_data();



	convert_sports_to_model(data_src, data_temp, FRAME_SIZE, config_32_to_model, NUM_CHANNEL);

	convert_model_to_sports(data_temp,data_target, FRAME_SIZE, config_32_to_model, NUM_CHANNEL);

	verify_data();



	return 0;
}

uint8_t prepare_data(void)
{
	for (int i = 0; i < DATA_SIZE; i++)
	{
		data_src[i] = i;
		data_target[i] = 0;
		if ((i % 16) == 0)
			printf("\n");
		printf("%4d ", data_src[i]);

	}

	return 0;
		
}

uint8_t verify_data(void)
{
	printf("\n=============================================================================================\n");
	for (uint32_t i = 0; i < DATA_SIZE; i++)
	{
		if ((i % 16) == 0)
			printf("\n");
		printf("%4d ", data_target[i]);

	}
	return 0;

}

/*
------------------
|     ch0 sample0
----------------
|    ch16 sample0
----------------
|     ch1 sample0 
________________ 
|	  ch17 sample0
-----------------
|
-----------------
|     ch0 sample1
----------------
|    ch16 sample1
----------------
|     ch1 sample1
________________
|    ch17 sample1
-----------------
|
-----------------
*/


uint32_t convert_model_to_sports(void* model, void* sports, uint32_t frame_size,  uint8_t* config, uint32_t config_len)
{
	uint32_t ch, slot, sample;
	uint32_t* dst;
	uint32_t* src;
	for (slot = 0; slot < config_len; slot++)
	{
		ch = (uint32_t)config[slot];
		dst = (uint32_t*)sports + slot;
		src = (uint32_t*)model + ch * frame_size;

		for (sample = 0; sample < frame_size; sample++)
		{
			*(dst + sample* config_len) = *(src + sample);
		}

	}
	

	return 0;
}

uint32_t convert_sports_to_model(void* sports, void* model, uint32_t frame_size, uint8_t* config,uint32_t config_len)
{
	uint32_t ch, slot,sample;
	uint32_t* dst;
	uint32_t* src;
	for (slot = 0; slot < config_len; slot++)
	{
		ch = (uint32_t)config[slot];
		dst = (uint32_t*)model + ch*frame_size;
		src = (uint32_t*)sports + slot;
		
		for (sample = 0; sample < frame_size; sample++)
		{
			*(dst + sample) = *(src + sample * config_len);
 		}

	}

	return 0;
}



