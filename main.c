#include <stdio.h>

#define M_PI 3.14159265358979323846
#define T_PI 180

#define ERROR -32768

float my_sin(float x);

float my_cos(float x);

float my_tan(float x);

float my_cot(float x);

float my_sec(float x);

float my_csc(float x);

float my_power(float x, int y);

unsigned int my_factorial(int number);

int main() {
	while(1){
		printf("1 --> sin\n");
		printf("2 --> cos\n");
		printf("3 --> tan\n");
		printf("4 --> cot\n");
		printf("5 --> sec\n");
		printf("6 --> csc\n");
	
		int order=0;
		float angle=-1;
	
		while(order < 1 || order > 6){
			printf("\nPlease enter the number of the function you want --> ");
			scanf("%d", &order);	
		}
		
		while(angle < 0){
			printf("\nPlese enter the angle you wish to calculate --> ");
			scanf("%f", &angle);	
		}
	
		switch(order){
			case 1:
				printf("\nsin(%g) = %g\n\n",angle,my_sin(angle));
				break;
			case 2:
				printf("\ncos(%g) = %g\n\n",angle,my_cos(angle));
				break;
			case 3:
				if(my_tan(angle) != ERROR)
					printf("\ntan(%g) = %g\n\n",angle,my_tan(angle));	
				else
					printf("\ntan(%g) = undefined\n\n",angle);
				break;
			case 4:
				if(my_cot(angle) != ERROR)
					printf("\ncot(%g) = %g\n\n",angle,my_cot(angle));	
				else
					printf("\ncot(%g) = undefined\n\n",angle);
				break;
			case 5:
				if(my_sec(angle) != ERROR)
					printf("\nsec(%g) = %g\n\n",angle,my_sec(angle));	
				else
					printf("\nsec(%g) = undefined\n\n",angle);
				break;
			case 6:
				if(my_csc(angle) != ERROR)
					printf("\ncsc(%g) = %g\n\n",angle,my_csc(angle));	
				else
					printf("\ncsc(%g) = undefined\n\n",angle);
				break;
		}
	}
	
	return 0;
}

float my_sin(float x){
	if(x > (T_PI/2)){
		int y = x / (T_PI/2);
		float z = x-(y*(T_PI/2));
		
		if(y > 4)
			y %= 4;	
		
		switch(y){
			case 1:
				// sin(pi/2 + angle)
				return my_cos(z);
			case 2:
				// sin(pi + angle)
				return -my_sin(z);
			case 3:
				// sin(3pi/2 + angle)
				return -my_cos(z);
			case 4:
				// sin(2pi + angle)
				return my_sin(z);
		}
	}else {
		float angle = (x*M_PI)/T_PI;
		float result = 0;
		int n=0;
		int loopCount=17;
	
		for(; n<loopCount; n++){
			float factor = 2*n+1;	
			result += (my_power(-1,n)*my_power(angle, factor))/(my_factorial(factor));
		}
		
		if(result >= 0.999f)
			return 1;
		else if(result <= 0.001f)
			return 0;
		else
			return result;	
	}
}

float my_cos(float x){
	if(x > (T_PI/2)){
		int y = x / (T_PI/2);
		float z = x-(y*(T_PI/2));
		
		switch(y){
			case 1:
				// cos(pi/2 + angle)
				return -my_sin(z);
			case 2:
				// cos(pi + angle)
				return -my_cos(z);
			case 3:
				// cos(3pi/2 + angle)
				return my_sin(z);
			case 4:
				// cos(2pi + angle)
				return my_cos(z);
		}
	}else {
		float angle = (x*M_PI)/T_PI;
		float result = 0;
		int n=0;
		int loopCount=17;
	
		for(; n<loopCount; n++){
			float factor = 2*n;	
			result += (my_power(-1,n)*my_power(angle, factor))/(my_factorial(factor));
		}
		
		if(result >= 0.999f)
			return 1;
		else if(result <= 0.001f)
			return 0;
		else
			return result;
	}
}

float my_tan(float x){
	if(my_cos(x) == 0)
		return ERROR;
	else
		return my_sin(x)/my_cos(x);
}

float my_cot(float x){
	if(my_sin(x) == 0)
		return ERROR;
	else
		return my_cos(x)/my_sin(x);
}

float my_sec(float x){
	if(my_cos(x) == 0)
		return ERROR;
	else
		return 1/my_cos(x);
}

float my_csc(float x){
	if(my_sin(x) == 0)
		return ERROR;
	else
		return 1/my_sin(x);
}

float my_power(float x, int y){
	if(y >= 0){
		int i=0;
		float newNum=1;
		for(; i<y; i++){
			newNum *= x;
		}
		return newNum;	
	}else {
		return -1;
	}
}

unsigned int my_factorial(int number){
	if(number >= 0){
		int i=2;
		unsigned int newNum=1;
		for(; i<=number; i++){
			newNum*=i;
		}
		return newNum;
	}else
		return -1;
}
