#include "../include/frame.hpp"

void frame_t::push_op(u1 value)
{
    this->operands.push(value);
}

u1 frame_t::pop_op()
{
    if (this->operands.empty()) return -1;
    auto res = this->operands.top();
    this->operands.pop();
    return res;
}

