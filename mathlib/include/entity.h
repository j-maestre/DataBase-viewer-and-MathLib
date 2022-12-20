/**
 * \file entity.h
 * \author Jose Maria Maestre Quiles <maestrequi@esat-alumni.com>
 * 
 */

#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include <oxml/Vec2.h>

class Entity{
  public:
    Entity();
    Entity(const Entity& o);
    virtual ~Entity();

    /**
     * \brief init of the entity
     * 
     */
    void init();

    /**
     * \brief Set the position of the entity
     * 
     * \param oxml::Vec2 pos position of the entity
     */
    void set_position(oxml::Vec2 pos);

    /**
     * \brief Set the rotation of the entity
     * 
     * \param float rotation rotation of the entity
     */
    void set_rotation(float rotation);

    /**
     * \brief Set the scale of the entity
     * 
     * \param oxml::Vec2 scale of the entity
     */
    void set_scale(oxml::Vec2 scale);

    /**
     * \brief Get the position of the entity
     * 
     * \return oxml::Vec2 position of the entity
     */
    oxml::Vec2 position() const;

    /**
     * \brief Get the rotation of the entity
     * 
     * \return float rotation of the entity
     */
    float rotation() const;

    /**
     * \brief get the scale of the camera
     * 
     * \return oxml::Vec2 scale of the camera
     */
    oxml::Vec2 scale() const;

    /**
     * \brief Draw the son classes
     * (this function needs to be implemented in the son class)
     */
    virtual void draw() = 0;

    //tag of the entity
    int tag_;
    //if the entity is enabled
    bool enabled_;

    protected:
      //position of the entity
      oxml::Vec2 position_;
      //rotation of the entity
      float rotation_;
      //scale of the entity
      oxml::Vec2 scale_;

  private:

};



#endif