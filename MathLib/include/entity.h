#ifndef __ENTITY_H__
#define __ENTITY_H_ 1

class Entity{
  public:
    Entity();
    Entity(const Entity& o);
    ~Entity();

    // Metodos
    void init(); // añadiremos cosas en el futuro

    int tag_;
    bool enabled_;
    


  private:

};

#endif
