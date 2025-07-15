#include "containers/list.h"
#include <stdlib.h>

MEMIO u8 list_node_insert_next(LIST_NODE_T *self, void *data) {
  LIST_NODE_T *node;
  node = malloc(sizeof(*node));
  if (node == NULL)
    return 1;

  node->data = data;
  node->next = self->next;
  node->prev = self;

  self->next->prev = node;
  self->next = self;
  return 0;
}
MEMIO u8 list_node_remove_next(LIST_NODE_T *self, void **ret) {
  LIST_NODE_T *node;
  // ASSERT that (ret != NULL)
  *ret = self->next->data;
  node = self->next;
  node->next->prev = self;
  self->next = node->next;

  free(node);
  return 0;
}
MEMIO u8 list_node_insert_prev(LIST_NODE_T *self, void *data) {

  LIST_NODE_T *node;
  node = malloc(sizeof(*node));
  if (node == NULL)
    return 1;

  node->data = data;
  node->prev = self->prev;
  node->next = self;

  self->prev->next = node;
  self->prev = self;
  return 0;
}
MEMIO u8 list_node_remove_prev(LIST_NODE_T *self, void **ret) {
  LIST_NODE_T *node;
  // ASSERT that (ret != NULL)
  *ret = self->prev->data;
  node = self->prev;
  node->prev->next = self;
  self->prev = node->prev;

  free(node);
  return 0;
}

MEMIO u8 list_new(LIST_T **self) {
  // ASSERT that (self != NULL)
  LIST_T *list;
  list = malloc(sizeof(*list));
  if (list == NULL)
    return 1;
  list->root.size = 0;
  list->root.next = &list->root;
  list->root.prev = &list->root;
  *self = list;
  return 0;
}

MEMIO u8 list_delete(LIST_T *self) {
  LIST_NODE_T *node = self->root.next;
  while (node != &self->root) {
    LIST_NODE_T *del_node = node;
    LIST_NODE_T *next = del_node->next;
    free(del_node);
    node = next;
  }
  return 0;
}

MEMIO u8 list_insert_head(LIST_T *self, void *data);
MEMIO u8 list_remove_head(LIST_T *self, void **ret);
MEMIO u8 list_insert_tail(LIST_T *self, void *data);
MEMIO u8 list_remove_tail(LIST_T *self, void **ret);
u8 list_get_head(LIST_T *self, void **data);
u8 list_get_tail(LIST_T *self, void **data);

u8 list_is_empty(LIST_T *self);
