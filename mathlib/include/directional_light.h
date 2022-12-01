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
    void DirectionalLightSettings();

    oxml::Vec4 color_;
    oxml::Vec3 light_direction_;

  protected:
  
  private:
};


#endif
