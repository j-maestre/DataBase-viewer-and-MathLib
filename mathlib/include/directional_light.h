/**
 * \file directional_light.h
 * \author Jose Maria Maestre Quiles <maestrequi@esat-alumni.com>
 * 
 */

#ifndef __DIRECTIONAL_LIGHT_H__
#define __DIRECTIONAL_LIGHT_H__ 1

#include "entity.h"
#include "oxml/Vec4.h"
#include "oxml/Vec3.h"

class DirectionalLight : public Entity{
  public:
    DirectionalLight();
    DirectionalLight(const DirectionalLight& o);
    ~DirectionalLight();
    
    
    void draw() override;
    /**
     * \brief Show a ImGui window with the settings of the light
     * 
     */
    void DirectionalLightSettings();

    //color of the light
    oxml::Vec4 color_;
    //direction of the light
    oxml::Vec3 light_direction_;

  protected:
  
  private:
};


#endif
