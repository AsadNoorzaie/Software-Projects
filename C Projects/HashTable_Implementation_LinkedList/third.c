#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node * next;
};

#define BUCKETS 10000
struct Node * hashtable[BUCKETS]; // a double pointer that points to a struct Node but since we gave it a size [BUCKETS] there are 10000 memory slots for it

int SearchValue(struct Node *, int);
struct Node * InsertValue(struct Node *, int, int);
void printLL(struct Node *);


int main(int argc, char ** argv){
	FILE* file = fopen(argv[1],"r");
	if (file==NULL) 
	{ 
		return 0; 
	}
	char op;
	int value;
	
	int count = 0;
	while(count < BUCKETS){
		hashtable[count] = NULL;
		count = count + 1;
	}
	struct Node *head = NULL;
	int key;
	int found;
	while(fscanf(file, "%c %d\n", &op, &value) == 2){
		//printf("%c %d\n", op, value);
		if (op == 'i'){
			// you want to insert into the hashtable if it does not already exist
			//Grab the respective linked list by doing modulo
			key = value % BUCKETS;
			key = abs(key);
			head = hashtable[key];
			head = InsertValue(head, value, key);
		}
		else{
			// you want to search if value is present in LL
			key = value % BUCKETS;
			key = abs(key);
			head = hashtable[key];
			found = SearchValue(head, value);
			if(found == 1){
				printf("present\n");
				continue;
			}
			else{
				printf("absent\n");
				continue;
			}
		}
	}
	return 0;

}

int SearchValue(struct Node *head, int data){
	if(head == NULL){
		return 0;
	}
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->data == data){
			return 1;
		}
		temp = temp->next;
	}
	
	return 0;
}


struct Node* InsertValue(struct Node *head, int data, int key){

	if(head == NULL){
		head = (struct Node *)malloc(sizeof(struct Node));
		head->data = data;
		head->next = NULL;
		hashtable[key] = head;
		printf("inserted\n");
		return head;
	}

	// check if the data already exists in the linked list
	struct Node *ptr = head;
	while(ptr!=NULL){
		if(ptr->data == data){
			printf("duplicate\n");
			return head;
		}
		ptr = ptr->next;
	}

	ptr = head;
	// insert in the beginning of the Linked List
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	hashtable[key] = head;
	printf("inserted\n");
	return head;
}


void printLL(struct Node *head){
	struct Node *ptr = head;
	while(ptr != NULL){
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

}

