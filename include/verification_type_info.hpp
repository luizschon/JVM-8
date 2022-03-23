#include <memory>
#include "types.hpp"

using namespace std;

typedef enum {
    ITEM_Top = 0,
    ITEM_Integer = 1,
    ITEM_Float = 2,
    ITEM_Double = 3,
    ITEM_Long = 4,
    ITEM_Null = 5,
    ITEM_UninitializedThis = 6,
    ITEM_Object = 7,
    ITEM_Uninitialized = 8,
} Variable_Types;

struct Top_variable_info {
    Top_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Top */
};

struct Integer_variable_info {
    Integer_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Integer */
};

struct Float_variable_info {
    Float_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Float */
};

struct Double_variable_info {
    Double_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Double */
};

struct Long_variable_info {
    Long_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Long */
};

struct Null_variable_info {
    Null_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Null */
};

struct UninitializedThis_variable_info {
    UninitializedThis_variable_info(bytestream_it&);
    u1 tag; /* ITEM_UninitializedThis */
};

struct Object_variable_info {
    Object_variable_info(bytestream_it&);
    u1 tag; /* ITEM_Object */
    u2 cpool_index;
};

struct Uninitialized_variable_info {
    Uninitialized_variable_info(bytestream_it&);
    u1 tag = ITEM_Uninitialized; /* 8 */
    u2 offset;
};

union verification_type_info {
    verification_type_info(bytestream_it&);
    Top_variable_info _top_var;
    Integer_variable_info _integer;
    Float_variable_info _float;
    Long_variable_info _long;
    Double_variable_info _double;
    Null_variable_info _null;
    UninitializedThis_variable_info _uninitialized_this;
    Object_variable_info _object;
    Uninitialized_variable_info _uninitialized_var;
};

typedef vector<shared_ptr<verification_type_info>> verification_type_info_vec;