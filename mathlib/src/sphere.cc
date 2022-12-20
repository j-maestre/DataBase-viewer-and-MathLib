#include "sphere.h"
#include "game_loop.h"
#include <ImGui/imgui.h>
#include <string.h>
#include <string>

Sphere::Sphere(){
    radius_ = 0.5f;
    sphereColor_ = oxml::Vec4(1.0f, 0.0f, 1.0f, 1.0f);
    sphereOrigin_ = oxml::Vec3(oxml::Vec3::zero);
}

Sphere::Sphere(const Sphere& o){
    radius_ = o.radius_;
    sphereColor_ =  o.sphereColor_;
    sphereOrigin_ = o.sphereOrigin_;
    tag_ = o.tag_;
}

Sphere::~Sphere(){}


void Sphere::draw(RayTracer *ray_tracer){
  char buff[20];
  itoa(tag_,buff,10);
  sphereSettings(buff);
  ray_tracer->add_sphere(this);
}

void Sphere::sphereSettings(const char *index){
 if (!ImGui::Begin("Sphere Settings")) {
    ImGui::End();
    return;
  }
    char name[20];
    snprintf(name,20,"%s","Sphere Positions");
    strcat(name,index);
  
  if (ImGui::CollapsingHeader(name)){
    snprintf(name,20,"%s","Positions");
    strcat(name,index);
    ImGui::Text(name);

    snprintf(name,20,"%s","x");
    strcat(name,index);
    ImGui::DragFloat(name,&sphereOrigin_.x, 0.005f, -100.0f, 100.0f, "%f");

    snprintf(name,20,"%s","y");
    strcat(name,index);
    ImGui::DragFloat(name,&sphereOrigin_.y, 0.005f, -100.0f, 100.0f, "%f");
    
    snprintf(name,20,"%s","z");
    strcat(name,index);
    ImGui::DragFloat(name,&sphereOrigin_.z, 0.005f, -100.0f, 100.0f, "%f");
    
    snprintf(name,20,"%s","Albedo");
    strcat(name,index);
    if(ImGui::ColorPicker3(name,color_)){
      sphereColor_ = oxml::Vec4(color_[2], color_[1], color_[0], 1.0f);
    }
    
  }

  ImGui::Button("Add");
  if(ImGui::IsItemClicked()){
    GameLoop::Instance().ReallocSpheres(GameLoop::Instance().sphere_size_+1);
  }
  //ImGui::ShowDemoWindow();

  ImGui::End();
}



