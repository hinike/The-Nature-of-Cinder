//
//  Mover.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover( const float _mass, const float _x, const float _y )
    : location( _x, _y ),
      velocity( Vec2f::zero() ),
      acceleration( Vec2f::zero() ),
      mass( _mass ),
      radius( _mass * 8 )
    { }

float Mover::getMass() const {
    return mass;
}

Vec2f Mover::getLocation() const {
    return location;
}

Vec2f Mover::getVelocity() const {
    return velocity;
}

void Mover::applyForce( const Vec2f& force ) {
    Vec2f scaledForce = force / mass;
    acceleration += scaledForce;
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    acceleration = Vec2f::zero();
}

void Mover::draw() const {
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::drawSolidCircle( location, radius );
}
