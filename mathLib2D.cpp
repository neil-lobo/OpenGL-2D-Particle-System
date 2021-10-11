#include <cmath>
#include "mathLib2D.h"

//Point2D
Point2D::Point2D()
{
    mX = 0.0;
    mY = 0.0;
}
Point2D::Point2D(float inX, float inY)
{
    mX = inX;
    mY = inY;
}
float Point2D::distanceTo(Point2D other)
{
    return sqrt(pow(other.mX - mX, 2.0) + pow(other.mY - mY, 2.0));
}

float Point2D::fastDistanceTo(Point2D other)
{
    return pow(other.mX - mX, 2.0) + pow(other.mY - mY, 2.0);
}

//Vec2D
Vec2D::Vec2D()
{
    mX = 0.0;
    mY = 0.0;
}
Vec2D::Vec2D(float inX, float inY)
{
    mX = inX;
    mY = inY;
}
float Vec2D::length()
{
    return sqrt(pow(mX, 2.0) + pow(mY, 2.0));
}
Vec2D Vec2D::normalize()
{
    if (length() == 0)
    {
        return Vec2D();
    }
    return Vec2D(mX / length(), mY / length());
}
Vec2D Vec2D::multiply(float scalar)
{
    return Vec2D(mX * scalar, mY * scalar);
}
Vec2D Vec2D::add(Vec2D vec)
{
    return Vec2D(mX + vec.mX, mY + vec.mY);
}
Point2D Vec2D::movePoint(Point2D source)
{
    return Point2D(source.mX + mX, source.mY + mY);
}
Vec2D Vec2D::createVector(Point2D p1, Point2D p2)
{
    return Vec2D(p2.mX - p1.mX, p2.mY - p1.mY);
}