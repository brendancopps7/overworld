//
//  npc.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 6/16/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef npc_hpp
#define npc_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class npc {
    
private:
    float screenwidth;
    float screenheight;
    float x;
    float y;
    sf::Sprite charsprite;
    sf::Texture chartexture;
    
public:
    npc(float height, float width);
    sf::Sprite getcharsprite();
    void move(float xchange, float ychange);
    void moveto(sf::Vector2f coord);
    void draw(sf::RenderWindow & window);
    
    
    
};

#endif /* npc_hpp */
