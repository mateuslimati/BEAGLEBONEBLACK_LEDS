#include<stdio.h>
#include<unistd.h>

void InverteState(int time){

	FILE* gpioVal101;

	int i;
	for( i = 0; i < 2; i++){

		gpioVal101 = fopen("/sys/class/gpio/gpio60/value", "w");				
		fprintf(gpioVal101, "%d", i);
		fclose(gpioVal101);
		usleep(time);

	}

	gpioVal101 = fopen("/sys/class/gpio/gpio60/value", "w");				
	fprintf(gpioVal101, "0");
	fclose(gpioVal101);
	usleep(time);

}

void iniGPIO(){

	FILE* fl = NULL;
	fl = fopen("/sys/class/gpio/export", "w");
	fprintf(fl, "60");
	fclose(fl);
}

void direction(){

	FILE* gpioDir60 = NULL;
	gpioDir60 = fopen("/sys/class/gpio/gpio60/direction", "w");
	fprintf(gpioDir60, "out");
	fclose(gpioDir60);
	
}
