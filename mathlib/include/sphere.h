#ifndef __SPHERE_H__
#define __SPHERE_H__ 1

#include <oxml/Vec4.h>
#include <oxml/Vec3.h>
#include "entity.h"


class Sphere : public Entity{
    public:

        Sphere();
        Sphere(const Sphere& o);
        ~Sphere();
        void Sphere::draw() override;
        
        float radius_;
        oxml::Vec4 sphereColor_;
        oxml::Vec3 sphereOrigin_;
    protected:

};

#endif