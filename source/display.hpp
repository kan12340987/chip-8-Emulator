
namespace C8E {
    class Display {
        public:
            static const int cols;
            static const int rows;
            static const int scale;
            int width;
            int height;

        Display(int scale);
        void setpixel(int x, int y);
        void clear();
        void render();
    };
}