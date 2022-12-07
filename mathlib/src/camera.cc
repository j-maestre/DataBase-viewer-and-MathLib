#include <stdio.h>
#include <oxml/Mathf.h>
//#include <oxml/esat/include/esat/math.h>
#include "camera.h"
#include "timer.h"
#include <ImGui/imgui.h>

bool Camera::mouse_clicked = false;

Camera::Camera(float fov, float near, float far){
  fov_ = fov;
  near_ = near;
  far_ = far;
  forward_ = oxml::Vec3(0.0f, 0.0f, 1.0f);
  up_ = oxml::Vec3::up;
  right_ = oxml::Vec3::right;
  position_ = oxml::Vec3::zero;
  ray_directions_ = nullptr;
  width_ = 0;
  height_ = 0;
  speed_ = 0.5f;
  rotation_speed_ = 0.05f;
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
    recalculeRayDirections();
    moved_ = false;
  }
}

void Camera::recalculeProjection() {
  projection_ = oxml::Mat4::Perspective(fov_, ((float)width_ / (float)height_), near_, far_);
  projection_.GetInverse(inverse_projection_);
}

void Camera::recalculateView() {
  view_ = oxml::Mat4::LookAt(position_, (position_ + (-forward_)), oxml::Vec3(0.0f, 1.0f, 0.0f));
  if(!view_.GetInverse(inverse_view_)){
    printf("No inverse!\n");
  }
  
}

void Camera::recalculeRayDirections() {
  if (width_ != 0 && height_ != 0) {
    if (ray_directions_ != nullptr) {
      delete[] ray_directions_;
    }
    ray_directions_ = new oxml::Vec3[width_ * height_];
    oxml::Vec2 coord;
    oxml::Vec4 target;
    oxml::Vec4 camera_coords;
    for (int y = 0; y < height_; y++) {
      for (int x = 0; x < width_; x++) {
        coord.x = ((float)x / (float)width_);
        coord.y = ((float)y / (float)height_);
        coord = ((coord * 2.0f) - 1.0f);

        //from negative one to one space back to world space
        target = inverse_projection_ * oxml::Vec4(coord.x, coord.y, 1.0f, 1.0f);
        camera_coords = (inverse_view_ * oxml::Vec4((oxml::Vec3(target.x, target.y, target.z) / target.w), 0.0f).Normalized());
        ray_directions_[x + y * width_].x = camera_coords.x;   
        ray_directions_[x + y * width_].y = camera_coords.y;   
        ray_directions_[x + y * width_].z = camera_coords.z;   
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
  recalculateView();
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
  right_ = oxml::Vec3::Cross(forward_.Normalized(),oxml::Vec3::up);
  up_ = oxml::Vec3::Cross(forward_.Normalized(),right_.Normalized());


  //Input keyboard
  
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);
  //oxml::Vec3(forward_);
  if(keystates[SDL_SCANCODE_W]){
    //Ha pulsado W
    position_ += forward_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_S]){
    //Ha pulsado S
    position_ -= forward_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_A]){
    //Ha pulsado A
    position_ += right_ * speed_;
    moved_ = true;
  }
  if(keystates[SDL_SCANCODE_D]){
    //Ha pulsado E
    position_ -= right_ * speed_;
    moved_ = true;
  }

  //printf("x->%f y->%f z->%f\n",forward_.x,forward_.y,forward_.z);

    


  //Rotation mouse
  mouse_clicked = false;
  if(delta_ != 0.0f && mouse_clicked){
    
    
    //printf("CLICK & ROTATE\n");
    float pitchDelta = (delta_.x * rotation_speed_) * oxml::Mathf::Deg2Rad; // Eje x
    float yawDelta = (delta_.y * rotation_speed_) * oxml::Mathf::Deg2Rad; // eje y, roll eje z

    oxml::Mat4 rotation = oxml::Mat4::Identity();
    //esat::Mat4 rotationEsat = esat::Mat4Identity();



    rotation = rotation.Multiply(oxml::Mat4::RotateX(pitchDelta));
    rotation = rotation.Multiply(oxml::Mat4::RotateY(yawDelta)) ;

    oxml::Vec4 rotation_direction(forward_.x,forward_.y,forward_.z,0.0f);
    rotation_direction = rotation * rotation_direction;

    forward_.x = rotation_direction.x; 
    forward_.y = rotation_direction.y; 
    forward_.z = rotation_direction.z;

    moved_ = true;
    /*forward_.x += delta_.x;
    forward_.y += -delta_.y;
    moved_ = true;*/
  }


}

void Camera::cameraSettings(){
 if (!ImGui::Begin("Camera Settings")) {
    ImGui::End();
    return;
  }
  
  if (ImGui::CollapsingHeader("Position")){
   
    ImGui::Text("Position");
    ImGui::DragFloat("Position.x",&position_.x, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Position.y",&position_.y, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Position.z",&position_.z, 0.005f, -100.0f, 100.0f, "%f");

    ImGui::Text("Forward");
    ImGui::DragFloat("Forward.x",&forward_.x, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Forward.y",&forward_.y, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Forward.z",&forward_.z, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::Text("Right");
    ImGui::DragFloat("Right.z",&right_.x, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Right.z",&right_.y, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Right.z",&right_.z, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::Text("Up");
    ImGui::DragFloat("Up.z",&up_.x, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Up.z",&up_.y, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::DragFloat("Up.z",&up_.z, 0.005f, -1.0f, 1.0f, "%f");
    ImGui::Text("Delta");
    ImGui::DragFloat("Delta.x",&delta_.x, 0.005f, 0.0f, 1.0f, "%f");
    ImGui::DragFloat("Delta.y",&delta_.y, 0.005f, 0.0f, 1.0f, "%f");
    moved_ = true;

    forward_.Normalize();

    //ImGui::EndMenu();
  }
  //ImGui::ShowDemoWindow();

  ImGui::End();
}

