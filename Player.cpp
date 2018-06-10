/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:16:36 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/10 16:54:00 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <ctime>
#include <cstdlib>

Player::Player(WINDOW * win, int x, int y, const char * c) : Entity(win, x, y, c){
    lives = 9;
}

Player::~Player(void) {
}

Player::Player(Player const & src) : Entity(src){
    lives = src.lives;
}

Player & Player::operator=(Player const & src){
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    lives = src.lives;
    keypad(currentWindow, true);
    return *this;
}

void Player::moveUp(void) {
    mvwaddstr(currentWindow, getY(), getX(), "  ");
    move(0, -SPEED);
    if (getY() < 1)
        yLoc = 1;
}

void Player::moveDown(void) {
    mvwaddstr(currentWindow, getY(), getX(), "  ");
    move(0, SPEED);
    if (getY() > yMax - 3)
        yLoc = yMax - 3;
}

void Player::moveBackwards(void) {
    mvwaddstr(currentWindow, getY(), getX(), "  ");
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

int Player::getLives(void) const {
    return lives;
}

int Player::decreaseLives(void){
    if (lives > 0)
        lives--;
    return lives;
}