#ifndef __CAMERA_H__
#define __CAMERA_H__ 1

#include <SDL/SDL.h>

#include <oxml/Vec3.h>
#include <oxml/Vec2.h>
#include <oxml/Mat4.h>

class Camera {
 public:
  Camera(float fov, float near, float far);

  ~Camera();

  void update();
  void resize(int width, int height); //OnResize

  const oxml::Vec3* ray_directions() const;

  const oxml::Vec3 GetPosition() const;
  const oxml::Vec3 GetForward() const;

  oxml::Vec3 position_;
  static bool mouse_clicked;

 protected:
 
  oxml::Mat4 projection_;
  oxml::Mat4 view_;
  oxml::Mat4 inverse_projection_;
  oxml::Mat4 inverse_view_;

  float fov_;
  float near_;
  float far_;

  oxml::Vec3 forward_;
  oxml::Vec3 up_;
  oxml::Vec3 right_;
  oxml::Vec3 *ray_directions_;

  int width_;
  int height_;
  float speed_;
  float rotation_speed_;

  oxml::Vec2 delta_;
  oxml::Vec2 mousePosition_;
  oxml::Vec2 lastMousePosition_;

 private:
  void recalculeProjection();
  void recalculeRayDirections();
  void recalculateView();
  void movement();
  bool moved_;




};

#endif