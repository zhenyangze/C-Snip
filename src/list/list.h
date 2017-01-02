/**
* File Name: src/list/list.h
* Author: zhenyangze
* Mail: zhenyangze@gmail.com 
* Created Time: 一  1/ 2 11:21:22 2017
*/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

enum LIST_CODE { 
    OK = 0,
    ERROR = 1,
};

struct list_node {
    void *data;
    struct list_node *prev;
    struct list_node *next;
};

struct list {
    struct list_node *head;
    struct list_node *tail;
    int len;
};

struct list_iter {
    struct list_node *node;
    struct list  *list;
};


struct list_node *list_node_new(void *data);
void list_node_free(struct list_node *node);

struct list *list_new(void);
void list_clear(struct list *list);
void list_free(struct list *list);
int list_len(struct list *list);

int list_rpush(struct list *list, void *data);
//int list_lpush(struct list *list, void *data);

//void *list_rpop(struct list *list);
void *list_lpop(struct list *list);

void *list_head(struct list *list);
void *list_tail(struct list *list);

//struct list_iter *list_iter_new(struct list *list);
//struct list_iter *list_iter_free(struct list_iter *list_iter);

//void *list_iter_prev(struct list_iter *list_iter);
//void *list_iter_next(struct list_iter *list_iter);

#endif /* ifndef __LIST_H__ */  
