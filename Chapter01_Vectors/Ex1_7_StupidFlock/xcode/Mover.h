//
//  Mover.h
//  Ex1_4_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#ifndef Ex1_4_VectorAccelConst_Mover_h
#define Ex1_4_VectorAccelConst_Mover_h

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"

class Mover {
  public:
    Mover( float );
    void resetPosition();
    void setAccel( cinder::Vec2f );
    void update();
    void draw();
    
    float fatness;

private:
    const int fatMax = 10.0;
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
};


#endif
