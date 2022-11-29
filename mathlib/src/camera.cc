#include "camera.h"
#include <stdio.h>


Camera::Camera(float fov, float near, float far){
  fov_ = fov;
  near_ = near;
  far_ = far;
  forward_ = oxml::Vec3(0.0f, 0.0f, -1.0f);
  up_ = oxml::Vec3::up;
  right_ = oxml::Vec3::right;
  position_ = oxml::Vec3::zero;
  ray_directions_ = nullptr;
  width_ = 0;
  height_ = 0;
  speed_ = 0.5f;
  mousePosition_.x = 0.0f;
  mousePosition_.y = 0.0f;
  lastMousePosition_.x = 0.0f;
  lastMousePosition_.y = 0.0f;
  delta_ = 0.0f;
  moved_ = true;
}

Camera::~Camera() {
  if (ray_directions_ != nullptr) {
    delete[] ray_directions_;
  }
  ray_directions_ = nullptr;
}

const oxml::Vec3* Camera::ray_directions() const {
  return ray_directions_;
}

void Camera::update() {
  movement();
  if(moved_){
    recalculateView();
    moved_ = false;
  }
}

void Camera::recalculeProjection() {
  projection_ = oxml::Mat4::Perspective(fov_, ((float)width_ / (float)height_), near_, far_);
  projection_.GetInverse(inverse_projection_);
}

void Camera::recalculateView() {
  view_ = oxml::Mat4::LookAt(position_, (position_ + forward_), oxml::Vec3(0.0f, 1.0f, 0.0f));
  view_.GetInverse(inverse_view_);
}

void Camera::recalculeRayDirections() {
  if (width_ != 0 && height_ != 0) {
    if (ray_directions_ != nullptr) {
      delete[] ray_directions_;
    }
    ray_directions_ = new oxml::Vec3[width_ * height_];
    oxml::Vec2 coord;
    for (int y = 0; y < height_; y++) {
      for (int x = 0; x < width_; x++) {
        coord.x = ((float)x / (float)width_);
        coord.y = ((float)y / (float)height_);
        coord = ((coord * 2.0f) - 1.0f);

        //from negative one to one space back to world space
        oxml::Vec4 target = inverse_projection_ * oxml::Vec4(coord.x, coord.y, 1.0f, 1.0f);
        oxml::Vec4 camera_coords = (inverse_view_ * oxml::Vec4((oxml::Vec3(target.x, target.y, target.z) / target.w), 0.0f).Normalized());
        oxml::Vec3 ray_direction = oxml::Vec3(camera_coords.x, camera_coords.y, camera_coords.z);
        ray_directions_[x + y * width_] = ray_direction;   
      }
    }
  }
}

void Camera::resize(int width, int height) {
  if (width == width_ && height == height_)
    return;
  
  width_ = width;
  height_ = height;

  recalculeProjection();
  recalculeRayDirections();
}

void Camera::movement(){

  //Get mouse position
  int x;
  int y;
  SDL_GetMouseState(&x, &y);
  mousePosition_.x = (float) x;
  mousePosition_.y = (float) y;
  delta_ = (mousePosition_ - lastMousePosition_) * 0.002f;
  lastMousePosition_ = mousePosition_;

  //Set right direction
  right_ = oxml::Vec3::Cross(forward_,up_);

  //Input keyboard
  SDL_Event e;
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);
  //oxml::Vec3(forward_);
  if(keystates[SDL_SCANCODE_W]){
    //Ha pulsado W
    position_ -= forward_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_S]){
    //Ha pulsado S
    position_ += forward_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_A]){
    //Ha pulsado A
    position_ -= right_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_D]){
    //Ha pulsado E
    position_ += right_ * speed_;
    moved_ = true;
  }


  //Rotation mouse
  if(delta_ != 0.0f){
    
    
  }


}
