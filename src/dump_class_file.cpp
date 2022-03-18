#include "../include/dump_class_file.hpp"
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <bits/stdc++.h>

using namespace std;

unsigned int pos_counter = 0;

void print_all(class_file &class_f, string filename)
{
    int pos_i = filename.find("/"), pos_f = filename.find(".class") - pos_i;
    string outname = filename.substr(pos_i + 1, pos_f - 1);

    ofstream outfile("./out/" + outname + ".md");
    outfile << "# **" << outname << "**" << endl << endl;
    print_general_info(class_f, outfile);
    print_pool(class_f, outfile);
    print_interfaces(class_f, outfile);
    // print_fields(class_f, outfile, class_f.constant_pool);
    // print_methods(class_f, outfile);
    print_attributes(class_f, outfile);
    outfile.close();
    pos_counter = 0;
}

void print_general_info(class_file &class_f, ofstream &outfile)
{
    outfile << "## **General Information**" << endl;
    ios_base::fmtflags f(outfile.flags());
    outfile << "Magic " << "`0x" << uppercase << hex << class_f.magic << "`  " << endl;
    outfile.flags(f);
    
    outfile << "Minor version `" << class_f.minor_version << "`  " << endl;
    outfile << "Major version `" << class_f.major_version << "`";
    outfile << "[`" << get_version(class_f.major_version, class_f.minor_version) << "`]  " << endl;
    
    outfile << "Constant Pool Count `" << class_f.constant_pool_count << "`  " << endl;
    
    ios_base::fmtflags g(outfile.flags());
    outfile << "Access Flags `0x" << setw(4) << setfill('0') << hex << class_f.access_flag << "`";
    outfile << "[`" << get_class_access_flags(class_f.access_flag) << "`]  " << endl;
    outfile.flags(g);
    
    auto this_class = class_f.constant_pool[class_f.this_class - 1]->_class->name_idx;
    outfile << "This Class `" << class_f.this_class << "` ";
    outfile << "`<" << get_utf8_content(*(class_f.constant_pool[this_class - 1]->_utf8)) << ">`  " << endl;
    
    auto super_class = class_f.constant_pool[class_f.super_class - 1]->_class->name_idx;
    outfile << "Super Class `" << class_f.super_class << "` ";
    outfile << "`<" << get_utf8_content(*(class_f.constant_pool[super_class - 1]->_utf8)) << ">`  " << endl;

    outfile << "Interfaces Count `" << class_f.interfaces_count << "`  " << endl;
    outfile << "Fields Count `" << class_f.fields_count << "`  " << endl;
    outfile << "Methods Count `" << class_f.methods_count << "`  " << endl;
    outfile << "Attributes Count `" << class_f.attributes_count << "`" << endl;
    outfile << endl;
}

string get_version(u2 major, u2 minor)
{
    if (major >= 45 && major <= 48)
        return "1." + to_string(major - 45 + 1);
    return to_string(major - 49 + 5);
}

string get_class_access_flags(u2 access_flags)
{
    string class_access = " ";
    u2 flag;
    bitset<16> z(access_flags);
    cout << "ACCESS FLAG PRIMEIRA VEZ: " << z << endl;
    for (int j = 0; j < 4; j++) 
    {
        // 0x0021 = 0010 0001
        // 0010 0001 >> 1 => 0001 (1) 0000 (0)
        // 1 -> 0x0002
        // 20 -> 0x0000

        // flag = access_flags % 0x16 * (0x16 * j);
        flag = access_flags >> 1;
        access_flags /= 10;
        bitset<16> x(access_flags);
        bitset<16> y(access_flags);
        cout << "FLAG: " << y << endl;
        cout << "ACCESS FLAG: " << x << endl;
        switch (flag)
        {
            case ACC_PUBLIC:
                class_access += "ACC_PUBLIC ";
                break;
            case ACC_FINAL:
                class_access += "ACC_FINAL ";
                break;
            case ACC_SUPER:
                class_access += "ACC_SUPER ";
                break;
            case ACC_INTERFACE:
                class_access += "ACC_INTERFACE ";
                break;
            case ACC_ABSTRACT:
                class_access += "ACC_ABSTRACT ";
                break;
            case ACC_SYNTHETIC:
                class_access += "ACC_SYNTHETIC ";
                break;
            case ACC_ANNOTATION:
                class_access += "ACC_ANNOTATION ";
                break;
            case ACC_ENUM:
                class_access += "ACC_ENUM ";
                break;
            default:
                cout << "INVALID ACCESS FLAG IN DUMP_CLASS_FILE.CPP" << endl;
                break;
        }
    }
    return class_access;
}

