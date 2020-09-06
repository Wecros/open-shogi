#ifndef GD_SHOGI_H
#define GD_SHOGI_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {

class Shogi : public Node2D {
    GODOT_CLASS(Shogi, Node2D)

private:
    float time_passed;
    float time_emit;
    float amplitude;
    float speed;

public:
    static void _register_methods();

    Shogi();
    ~Shogi();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    void set_speed(float p_speed);
    float get_speed();
};

}

#endif
