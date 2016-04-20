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

#include <algorithm>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <string>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_ARRAY_UNIQUE_SYMBOL TALK_ARRAY_USYMBOL
extern "C" {
#include <numpy/arrayobject.h>
}

#if PY_MAJOR_VERSION >= 3
int
#else
void
#endif
init_numpy()
{
    import_array();
}

using namespace boost::python;

//============================================================================
bool is_array(const object &o)
{
    if(o.ptr())
        return PyArray_CheckExact(o.ptr());
    else
        return false;
}

//============================================================================
object create_array(const tuple &shape,double fill_value=0.0)
{
    using iterator_type = stl_input_iterator<npy_intp>;

    //copy the shape data to a vector
    iterator_type shape_begin(shape),shape_end;
    std::vector<npy_intp> array_shape(shape_begin,shape_end);

    //create the array
    handle<> h(reinterpret_cast<PyObject*>(
               PyArray_SimpleNew(len(shape),array_shape.data(),NPY_FLOAT64)
               ));
    object array(h);
   
    //initiazlize data
    for(size_t i=0;i<array.attr("size");i++) 
        array.attr("flat")[i] = fill_value;

    return array;
}

//============================================================================
PyObject *create_array_ptr(const tuple &shape,double fill_value=0.0)
{
    using iterator_type = stl_input_iterator<npy_intp>;

    //copy the shape data to a vector
    iterator_type shape_begin(shape),shape_end;
    std::vector<npy_intp> array_shape(shape_begin,shape_end);

    //create the array
    handle<> h(reinterpret_cast<PyObject*>(
               PyArray_SimpleNew(len(shape),array_shape.data(),NPY_FLOAT64)
               ));
    object array(h);
   
    //initiazlize data
    for(size_t i=0;i<array.attr("size");i++) 
        array.attr("flat")[i] = fill_value;

    return array.ptr();
}

//============================================================================
PyObject *create_array_ptr2(const tuple &shape,double fill_value=0.0)
{
    using iterator_type = stl_input_iterator<npy_intp>;

    //copy the shape data to a vector
    iterator_type shape_begin(shape),shape_end;
    std::vector<npy_intp> array_shape(shape_begin,shape_end);

    //create the array
    handle<> h(reinterpret_cast<PyObject*>(
               PyArray_SimpleNew(len(shape),array_shape.data(),NPY_FLOAT64)
               ));
    object array(h);
   
    //initiazlize data
    for(size_t i=0;i<array.attr("size");i++) 
        array.attr("flat")[i] = fill_value;

    return incref(array.ptr());
}

//============================================================================
PyObject *create_array_ptr3(const tuple &shape,double fill_value=0.0)
{
    using iterator_type = stl_input_iterator<npy_intp>;

    //copy the shape data to a vector
    iterator_type shape_begin(shape),shape_end;
    std::vector<npy_intp> array_shape(shape_begin,shape_end);

    //create the array
    handle<> h(borrowed(reinterpret_cast<PyObject*>(
               PyArray_SimpleNew(len(shape),array_shape.data(),NPY_FLOAT64)
               )));
    object array(h);
   
    //initiazlize data
    for(size_t i=0;i<array.attr("size");i++) 
        array.attr("flat")[i] = fill_value;

    return array.ptr();
}

//============================================================================
BOOST_PYTHON_MODULE(array)
{
    init_numpy();

    def("create_array",create_array,("shape",arg("fill_value")=0.0));
    def("create_array_ptr",create_array_ptr,("shape",arg("fill_value")=0.0));
    def("create_array_ptr2",create_array_ptr2,("shape",arg("fill_value")=0.0));
    def("create_array_ptr3",create_array_ptr3,("shape",arg("fill_value")=0.0));

}

