//
//  bullet.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 9/13/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef bullet_cpp
#define bullet_cpp

#include "bullet.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <cmath>


bullet::bullet(int width, int height, int x_, int y_, float xvel_, float yvel_){
    screenwidth = width;
    screenheight = height;
    charscale = 4;
    x = x_;
    y = y_;
    xvel = 15*xvel_;
    yvel = 15*yvel_;
    gravity = false;
    toErase = false;
    if (!chartexture.loadFromFile(resourcePath() + "Bullet.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    if (yvel > 0) {
        charsprite.setRotation(int(180*asin(-xvel_)/3.14159)+90);
    }
    else{
        if (yvel == 0) {
            if (xvel > 0) {
                charsprite.setRotation(-90);
            }
            else{
                charsprite.setRotation(90);
            }
        }
        else{
            charsprite.setRotation(int(-180*asin(-xvel_)/3.14159) - 90);
        }
    }
}

bool bullet::getToErase(){
    return toErase;
}

void bullet::update(float elapsedTime){
    x = x+xvel*elapsedTime*60;
    y = y+yvel*elapsedTime*60;
    if (gravity){
        yvel = yvel + .5;
    }
    charsprite.setPosition(x, y);
    //if it is off the screen, slate it for deletion
    if (x > screenwidth + 50 || x < -50 || y > screenheight + 50 || y < screenheight){
        toErase = true;
    }
}

void bullet::draw(sf::RenderWindow & window){
    window.draw(charsprite);
}

#endif /*bullet_cpp*/
