
#ifndef __FIGURE_H__
#define __FIGURE_H_ 1

class Figure : public Entity{
    public:
        Figure();
        ~Figure();
        float size_;
        float pos_x_;
        float pos_y_;
        xemath::Mat3 *circle_points_;

    private:


};

#endif