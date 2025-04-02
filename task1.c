#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main(){
	int bits = sizeof(time_t) * 8;
	printf("Size of time_t: %zu bytes(%d-bit)\n", sizeof(time_t), bits);
	
	if(sizeof(time_t) == 4){
		printf("32-bit system detected. time_t will overflow at: ");
	}else{
		printf("64-bit system detected. time_t overflow at: ");
	}

	time_t max_time = (time_t)((uint64_t)1 << (bits - 1)) -1; //for signed time_t
	printf("%s ", ctime(&max_time));
	return 0;

}
