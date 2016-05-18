extern "C" {
#include <Python.h>
}
#include <string>
#include <boost/python.hpp>

using namespace boost::python;
static const std::wstring program_name = L"pyshell";

int main(int argc,char **argv)
{
    Py_SetProgramName((wchar_t*)program_name.data());
    Py_Initialize(); 

    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    
    std::string line_buffer;
    while(!std::cin.eof())
    {
        std::cout<<"$> ";
        std::getline(std::cin,line_buffer,'\n');

        try
        {
            exec(str(line_buffer),main_namespace);
        }
        catch(error_already_set const &error)
        {
            PyErr_Print();
        }
    }
    return 0;
}
