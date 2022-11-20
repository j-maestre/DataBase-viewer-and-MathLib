#include <xemath/path.h>
#include <esat/draw.h>

Path::Path(){
    position_.x = 0.0f;
    position_.y = 0.0f;
    rotation_ = 0.0f;
    scale_.x = 1.0f;
    scale_.y = 1.0f;

    stroke_color_[0] = 255;
    stroke_color_[1] = 255;
    stroke_color_[2] = 255;
    stroke_color_[3] = 255;

    fill_color_[0] = 255;
    fill_color_[1] = 255;
    fill_color_[2] = 255;
    fill_color_[3] = 255;

    solid_ = true;

    vertices_ = (float*) malloc(sizeof(float)*6); //3 vertices como minimo
    n_vertex_ = 3;
}

Path::Path(float *vertices, int n_vertex){
    position_.x = 0.0f;
    position_.y = 0.0f;
    rotation_ = 0.0f;
    scale_.x = 0.0f;
    scale_.y = 0.0f;

    stroke_color_[0] = 255;
    stroke_color_[1] = 255;
    stroke_color_[2] = 255;
    stroke_color_[3] = 255;

    fill_color_[0] = 255;
    fill_color_[1] = 255;
    fill_color_[2] = 255;
    fill_color_[3] = 255;

    solid_ = true;
    vertices_ = vertices;
    n_vertex_ = n_vertex;
}

Path::~Path(){
    free(vertices_);
}

Path::Path(const Path& p){
    position_.x =p.position_.x;
    position_.y =p.position_.y;
    rotation_ = p.rotation_;
    scale_.x =p.scale_.x;
    scale_.y =p.scale_.y;

    stroke_color_[0] = p.stroke_color_[0];
    stroke_color_[1] = p.stroke_color_[1];
    stroke_color_[2] = p.stroke_color_[2];
    stroke_color_[3] = p.stroke_color_[3];

    fill_color_[0] = p.fill_color_[0];
    fill_color_[1] = p.fill_color_[1];
    fill_color_[2] = p.fill_color_[2];
    fill_color_[3] = p.fill_color_[3];

    solid_ = p.solid_;

    vertices_ = p.vertices_;
    n_vertex_ = p.n_vertex_;
}

void Path::draw(){

    esat::DrawSetStrokeColor(stroke_color_[0],stroke_color_[1],stroke_color_[2]);
    //esat::DrawSetFillColor(fill_color_[0],fill_color_[1], fill_color_[2]);
    esat::DrawSetFillColor(0,0,0);

    if(solid_){
        esat::DrawSolidPath(vertices_,n_vertex_);
    }else{
        esat::DrawPath(vertices_,n_vertex_);
    }

}
