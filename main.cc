#include <iostream>
#include <cmath>   // for std::sin and M_PI

int main() {
    const double amplitude = 10.0;   // starting maximum wave height
    const double decay = 0.95;       // how much the wave shrinks each cycle
    const double frequency = 0.2;    // speed of oscillation (controls wave length)

    double value = amplitude;        // current amplitude

    for (int t = 0; t < 100; ++t) {
        // compute echo wave = sine * current amplitude
        double echo = value * std::sin(frequency * t);

        std::cout << "t=" << t << " value=" << echo << std::endl;

        // reduce amplitude slightly after each step (like fading sound)
        value *= decay;
    }

    return 0;
}
