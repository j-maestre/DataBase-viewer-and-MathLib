Figure::Figure(){
    size_ = 1.0f;
    pos_x_ = 1.0f;
    pos_y_ = 1.0f;
    *circle_points_ = (xemath::Mat3*) malloc(sizeof(xemath::Mat3)*180);
}
Figure::~Figure(){
    free(circle_points_);
}