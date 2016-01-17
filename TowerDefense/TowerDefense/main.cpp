//
//  main.cpp
//  TowerDefense
//
//  Created by Ian Wilson on 1/16/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ResourceManager.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

int main(int argc,char* argv[])
{
    //Creation of the window
    sf::RenderWindow window(sf::VideoMode(600,800),"Example animation");
                            
    //load of the texture image
    ResourceManager<sf::Texture,int> textures;
    textures.load(0,"media/skins/eye.png");
    
    //Creation of the different animations
    Animation walkLeft(&textures.get(0));
    walkLeft.addFramesLine(4,2,0);
    Animation walkRight(&textures.get(0));
    walkRight.addFramesLine(4,2,1);
    
    //Creation of the animates sprite
    AnimatedSprite sprite(&walkLeft,AnimatedSprite::Playing,sf::seconds(0.1));
    //game loop
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time delta = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) //close event
                window.close();
        }
        float speed = 50; // the movement speed of the entity
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //move left
        {
            sprite.setAnimation(&walkLeft);
            sprite.play();
            sprite.move(-speed*delta.asSeconds(),0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            sprite.setAnimation(&walkRight);
        sprite.play();
        sprite.move(speed*delta.asSeconds(),0);
        }
    window.clear();
    sprite.update(delta); //update the animate sprite for possible frame change
    window.draw(sprite); //display the animation
    window.display();
    }
    return 0;
}
