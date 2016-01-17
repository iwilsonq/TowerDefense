//
//  Animation.hpp
//  TowerDefense
//
//  Created by Ian Wilson on 1/16/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include <SFML/Graphics.hpp>

#ifndef __TowerDefense__Animation__
#define __TowerDefense__Animation__

// This class will function as a kind of resource, thus it will be used through the resource manager
// --> As it stands this is just a container for a texture and some rectangles

class Animation
{
public:
    Animation(sf::Texture* texture = nullptr);
    ~Animation();
    
    void setTexture(sf::Texture* texture);
    sf::Texture* getTexture() const;
    
    Animation& addFrame(const sf::IntRect& rect);
    Animation& addFramesLine(int number_x, int number_y, int line);
    Animation& addFramesColumn(int number_x, int number_y, int column);
    size_t size() const;
    
    const sf::IntRect& getRect(size_t index) const;
    
private:
    friend class AnimatedSprite; // To be constructed
    std::vector<sf::IntRect> _frames;
    sf::Texture* _texture;
    
};


#endif /* defined(__TowerDefense__Animation__) */
