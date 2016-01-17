//
//  AnimatedSprite.hpp
//  TowerDefense
//
//  Created by Ian Wilson on 1/16/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __TowerDefense__AnimatedSprite__
#define __TowerDefense__AnimatedSprite__

#include <SFML/Graphics.hpp>
#include <Animation.hpp>
#include <functional>

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
    AnimatedSprite(const AnimatedSprite&) = default;
    AnimatedSprite& operator=(const AnimatedSprite&) = default; //Non-copyable
    AnimatedSprite(AnimatedSprite&&) = default;
    AnimatedSprite& operator=(AnimatedSprite&&) = default;
    
    using FuncType = std::function<void()>;
    static FuncType defaultFunc;
    FuncType onFinished;
    
    enum Status
    {
        Stopped,
        Paused,
        Playing
    };
    
    AnimatedSprite(Animation* animation = nullptr, Status status = Playing, const sf::Time& deltaTime = sf::seconds(0.15), bool loop = true, int repeat = 0);
    
    void setAnimation(Animation* animation);
    Animation* getAnimation()const;
    
    void setFrameTime(sf::Time deltaTime);
    sf::Time getFrameTime()const;
    
    void setLoop(bool loop);
    bool getLoop()const;
    void setRepeat(int nb);
    int getRepeat()const;
    
    void play();
    void pause();
    void stop();
    Status getStatus()const;
    
    void setFrame(size_t index);
    void setColor(const sf::Color& color);
    void update(const sf::Time& deltaTime);
    
private:
    Animation* _animation;
    sf::Time _delta;
    sf::Time _elapsed;
    bool _loop;
    int _repeat;
    Status _status;
    size_t _currentFrame;
    sf::Vertex _vertices[4];

    void setFrame(size_t index,bool resetTime);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    
};


#endif /* defined(__TowerDefense__AnimatedSprite__) */
