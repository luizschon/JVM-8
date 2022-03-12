#include "class_file.hpp"
#include "types_definition.hpp"

class CP_Info {
public:
    u1 tag;
    virtual ~CP_Info();
    virtual u2 get_tag();
};

class Constant_Utf8_Info : public CP_Info {
private:
    u2 length;
    // u1 bytes[length]; -> length isnt defined at runtime so we use vector instead
    vector<u1> bytes;

public:
    Constant_Utf8_Info(ifstream &file) {
        tag = CONSTANT_Utf8;        
        length = read_u2(file);

        for (auto i = 0; i < length; i++)
            bytes.push_back(read_u1(file));
    }

    u2 get_tag() override {
        return tag;
    }
};