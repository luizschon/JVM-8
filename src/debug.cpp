#include "../include/debug.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void print_all(class_file &class_f, string filename)
{
    int pos_i = filename.find("/"), pos_f = filename.find(".class") - pos_i;
    string outname = filename.substr(pos_i + 1, pos_f - 1);

    ofstream outfile("./out/" + outname + ".md");
    outfile << "# **" << outname << "**" << endl << endl;
    print_general_info(class_f, outfile);
    print_pool(class_f, outfile);
    print_interfaces(class_f, outfile);
    print_fields(class_f, outfile);
    print_methods(class_f, outfile);
    print_attributes(class_f, outfile);
    outfile.close();
}

void print_general_info(class_file &class_f, ofstream &outfile)
{
    outfile << "## **General Information**" << endl;
    ios_base::fmtflags f(outfile.flags());
    outfile << "Magic " << "**0x" << uppercase << hex << class_f.magic << "**  " << endl;
    outfile.flags(f);
    outfile << "Minor version **" << class_f.minor_version << "**  " << endl;
    outfile << "Major version **" << class_f.major_version << "**  " << endl;
    outfile << "Constant Pool Count **" << class_f.constant_pool_count << "**  " << endl;
    outfile << "Access Flags **" << class_f.access_flag << "**  " << endl;
    outfile << "This Class **" << class_f.this_class << "**  " << endl;
    outfile << "Super Class **" << class_f.super_class << "**  " << endl;
    outfile << "Interfaces Count **" << class_f.interfaces_count << "**  " << endl;
    outfile << "Fields Count **" << class_f.fields_count << "**  " << endl;
    outfile << "Methods Count **" << class_f.methods_count << "**  " << endl;
    outfile << "Attributes Count **" << class_f.attributes_count << "**  " << endl;
    outfile << endl;
}

void print_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Constant Pool**" << endl;
    print_utf8_pool(class_f, outfile);
    print_integer_pool(class_f, outfile);
    print_float_pool(class_f, outfile);
    print_long_pool(class_f, outfile);
    print_double_pool(class_f, outfile);
    print_class_pool(class_f, outfile);
    print_string_pool(class_f, outfile);
    print_fieldref_pool(class_f, outfile);
    print_methodref_pool(class_f, outfile);
    print_interface_methodref_pool(class_f, outfile);
    print_name_and_type_pool(class_f, outfile);
    print_method_handle_pool(class_f, outfile);
    print_method_type_pool(class_f, outfile);
    print_invoke_dynamic_pool(class_f, outfile);
}

void print_utf8_pool(class_file &class_f, ofstream &outfile)
{
    for (auto i : class_f.utf8_pool)
    {
        outfile << "### *CONSTANT_Utf8_info*" << endl;
        outfile << "- Length " << i.length << "  " << endl;
        outfile << "- Bytes [ `";
        
        for (auto j : i.bytes)
            outfile << j;
        outfile << "` ]" << endl;
    }
    outfile << endl;
}

void print_integer_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Integer_info*" << endl;
    for (auto i : class_f.integer_pool)
        outfile << "- Bytes " << i.bytes << endl;
    outfile << endl;
}

void print_float_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Float_info*" << endl;
    for (auto i : class_f.float_pool)
    {
        ios_base::fmtflags f(outfile.flags());
        outfile << "- Bytes 0x" << hex << i.bytes << endl;
        outfile.flags(f);
        outfile << "- Float " << calc_float(i.bytes) << endl;
    }
    outfile << endl;
}

void print_long_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Long_info*" << endl;
    for (auto i : class_f.long_pool)
    {
        ios_base::fmtflags f(outfile.flags());
        outfile << "- High Bytes 0x" << hex << i.high_bytes << endl;
        outfile << "- Low Bytes 0x" << hex << i.low_bytes << endl;
        outfile.flags(f);
        outfile << "- Long " << calc_long(i.high_bytes, i.low_bytes) << endl;
    }
    outfile << endl;
}

void print_double_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Double_info*" << endl;
    for (auto i : class_f.double_pool)
    {
        ios_base::fmtflags f(outfile.flags());
        outfile << "- High Bytes 0x" << hex << i.high_bytes << endl;
        outfile << "- Low Bytes 0x" << hex << i.low_bytes << endl;
        outfile.flags(f);
        outfile << "- Double " << calc_double(i.high_bytes, i.low_bytes) << endl;
    }
    outfile << endl;
}

void print_class_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Class_info*" << endl;
    for (auto i : class_f.class_pool)
        outfile << "- Name Index " << i.name_idx << endl;
    outfile << endl;
}

void print_string_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_String_info*" << endl;
    for (auto i : class_f.string_pool)
        outfile << "- String Index " << i.str_idx << endl;
    outfile << endl;
}

void print_fieldref_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Fieldref_info*" << endl;
    for (auto i : class_f.fieldref_pool)
    {
        outfile << "- Class Index " << i.class_idx << endl;
        outfile << "- Name And Type Index " << i.name_and_type_idx << endl;
    }
    outfile << endl;
}

