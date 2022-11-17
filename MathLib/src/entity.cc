#include <xemath/entity.h>
#include <stdio.h>


Entity::Entity(){
  tag_ = 0;
  enabled_ = true;
}

Entity::Entity(const Entity& other){
  tag_ = other.tag_;
  enabled_ = other.enabled_;
}

Entity::~Entity(){}

void Entity::init(){
  printf("\n--Se ha creado una entidad--\n");
  tag_ = 0;
  enabled_ = true;
}
