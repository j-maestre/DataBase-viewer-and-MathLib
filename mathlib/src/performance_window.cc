#include <ImGui/imgui.h>

#include "performance_window.h"
#include "timer.h"

void PerformanceWindow::draw() {
  if (!ImGui::Begin("Performance")) {
    ImGui::End();
    return;
  }
  ImGui::Text("Delta time -> %fms", Time::delta_time_ * 1000.0f);
  ImGui::Text("Fps -> %f", Time::fps_);

  ImGui::End();
}