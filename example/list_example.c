/**
* File Name: example/list_example.c
* Author: zhenyangze
* Mail: zhenyangze@gmail.com 
* Created Time: 一  1/ 2 12:20:11 2017
*/

#include <stdio.h>
#include <assert.h>

#include "list.h"

int main(int argc, char *argv[])
{
    struct list *ll = list_new();
    assert(ll != NULL);
    list_rpush(ll, "aa");
    list_rpush(ll, "bb");
    list_rpush(ll, "cc");
    list_rpush(ll, "dd");
    printf("%d\n", ll->len);

    void *data = list_lpop(ll);
    printf("%s\n", data);

    list_free(ll);
    printf("%d\n", ll->len);
    return 0;
}
