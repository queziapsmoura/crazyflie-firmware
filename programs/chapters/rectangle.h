#ifndef rectangle_h
#define rectangle_h

class Rectangle
{
    public:
        Rectangle();
        void set_values(int w, int h);
        int area;
    private:
        int width;
        int height;
}

#endif