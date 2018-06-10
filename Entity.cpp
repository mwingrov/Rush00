/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:26:32 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/10 16:55:10 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(WINDOW * win, int x, int y, const char * c) {
    currentWindow = win;
    xLoc = x;
    yLoc = y;
    getmaxyx(currentWindow, yMax, xMax);
    character = c;
}

Entity::Entity() {
    
}


Entity::~Entity() {
    
}

Entity::Entity(Entity const & src) {
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
}

Entity & Entity::operator = (Entity const & src){
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    return *this;
}

bool Entity::comparePos(Entity const * src) const{
    const int RADIUS = 2;
    // if (xLoc == src->getX() && yLoc == src->getY())
    //     return true;
    // else
    //     return false;
    if (src->getX() <= (xLoc + RADIUS) && src->getX() >= (xLoc) && src->getY() == yLoc)
        return true;
    else
        return false;
}

bool Entity::comparePos(Entity const & src) const{
    // if (xLoc == src.getX() && yLoc == src.getY())
    //     return true;
    // else
    //     return false;
    const int RADIUS = 2;
    if (src.getX() <= (xLoc + RADIUS) && src.getX() >= (xLoc) && src.getY() == yLoc)
        return true;
    else
        return false;
    
}

void Entity::display(void) const{
    mvwaddstr(currentWindow, yLoc, xLoc, character);
}

int Entity::getX(void) const{
    return xLoc;
}

int Entity::getY(void) const{
    return yLoc;
}

int     Entity::getXMax(void) const{
    return xMax;
}

int     Entity::getYMax(void) const{
    return yMax;
}

const char *  Entity::getCharater(void) const{
    return character;
}

WINDOW *    Entity::getCurrentWindow(void) const{
    return currentWindow;
}

void    Entity::move(int xIncr, int yIncr){
    xLoc += xIncr;
    yLoc += yIncr;
}

void    Entity::moveForward(int xIncr) {
    mvwaddstr(currentWindow, getY(), getX(), "  ");
    move(xIncr, 0);
    if (getX() < 1)
        xLoc = 1;
}