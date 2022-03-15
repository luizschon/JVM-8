// #ifndef _STACK_MAP_FRAME_HPP
// #define _STACK_MAP_FRAME_HPP 

// #include "types_definition.hpp"
// #include "verification_type_info.hpp"
// #include <vector>

// struct same_frame {
//     u1 frame_type = SAME; /* 0-63 */
// };

// struct same_locals_1_stack_item_frame {
//     u1 frame_type = SAME_LOCALS_1_STACK_ITEM; /* 64-127 */
//     verification_type_info_vec stack; // verification_type_info stack[1];
// };

// struct same_locals_1_stack_item_frame_extended {
//     u1 frame_type = SAME_LOCALS_1_STACK_ITEM_EXTENDED; /* 247 */
//     u2 offset_delta;
//     verification_type_info_vec stack; // verification_type_info stack[1];
// };

// struct chop_frame {
//     u1 frame_type = CHOP; /* 248-250 */
//     u2 offset_delta;
// };

// struct same_frame_extended {
//     u1 frame_type = SAME_FRAME_EXTENDED; /* 251 */
//     u2 offset_delta;
// };

// struct append_frame {
//     u1 frame_type = APPEND; /* 252-254 */
//     u2 offset_delta;
//     verification_type_info_vec locals;// verification_type_info locals[frame_type - 251];
// };

// struct full_frame {
//     u1 frame_type = FULL_FRAME; /* 255 */
//     u2 offset_delta;
//     u2 number_of_locals;
//     verification_type_info_vec locals; // verification_type_info locals[number_of_locals];
//     u2 number_of_stack_items;
//     verification_type_info_vec stack; // verification_type_info stack[number_of_stack_items];
// };

// union stack_map_frame {
//     stack_map_frame(vector<u1>)
//     same_frame;
//     same_locals_1_stack_item_frame;
//     same_locals_1_stack_item_frame_extended;
//     chop_frame;
//     same_frame_extended;
//     append_frame;
//     full_frame;
// };

// #endif // _STACK_MAP_FRAME_HPP
