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
}

Sphere::~Sphere(){}


void Sphere::draw(){

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
    //snprintf(type_tmp,17,"%s",type);
    snprintf(name,20,"%s","x");
    strcat(name,index);
    //snprintf(name,20,"%s",index);
    ImGui::DragFloat(name,&sphereOrigin_.x, 0.005f, -100.0f, 100.0f, "%f");
    snprintf(name,20,"%s","y");
    strcat(name,index);
    ImGui::DragFloat(name,&sphereOrigin_.y, 0.005f, -100.0f, 100.0f, "%f");
    snprintf(name,20,"%s","z");
    strcat(name,index);
    ImGui::DragFloat(name,&sphereOrigin_.z, 0.005f, -100.0f, 100.0f, "%f");
    
  }
  //ImGui::ShowDemoWindow();

  ImGui::End();
}



