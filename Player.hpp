/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngwato <kngwato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:17:37 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/09 13:38:04 by kngwato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"

class Player : public Entity {
    public:
        Player(WINDOW * win, int x, int y, char c);
        ~Player(void);
        Player(Player const & src);
        Player & operator=(Player const & src);
        void moveUp(void);
        void moveDown(void);
        void moveBackwards(void);
        int getPlayerInput(void);
        // Weapon & shoot(void) const;
};

#endif