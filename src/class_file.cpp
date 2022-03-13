#pragma once
#include "../include/class_file.hpp"
#include "../include/constant_pool_info.hpp"
#include "../include/cmd_arguments.hpp"
#include <iomanip>

using namespace std;

u1 read_u1(ifstream &file) 
{
    u1 data = 0;
    file.read(reinterpret_cast<char *>(&data), 1);
    return data;
}

u2 read_u2(ifstream &file)
{
    u1 byte = 0;
    u2 data = 0;  
    for (int i = 0; i < sizeof(u2); i++)
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}

u4 read_u4 (ifstream &file)
{
    u1 byte = 0;
    u4 data = 0;
    for (int i = 0; i < sizeof(u4); i++) 
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}

u8 read_u8(ifstream &file) 
{
    u1 byte = 0;
    u8 data = 0;
    for (int i = 0; i < sizeof(u8); i++) 
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}

// finish docs
ifstream open_file(int argc, char** argv)
{
    CmdArgs cmd_args;
    cmd_args.init(argc, argv);

    // if (cmd_args.read_bytecode)
    // else

    // open given file and return
    string filename = cmd_args.filename;
    ifstream file(filename, ios::binary);
    return file;
}

// finish docs
void get_metadata(class_file &class_f, ifstream &file) 
{
    // read class file fields
    u4 magic     = read_u4(file);        // signature (0xCAFEBABE)
    u2 minor_ver = read_u2(file);        // minor version
    u2 major_ver = read_u2(file);        // major version
    
    cout << setw(50) << left << "Reading bytecodes" << setfill('-') << endl;
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << left << "Signature " << right << " 0x" << uppercase << hex << magic << endl;
    cout.flags(f);
    cout << setw(50) << left << "Minor version " << right << " " << minor_ver << endl;
    cout << setw(50) << left << "Major version " << right << " " << major_ver << endl;
}

// finish docs
void get_constant_pool(class_file &class_f, ifstream &file)
{
    u2 const_pool_count = read_u2(file);
    cout << setw(50) << left << "Constant Pool Count " 
         << right << " " << const_pool_count << endl;
    
    int iterator_counter = const_pool_count - 1;
    while (iterator_counter--)
    {
        u1 tag = read_u1(file);
        switch (tag) {
            case CONSTANT_Utf8: // utf8
                class_f.utf8_pool.push_back(CONSTANT_utf8_info(file));
                break;
            case CONSTANT_Integer: // integer
                class_f.integer_pool.push_back(CONSTANT_integer_info(file));
                break;
            case CONSTANT_Float: // float
                class_f.float_pool.push_back(CONSTANT_float_info(file));
                break;
            case CONSTANT_Long: // long
                class_f.long_pool.push_back(CONSTANT_long_info(file));
                iterator_counter--; // Long uses 8 bytes (Large numeric continued)
                break;
            case CONSTANT_Double: // double
                class_f.double_pool.push_back(CONSTANT_double_info(file));
                iterator_counter--; // Double uses 8 bytes (Large numeric continued)
                break;
            case CONSTANT_Class: // class
                class_f.class_pool.push_back(CONSTANT_class_info(file));
                break;
            case CONSTANT_String: // string
                class_f.string_pool.push_back(CONSTANT_string_info(file));
                break;
            case CONSTANT_Fieldref: // fieldref
                class_f.fieldref_pool.push_back(CONSTANT_fieldref_info(file));
                break;
            case CONSTANT_Methodref: // methodref
                class_f.methodref_pool.push_back(CONSTANT_methodref_info(file));
                break;
            case CONSTANT_InterfaceMethodref: // InterfaceMethodref
                class_f.interface_methodref_pool.push_back(CONSTANT_interface_methodref_info(file));
                break;
            case CONSTANT_NameAndType: // Nameandtype
                class_f.name_and_type_pool.push_back(CONSTANT_name_and_type_info(file));
                break;
            case CONSTANT_MethodHandle: // methodhandle
                class_f.method_handle_pool.push_back(CONSTANT_method_handle_info(file));
                break;
            case CONSTANT_MethodType: // methodtype
                class_f.method_type_pool.push_back(CONSTANT_method_type_info(file));
                break;
            case CONSTANT_InvokeDynamic: // invokedynamic
                class_f.invoke_dynamic_pool.push_back(CONSTANT_invoke_dynamic_info(file));
                break;
            default: // invalid type
                cout << "ERROR IN TAG" << endl;
                break;
        }
    }
}

