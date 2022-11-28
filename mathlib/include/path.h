
#ifndef _PATH_H__
#define _PATH_H__ 1

#include <math.h>
#include <oxml/Vec2.h>
#include "entity.h"

class Path : public Entity{

  public:
    Path();
    Path(const Path& o);
    Path(float *vertices, int n_vertex);
    ~Path();

    void addVertex(const oxml::Vec2 v);
    void draw();

    oxml::Vec2 position_; // Traslacion
    float rotation_;
    oxml::Vec2 scale_;

    unsigned int stroke_color_[4];
    unsigned int fill_color_[4];
    bool solid_;

  protected:
    int n_vertex_;
    float *vertices_;
    
  private:
};

#endif