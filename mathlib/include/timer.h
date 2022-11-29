#ifndef __TIMER_H__
#define __TIMER_H__ 1

class Time {
 public:
  Time() = delete;

  static float delta_time_;
  static float last_time_;
  static float current_time_;
  static float fps_;

};

#endif