void print_methodref_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Methodref_info*" << endl;
    for (auto i : class_f.methodref_pool)
    {
        outfile << "- Class Index " << i.class_idx << endl;
        outfile << "- Name And Type Index " << i.name_and_type_idx << endl;
    }
    outfile << endl;
}

void print_interface_methodref_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Interface_methodref_info*" << endl;
    for (auto i : class_f.interface_methodref_pool)
    {
        outfile << "- Class Index " << i.class_idx << endl;
        outfile << "- Name And Type Index " << i.name_and_type_idx << endl;
    }
    outfile << endl;
}

void print_name_and_type_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Name_and_type*" << endl;
    for (auto i : class_f.name_and_type_pool)
    {
        outfile << "- Name Index " << i.name_idx << endl;
        outfile << "- Descriptor Index " << i.descriptor_idx << endl;
    }
    outfile << endl;
}

void print_method_handle_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Method_handle_info*" << endl;
    for (auto i : class_f.method_handle_pool)
    {
        outfile << "- Reference Kind " << i.reference_kind << endl;
        outfile << "- Reference Index " << i.reference_index << endl;
    }
    outfile << endl;
}

void print_method_type_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Method_type*" << endl;
    for (auto i : class_f.method_type_pool)
        outfile << "- Descriptor Index " << i.descriptor_index << endl;
    outfile << endl;
}

void print_invoke_dynamic_pool(class_file &class_f, ofstream &outfile)
{
    outfile << "### *CONSTANT_Invoke_dynamic*" << endl;
    for (auto i : class_f.invoke_dynamic_pool)
    {
        outfile << "- Bootstrap Method Attribute Index " << i.bootstrap_method_attr_index << endl;
        outfile << "- Name and Type Index " << i.name_and_type_index << endl;
    }
    outfile << endl;
}

void print_interfaces(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Interfaces**" << endl;
    for (int i = 0; i < class_f.interfaces_count; i++)
        outfile << "- Interface " << class_f.interfaces[i];
    outfile << endl << endl;
}

void print_fields(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Fields**" << endl;
    for(int i = 0; i < class_f.fields_count; i++) 
    {
        outfile << "### *Field*" << endl;
        ios_base::fmtflags f(outfile.flags());
        outfile << "- Fields Access Flags " << hex << class_f.fields[i].access_flags << endl;
        outfile.flags(f);
        outfile << "- Descriptor Index " << class_f.fields[i].descriptor_idx << endl;
        outfile << "- Name Index " << class_f.fields[i].name_idx << endl;
        outfile << "- Attr Count " << class_f.fields[i].attr_count << endl;
        
        for (int k = 0; k < class_f.fields[i].attr_count; k++)
        {
            outfile << "  * Attribute Name Index " << class_f.fields[i].attr[k].attr_name_idx << endl;
            outfile << "  * Attribute Length " << class_f.fields[i].attr[k].attr_length << endl;
            outfile << "  * Attributes [ "; 
            for (int l = 0; l < class_f.fields[i].attr[k].attr_length; l++) 
                outfile << class_f.fields[i].attr[k].info[l];
            outfile << " ]" << endl;
        }
    }
    outfile << endl;
}

void print_methods(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Methods**" << endl;
    for(int i = 0; i < class_f.methods_count; i++) 
    {
        outfile << "### *Method*" << endl;
        ios_base::fmtflags f(outfile.flags());
        outfile << "- Methods Access Flags " << right << " 0x" << uppercase << hex << class_f.methods[i].access_flags << endl;
        outfile.flags(f);
        outfile << "- Name Index " << class_f.methods[i].name_idx << endl;
        outfile << "- Descriptor Index " << class_f.methods[i].descriptor_idx << endl;
        outfile << "- Attribute Count " << class_f.methods[i].attr_count << endl;
        
        for (int k = 0; k < class_f.methods[i].attr_count; k++)
        {
            outfile << "  * Attribute Name Idx " << class_f.methods[i].attr[k].attr_name_idx << endl;
            outfile << "  * Attribute Length " << class_f.methods[i].attr[k].attr_length << endl;
            // outfile << "  * Attributes [ "; 
            // for (int l = 0; l < class_f.methods[i].attr[k].attr_length; l++) 
            //     outfile << class_f.methods[i].attr[k].info[l];
            // outfile << " ]" << endl;
        }
    }
    outfile << endl;
}

void print_attributes(class_file &class_f, ofstream &outfile)
{
    outfile << "## **Attributes**" << endl;
    for (int i = 0; i < class_f.attributes_count; i++)
    {
        outfile << "- Attribute Name Index " << class_f.attributes[i].attr_name_idx << endl;
        outfile << "- Attribute Length " << class_f.attributes[i].attr_length << endl;
        // outfile << "Attributes Info: [ "; 
        // for (int j = 0; j < class_f.attributes[i].attr_length; j++)
        //     outfile << class_f.attributes[i].info[j] << " ";
        // outfile << "]" << endl; 
    }
    outfile << endl;
}