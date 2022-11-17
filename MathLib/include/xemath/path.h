
#ifndef _PATH_H__
#define _PATH_H__ 1

#include <vector>
#include "math.h"
#include "entity.h"

class Path : public Entity{

  public:
    Path();
    Path(const Path& o);
    Path(float *vertices, int n_vertex);
    ~Path();

    void addVertex(const xemath::Vec2 v);
    void draw();

    xemath::Vec2 position_; // Traslacion
    float rotation_;
    xemath::Vec2 scale_;

    unsigned int stroke_color_[4];
    unsigned int fill_color_[4];
    bool solid_;

  protected:
    int n_vertex_;
    float *vertices_;
    
  private:
};

#endif