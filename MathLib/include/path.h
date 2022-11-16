
#ifndef _PATH_H__
#define _PATH_H__ 1

#include <vector>
#include "entity.h"

class Path : public Entity{

  public:
    Path();
    Path(const Path& o);
    ~Path();

    void addVertex(const Vec2& v);
    void draw();

    Vec2 position_; // Traslacion
    float rotation_;
    Vec2 scale_;

    unsigned int stroke_color_[4];
    unsigned int fill_color_[4];
    bool solid_;

  protected:
    std::vector<Vec2> vertices_;
    
  private:
};

#endif