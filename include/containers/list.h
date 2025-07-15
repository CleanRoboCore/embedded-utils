#pragma once

#include "macros/type.h"
#include "macros/flag.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// TYPE DEF
typedef struct LIST LIST_T;
typedef struct LIST_NODE LIST_NODE_T;
typedef struct INTR_LIST INTR_LIST_T;

struct LIST_NODE {
  LIST_NODE_T *prev;
  LIST_NODE_T *next;
  union {
    void *data;
    size_t size;
  };
};
struct LIST {
  LIST_NODE_T root;
};
struct INTR_LIST {};

// FUNCTION DEF
MEMIO u8 list_node_insert_next(LIST_NODE_T *self, void *data);
MEMIO u8 list_node_remove_next(LIST_NODE_T *self, void **ret);
MEMIO u8 list_node_insert_prev(LIST_NODE_T *self, void *data);
MEMIO u8 list_node_remove_prev(LIST_NODE_T *self, void **ret);

MEMIO u8 list_new(LIST_T **self);
MEMIO u8 list_delete(LIST_T *self);

MEMIO u8 list_insert_head(LIST_T *self, void *data);
MEMIO u8 list_remove_head(LIST_T *self, void **ret);
MEMIO u8 list_insert_tail(LIST_T *self, void *data);
MEMIO u8 list_remove_tail(LIST_T *self, void **ret);
u8 list_get_head(LIST_T *self, void **data);
u8 list_get_tail(LIST_T *self, void **data);

u8 list_is_empty(LIST_T *self);

#ifdef __cplusplus
}
#endif
  
