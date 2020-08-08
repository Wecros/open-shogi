#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

class Shogi : public Sprite {
    GODOT_CLASS(Shogi, Sprite)

private:
    float time_passed;

public:
    static void _register_methods();

    Shogi();
    ~Shogi();

    void _init(); // our initializer called by Godot

    void _process(float delta);
};

}

#endif
