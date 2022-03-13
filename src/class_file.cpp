#pragma once
#include "../include/class_file.hpp"
#include "../include/constant_pool_info.hpp"
#include "../include/cmd_arguments.hpp"
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <ostream>

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
         
    void* data = NULL;

    int iterator_counter = const_pool_count - 1;
    while (iterator_counter--)
    {
        u1 tag = read_u1(file);
        switch (tag) {
            case CONSTANT_Utf8: // utf8
                data = new CONSTANT_utf8_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << (int)(((CONSTANT_utf8_info *) data)->tag) << endl;
                break;
            case CONSTANT_Integer: // integer
                data = new CONSTANT_integer_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_integer_info *) data)->tag) << endl;
                break;
            case CONSTANT_Float: // float
                data = new CONSTANT_float_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_float_info *) data)->tag) << endl;
                break;
            case CONSTANT_Long: // long
                data = new CONSTANT_long_info(file);
                iterator_counter--; // Long uses 8 bytes (Large numeric continued)
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_long_info *) data)->tag) << endl;
                break;
            case CONSTANT_Double: // double
                data = new CONSTANT_double_info(file);
                iterator_counter--; // Double uses 8 bytes (Large numeric continued)
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_double_info *) data)->tag) << endl;
                break;
            case CONSTANT_Class: // class
                data = new CONSTANT_class_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_class_info *) data)->tag) << endl;
                break;
            case CONSTANT_String: // string
                data = new CONSTANT_string_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_string_info *) data)->tag) << endl;
                break;
            case CONSTANT_Fieldref: // fieldref
                data = new CONSTANT_fieldref_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_fieldref_info *) data)->tag) << endl;
                break;
            case CONSTANT_Methodref: // methodref
                data = new CONSTANT_methodref_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_methodref_info *) data)->tag) << endl;
                break;
            case CONSTANT_InterfaceMethodref: // InterfaceMethodref
                data = new CONSTANT_interface_methodref_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_interface_methodref_info *) data)->tag) << endl;
                break;
            case CONSTANT_NameAndType: // Nameandtype
                data = new CONSTANT_name_and_type_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_name_and_type_info *) data)->tag) << endl;
                break;
            case CONSTANT_MethodHandle: // methodhandle
                data = new CONSTANT_method_handle_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_method_handle_info *) data)->tag) << endl;
                break;
            case CONSTANT_MethodType: // methodtype
                data = new CONSTANT_method_type_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_method_type_info *) data)->tag) << endl;
                break;
            case CONSTANT_InvokeDynamic: // invokedynamic
                data = new CONSTANT_invoke_dynamic_info(file);
                cout << setw(50) << left << "Tag " << right << " " 
                     << ((int)((CONSTANT_invoke_dynamic_info *) data)->tag) << endl;
                break;
            default: // invalid type
                cout << "ERROR IN TAG" << endl;
                break;
        }
        if (class_f.constant_pool == NULL)
            class_f.constant_pool = create_pool(data);
        else
            add_to_pool(class_f.constant_pool, data);
    }
}

cp_info* create_pool(void* data) 
{
    cp_info* constant_pool = new cp_info;

    if (!constant_pool) return NULL;

    constant_pool->data = data;
    constant_pool->next = NULL;

    return constant_pool;
}

void add_to_pool(cp_info* constant_pool, void* data) 
{
    cp_info* new_item = new cp_info;
    cp_info* temp = constant_pool;

    if (!new_item) return;

    new_item->data = data;
    new_item->next = NULL;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_item;
}

void delete_pool(cp_info *pool) 
{
    if (pool->next) delete_pool(pool->next);
    delete pool;
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