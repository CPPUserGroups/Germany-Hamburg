//
// (c) Copyright 2016 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of python-talk.
//
// python-talk is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// python-talk is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with python-talk.  If not, see <http://www.gnu.org/licenses/>.
// ===========================================================================

#include <boost/python.hpp>
#include <talk/functions.hpp>
#include <talk/exceptions.hpp>

using namespace boost::python;

static object TalkError;
static char *TalkError_Doc = "Internal error in talk library";


void division_by_zero_translator(const talk::division_by_zero &)
{
    PyErr_SetString(PyExc_ZeroDivisionError,"only Chuck Norris can do this!");
}

void talk_error_translator(const talk::talk_error &)
{
    PyErr_SetString(TalkError.ptr(),"An internal error");
}

BOOST_PYTHON_FUNCTION_OVERLOADS(add_overloads,talk::add,2,2);

//=================implementation of the python extension======================
BOOST_PYTHON_MODULE(functions)
{
    def("div",talk::div);
    
    TalkError = object(handle<>(PyErr_NewExceptionWithDoc("talk.functions.TalkError",TalkError_Doc,
                                                          nullptr,nullptr)));
    scope().attr("TalkError")=TalkError;

    register_exception_translator<talk::division_by_zero>(division_by_zero_translator);
    register_exception_translator<talk::talk_error>(talk_error_translator);
   
    def("add",(double (*)(double,double))2,add_overloads());
    def("add",(int (*)(int,int))2,add_overloads());

}
