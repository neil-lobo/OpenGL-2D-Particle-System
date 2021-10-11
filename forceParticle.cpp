#include "forceParticle.h"

ForceParticle2D::ForceParticle2D(Point2D position, int size, Vec2D direction, float range, float speed, float density, bool repulsing, bool hasFriction, bool collisionEnergyLoss) : Particle2D(position, Colour3(), size, direction, range, speed, hasFriction, collisionEnergyLoss)
{
    this->density = density;
    this->repulsing = repulsing;
    this->mass = size * density;
}

void ForceParticle2D::applyForceTo(Particle2D *p)
{
    float distanceSquared = pos.fastDistanceTo(p->pos);
    Vec2D force = Vec2D::createVector(p->pos, pos).normalize().multiply(mass * p->mass / distanceSquared).multiply(repulsing ? -1 : 1);
    if (force.length() >= 0.001)
    {
        p->forces.push_back(force);
    }
}