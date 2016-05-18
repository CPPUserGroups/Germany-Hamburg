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
    exec("print(\"hello world\")",main_namespace);
    return 0;
}
