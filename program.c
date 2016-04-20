#include<stdio.h>
#include"piscLed.h"

int main(){

	iniGPIO();
	direction();	

	int time;
	int i = 0;

	while(1){
		
		printf("DIGITE O TEMPO DE INVERSÃO EM us :\n");
		scanf("%d", &time);
		
		while(i < 16){

			InverteState(time);
			i++;

		}
	
		i = 0;

	}

	return 0;
}
