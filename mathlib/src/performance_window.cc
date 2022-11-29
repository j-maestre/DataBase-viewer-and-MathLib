#include <ImGui/imgui.h>

#include "performance_window.h"
#include "timer.h"

void PerformanceWindow::draw() {
  if (!ImGui::Begin("Performance")) {
    ImGui::End();
    return;
  }
  ImGui::Text("Delta time -> %fms", Time::delta_time_);
  ImGui::Text("Fps -> %f", Time::fps_);

  ImGui::End();
}