#include <entity.h>
#include <Vec2.h>


Entity::Entity(){
  tag_ = 0;
  enabled_ = true;

  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};

}

Entity::Entity(const Entity& o){
  tag_ = o.tag_;
  enabled_ = o.enabled_;

  position_ = o.position_;
  rotation_ = o.rotation_;
  scale_ = o.scale_;
}

Entity::~Entity(){}

void Entity::init(){
  tag_ = 0;
  enabled_ = true;

  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
}

void Entity::set_position(oxml::Vec2 pos){
  position_ = pos;
}

void Entity::set_rotation(float rot){
  rotation_ = rot;
}

void Entity::set_scale(oxml::Vec2 scale){
  scale_ = scale;
}

oxml::Vec2 Entity::position() const{
  return position_;
}

float Entity::rotation() const{
  return rotation_;
}

oxml::Vec2 Entity::scale() const{
  return scale_;
}




