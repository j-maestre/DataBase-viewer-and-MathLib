#ifndef __CAMERA_H__
#define __CAMERA_H__ 1

#include <oxml/Vec3.h>
#include <oxml/Mat4.h>

class Camera {
 public:
  Camera(float fov, float near, float far);

  ~Camera();

  void update();
  void resize(int width, int height);

  const oxml::Vec3* ray_directions() const;

  oxml::Vec3 position_;

 protected:
 
  oxml::Mat4 projection_;
  oxml::Mat4 view_;
  oxml::Mat4 inverse_projection_;
  oxml::Mat4 inverse_view_;

  float fov_;
  float near_;
  float far_;

  oxml::Vec3 forward_;
  oxml::Vec3 *ray_directions_;

  int width_;
  int height_;

 private:
  void recalculeProjection();
  void recalculeRayDirections();
  void recalculateView();

};

#endif