void print_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Constant Pool**" << endl;
    for (auto i : class_f.constant_pool) 
    {
        pos_counter++;
        switch (i->tag) 
        {
            case CONSTANT_Utf8:
                print_utf8_pool(*(i->_utf8), outfile);
                break;
            case CONSTANT_Integer:
                print_integer_pool(*(i->_integer), outfile);
                break;
            case CONSTANT_Float:
                print_float_pool(*(i->_float), outfile);
                break;
            case CONSTANT_Long:
                print_long_pool(*(i->_long), outfile);
                break;
            case CONSTANT_Double:
                print_double_pool(*(i->_double), outfile);
                break;
            case CONSTANT_Class:
                print_class_pool(*(i->_class), outfile, class_f.constant_pool);
                break;
            case CONSTANT_String:
                print_string_pool(*(i->_string), outfile, class_f.constant_pool);
                break;
            case CONSTANT_Fieldref:
                print_fieldref_pool(*(i->_fieldref), outfile, class_f.constant_pool);
                break;
            case CONSTANT_Methodref:
                print_methodref_pool(*(i->_methodref), outfile);
                break;
            case CONSTANT_InterfaceMethodref:
                print_interface_methodref_pool(*(i->_interface_methodref), outfile);
                break;
            case CONSTANT_NameAndType:
                print_name_and_type_pool(*(i->_name_and_type), outfile);
                break;
            case CONSTANT_MethodHandle:
                print_method_handle_pool(*(i->_method_handle), outfile);
                break;
            case CONSTANT_MethodType:
                print_method_type_pool(*(i->_method_type), outfile);
                break;
            case CONSTANT_InvokeDynamic:
                print_invoke_dynamic_pool(*(i->_invoke_dynamic), outfile);
                break;
            case CONSTANT_Empty:
                print_empty_pool(outfile);
                break;
            default:
                cout << "INVALID TAG" << endl;
                break;
        }
    }
}

string get_utf8_content(bytestream &bytes)
{
    string out = "";
    for (auto j : bytes)
         out += j;
    return out;
}

void print_utf8_pool(CONSTANT_utf8_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Utf8_info*" << endl;
    outfile << "- Length `" << info.length << "`" << endl;
    outfile << "- Bytes [ `" << get_utf8_content(info) << "`]" << endl << endl;
}

void print_integer_pool(CONSTANT_integer_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Integer_info*" << endl;
    outfile << "- Bytes `" << info.bytes << "`" << endl;
    outfile << endl;
}

void print_float_pool(CONSTANT_float_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Float_info*" << endl;
    ios_base::fmtflags f(outfile.flags());
    outfile << "- Bytes `0x" << hex << info.bytes << "`" << endl;
    outfile.flags(f);
    outfile << "- Float `" << calc_float(info.bytes) << "`" << endl;
    outfile << endl;
}

void print_long_pool(CONSTANT_long_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Long_info*" << endl;
    ios_base::fmtflags f(outfile.flags());
    outfile << "- High Bytes `0x" << hex << info.high_bytes << "`" << endl;
    outfile << "- Low Bytes `0x" << hex << info.low_bytes << "`" << endl;
    outfile.flags(f);
    outfile << "- Long `" << calc_long(info.high_bytes, info.low_bytes) << "`" << endl;
    outfile << endl;
}

