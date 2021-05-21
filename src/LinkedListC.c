/*
	A version of the linked list but in C
 */

#include <stdio.h>
#include <stdlib.h>

//node used for data
typedef struct node{
	struct node* next;
	int data;
}node;

void push_back(node** h, int d); //inserts data at the end, where h is head and d is data
void print_list(node* h); //prints out the entire linked list to terminal, where h is head
unsigned int list_size(node* h); //returns the size of the linked list as unsigned int, where h is head
void clear_list(node** h); //empties the list and nullifies it, where h is head
void remove_at(node** h, unsigned int _at); //removes node at _at, where h is head
int get_at(node* h, unsigned int _at); //retrieves the value at _at, where h is head

int main(void) {
	const unsigned int val_at = 2; //where we will retrieve data at
	node* head = NULL; //main linked list
	//populate linked list with some data
	push_back(&head, 10);
	push_back(&head, 15);
	push_back(&head, 20);
	push_back(&head, 25);
	push_back(&head, 30);
	push_back(&head, 35);
	puts("Data in the list:");
	puts("==============");
	print_list(head);			//print the linked list to the terminal
	puts("==============");
	puts("Size of list:");
	puts("==============");
	printf("%u\n", list_size(head)); //print the size of the linked list
	puts("==============");
	puts("Removing node from list.");
	puts("==============");
	remove_at(&head, 3);			//remove the third node of the linked list
	print_list(head);				//print the linked list
	puts("==============");
	printf("Value at %u is:\n", val_at);
	puts("==============");
	printf("%u\n", get_at(head,val_at));	//remove the node at val_at
	puts("==============");
	clear_list(&head);				//delete the entire linked list

	return EXIT_SUCCESS;
}//main

void push_back(node** h, int d){
	//first, determine if the head is null
	if (*h == NULL){ //if the head is null...
		//populate the head with a new node
		(*h) = (node*) malloc(sizeof(node));
		(*h)->data = d;
		(*h)->next = NULL;
	}//if
	else{	//if the head has data in it...
		//iterate until we can't find another node at the end
		node* temp = (*h); //traversal node uses head to traverse
		while (temp->next != NULL){ //go to the next node in the list until we can't find the end
			temp = temp->next;
		}
		//now at the end of the list, just give the last node data
		temp->next = (node*) malloc(sizeof(node));
		temp->next->data = d;
		temp->next->next = NULL;
	}//else
}//push_back

void print_list(node* h){
	node* temp = h;					//traversal node
	while(temp != NULL){			//iterate through each node in the list
		printf("%i\n", temp->data);	//print the data in each populated node
		temp = temp->next;			//go to the next node
	}//while
}//print_list

unsigned int list_size(node* h){
	node* temp = h;					//traversal node
	unsigned int counter = 0;		//user counter variable to keep track of size
	while(temp != NULL){			//iterate through each node in the list
		++counter;					//iterate the counter variable
		temp = temp->next;			//go to the next node
	}//while
	return counter;					//return the length as unsigned int
}//list_size

void clear_list(node** h){
	node* temp = NULL; //the temp references the head for deletion
	while ((*h)!=NULL){	//while the head is not null...
		temp = (*h);		//save reference to head in temp
		(*h) = (*h)->next;	//iterate head forward once
		free(temp);			//free the reference to the head
		temp = NULL;		//nullify the head
	}//while
	(*h) = NULL;			//make sure the head is null before exiting

}//clear_list

void remove_at(node** h, unsigned int _at){
	if (_at < list_size(*h)){	//if our _at value is within range...
		node* temp = (*h);		//create a temp node for traversal/deletion
		if (_at == 0){			//if the position we're popping is 0...
			(*h) = (*h)->next;	//iterate the head once
			free(temp);			//free temp, as it references the old head
			return;				//break from the function
		}//if

		node* prev = temp;		//create a node to keep track of the previous node
		for (unsigned int i = 0; i < _at;++i){ //iterate to _at
			prev = temp;		//previous node captures current node
			temp = temp->next;	//current node becomes next node
		}//while
		prev->next = temp->next;//the previous node's next becomes the next' node's next
		free(temp);				//free the current node
	}//if
}//remove_at

int get_at(node* h, unsigned int _at){
	if (_at < list_size(h)){	//if our _at value is within range...
		node* temp = h;			//create a temp node for traversal

		for (unsigned int i = 0; i < _at;++i){ //iterate to _at
			temp = temp->next;	//current node becomes next node
		}//while
		return temp->data;		//return data at the node we're at
	}//if
	return -1;					//return highest possible int value as an error
}//get_at





