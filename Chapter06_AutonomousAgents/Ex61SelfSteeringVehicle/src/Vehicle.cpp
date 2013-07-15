//
//  Vehicle.cpp
//  Ex61SelfSteeringVehicle
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#include "Vehicle.h"

void Vehicle::update( const Vec2f& mousePosition ) {
    arrive( mousePosition );
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Vehicle::draw() const {
    gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f(r*2, 0), Vec2f(-r*2, r), Vec2f(-r*2, -r) );
    gl::popMatrices();
}

void Vehicle::arrive( const Vec2f& target ) {
    Vec2f desired = target - position;
    float d = desired.length();
    
    if ( d < 200 ) {
        float m = (d / 100.0f) * maxSpeed;
        desired.normalize();
        desired *= m;
    } else {
        desired.normalize();
        desired *= maxSpeed;
    }
    
    Vec2f steer = desired - velocity;
    steer.limit( maxForce );
    acceleration += steer;
}