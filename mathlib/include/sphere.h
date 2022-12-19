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

        /**
         * \brief draw the sphere
         * 
         */
        void Sphere::draw() override;
        /**
         * \brief draw the sphere window settings
         * 
         * \param index indes of the sphere
         */
        void Sphere::sphereSettings(const char *index);
        
        float radius_;
        oxml::Vec3 sphereOrigin_;
        oxml::Vec4 sphereColor_;
        float color_[3];
    protected:

};

#endif