#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>

#define INITIAL_POOL_SIZE 16  // Define initial pool size as constant

typedef struct {
    void** pools;           // Array of component type pools
    size_t* pool_sizes;     // Size of each pool
    size_t* element_sizes;  // Size of elements in each pool
    size_t type_count;      // Number of component types
} MemoryManager;

#endif // MEMORY_MANAGER_H