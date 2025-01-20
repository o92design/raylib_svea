#include "systems/sprite_loader_system.h"
#include <stdio.h>
#include <assert.h>

SpriteComponent load_sprite(const char* p_pathPtr) {
    SpriteComponent spriteComponent;
    spriteComponent.sprite = LoadTexture(p_pathPtr);
    if(spriteComponent.sprite.id == 0) {
        fprintf(stderr, "Error: Could not load sprite from path: %s\n", p_pathPtr);
    }
    return spriteComponent;
}

int unload_sprite(SpriteComponent* p_spriteComponentPtr, const size_t p_index) {
    fprintf(stdout, "Unloading sprite at index %ld\n", p_index);
    if(p_spriteComponentPtr[p_index].sprite.id == 0) {
        fprintf(stdout, "Warning: Sprite at index %ld is already unloaded.\n", p_index);
        return -1;
    }

    SpriteComponent* spriteComponentPtr = p_spriteComponentPtr + p_index;

    UnloadTexture(spriteComponentPtr->sprite);

    // Set sprite.id to 0 to indicate that it has been unloaded
    spriteComponentPtr->sprite.id = 0;
    
    return 0;
}

int unload_sprites(SpriteComponent* p_spriteComponentsPtr, const size_t p_count) {
    if(p_count == 0) {
        fprintf(stderr, "Error: No sprites to unload.\n");
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
    fprintf(stdout, "Sprites: Unloaded %d / Still loaded: %d\n", unloadedSprites, nonZeroSprites);

    return 0;
}
