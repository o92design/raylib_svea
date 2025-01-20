#ifndef ID_TYPES_H
#define ID_TYPES_H

#include <stdint.h>
#include <stdbool.h>

// ID Types
typedef uint32_t ENTITY_ID;
typedef uint32_t COMPONENT_ID;
typedef uint16_t GENERATION_ID;
typedef uint16_t TYPE_ID;
typedef uint16_t INDEX_ID;

// Bit masks and shifts
#define GENERATION_BITS 16
#define INDEX_BITS 16
#define TYPE_BITS 16

#define INDEX_MASK ((1 << INDEX_BITS) - 1)
#define GENERATION_MASK ((1 << GENERATION_BITS) - 1)
#define TYPE_MASK ((1 << TYPE_BITS) - 1)

// Entity ID functions
static inline ENTITY_ID create_entity_id(INDEX_ID p_index, GENERATION_ID p_generation) {
    return ((ENTITY_ID) p_generation << INDEX_BITS) | p_index;
}

static inline INDEX_ID get_entity_index(ENTITY_ID p_entityId) {
    return p_entityId & INDEX_MASK;
}

static inline GENERATION_ID get_entity_generation(ENTITY_ID p_entityId) {
    return (p_entityId >> INDEX_BITS) & ((1 << GENERATION_BITS) - 1);
}

// Component ID functions
static inline COMPONENT_ID make_component_id(TYPE_ID p_type, INDEX_ID p_index) {
    return ((COMPONENT_ID)p_type << INDEX_BITS) | p_index;
}

static inline TYPE_ID get_component_type(COMPONENT_ID p_id) {
    return (p_id >> INDEX_BITS) & ((1 << TYPE_BITS) - 1);
}

static inline INDEX_ID get_component_index(COMPONENT_ID p_id) {
    return p_id & INDEX_MASK;
}

// ID validation
static inline bool is_valid_entity_id(ENTITY_ID p_id) {
    return p_id != 0;
}

static inline bool is_valid_component_id(COMPONENT_ID p_id) {
    return p_id != 0;
}

#endif // ID_TYPES_H