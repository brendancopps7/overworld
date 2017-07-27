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

fighter::fighter(float width, float height) {
    screenwidth = width;
    screenheight = height;
    float charscale = 1.5;
    x=0;
    y=screenheight*.75;
    if (!chartexture.loadFromFile(resourcePath() + "sprite_1.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    
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

void fighter::draw(sf::RenderWindow & window){
    window.draw(charsprite);
};

void fighter::update(float elapsedTime){
    //gravity updates
    if(!grounded){
        yvelocity += .5;
    }
    
    //friction updates
    if(grounded){
        if(slow) {
            if(xvelocity > 0){
                xvelocity -= .25;
            }
            if(xvelocity < 0){
                xvelocity += .25;
            }
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
    if (x>=screenwidth-64)
        x=screenwidth-64;
    else if (x<0)
        x=0;
    
    //get y from yvelocity
    y=y+yvelocity*elapsedTime*60;
    if (y>=screenheight*.75){
        y=screenheight*.75;
        grounded = true;
    }
    else if (y<0) //maybe remove the ceiling from fighting rooms, that could be fun
        y=0;
    
    //update sprite position
    charsprite.setPosition(x, y);
};


