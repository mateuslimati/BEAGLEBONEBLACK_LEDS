#include "gpioFunc.h"

void initGpio(int gpio){

	char set_value[3]; 
	FILE* fp= NULL;

	fp = fopen("/sys/class/gpio/export", "w");
	sprintf(set_value,"%d",gpio);
	fprintf(fp, set_value);
	fclose(fp);

}

void releaseGpio(int gpio){

	char set_value[3]; 
	FILE* fp= NULL;

	fp = fopen("/sys/class/gpio/unexport", "w");
	sprintf(set_value,"%d",gpio);
	fprintf(fp, set_value);
	fclose(fp);

}

void gpio_set_dir(int gpio, int out_flag){
	
	char set_value_out[] = "out";
	char set_value_in[] = "in";
	char out[3], path[100];
	
	FILE* fp= NULL;
	sprintf(path,"/sys/class/gpio/gpio%d/direction", gpio);
	fp = fopen(path,"w");

	if (out_flag == 0 ){
		
		fprintf(fp, set_value_out);
		fclose(fp);

	}
	else if (out_flag == 1){
		
		fprintf(fp, set_value_in);
		fclose(fp);

	}	
    
}


void gpio_set_value(int gpio, int value){

	char set_value[3]; 
	char path[40];
	FILE* fp= NULL;

	sprintf(path,"/sys/class/gpio/gpio%d/value", gpio);
	fp = fopen(path,"w");

	sprintf(set_value,"%d",value);
	fprintf(fp, set_value);
	fclose(fp);

}


