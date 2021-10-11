#include "particle.h"
#include <cmath>

#include <iostream>

Particle2D::Particle2D(Point2D position, Colour3 colour, int size, Vec2D direction, float range, float speed, bool hasFriction, bool collisionEnergyLoss)
{
    this->pos = position;
    this->col = colour;
    this->size = size;
    this->mass = size;
    this->acc = Vec2D();
    this->dir = direction.normalize();
    this->mouseForce = Vec2D();
    std::vector<Vec2D> forces;
    this->range = range;
    this->speed = speed;
    this->hasFriction = hasFriction;
    this->collisionEnergyLoss = collisionEnergyLoss;

}

const float Particle2D::FRICTION_CONSTANT = 0.01;

const float Particle2D::MIN_SPEED = 0.05;
const float Particle2D::MAX_SPEED = 25.0;

void Particle2D::wallCollision(int width, int height)
{
    float r = getRadius();
    if (pos.mX + r > width)
    {
        pos.mX = width - r;
        dir.mX = -dir.mX;
        if (collisionEnergyLoss)
        {
            multiplyEnergy(0.75);
        }
    }
    else if (pos.mX - r < 0)
    {
        pos.mX = r;
        dir.mX = -dir.mX;
        if (collisionEnergyLoss)
        {
            multiplyEnergy(0.75);
        }
    }

    if (pos.mY + r > height)
    {
        pos.mY = height - r;
        dir.mY = -dir.mY;
        if (collisionEnergyLoss)
        {
            multiplyEnergy(0.75);
        }
    }
    else if (pos.mY - r < 0)
    {
        pos.mY = r;
        dir.mY = -dir.mY;
        if (collisionEnergyLoss)
        {
            multiplyEnergy(0.75);
        }
    }
}

void Particle2D::update(int width, int height)
{
    // std::cout << speed << "\n";
    Vec2D force = sumForces();
    mouseForce = Vec2D();
    forces.clear();
    acc = force.multiply(1.0 / mass);
    Vec2D vel = getVelocity();
    vel = vel.add(acc);
    speed = vel.length();
    if (speed <= MIN_SPEED)
    {
        speed = 0.0;
    }
    else if (speed >= MAX_SPEED)
    {
        speed = MAX_SPEED;
    }
    dir = vel.normalize();
    pos = vel.movePoint(pos);
    wallCollision(width, height);
}

float Particle2D::getRadius()
{
    return size / 2.0;
}

Vec2D Particle2D::getVelocity()
{
    return dir.multiply(speed);
}

Vec2D Particle2D::sumForces()
{
    Vec2D total = Vec2D();
    total = total.add(mouseForce);
    if (hasFriction)
    {
        total = total.add(dir.multiply(-1.0 * mass * FRICTION_CONSTANT)); //friction force
    }

    for (long long unsigned int i = 0; i < forces.size(); i++)
    {
        total = total.add(forces.at(i));
    }
    return total;
}

void Particle2D::multiplyEnergy(float percent)
{
    speed = std::sqrt(std::pow(speed, 2) * percent);
}