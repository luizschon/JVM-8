#include "../include/frame.hpp"
#include "../include/utils.hpp"
#include <iostream>

frame_t::frame_t(method_info* method, class_file* cls_f)
{
    cp_reference = cls_f->constant_pool;
    class_f = cls_f;
    mthd_info = method;
    pc = 0;

    for (auto attr : mthd_info->attr)
    {
        auto attr_info = to_attr_info(attr);
        if (attr_info->tag == Code)
            code = attr_info->_code;
    }

    local_variable_array.resize(code->max_locals);
}

void frame_t::push_op(u1 value)
{
    this->operands.push(value);
}

u1 frame_t::pop_op(){
    if (this->empty_op())
        throw runtime_error("frame_t::pop_op: Operand stack is empty.");
    auto res = this->operands.top();
    this->operands.pop();
    return res;
}

u1 frame_t::top_op()
{
    return this->operands.top();
}

bool frame_t::empty_op()
{
    return this->operands.empty();
}

void stack_frame::push(frame_t frame)
{
    this->stack_f.push(frame);
}

frame_t stack_frame::pop()
{
    if (this->empty())
        throw runtime_error("stack_frame::pop: Stack frame is empty.");
    auto res = this->stack_f.top();
    this->stack_f.pop();
    return res;
}

bool stack_frame::empty()
{
    return this->stack_f.empty();
}

frame_t stack_frame::top()
{
    return this->stack_f.top();
}