#include"link_list.h"
#include"error.h"

#include<stdio.h>
#include<stdlib.h>

/* single linked list */
struct LINK_LIST *init_link_list() {
	struct LINK_LIST *new_link = malloc(sizeof(struct LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->string = NULL;
	new_link->next = NULL;

	return new_link;
}

void destroy_link_list(struct LINK_LIST *link) {
	struct LINK_LIST *temp = init_link_list();
	while(link!=NULL) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next = NULL;
		temp->string = NULL;
	}
}

int is_empty(struct LINK_LIST *link) {
	if (link->next==NULL) {
		return YES;
	}
	return NO;
}

int get_length(struct LINK_LIST *link) {
	int count;
	count = 0;

	while(link->next!=NULL) {
		count += 1;
		link = link->next;
	}

	return count;
}

char *get_element(struct LINK_LIST *link, int pos) {
	int i;

	if (is_empty(link)==YES) {
		return NULL;
	}
	if (pos <= 0 || pos-1 > get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		exit(1);
	}
	else {
		for (i = 0; i < pos; ++i) {
			link = link->next;
		}
	}
	return link->string;
}

int create(struct LINK_LIST *link, char *in) {
	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		struct LINK_LIST *new_node;
		new_node = init_link_list();
		if (new_node==NULL) {
			return ERROR;
		} 
		new_node->next = link->next;
		link->next = new_node;
		new_node->string = in;
	}

	return OK;
}

int tail_create(struct LINK_LIST *link, char *in) {
	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		while (link->next!=NULL) {
			link = link->next;
		}
		struct LINK_LIST *new_node;
		new_node = init_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		link->next = new_node;
		new_node->string = in;
	}
	
	return OK;
}

int insert(struct LINK_LIST *link, int pos, char *in) {
	int i;

	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		if (pos <= 0 || pos-1 > get_length(link)) {
			fprintf(stderr, "Invalid position");
			return ERROR;
		}
		else {
			for (i = 1; i <= pos-1; ++i) {
				link = link->next;
			}
			struct LINK_LIST *new_node;
			new_node = init_link_list();
			if (new_node==NULL) {
				return ERROR;
			}
			new_node->next = link->next;
			link->next = new_node;
			new_node->string = in;
		}
	}

	return OK;
}

int del(struct LINK_LIST *link, int pos) {
	int i;

	if (is_empty(link)==YES) {
		fprintf(stderr, "Link list is empty!!!");
		return ERROR;
	}
	else {
		if (pos <= 0 || pos-1 > get_length(link))	 {
			fprintf(stderr, "Invalid position!!!");
			return ERROR;
		}
		else {
			for (i = 1; i <= pos-1; ++i) {
				link = link->next;
			}
			struct LINK_LIST *temp;
			temp = init_link_list();
			if (temp==NULL) {
				return ERROR;
			}
			temp = link->next;
			link->next = temp->next;
			free(temp);
			temp->next = NULL;
			temp->string = NULL;
		}
	}

	return OK;
}

int find(struct LINK_LIST *link, char *key) {
	int pos;
	pos = 0;

	if (is_empty(link)==YES) {
		return -1;
	}
	while(link!=NULL) {
		if (link->string==key) {
			return pos;
		}
		else {
			pos += 1;
			link = link->next;
		}
	}

	return -1;
}

char *get_next(struct LINK_LIST *link, char *key) {
	if (is_empty(link)==YES) {
		return NULL;
	}
	while(link->next!=NULL) {
		if (link->string==key) {
			return link->next->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

/* double linked list */
struct DOUBLE_LINK_LIST *init_double_link_list() {
	struct DOUBLE_LINK_LIST *new_link = malloc(sizeof(struct DOUBLE_LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->string = NULL;
	new_link->pre = NULL;
	new_link->next = NULL;

	return new_link;
}

void D_destroy_link_list(struct DOUBLE_LINK_LIST *link) {
	struct DOUBLE_LINK_LIST *temp = init_double_link_list();
	while (link!=NULL) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next = NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}
}

int D_is_empty(struct DOUBLE_LINK_LIST *link) {
	if (link->next==NULL) {
		return YES;
	}

	return NO;
}

int D_get_length(struct DOUBLE_LINK_LIST *link) {
	int count;
	count = 0;
	
	while (link->next!=NULL) {
		count += 1;
		link = link->next;
	}

	return count;
}

char *D_get_element(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;
	
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	if (pos <= 0 || pos-1 > D_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		exit(1);
	}
	else {
		for (i = 0; i < pos; ++i) {
			link = link->next;
		}
	}

	return link->string;
}

int D_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		if(new_node->next!=NULL) {
			new_node->next->pre = new_node;
		}
		new_node->string = in;
	}

	return OK;
}

int D_tail_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		while(link->next!=NULL) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		new_node->string = in;
	}

	return OK;
}

int D_insert(struct DOUBLE_LINK_LIST *link, int pos, char *in) {
	int i;

	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		if (new_node->next!=NULL) {
			new_node->next->pre = new_node;
		}
		new_node->string = in;
	}

	return OK;
}

int D_del(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;

	if (D_is_empty(link)==YES) {
		fprintf(stderr, "Double link list is empty!!!");
		return ERROR;
	}
	else {
		if (pos <=0 || pos-1 > D_get_length(link)) {
			return ERROR;
		}
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *temp;
		temp = init_double_link_list();
		if (temp==NULL) {
			return ERROR;
		}
		temp = link->next;
		link->next = temp->next;
		link->next->pre = link;
		free(temp);
		temp->next = NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}

	return 0;
}

int D_find(struct DOUBLE_LINK_LIST *link, char *key) {
	int pos;
	pos = 0;
	
	if (D_is_empty(link)==YES) {
		return -1;
	}
	while (link!=NULL) {
		if (link->string==key) {
			return pos;
		}
		else {
			link = link->next;
			pos += 1;
		}
	}

	return -1;
}

char *D_get_next(struct DOUBLE_LINK_LIST *link, char *key) {
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	while (link->next!=NULL) {
		if (link->string==key) {
			return link->next->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

char *D_get_pre(struct DOUBLE_LINK_LIST *link, char *key) {
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	while(link!=NULL) {
		if (link->string==key) {
			return link->pre->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}
