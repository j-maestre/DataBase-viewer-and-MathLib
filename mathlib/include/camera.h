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

  /**
   * \brief Show a ImGui window with the settings of the camera
   * 
   */
  void cameraSettings();

  /**
   * \brief Update the camera
   * 
   */
  void update();

  /**
   * \brief Resize the camera
   * 
   * \param width Width of the window
   * \param height Height of the window
   */
  void resize(int width, int height);

  /**
   * \brief Getter for the rays
   * 
   * \return const oxml::Vec3* pointer to the rays
   */
  const oxml::Vec3* ray_directions() const;

  //position of the camera
  oxml::Vec3 position_;
  //if the mouse is clicked
  static bool mouse_clicked;

 protected:
 
  //the projection matrix
  oxml::Mat4 projection_;
  //the view matrix
  oxml::Mat4 view_;
  //the inverse of the projection matrix
  oxml::Mat4 inverse_projection_;
  //the view of the projection matrix
  oxml::Mat4 inverse_view_;

  //field of view of the camera
  float fov_;
  //the near point of the camera
  float near_;
  //the far point of the camera
  float far_;

  //pointer to the directiosn of the rays
  oxml::Vec3 *ray_directions_;

  //width of the window
  int width_;
  //height of the window
  int height_;
  //speed of the camera
  float speed_;
  //speed of the rotation of the camera
  float rotation_speed_;
  
  //vector forward of the camera
  oxml::Vec3 forward_;
  //vector up of the camera
  oxml::Vec3 up_;
  //vecotr right of the camera
  oxml::Vec3 right_;

  //delta move of the mouse
  oxml::Vec2 delta_;
  //position of the mouse
  oxml::Vec2 mousePosition_;
  //the last known position
  oxml::Vec2 lastMousePosition_;

 private:

  /**
   * \brief Recalcule the projection and the inverse 
   *        projection matrix
   * 
   */
  void recalculeProjection();

  /**
   * \brief Recalcule the ray directions
   * 
   */
  void recalculeRayDirections();

  /**
   * \brief Recalcule the view and inverse view matrix
   * 
   */
  void recalculateView();

  /**
   * \brief calcule the movement of the camera
   * 
   */
  void movement();

  //if the camera is moved
  bool moved_;




};

#endif