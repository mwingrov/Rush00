/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:16:36 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 14:36:56 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <ctime>
#include <cstdlib>

Player::Player(WINDOW * win, int x, int y, char c) : Entity(win, x, y, c){
}

Player::~Player(void) {
}

Player::Player(Player const & src) : Entity(src){
}

Player & Player::operator=(Player const & src){
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    keypad(currentWindow, true);
    return *this;
}

void Player::moveUp(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(0, -SPEED);
    if (getY() < 1)
        yLoc = 1;
}

void Player::moveDown(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(0, SPEED);
    if (getY() > yMax - 2)
        yLoc = yMax - 2;
}

void Player::moveBackwards(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(SPEED, 0);
    if (getX() > xMax - 2)
        xLoc = xMax - 2;
}

int Player::getPlayerInput(void) {
    int input = wgetch(currentWindow);
    switch(input)
    {
        case 65: // KEY_UP
            moveUp();
            break;
        case 66: // KEY_DOWN
            moveDown();
            break;
        case 67: //KEY_LEFT
            moveBackwards();
            break;
        case 68: // KEY_RIGHT
            moveForward(-SPEED);
            break;
        default:
            break;
    }
    return input;
}
