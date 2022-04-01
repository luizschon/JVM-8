#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "class_file.hpp"
#include "constant_pool_info.hpp"
#include "types.hpp"
#include <algorithm>
#include <stack>

typedef struct operand_t {
    union {
        u4 int_data;
        u4 float_data;
        u8 long_type;
        u8 double_type;

        u4 bool_type;
        u4 byte_type;
        u4 char_type;
        u4 short_type;
/*
        string;
        array;
        class_container;*/
    };
} operand_t;

// TODO: change type of local_var_array?
typedef struct frame_t {
    vector<u1> local_variable_array;
    stack<u1> operands;
    class_file* class_f;
    void push_op(u1);
    u1 pop_op();
    u1 top_op();
    bool empty_op();
} frame_t;

struct stack_frame {
    stack<frame_t> stack_frame;
    void push(frame_t);
    frame_t pop();
    frame_t top();
    bool empty();
};

#endif // _FRAME_HPP