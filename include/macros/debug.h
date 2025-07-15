#pragma once

void panic(const char* ret_info);

#define ASSERT(expr, ret_info) \
  do { \
    if (!(expr)) { \
      panic(ret_info); \
    } \
  } while(0)

#define ASSERT_NOT_NULL(ptr, ret_info) ASSERT((ptr) != NULL, ret_info)
#define ASSERT_NOT_ZERO(val, ret_info) ASSERT((val) != 0, ret_info)
