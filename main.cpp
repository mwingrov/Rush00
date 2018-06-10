/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <mwingrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:46:12 by kngwato           #+#    #+#             */
/*   Updated: 2018/06/10 17:06:16 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Enemy.hpp"
#include "Weapons.hpp"
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


WINDOW * space;
Enemy  enemies[20];
Player * player;
Weapons weapons[50];
int weaponsCount = 0;
int score = 0;
int enemyCounter = 20;

void    detectEnemyCol(int j) {
    for(int i = 0; i <= weaponsCount; i++) {
        if (i != 50) {
            if (enemies[j].comparePos(weapons[i]) == true)
            {
                mvwaddstr(space, enemies[j].getY(), enemies[j].getX(), "   ");
                enemies[j] = Enemy();
                score += 10;
                enemyCounter--;
                mvwprintw(space, 18, 38, "score: %d", score);
                if (enemyCounter == 0) {
                    mvwprintw(space, 18, 18, "YOU WIN!!!!!");
                    getch();
                    refresh();
                    exit(0);
                }
            }
        }
    }
    wrefresh(space);
}

void    genEnemy() {
    int y = 0;
    int x = 48;
    int speed = 0;
    
    for(int i = 0; i < 20; i++) {
        srand(i);
        y = 1 + rand()%17;
        speed = 1 + rand()% 2;
        enemies[i] =  Enemy(space, x, y, "<={");
        enemies[i].setSpeed(speed);
    }
}

void    moveWeapons(void) {
    mvwprintw(space, 18, 2, "Ammo: %d", 50 - weaponsCount);
    for(int i = 0; i <= weaponsCount; i++) {
        if (i != 200) {
            weapons[i].moveForward(2);
            weapons[i].shoot();
        }
    }
}

void    moveEnemies() {
    for(int i = 0; i < 20; i++) {
        if (enemies[i].isReady()) {
            enemies[i].moveForward(enemies[i].getSpeed());
            enemies[i].display();
            if (enemies[i].comparePos(player) == true)
            {
                enemyCounter--;
                if (player->decreaseLives() == 0)
                {
                    mvwprintw(space, 18, 18, "YOU DIED!!!");
                    getch();
                    refresh();
                    exit(0);
                }
                mvwaddstr(space, enemies[i].getY(), enemies[i].getX(), "   ");
                enemies[i] = Enemy();
            }
            else {
                detectEnemyCol(i);
            }
            wrefresh(space);
        }
    }
}


void    EnemyShip(void) {

    genEnemy();
    wrefresh(space);
    while(true) {
            moveWeapons();
            moveEnemies();
            mvwprintw(space, 18, 18, "Lives: ");
            mvwprintw(space, 18, 18, "Lives: %d", player->getLives());
            wrefresh(space);
            usleep(100000);
    }
}

int main() {
    
    
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int yMax, xMax;
    int input;
    getmaxyx(stdscr, yMax, xMax);
    space = newwin(20, 50, (yMax/2 - 10), 10);
    box(space,0,0);
    refresh();
    wrefresh(space);
    player = new Player(space, 4, 10, "=>");
    mvwprintw(space, 18, 18, "Lives: 9");
    mvwprintw(space, 18, 38, "score: %d", score);
    std::thread runner (EnemyShip);
    do
    {
        player->display();
        wrefresh(space);
        input = player->getPlayerInput();
        if (input == 32 && weaponsCount < 200) //KEY_SPACE
        {
            weapons[weaponsCount] = Weapons(space, player->getX()+3, player->getY(), "->");
            weapons[weaponsCount].shoot();
            weaponsCount++;
        }
        if(input == 'x')
        {
            runner.detach();
            refresh();
            return 0;
        }
    }
    while(true);
    runner.join();
    getch();
    endwin();
    
    return 0;
}