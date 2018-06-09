/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:25:27 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 16:08:22 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(WINDOW * win, int x, int y, char c) : Entity(win, x, y, c){
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
    return *this;
}
