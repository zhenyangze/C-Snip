/**
 * File Name: src/list/list.c
 * Author: zhenyangze
 * Mail: zhenyangze@gmail.com 
 * Created Time: 一  1/ 2 11:21:08 2017
 */

#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


struct list_node *list_node_new(void *data) {
    struct list_node *node = malloc(sizeof(struct list_node));

    if (NULL != node){
        node->data = data;
        node->prev = NULL;
        node->next = NULL;
    }

    return node;
}

void list_node_free(struct list_node *node) {
    if (NULL != node) {
        free(node);
    }
}

struct list *list_new(void) {
    struct list *list = malloc(sizeof(struct list));

    if (NULL != list) {
        list->head = NULL;
        list->tail = NULL;
        list->len = 0;
    }

    return list;
}

void list_clear(struct list *list) {
    if (NULL != list) {
        while (0  != list_len(list)) {
            list_lpop(list);
        }
    }
}

void list_free(struct list *list) {
    if (NULL != list) {
        list_clear(list);
        free(list);
        list = NULL;
    }
}

int list_len(struct list *list) {
    assert(NULL != list);

    return list->len;
}

void *list_lpop(struct list *list) {
    assert(NULL != list);

    if (0 == list->len) {
        assert(NULL == list->head && NULL == list->tail);
        return NULL;
    }

    assert(NULL != list->head && NULL != list->tail);

    struct list_node *head = list->head;
    struct list_node *node = head->next;

    if (NULL == node) {
        assert(1 == list->len);
        list->tail = NULL;
    } else {
        assert(list->len >= 2);
        node->prev = NULL;
    }

    list->head = node;
    list->len -= 1;

    void *data = head->data;
    list_node_free(head);

    return data;
}

int list_rpush(struct list *list, void *data) {
    assert(NULL != list);

    struct list_node *node = list_node_new(data);

    assert(NULL != node);

    if (0 == list->len) {
        list->head = node;
        list->tail = node;
    } else {
        struct list_node *tail = list->tail;
        tail->next = node;
        node->prev = tail;
        list->tail = node;
    }
    list->len += 1;

    return list->len - 1;
}

void *list_head(struct list *list) {
    assert(NULL != list);

    if (0 == list->len) {
        assert(NULL == list->head && NULL == list->tail);
        return NULL;
    }

    assert(NULL != list->head);

    return list->head->data;
}

void *list_tail(struct list *list) {
    assert(NULL != list);

    if (0 == list->len) {
        assert(NULL == list->head && NULL == list->tail);
        return NULL;
    }

    assert(NULL != list->tail);

    return list->tail->data;
}
