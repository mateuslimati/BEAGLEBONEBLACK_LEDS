#include "gpioFunc.h"

void initGpio(int gpio){

	FILE* fp= NULL;

	fp = fopen("/sys/class/gpio/export", "w");
	fprintf(fp, "%d", gpio);
	fclose(fp);

}

void releaseGpio(int gpio){

	FILE* fp= NULL;

	fp = fopen("/sys/class/gpio/unexport", "w");
	fprintf(fp, "%d", gpio);
	fclose(fp);

}

void gpio_set_dir(int gpio, int out_flag){
	

	char path[100];
	
	FILE* fp= NULL;
	sprintf(path,"/sys/class/gpio/gpio%d/direction", gpio);
	fp = fopen(path,"w");

	if (out_flag == 0 ){
		
		fprintf(fp, "out");
		fclose(fp);

	}
	else if (out_flag == 1){
		
		fprintf(fp, "in");
		fclose(fp);

	}	
    
}


void gpio_set_value(int gpio, int value){

	char path[40];
	FILE* fp= NULL;

	sprintf(path,"/sys/class/gpio/gpio%d/value", gpio);
	fp = fopen(path,"w");

	fprintf(fp, "%d", value);
	fclose(fp);

}

void InverteState(int time, int gpio){
	
	int i;
	for( i = 0; i < 2; i++){

		gpio_set_value(gpio, i);
		usleep(time);

	}
	
	gpio_set_value(gpio, 0);
	usleep(time);

}


