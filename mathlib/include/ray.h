/**
 * \file ray.h
 * \author Hector Ochando <ochandoca@esat-alumni.com>
 * 
 */

#ifndef __RAY_H__ 
#define __RAY_H__ 1

#include <oxml/Vec3.h>

struct Ray {
  oxml::Vec3 origin;
  oxml::Vec3 direction;
};


#endif