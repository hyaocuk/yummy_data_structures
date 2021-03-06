#ifndef _LINK_LIST_H
#define _LINK_LIST_H

struct LINK_LIST {
	char *string;
	struct LINK_LIST *next;
}link_list;

struct DOUBLE_LINK_LIST {
	char *string;
	struct DOUBLE_LINK_LIST *pre;
	struct DOUBLE_LINK_LIST *next;
}double_link_list, cyclic_singly_link_list, cyclic_double_link_list;

/* single linked list operations */
struct LINK_LIST *init_link_list();
void destroy_link_list(struct LINK_LIST *);
int is_empty(struct LINK_LIST *);
int get_length(struct LINK_LIST *);
char *get_element(struct LINK_LIST *, int );
int create(struct LINK_LIST *, char *);
int tail_create(struct LINK_LIST *, char *);
int insert(struct LINK_LIST *, int, char *);
int del(struct LINK_LIST *, int);
int find(struct LINK_LIST *, char *);
char *get_next(struct LINK_LIST *, char *);

/* double linked list operations */
struct DOUBLE_LINK_LIST *init_double_link_list();
void D_destroy_link_list(struct DOUBLE_LINK_LIST *);
int D_is_empty(struct DOUBLE_LINK_LIST *);
int D_get_length(struct DOUBLE_LINK_LIST *);
char *D_get_element(struct DOUBLE_LINK_LIST *, int );
int D_create(struct DOUBLE_LINK_LIST *, char *);
int D_tail_create(struct DOUBLE_LINK_LIST *, char *);
int D_insert(struct DOUBLE_LINK_LIST *, int, char *);
int D_del(struct DOUBLE_LINK_LIST *, int );
int D_find(struct DOUBLE_LINK_LIST *, char *);
char *D_get_next(struct DOUBLE_LINK_LIST *, char *);
char *D_get_pre(struct DOUBLE_LINK_LIST *, char *);

/* cyclic double linked list */
struct DOUBLE_LINK_LIST *init_cyclic_double_link_list();
void CD_destroy_link_list(struct DOUBLE_LINK_LIST *);
int CD_is_empty(struct DOUBLE_LINK_LIST *);
int CD_get_length(struct DOUBLE_LINK_LIST *);
char *CD_get_element(struct DOUBLE_LINK_LIST *, int );
int CD_create(struct DOUBLE_LINK_LIST *, char *);
int CD_tail_create(struct DOUBLE_LINK_LIST *, char *);
int CD_insert(struct DOUBLE_LINK_LIST *, int , char *);
int CD_del(struct DOUBLE_LINK_LIST *, int );
int CD_find(struct DOUBLE_LINK_LIST *, char *);
char *CD_get_next(struct DOUBLE_LINK_LIST *, char *);
char *CD_get_pre(struct DOUBLE_LINK_LIST *, char *);

/* cyclic singly linked list */
struct LINK_LIST *init_cyclic_link_list();
void CS_destroy_link_list(struct LINK_LIST *);
int CS_is_empty(struct LINK_LIST *);
int CS_get_length(struct LINK_LIST *);
char *CS_get_element(struct LINK_LIST *, int );
int CS_create(struct LINK_LIST *, char *);
int CS_tail_create(struct LINK_LIST *, char *);
int CS_insert(struct LINK_LIST *, int , char *);
int CS_del(struct LINK_LIST *, int );
int CS_find(struct LINK_LIST *, char *);
char *CS_get_next(struct LINK_LIST *, char *);

#endif
