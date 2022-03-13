#include "../include/debug.hpp"
#include <iostream>

using namespace std;

void print_all_pool(class_file &class_f)
{
    print_utf8_pool(class_f);
    print_integer_pool(class_f);
    print_float_pool(class_f);
    print_long_pool(class_f);
    print_double_pool(class_f);
    print_class_pool(class_f);
    print_string_pool(class_f);
    print_fieldrefpool(class_f);
    print_methodref_pool(class_f);
    print_interface_methodref_pool(class_f);
    print_name_and_type_pool(class_f);
    print_method_handle_pool(class_f);
    print_method_type_pool(class_f);
    print_invoke_dynamic(class_f);
}

void print_utf8_pool(class_file &class_f)
{
    cout << "Utf8: " << endl;
    for (auto i : class_f.utf8_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "Length: " << i.length << endl;
        cout << "Bytes: ";
        
        for (auto j : i.bytes)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_integer_pool(class_file &class_f)
{
    cout << "Integer:" << endl;
    for (auto i : class_f.integer_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "Bytes: " << i.bytes << endl;
    }
}

void print_float_pool(class_file &class_f)
{
    cout << "Float:" << endl;
    for (auto i : class_f.float_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "Bytes: " << i.bytes << endl;
    }
}

void print_long_pool(class_file &class_f)
{
    cout << "Long:" << endl;
    for (auto i : class_f.long_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "High Bytes: " << i.high_bytes << endl;
        cout << "Low Bytes: " << i.low_bytes << endl;
    }
}

void print_double_pool(class_file &class_f)
{
    cout << "double:" << endl;
    for (auto i : class_f.double_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "High Bytes: " << i.high_bytes << endl;
        cout << "Low Bytes: " << i.low_bytes << endl;
    }
}

void print_class_pool(class_file &class_f)
{
    cout << "Class:" << endl;
    for (auto i : class_f.class_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "Name idx: " << i.name_idx << endl;
    }
}

void print_string_pool(class_file &class_f)
{
    cout << "String:" << endl;
    for (auto i : class_f.string_pool)
    {
        cout << "Tag: " << i.tag << endl;
        cout << "String Idx: " << i.str_idx << endl;
    }
}

void print_fieldrefpool(class_file &class_f)
{
    cout << "print_fieldref_info: " << endl;
    for (auto i : class_f.fieldref_pool)
    {
        cout << i.tag << endl;
        cout << i.class_idx << endl;
        cout << i.name_and_type_idx << endl;
    }
}

void print_methodref_pool(class_file &class_f)
{
    cout << "print_methodref: " << endl;
    for (auto i : class_f.methodref_pool)
    {
        cout << i.tag << endl;
        cout << i.class_idx << endl;
        cout << i.name_and_type_idx << endl;
    }
}

void print_interface_methodref_pool(class_file &class_f)
{
    cout << "interface_methodref: " << endl;
    for (auto i : class_f.interface_methodref_pool)
    {
        cout << i.tag << endl;
        cout << i.class_idx << endl;
        cout << i.name_and_type_idx << endl;
    }
}

void print_name_and_type_pool(class_file &class_f)
{
    cout << "name_and_type: " << endl;
    for (auto i : class_f.name_and_type_pool)
    {
        cout << i.tag << endl;
        cout << i.name_idx << endl;
        cout << i.descriptor_idx << endl;
    }
}

void print_method_handle_pool(class_file &class_f)
{
    cout << "method_handle_info: " << endl;
    for (auto i : class_f.method_handle_pool)
    {
        cout << i.tag << endl;
        cout << i.reference_kind << endl;
        cout << i.reference_index << endl;
    }
}

void print_method_type_pool(class_file &class_f)
{
    cout << "print_method_type: " << endl;
    for (auto i : class_f.method_type_pool)
    {
        cout << i.tag << endl;
        cout << i.descriptor_index << endl;
    }
}

void print_invoke_dynamic(class_file &class_f)
{
    cout << "invoke_dynamic: " << endl;
    for (auto i : class_f.invoke_dynamic_pool)
    {
        cout << i.tag << endl;
        cout << i.bootstrap_method_attr_index << endl;
        cout << i.name_and_type_index << endl;
    }
}