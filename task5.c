#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MSG "In function %20s; &localvar = %p\n"

static void bar_is_now_closed(void){
	int localvar = 5;
	printf(MSG, __FUNCTION__, &localvar);
	printf("\nNow blocking on pause()...\n");

	pause();
}

static void bar(void){
	int localvar = 5;
	printf(MSG, __FUNCTION__,&localvar);
	bar_is_now_closed();
}

static void foo(){
	int localvar = 5;
	printf(MSG,__FUNCTION__,&localvar);
	bar();

}


int main(){
	int localvar = 5;
	printf(MSG,__FUNCTION__,&localvar);
	foo();
	exit(EXIT_SUCCESS);

}

