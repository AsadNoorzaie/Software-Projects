#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
};

struct Node* InsertNode(struct Node *, int);
void printLL(struct Node *);
void freeevery(struct Node *);
struct Node* DeleteNode(struct Node *, int);

int main(int argc, char** argv){
	FILE* file = fopen(argv[1],"r");
	if (file==NULL) 
	{ 
		printf("error\n"); 
		return 0; 
	}
	char op;
	int value;
	struct Node *head = NULL;
	
	while(fscanf(file, "%c %d\n", &op, &value) == 2){
		
		if(op == 'i'){
			head = InsertNode(head, value);
		}
		else{
			head = DeleteNode(head, value);
		}
	}
	fclose(file);
	printLL(head);
	//freeevery(head);
	return 0;

}

struct Node* DeleteNode(struct Node *head, int target){
	if(head == NULL)
		return head;
	struct Node *ptr = head;
	struct Node *lag_ptr = NULL;
	while(ptr != NULL){
		if(ptr->value == target)
			break;
		lag_ptr = ptr;
		ptr = ptr->next;
	}

	// target not found, return head
	if(ptr == NULL)
		return head;

	// delete head
	if(lag_ptr == NULL){
		struct Node *temp = head;
		head = head->next;
		temp->next = NULL;
		free(temp);
		return head;
	}
	// set lag_ptr next to ptr->next
	struct Node *temp = ptr;
	lag_ptr->next = ptr->next;
	temp->next = NULL;
	free(temp);
	return head;
}

void freeevery(struct Node *head){
	struct Node * lag_ptr = NULL;
	struct Node * ptr = head;
	while(ptr!=NULL){
		lag_ptr = ptr;
		ptr = ptr->next;
		free(lag_ptr);
	}
	return;
}
struct Node* InsertNode(struct Node *head, int value){
	// First check if ptr is NULL, if yes then create L.L
	if(head == NULL){
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->value = value;
		temp->next = NULL;
		head = temp;
		//head->value = value;
		//printf("test %d\n", head->value);
		return head;
	}
	struct Node *ptr = head;
	// First check if it exists in Linked List, if exists then return head
	while(ptr != NULL){
		if(ptr->value == value){
			return head;
		}
		ptr = ptr->next;
	}
	ptr = head;
	struct Node *lag_ptr = NULL;
	while(ptr!=NULL && ptr->value < value){
		lag_ptr = ptr;
		ptr = ptr->next;
	}
	/* Three edge cases: 1) lag_ptr is NULL: insert at head 2) Ptr is NULL: insert at end
	   3) lag_ptr is not NULL so insert in middle
	*/
	if(lag_ptr == NULL){
		struct Node *new_head = (struct Node *)malloc(sizeof(struct Node));
		new_head->value = value;
		new_head->next = head;
		head = new_head;
		return head;
	}
	if(ptr == NULL){
		//struct Node *last_node = (struct Node *)malloc(sizeof(struct Node));
		ptr = (struct Node *)malloc(sizeof(struct Node));
		ptr->value = value;
		ptr->next = NULL;
		//last_node->value = value;
		lag_ptr->next = ptr;

		//ptr = head;
		return head;
	}
	else{
		struct Node *middle_node = (struct Node *)malloc(sizeof(struct Node));
		middle_node->value = value;
		middle_node->next = ptr;
		lag_ptr->next = middle_node;
		return head;
	}

}

void printLL(struct Node *head){
	int total = 0;
	struct Node *ptr = head;
	while(ptr != NULL){
		total ++;
		ptr = ptr->next;
	}
	if(total == 0){
		printf("0\n");
		return;
	}
	printf("%d\n", total);
	ptr = head;
	while(ptr != NULL){
		printf("%d", ptr->value);
		ptr = ptr->next;
		if(ptr == NULL){
			break;
		}
		printf("\t");

	}
	printf("\n");

}