void print_double_pool(CONSTANT_double_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Double_info*" << endl;
    ios_base::fmtflags f(outfile.flags());
    outfile << "- High Bytes `0x" << hex << info.high_bytes << "`" << endl;
    outfile << "- Low Bytes `0x" << hex << info.low_bytes << "`" << endl;
    outfile.flags(f);
    outfile << "- Double `" << calc_double(info.high_bytes, info.low_bytes) << "`" << endl;
    outfile << endl;
}

void print_class_pool(CONSTANT_class_info &info, ofstream &outfile, cp_info_vector &constant_pool)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Class_info*" << endl;
    outfile << "- Name Index `" << info.name_idx << "`" << endl;
    outfile << "- Class Name `<";
    for (auto i : constant_pool[info.name_idx - 1]->_utf8->bytes)
        outfile << i;
    outfile << ">`" << endl << endl;
}

void print_string_pool(CONSTANT_string_info &info, ofstream &outfile, cp_info_vector &constant_pool)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_String_info*" << endl;
    outfile << "- String Index `" << info.str_idx << "`" << endl;
    outfile << "- String `<";
    for (auto i : constant_pool[info.str_idx - 1]->_utf8->bytes)
        outfile << i;
    outfile << ">`" << endl << endl;
}

void print_fieldref_pool(CONSTANT_fieldref_info &info, ofstream &outfile, cp_info_vector &constant_pool)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Fieldref_info*" << endl;
    outfile << "- Class Index `" << info.class_idx << "`" << endl;
    outfile << "- Class Name `<";
    
    auto name_index = constant_pool[info.class_idx - 1]->_class->name_idx;
    for (auto i : constant_pool[name_index - 1]->_utf8->bytes)
        outfile << i;
    outfile << ">`" << endl;
    outfile << "- Name And Type Index `" << info.name_and_type_idx << "`" << endl;
    
    auto name_idx = constant_pool[info.name_and_type_idx - 1]->_name_and_type->name_idx;
    auto descriptor_index = constant_pool[info.name_and_type_idx - 1]->_name_and_type->descriptor_idx;
    outfile << "- Name And Type `<";
    for (auto i : constant_pool[name_idx - 1]->_utf8->bytes) 
        outfile << i;
    outfile << ":";
    for (auto i : constant_pool[descriptor_index - 1]->_utf8->bytes)
        outfile << i;
    outfile << ">`" << endl << endl;
}

void print_methodref_pool(CONSTANT_methodref_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Methodref_info*" << endl;
    outfile << "- Class Index `" << info.class_idx << "`" << endl;
    outfile << "- Name And Type Index `" << info.name_and_type_idx << "`" << endl;
    outfile << endl;
}

void print_interface_methodref_pool(CONSTANT_interface_methodref_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Interface_methodref_info*" << endl;
    outfile << "- Class Index `" << info.class_idx << "`" << endl;
    outfile << "- Name And Type Index `" << info.name_and_type_idx << "`" << endl;
    outfile << endl;
}

void print_name_and_type_pool(CONSTANT_name_and_type_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Name_and_type*" << endl;
    outfile << "- Name Index `" << info.name_idx << "`" << endl;
    outfile << "- Descriptor Index `" << info.descriptor_idx << "`" << endl;
    outfile << endl;
}

void print_method_handle_pool(CONSTANT_method_handle_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Method_handle_info*" << endl;
    outfile << "- Reference Kind `" << info.reference_kind << "`" << endl;
    outfile << "- Reference Index `" << info.reference_index << "`" << endl;
    outfile << endl;
}

void print_method_type_pool(CONSTANT_method_type_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Method_type*" << endl;
    outfile << "- Descriptor Index `" << info.descriptor_index << "`" << endl;
}

void print_invoke_dynamic_pool(CONSTANT_invoke_dynamic_info &info, ofstream &outfile)
{
    outfile << "### [" << pos_counter << "] *CONSTANT_Invoke_dynamic*" << endl;
    outfile << "- Bootstrap Method Attribute Index `" << info.bootstrap_method_attr_index << "`" << endl;
    outfile << "- Name and Type Index `" << info.name_and_type_index << "`" << endl;
    outfile << endl;
}

