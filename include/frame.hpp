#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "class_file.hpp"
#include "types.hpp"
#include <stack>

struct Array_type;
struct class_container;

typedef struct operand_t {
    u1 tag;
    union {
        u4              int_type;
        u4              float_type;
        u8              long_type;
        u8              double_type;

        u4              bool_type;
        u4              byte_type;
        u4              char_type;
        u4              short_type;
        
        string          *string_type;
        Array_type      *array_type;
        class_container *class_type;
    };
} operand_t;

typedef struct Array_type {
    vector<operand_t> *array;
} Array_type;

// TODO: change type of local_var_array?
typedef struct frame_t {
    frame_t(method_info*, class_file*);

    stack<u1> operands;
    vector<u1> local_variable_array;

    class_file* class_f;
    method_info* mthd_info = nullptr;
    cp_info_vector cp_reference;
    Code_attribute* code = nullptr;
    u4 pc;
    
    void push_op(u1);
    u1 pop_op();
    u1 top_op();
    bool empty_op();
} frame_t;

struct stack_frame {
    stack<frame_t> stack_f;
    void push(frame_t);
    frame_t pop();
    frame_t top();
    bool empty();
};

#endif // _FRAME_HPP