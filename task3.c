#include <stdio.h>

int global_var = 10;

void func(){
	int local_var = 100;
	int large_array[1000];

	printf("Addres of local var: %p\n", &local_var);
	printf("Addres of large array: %p\n", &large_array);
}


int main(){
	int i;
	printf("The stack top is near %p\n", &i);
	
	printf("Addres of global var: %p\n", &global_var);

	func();
	return 0;
}
