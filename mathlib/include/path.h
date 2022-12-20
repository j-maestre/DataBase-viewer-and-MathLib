/**
 * \file path.h
 * \author Jose Maria Maestre Quiles <maestrequi@esat-alumni.com>
 * 
 */

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

    /**
     * \brief add a vertex to the path
     * 
     * \param v vertex
     */
    void addVertex(const oxml::Vec2 v);

    /**
     * \brief draw the path
     * 
     */
    void draw();

    //position of the path
    oxml::Vec2 position_; // Traslacion
    //rotation of the path
    float rotation_;
    //scale of the path
    oxml::Vec2 scale_;

    //stroke color
    unsigned int stroke_color_[4];
    //fill color
    unsigned int fill_color_[4];
    //solid color
    bool solid_;

  protected:
    //number of vertex
    int n_vertex_;
    // poiter to the vertex
    float *vertices_;
    
  private:
};

#endif