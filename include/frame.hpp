#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "class_file.hpp"
#include "constant_pool_info.hpp"
#include "types.hpp"
#include <algorithm>
#include <stack>

// TODO: change type of local_var_array
typedef struct frame_t {
    vector<u1> local_variable_array;
    stack<u1> operands;
    class_file* class_f;
    void push_op(u1 value);
    u1 pop_op();
} frame_t;

typedef stack<frame_t> frames_t;

#endif // _FRAME_HPP