
class Rect {
    public:
        Rect();
        ~Rect();
        int x;
        int y;
        int w;
        int h;
        bool Contains(float mouseX, float mouseY);
};

