#ifndef MEMORY_SYSTEM_H
#define MEMORY_SYSTEM_H

#include "memory_manager.h"
#include "component_handler.h"

MemoryManager* create_memory_manager(size_t initial_pool_count);
void destroy_memory_manager(MemoryManager* manager);
void* allocate_component(MemoryManager* manager, COMPONENT_TYPE type);
void free_component(MemoryManager* manager, COMPONENT_TYPE type, void* component);

#endif // MEMORY_SYSTEM_H