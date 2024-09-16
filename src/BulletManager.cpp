#include "../libraries/BulletManager.h"

using namespace std;

void BulletManager::MoveBullets(vector<Invader> &invaders, Player& player) {
    for (it = bulletsFired.begin(); it != bulletsFired.end(); it++) {
        (*it)->Move();
        if ((*it)->isInvader)
        {
            if ((*it)->Impact(player) == 2) {
                player.UpdateHealth();
            }
        }
        else {
            for (Invader& invader : invaders) {
                if ((*it)->Impact(invader) == 1) {
                    player.SetScore(player.GetScore() + 10);
                }
            }
        }
    }
}

void BulletManager::Shoot(bool isInvader, Entity &entity) {
    COORD coords = entity.GetCoords();
    bool isBulletFound = false;
    for (it = bulletsFired.begin(); it != bulletsFired.end(); it++) {
        if ((*it)->bulletDestroyed) {
            (*it)->bulletDestroyed = false;
            (*it)->Spawn(coords, isInvader);
            isBulletFound = true;
            break;
        }
    }
    if (!isBulletFound) {
        bulletsFired.push_back(new Bullet(coords, isInvader));
    }
}