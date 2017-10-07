#include "player.h"
#include "sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, const char * texturePath) {
 texture = loadTexture(renderer, texturePath);

 // Set rewidth and height to the same dimensions as the texture
 SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

 // This seems safer as sometimes it appears we get random vals
 rect.x = 0;
 rect.y = 0;
}

void Sprite::update(Player& player) {
  // @TODO could I make this reference it instead of reassign each frame?
  rect.x = player.x;
  rect.y = player.y;
};


// @TODO maybe this should go on the entity instead.
void Sprite::render(Player& player, SDL_Renderer* renderer) {
  SDL_RenderCopy(renderer, player.sprite.texture, NULL, &rect);
}

// @TODO Destruct and free texture.