void get_class_data(class_file &class_f, ifstream &file)
{
    class_f.access_flag = read_u2(file);
    class_f.this_class  = read_u2(file);
    class_f.super_class = read_u2(file);
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << left << "Access flag: " << right << " 0x" << uppercase << hex << class_f.access_flag << endl;
    cout.flags(f);
    cout << "This class idx: " << class_f.this_class << endl;
    cout << "Super class idx: " << class_f.super_class << endl;

    cout << setw(50) << "Interfaces " << endl;
    get_interfaces(class_f, file);

    cout << setw(50) << "Fields " << endl;
    get_fields(class_f, file);

    cout << setw(50) << "Methods " << endl;
    get_methods(class_f, file);

    cout << setw(50) << "Attributes " << endl;
    get_attributes(class_f, file);
}

void get_interfaces(class_file &class_f, ifstream &file)
{
    class_f.interfaces_count = read_u2(file);
    cout << "Interfaces count: " << class_f.interfaces_count << endl;
    for (int i = 0; i < class_f.interfaces_count; i++)
        class_f.interfaces.push_back(read_u2(file));

    cout << "Interfaces: [ ";
    for (int i = 0; i < class_f.interfaces_count; i++)
        cout << class_f.interfaces[i] << " ";
    cout << "]" << endl;
}

void get_fields(class_file &class_f, ifstream &file)
{
    class_f.fields_count = read_u2(file);
    cout << "Fields count: " << class_f.fields_count << endl;

    for(int i = 0; i < class_f.fields_count; i++)
        class_f.fields.push_back(field_info(file));

    for(int i = 0; i < class_f.fields_count; i++) 
    {
        ios_base::fmtflags f(cout.flags());
        cout << "Fields_access_flags: " << hex << class_f.fields[i].access_flags << endl;
        cout.flags(f);
        cout << "Descriptor_index: " << class_f.fields[i].descriptor_idx << endl;
        cout << "Name_index: " << class_f.fields[i].name_idx << endl;
        cout << "Attr_count: " << class_f.fields[i].attr_count << endl;
        
        for (int k = 0; k < class_f.fields[i].attr_count; k++)
        {
            cout << "Attr_name_idx: " << class_f.fields[i].attr[k].attr_name_idx << endl;
            cout << "Attr_length: " << class_f.fields[i].attr[k].attr_length << endl;
            cout << "Attributes: [ "; 
            for (int l = 0; l < class_f.fields[i].attr[k].attr_length; l++) 
            {
                cout << class_f.fields[i].attr[k].info[l] << " ";
            }
            cout << "]" << endl;
        }
    }
}

void get_methods(class_file &class_f, ifstream &file)
{
    class_f.methods_count = read_u2(file);
    cout << "Methods count: " << class_f.methods_count << endl;

    for(int i = 0; i < class_f.methods_count; i++)
        class_f.methods.push_back(method_info(file));

    for(int i = 0; i < class_f.methods_count; i++) 
    {
        ios_base::fmtflags f(cout.flags());
        cout << "Methods_access_flags: " << hex << class_f.methods[i].access_flags << endl;
        cout.flags(f);
        cout << "Name_index: " << class_f.methods[i].name_idx << endl;
        cout << "Descriptor_index: " << class_f.methods[i].descriptor_idx << endl;
        cout << "Attr_count: " << class_f.methods[i].attr_count << endl;
        
        for (int k = 0; k < class_f.methods[i].attr_count; k++)
        {
            cout << "Attr_name_idx: " << class_f.methods[i].attr[k].attr_name_idx << endl;
            cout << "Attr_length: " << class_f.methods[i].attr[k].attr_length << endl;
            cout << "Attributes: [ "; 
            for (int l = 0; l < class_f.methods[i].attr[k].attr_length; l++) 
            {
                cout << class_f.methods[i].attr[k].info[l] << " ";
            }
            cout << "]" << endl;
        }
    }
}

void get_attributes(class_file &class_f, ifstream &file)
{
    class_f.attributes_count = read_u2(file);
    cout << "Attributes count: " << class_f.attributes_count << endl;

    for (int i = 0; i  < class_f.attributes_count; i++)
        class_f.attributes.push_back(attr_info(file));

    for (int i = 0; i < class_f.attributes_count; i++) {
        cout << "Attr_name_index: " << class_f.attributes[i].attr_name_idx << endl;
        cout << "Attr_length: " << class_f.attributes[i].attr_length << endl;
        cout << "Attributes_info: [ "; 
        for (int j = 0; j < class_f.attributes[i].attr_length; j++)
            cout << class_f.attributes[i].info[j] << " ";
        cout << "]" << endl; 
    }
}