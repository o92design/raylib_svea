#include "systems/memory_system.h"

#include <stdlib.h>
#include <stdio.h>

#include "log_system.h"

MemoryManager* create_memory_manager(size_t p_initial_pool_count) {
    MemoryManager* managerPtr = malloc(sizeof(MemoryManager));
    if (!managerPtr) {
        log_error("Failed to allocate memory p_managerPtr\n");
        return NULL;
    }

    managerPtr->pools = malloc(p_initial_pool_count * sizeof(void*));
    managerPtr->pool_sizes = malloc(p_initial_pool_count * sizeof(size_t));
    managerPtr->element_sizes = malloc(p_initial_pool_count * sizeof(size_t));
    
    if (!managerPtr->pools || !managerPtr->pool_sizes || !managerPtr->element_sizes) {
        free(managerPtr->pools);
        free(managerPtr->pool_sizes);
        free(managerPtr->element_sizes);
        free(managerPtr);
        log_error("Failed to allocate memory p_managerPtr arrays\n");
        return NULL;
    }

    managerPtr->type_count = p_initial_pool_count;
    
    // Initialize arrays
    for (size_t i = 0; i < p_initial_pool_count; i++) {
        managerPtr->pools[i] = NULL;
        managerPtr->pool_sizes[i] = 0;
        managerPtr->element_sizes[i] = 0;
    }

    return managerPtr;
}

void destroy_memory_manager(MemoryManager* p_managerPtr) {
    if (!p_managerPtr) return;

    // Free all component pools
    for (size_t i = 0; i < p_managerPtr->type_count; i++) {
        if (p_managerPtr->pools[i]) {
            // Calculate total allocated size for this pool
            size_t total_size = p_managerPtr->pool_sizes[i] * p_managerPtr->element_sizes[i];
            if (total_size > 0) {
                free(p_managerPtr->pools[i]);
                p_managerPtr->pools[i] = NULL;
            }
        }
    }

    // Now free the arrays
    if (p_managerPtr->pools) {
        free(p_managerPtr->pools);
    }
    if (p_managerPtr->pool_sizes) {
        free(p_managerPtr->pool_sizes);
    }
    if (p_managerPtr->element_sizes) {
        free(p_managerPtr->element_sizes);
    }

    // Finally free the manager itself
    free(p_managerPtr);
}

void* allocate_component(MemoryManager* p_managerPtr, COMPONENT_TYPE p_type) {
    if (!p_managerPtr || p_type >= p_managerPtr->type_count) {
        return NULL;
    }

    // If pool doesn't exist yet, create it
    if (!p_managerPtr->pools[p_type]) {
        p_managerPtr->pools[p_type] = malloc(INITIAL_POOL_SIZE * p_managerPtr->element_sizes[p_type]);
        if (!p_managerPtr->pools[p_type]) {
            return NULL;
        }
        p_managerPtr->pool_sizes[p_type] = 0;  // Start at 0 used components
    }

    // Check if we need to grow the pool
    size_t current_size = p_managerPtr->pool_sizes[p_type];
    if (current_size >= INITIAL_POOL_SIZE) {
        size_t new_capacity = INITIAL_POOL_SIZE * 2;
        void* new_pool = realloc(p_managerPtr->pools[p_type], 
                                new_capacity * p_managerPtr->element_sizes[p_type]);
        if (!new_pool) {
            return NULL;
        }
        p_managerPtr->pools[p_type] = new_pool;
    }

    // Return pointer to next available component slot
    size_t next_index = p_managerPtr->pool_sizes[p_type]++;
    return (char*)p_managerPtr->pools[p_type] + (next_index * p_managerPtr->element_sizes[p_type]);
}

void free_component(MemoryManager* p_managerPtr, COMPONENT_TYPE p_type, void* p_component) {
    if (!p_managerPtr || !p_component || p_type >= p_managerPtr->type_count) {
        return;
    }

    // For now, we don't actually free memory, just mark it as available
    // TODO(kioskars, 20/1-25): Implement proper component recycling
}