#include "directional_light.h"
#include "oxml/Vec4.h"
#include <ImGui/imgui.h>

DirectionalLight::DirectionalLight() : color_(0.1f,0.1f,0.1f,1.0f), light_direction_(-1.0f, -1.0f, 1.0f){
  /*color_ = oxml::Vec4(1.0f,1.0f,1.0f,1.0f);
  light_direction_ = oxml::Vec3(-1.0f, -1.0f, 1.0f);*/

}
DirectionalLight::DirectionalLight(const DirectionalLight& o){
  color_ = o.color_;
  light_direction_ = o.light_direction_;
}

DirectionalLight::~DirectionalLight(){}

void DirectionalLight::draw(){

}

void DirectionalLight::DirectionalLightSettings(){

  if (!ImGui::Begin("Directional Light Settings")) {
    ImGui::End();
    return;
  }
  
  if (ImGui::CollapsingHeader("Direction")){
    ImGui::DragFloat("Direction.x",&light_direction_.x, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Direction.y",&light_direction_.y, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Direction.z",&light_direction_.z, 0.005f, -100.0f, 100.0f, "%f");
  }

  if (ImGui::CollapsingHeader("Color")){
    ImGui::DragFloat("Color.r",&color_.z, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Color.g",&color_.y, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Color.b",&color_.x, 0.005f, -100.0f, 100.0f, "%f");
    ImGui::DragFloat("Color.a",&color_.w, 0.005f, -100.0f, 100.0f, "%f");
  }

  if(ImGui::Button("Reset")){
    color_.x = 0.0f;
    color_.y = 0.0f;
    color_.z = 0.0f;
    color_.w = 1.0f;
  }


  ImGui::End();

}

