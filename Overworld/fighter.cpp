//
//  fighter.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 7/22/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "fighter.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <cmath>

fighter::fighter(float width, float height, sf::Vector2i mouseposition) {
    screenwidth = width;
    screenheight = height;
    charscale = 4;
    x=0;
    y=screenheight*.75;
    if (!chartexture.loadFromFile(resourcePath() + "FighterStandIn.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    
    if (!armtexture.loadFromFile(resourcePath() + "FighterArmStandIn.png")) {
        return EXIT_FAILURE;
    }
    armsprite.setTexture(armtexture);
    xArmOffset = charscale * 13;
    yArmOffset = charscale * 12;
    xArmAngleOffset = 0;
    yArmAngleOffset = 0;
    armsprite.setPosition(x + xArmOffset + xArmAngleOffset, y + yArmOffset + yArmAngleOffset);
    aim(mouseposition);
    armsprite.scale(charscale, charscale);
    xdirection = 0;
    grounded=true;
    slow=false;
};

void fighter::setXSpeed(float xdirection){
    xvelocity=xdirection;
}

void fighter::setYSpeed(float ydirection){
    yvelocity = ydirection;
}

void fighter::walk(float direction){
    xdirection=direction;
    slow=false;
}

void fighter::jump(){
    if(grounded)
    {
        yvelocity = -12.5;
        //yvelocity = -50;
    }
}

void fighter::shoot(){
    xvelocity += -10*aimx; //TODO: Change variable to be a call to weapon.power()
    yvelocity += -10*aimy;
}

void fighter::slowing(){
    xdirection = 0;
    slow=true;
}

sf::Sprite fighter::getcharsprite(){
    return charsprite;
}

void fighter::moveto(sf::Vector2f coord){
    x=coord.x;
    y=coord.y;
    charsprite.setPosition(coord);
};

void fighter::aim(sf::Vector2i direction){
    int tempx = direction.x;
    int tempy = direction.y;
    //int width = charsprite.getGlobalBounds().width;
    //int height = charsprite.getGlobalBounds().height;
    int relx = tempx - (x + xArmOffset);
    int rely = tempy - (y + yArmOffset);
    aimx = relx/(sqrt(pow(relx,2) + pow(rely,2)));
    aimy = rely/(sqrt(pow(relx,2) + pow(rely,2)));
    if (aimy > 0) {
        armsprite.setRotation(int(180*asin(-aimx)/3.14159));
    }
    else{
        if (aimy == 0) {
            if (aimx > 0) {
                armsprite.setRotation(-90);
            }
            else{
                armsprite.setRotation(90);
            }
        }
        else{
            armsprite.setRotation(int(-180*asin(-aimx)/3.14159) + 180);
        }
    }
    xArmAngleOffset = -4*2.5*(aimy);
    yArmAngleOffset = 4*2.5*(aimx);
    armsprite.setPosition(x + xArmOffset + xArmAngleOffset, y + yArmOffset + yArmAngleOffset);
}

void fighter::draw(sf::RenderWindow & window){
    window.draw(charsprite);
    window.draw(armsprite);
};

void fighter::update(float elapsedTime){
    //gravity updates
    if(!grounded){
        yvelocity += .5;
    }
    
    //friction updates
    if(grounded){
        if(slow) {
            xvelocity*=.9;
        }
        else{
            if(xvelocity > -5 && xvelocity < 5){
                xvelocity += .5 * xdirection;
            }
            else if(xvelocity < -5){
                xvelocity = -5;
            }
            else if(xvelocity > 5){
                xvelocity = 5;
            }
        }
    }
    
    grounded=false;
    
    //get x from xvelocity
    x=x+xvelocity*elapsedTime*60;
    if (x>=screenwidth-64){
        x=screenwidth-64;
        xvelocity=0;
    }
    else if (x<0){
        x=0;
        xvelocity=0;
    }
    
    //get y from yvelocity
    y=y+yvelocity*elapsedTime*60;
    if (y>=screenheight*.75){
        y=screenheight*.75;
        grounded = true;
        yvelocity = 0;
    }
    
    
    //update sprite position
    charsprite.setPosition(x, y);
    armsprite.setPosition(x + xArmOffset + xArmAngleOffset, y + yArmOffset + yArmAngleOffset);
};