void print_empty_pool(ofstream &outfile)
{
    cout << "empty detected" << endl;
    outfile << "### [" << pos_counter << "] *Number continuation*" << endl << endl;
}

void print_interfaces(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Interfaces**" << endl;
    for (int i = 0; i < class_f.interfaces_count; i++)
        outfile << "- Interface `" << class_f.interfaces[i] << "`";
    outfile << endl << endl;
}

// void print_fields(class_file &class_f, ofstream &outfile)
// {
//     outfile << "## **Fields**" << endl;
//     for(int i = 0; i < class_f.fields_count; i++) 
//     {
//         outfile << "### *Field*" << endl;
//         ios_base::fmtflags f(outfile.flags());
//         outfile << "- Fields Access Flags `" << hex << class_f.fields[i].access_flags << "`" << endl;
//         outfile.flags(f);
//         outfile << "- Descriptor Index `" << class_f.fields[i].descriptor_idx << "`" << endl;
//         outfile << "- Name Index `" << class_f.fields[i].name_idx << "`" << endl;
//         outfile << "- Attr Count `" << class_f.fields[i].attr_count << "`" << endl;
        
//         for (int k = 0; k < class_f.fields[i].attr_count; k++)
//         {
//             outfile << "  * Attribute Name Index `" << class_f.fields[i].attr[k].attr_name_idx << "`" << endl;
//             outfile << "  * Attribute Length `" << class_f.fields[i].attr[k].attr_length << "`" << endl;
//             outfile << "  * Attributes [ `"; 
//             for (int l = 0; l < class_f.fields[i].attr[k].attr_length; l++) 
//                 outfile << class_f.fields[i].attr[k].info[l];
//             outfile << "` ]" << endl;
//         }
//     }
//     outfile << endl;
// }

// add attributes info when types are defined
// void print_methods(class_file &class_f, ofstream &outfile)
// {
//     outfile << "## **Methods**" << endl;
//     for(int i = 0; i < class_f.methods_count; i++) 
//     {
//         outfile << "### *Method*" << endl;
//         ios_base::fmtflags f(outfile.flags());
//         outfile << "- Methods Access Flags " << "`0x" << uppercase << hex << class_f.methods[i].access_flags << "`" << endl;
//         outfile.flags(f);
//         outfile << "- Name Index `" << class_f.methods[i].name_idx << "`" << endl;
//         outfile << "- Descriptor Index `" << class_f.methods[i].descriptor_idx << "`" << endl;
//         outfile << "- Attribute Count `" << class_f.methods[i].attr_count << "`" << endl;
        
//         for (int k = 0; k < class_f.methods[i].attr_count; k++)
//         {
//             outfile << "  * Attribute Name Index `" << class_f.methods[i].attr[k].attr_name_idx << "` " << endl;
//             outfile << "  * Attribute Length `" << class_f.methods[i].attr[k].attr_length << "` " << endl;
//             outfile << "  * Attributes  " << endl; 
//             for (int l = 0; l < class_f.methods[i].attr[k].attr_length; l++) 
//                 outfile << "  - `" << (char) class_f.methods[i].attr[k].info[l] << "`" << endl;
//             outfile << endl;
//         }
//     }
//     outfile << endl;
// }

// add attributes info when types are defined
void print_attributes(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Attributes**" << endl;
    for (auto attr : class_f.attributes)
    {
        outfile << "- Attribute Name Index `" << attr->attribute_name_index << "` " << endl;
        outfile << "- Attribute Length `" << attr->attribute_length << "` " << endl;
        outfile << "- Attributes Info  " << endl; 
        outfile << "- Attribute tag (debug) `" << attr->tag << "`" << endl; // REmover
        // if (attr->tag == SourceFile)
        // {
        //     auto _attr = dynamic_pointer_cast<Attribute_Info>(attr);
        //     outfile << "- Sourcefile: `" << _attr->_sourcefile->sourcefile_index << "`" << endl; // REmover
        // }
        outfile << endl; 
    }
    outfile << endl;
}