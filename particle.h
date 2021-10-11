#ifndef PARTICLE_2D_H
#define PARTICLE_2D_H
#include <vector>
#include "mathLib2D.h"
#include "colour.h"

class Particle2D
{
public:
    Particle2D(Point2D position, Colour3 colour, int size, Vec2D direction, float range, float speed, bool hasFriction, bool collisionEnergyLoss);

    static const float FRICTION_CONSTANT;
    static const float MIN_SPEED;
    static const float MAX_SPEED;

    Point2D pos;
    Colour3 col;
    int size;
    int mass;
    Vec2D acc;
    Vec2D dir;
    Vec2D mouseForce;
    std::vector<Vec2D> forces;
    float range;
    float speed;
    bool hasFriction;
    bool collisionEnergyLoss;

    void wallCollision(int width, int height);
    void update(int width, int height);
    float getRadius();
    Vec2D getVelocity();
    Vec2D sumForces();
    void multiplyEnergy(float percent);
};
#endif