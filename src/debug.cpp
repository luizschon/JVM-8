#include "../include/debug.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void print_all(class_file &class_f)
{
    print_pool(class_f);
    print_class_data(class_f);
    print_interfaces(class_f);
    print_fields(class_f);
    print_methods(class_f);
    print_attributes(class_f);
}

void print_pool(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << right << " Constant Pool" << setfill('-') << endl;
    cout.flags(f);
    print_utf8_pool(class_f);
    print_integer_pool(class_f);
    print_float_pool(class_f);
    print_long_pool(class_f);
    print_double_pool(class_f);
    print_class_pool(class_f);
    print_string_pool(class_f);
    print_fieldref_pool(class_f);
    print_methodref_pool(class_f);
    print_interface_methodref_pool(class_f);
    print_name_and_type_pool(class_f);
    print_method_handle_pool(class_f);
    print_method_type_pool(class_f);
    print_invoke_dynamic_pool(class_f);
}

void print_utf8_pool(class_file &class_f)
{
    cout << "Utf8" << endl;
    for (auto i : class_f.utf8_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Length: " << i.length << endl;
        cout << "Bytes: ";
        
        for (auto j : i.bytes)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

void print_integer_pool(class_file &class_f)
{
    cout << "Integer" << endl;
    for (auto i : class_f.integer_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Bytes: " << i.bytes << endl;
    }
    cout << endl;
}

void print_float_pool(class_file &class_f)
{
    cout << "Float" << endl;
    for (auto i : class_f.float_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Bytes: " << i.bytes << endl;
    }
    cout << endl;
}

// ios_base::fmtflags f(cout.flags());
// cout << "Methods_access_flags: " << hex << class_f.methods[i].access_flags << endl;
// cout.flags(f);

void print_long_pool(class_file &class_f)
{
    cout << "Long" << endl;
    for (auto i : class_f.long_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "High Bytes: " << i.high_bytes << endl;
        cout << "Low Bytes: " << i.low_bytes << endl;
    }
    cout << endl;
}

void print_double_pool(class_file &class_f)
{
    cout << "Double" << endl;
    for (auto i : class_f.double_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "High Bytes: " << i.high_bytes << endl;
        cout << "Low Bytes: " << i.low_bytes << endl;
    }
    cout << endl;
}

void print_class_pool(class_file &class_f)
{
    cout << "Class" << endl;
    for (auto i : class_f.class_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Name Index: " << i.name_idx << endl;
    }
    cout << endl;
}

void print_string_pool(class_file &class_f)
{
    cout << "String" << endl;
    for (auto i : class_f.string_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "String Index: " << i.str_idx << endl;
    }
    cout << endl;
}

void print_fieldref_pool(class_file &class_f)
{
    cout << "Fieldref" << endl;
    for (auto i : class_f.fieldref_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Class Index: " << i.class_idx << endl;
        cout << "Name And Type Index: " << i.name_and_type_idx << endl;
    }
    cout << endl;
}

void print_methodref_pool(class_file &class_f)
{
    cout << "Methodref" << endl;
    for (auto i : class_f.methodref_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Class Index: " << i.class_idx << endl;
        cout << "Name And Type Index: " << i.name_and_type_idx << endl;
    }
    cout << endl;
}

void print_interface_methodref_pool(class_file &class_f)
{
    cout << "Interface Methodref" << endl;
    for (auto i : class_f.interface_methodref_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Class Index: " << i.class_idx << endl;
        cout << "Name And Type Index: " << i.name_and_type_idx << endl;
    }
    cout << endl;
}

void print_name_and_type_pool(class_file &class_f)
{
    cout << "Name And Type" << endl;
    for (auto i : class_f.name_and_type_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Name Index: " << i.name_idx << endl;
        cout << "Descriptor Index: " << i.descriptor_idx << endl;
    }
    cout << endl;
}

void print_method_handle_pool(class_file &class_f)
{
    cout << "Method Handle Info" << endl;
    for (auto i : class_f.method_handle_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Reference Kind: " << i.reference_kind << endl;
        cout << "Reference Index: " << i.reference_index << endl;
    }
    cout << endl;
}

void print_method_type_pool(class_file &class_f)
{
    cout << "Method Type" << endl;
    for (auto i : class_f.method_type_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Descriptor Index: " << i.descriptor_index << endl;
    }
    cout << endl;
}

void print_invoke_dynamic_pool(class_file &class_f)
{
    cout << "Invoke Dynamic" << endl;
    for (auto i : class_f.invoke_dynamic_pool)
    {
        cout << "Tag: " << (int) i.tag << endl;
        cout << "Bootstrap Method Attribute Index: " << i.bootstrap_method_attr_index << endl;
        cout << "Name and Type Index: " << i.name_and_type_index << endl;
    }
    cout << endl;
}

void print_class_data(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << left << "Access flag: " << right << " 0x" << uppercase << hex << class_f.access_flag << endl;
    cout.flags(f);
    cout << "This class idx: " << class_f.this_class << endl;
    cout << "Super class idx: " << class_f.super_class << endl;
}

void print_interfaces(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << right << " Interfaces" << setfill('-') << endl;
    cout.flags(f);
    cout << "Interfaces count: " << class_f.interfaces_count << endl;
    cout << "Interfaces: [ ";
    for (int i = 0; i < class_f.interfaces_count; i++)
        cout << class_f.interfaces[i] << " ";
    cout << "]" << endl << endl;
}

void print_fields(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << right << " Fields" << setfill('-') << endl;
    cout.flags(f);
    cout << "Fields count: " << class_f.fields_count << endl;
    for(int i = 0; i < class_f.fields_count; i++) 
    {
        ios_base::fmtflags f(cout.flags());
        cout << "Fields Access Flags: " << hex << class_f.fields[i].access_flags << endl;
        cout.flags(f);
        cout << "Descriptor Index: " << class_f.fields[i].descriptor_idx << endl;
        cout << "Name Index: " << class_f.fields[i].name_idx << endl;
        cout << "Attr Count: " << class_f.fields[i].attr_count << endl;
        
        for (int k = 0; k < class_f.fields[i].attr_count; k++)
        {
            cout << "Attr Name Idx: " << class_f.fields[i].attr[k].attr_name_idx << endl;
            cout << "Attr Length: " << class_f.fields[i].attr[k].attr_length << endl;
            cout << "Attributes: [ "; 
            for (int l = 0; l < class_f.fields[i].attr[k].attr_length; l++) 
                cout << class_f.fields[i].attr[k].info[l] << " ";
            cout << "]" << endl;
        }
    }
    cout << endl;
}

void print_methods(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << right << " Methods" << setfill('-') << endl;
    cout.flags(f);
    cout << "Methods Count: " << class_f.methods_count << endl;
    for(int i = 0; i < class_f.methods_count; i++) 
    {
        ios_base::fmtflags f(cout.flags());
        cout << "Methods Access Flags: " << right << " 0x" << uppercase << hex << class_f.methods[i].access_flags << endl;
        cout.flags(f);
        cout << "Name Index: " << class_f.methods[i].name_idx << endl;
        cout << "Descriptor Index: " << class_f.methods[i].descriptor_idx << endl;
        cout << "Attr Count: " << class_f.methods[i].attr_count << endl;
        
        for (int k = 0; k < class_f.methods[i].attr_count; k++)
        {
            cout << "Attr Name Idx: " << class_f.methods[i].attr[k].attr_name_idx << endl;
            cout << "Attr Length: " << class_f.methods[i].attr[k].attr_length << endl;
            cout << "Attributes: [ "; 
            for (int l = 0; l < class_f.methods[i].attr[k].attr_length; l++) 
                cout << class_f.methods[i].attr[k].info[l] << " ";
            cout << "]" << endl;
        }
    }
    cout << endl;
}

void print_attributes(class_file &class_f)
{
    ios_base::fmtflags f(cout.flags());
    cout << setw(50) << right << " Attributes" << setfill('-') << endl;
    cout.flags(f);
    cout << "Attributes count: " << class_f.attributes_count << endl;
    for (int i = 0; i < class_f.attributes_count; i++) {
        cout << "Attr Name Index: " << class_f.attributes[i].attr_name_idx << endl;
        cout << "Attr Length: " << class_f.attributes[i].attr_length << endl;
        cout << "Attributes Info: [ "; 
        for (int j = 0; j < class_f.attributes[i].attr_length; j++)
            cout << class_f.attributes[i].info[j] << " ";
        cout << "]" << endl; 
    }
    cout << endl;
}