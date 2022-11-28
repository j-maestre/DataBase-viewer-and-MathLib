#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include <oxml/Vec2.h>

class Entity{
  public:
    Entity();
    Entity(const Entity& o);
    virtual ~Entity();

    void init();

    void set_position(oxml::Vec2 pos);
    void set_rotation(float rotation);
    void set_scale(oxml::Vec2 scale);

    oxml::Vec2 position() const;
    float rotation() const;
    oxml::Vec2 scale() const;

    virtual void draw() = 0;

    int tag_;
    bool enabled_;

    protected:
      oxml::Vec2 position_;
      float rotation_;
      oxml::Vec2 scale_;

  private:

};



#endif