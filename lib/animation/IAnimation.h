#ifndef I_ANIMATION_H
#define I_ANIMATION_H
#include <vector>

class IAnimation {
public:
    virtual ~IAnimation() = default;

    virtual std::vector<CRGB> frame();
};

class Wave : public IAnimation {
    int x = 0;

public:
    std::vector<CRGB> frame() {
        std::vector<CRGB> buffer(BOARD_WIDTH * BOARD_HEIGHT, CRGB::Black);

        const int column = x % BOARD_WIDTH;
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            buffer[y * BOARD_WIDTH + column] = CRGB::Green;
        }

        x++;
        return buffer;
    }
};

#endif
