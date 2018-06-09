/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:25:15 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 16:58:38 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Entity.hpp"

class Enemy : public Entity
{
    public:
        Enemy(WINDOW * win, int x, int y, char c);
        ~Enemy();
        Enemy(Enemy const & src);
        Enemy & operator = (Enemy const & src);
        void    moveForward(int xIncr);
};

#endif
