/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:25:27 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/10 16:59:05 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(WINDOW * win, int x, int y, const char * c) : Entity(win, x, y, c){
    ready = true;
}

Enemy::Enemy(void) {
    ready = false;
}

Enemy::~Enemy(void) {
}

Enemy::Enemy(Enemy const & src) : Entity(src){
}

Enemy & Enemy::operator=(Enemy const & src){
    xLoc = src.getX();
    yLoc = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    ready = true;
    return *this;
}

void    Enemy::moveForward(int xIncr) {
    mvwaddstr(currentWindow, getY(), getX(), "   ");
    move(-xIncr, 0);
    if (getX() < 1) {
        xLoc = 48;
    }
}

void Enemy::setSpeed(int speed) {
    enemySpeed = speed;
}

int Enemy::getSpeed(void)const {
    return enemySpeed;
}


bool Enemy::isReady(void)const{
    return ready;
}