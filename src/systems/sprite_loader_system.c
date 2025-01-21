#include "systems/sprite_loader_system.h"
#include <stdio.h>
#include <assert.h>

#include "log_system.h"

SpriteComponent load_sprite(const char* p_pathPtr) {
    SpriteComponent spriteComponent = {0};  // Initialize all members to 0
    
    if (p_pathPtr == NULL) {
        log_error("Error: Invalid path pointer\n");
        return spriteComponent;
    }
    
    // Ensure we have a valid window context before loading textures
    if (!IsWindowReady()) {
        log_error("Error: No valid window context for loading textures\n");
        return spriteComponent;
    }

    spriteComponent.componentId = -1;
    spriteComponent.sprite = LoadTexture(p_pathPtr);
    
    if (spriteComponent.sprite.id == 0) {
        log_error("Error: Could not load sprite from path: %s\n", p_pathPtr);
    }
    
    return spriteComponent;
}

int unload_sprite(SpriteComponent* p_spriteComponentPtr, const size_t p_index) {
    if (p_spriteComponentPtr == NULL) {
        log_error("Error: Invalid sprite component pointer\n");
        return -1;
    }

    log_info("Unloading sprite at index %ld\n", p_index);
    
    // Get pointer to specific sprite component
    SpriteComponent* spriteComponentPtr = &p_spriteComponentPtr[p_index];
    
    // Check if sprite is already unloaded
    if (spriteComponentPtr->sprite.id == 0) {
        log_info("Warning: Sprite at index %ld is already unloaded.\n", p_index);
        return -1;
    }

    // Unload the texture
    UnloadTexture(spriteComponentPtr->sprite);
    spriteComponentPtr->sprite.id = 0;  // Mark as unloaded
    
    return 0;
}

int unload_sprites(SpriteComponent* p_spriteComponentsPtr, const size_t p_count) {
    if(p_count == 0) {
        log_error("Error: No sprites to unload.\n");
        return -1;
    }

    for(size_t i = 0; i < p_count; ++i) {
        unload_sprite(p_spriteComponentsPtr, i);
    }

    int unloadedSprites = 0;
    int nonZeroSprites = 0;
    // Assert that all sprites have been unloaded
    for(size_t i = 0; i < p_count; i++) {
        if (p_spriteComponentsPtr[i].sprite.id == 0) 
        {
            unloadedSprites++;
        } else {
            nonZeroSprites++;
        }
    }

    assert(unloadedSprites > 0 && "Didn't unload all sprites");
    log_info("Sprites: Unloaded %d / Still loaded: %d\n", unloadedSprites, nonZeroSprites);

    return 0;
}
