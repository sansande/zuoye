#include <stdio.h>

typedef struct list_item {
		int data;
		struct list_item *next;
} list_item;

void erase_list(list_item *head) {
	list_item *current = head;
	list_item *temp;
	while (current != NULL) {
		temp = current->next;
		free(current);
		current = temp;
	}
}
int main() {
     list_item *node1 = (list_item *)malloc(sizeof(list_item));
     list_item *node2 = (list_item *)malloc(sizeof(list_item));
     list_item *node3 = (list_item *)malloc(sizeof(list_item));
     node1->data = 1;
     node1->next = node2;
     node2->data = 2;
     node2->next = node3;
     node3->data = 3;
     node3->next = NULL;
     erase_list(node1);
     return 0;
 }

		
