#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	void *ptr;
	struct Node *next;
}Node;


int main(){
	size_t step = 1024*1024; // 1Mb
	size_t allocated = 0;
	void *ptr;
	Node *head = NULL, *temp;

	while((ptr = malloc(step)) != NULL) {
		memset(ptr,0,step);
		allocated+= step;
		printf("Allocated: %zu MB\n", allocated / (1024*1024));

		Node *new_node = malloc(sizeof(Node));
		if(new_node == NULL){
			printf("Failed to allocate memory for list node!\n");
			break;
		}

		new_node->ptr = ptr;
		new_node->next = head;
		head = new_node;

	}

	printf("Max heap segment size: %zu MB\n", allocated/(1024*1024));

	while(head != NULL) {
		free(head->ptr);
		temp = head;
		head = head->next;
		free(temp);
	}
	return 0;

}
