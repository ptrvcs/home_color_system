#include <iostream>
#include <cmath> // for std::sin and M_PI
#include <vector>

class Box
{
public:
    Box(int w, int h) : width(w), height(h) {}
    void print() const
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }
    void drawBox(const Box &box, int x, int y)
    {
        std::cout << "Drawing box at (" << x << ", " << y << ")\n";
        box.print();
    }

private:
    const int width;
    const int height;
    std::vector<std::vector<int>> canvas_matrix;
};

class Canvas
{
public:
    Canvas(int w, int h) : width(w), height(h), canvas_matrix(h, std::vector<int>(w, 0)) { initBorders(); }

    void drawCanvas()
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (canvas_matrix[i][j] == 1)
                    std::cout << ".";
                else if (canvas_matrix[i][j] == 2)
                    std::cout << ".";
                else
                    std::cout << " ";
            }
            std::cout << "\n";
        }
    }

private:
    void initBorders()
    {
        for (int i = 0; i < height; ++i)
        {
            if (i == 0 || i == height - 1)
            {
                for (int j = 0; j < width; ++j)
                {
                    canvas_matrix[i][j] = 1; // Top and bottom borders
                }
            }
            else
            {
                canvas_matrix[i][0] = 2;         // Left border
                canvas_matrix[i][width - 1] = 2; // Right border
            }
        }
    }

private:
    const int width;
    const int height;
    std::vector<std::vector<int>> canvas_matrix;
};

int main()
{
    // Box box(10, 5);
    // box.print();
    Canvas canvas(100, 20);
    canvas.drawCanvas();

    const int amplitude = 10.0; // starting maximum wave height
    const int decay = 0.95;     // how much the wave shrinks each cycle
    const int frequency = 0.2;  // speed of oscillation (controls wave length)

    int value = amplitude; // current amplitude

    for (int t = 0; t < 100; ++t)
    {
        // compute echo wave = sine * current amplitude
        int echo = value * std::sin(frequency * t);

        std::cout << "t=" << t << " value=" << echo << std::endl;

        // reduce amplitude slightly after each step (like fading sound)
        value *= decay;
    }

    return 0;
}

