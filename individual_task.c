#include <stdio.h>
#include <stdlib.h>

struct list{
	void *ptr;
	struct list *next;
};

int main(){
	FILE *fptr;
	fptr = fopen("datafile.txt", "w");
	if(fptr == NULL){
		printf("Error opening file!\n");
		return 1;
	}

	struct list *head = NULL, *current;
	size_t step = 1024; //1 kb
	size_t successful_allocations = 0;

	while(1){
		void *ptr = malloc(step);
		if(ptr == NULL){
			printf("Allocation error!\n");
			break;
		}
	
		struct list *new_node = malloc(sizeof(struct list));
		if(new_node == NULL){
			free(ptr);
			printf("Allocation error for list node!\n");
			break;
		}

		new_node->ptr = ptr;
		new_node->next = head;
		head = new_node;

		successful_allocations++;
		fprintf(fptr,"%zu\n", successful_allocations*1024);

	}

	current = head;
	while(current != NULL){
		free(current->ptr);
		struct list *temp = current;
		current = current->next;
		free(temp);

	}
	
	fclose(fptr);
	printf("Max size of heap segment: %zu Kb\n", successful_allocations*step/1024);

	return 0;

}
