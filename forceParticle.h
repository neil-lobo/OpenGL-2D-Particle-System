#ifndef FORCE_PARTICLE_2D_H
#define FORCE_PARTICLE_2D_H
#include "particle.h"

class ForceParticle2D : public Particle2D
{
public:
    ForceParticle2D(Point2D position, int size, Vec2D direction, float range, float speed, float density, bool repulsing, bool hasFriction, bool collisionEnergyLoss);

    float density;
    bool repulsing;

    void applyForceTo(Particle2D *p);
};
#endif