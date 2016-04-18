#include <Python.h>

static PyObject *
get_answer(PyObject *self, PyObject *args)
{
    return Py_BuildValue("i", 42);
}

static PyMethodDef cppsamplemethods[] = {
    {"get_answer",  get_answer, METH_VARARGS, "The meaning of life."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef cppsamplemodule = {
   PyModuleDef_HEAD_INIT,
   "cppsample",   /* name of module */
   "just a simple extension module", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   cppsamplemethods
};

PyMODINIT_FUNC
PyInit_cppsample(void) {
  PyObject *m = PyModule_Create(&cppsamplemodule);
  return m;
}

