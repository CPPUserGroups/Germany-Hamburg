#include <Python.h>
#include <string>

static PyObject *
f1(PyObject *self, PyObject *args)
{
  int a,b,c;
  char *s;
  if (!PyArg_ParseTuple(args,"iiis",&a,&b,&c,&s))
    return NULL;
  assert(s);
  return Py_BuildValue("i", a+b+c+std::stoi(s));
}

static PyObject *
f2(PyObject *self, PyObject *args, PyObject *kwargs)
{
  int a,b,c;
  char *s;
  static char *kwlist[] = {(char*)"arg1",(char*)"arg2",(char*)"arg3",(char*)"arg4",NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii|is", kwlist, &a, &b, &c, &s))
    return NULL;
  assert(s);
  int si = 0; 
  try { si = std::stoi(s); } catch (...) {};
  return Py_BuildValue("i", a+b+c+si);
}

static PyMethodDef unpackparamsmethods[] = {
    {"f1",  f1, METH_VARARGS, "f1"},
    {"f2",  (PyCFunction)f2, METH_VARARGS | METH_KEYWORDS, "f2"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef unpackparamsmodule = {
   PyModuleDef_HEAD_INIT,
   "unpackparams",   /* name of module */
   "just a simple extension module", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   unpackparamsmethods
};

PyMODINIT_FUNC
PyInit_unpackparams(void) {
  PyObject *m = PyModule_Create(&unpackparamsmodule);
  return m;
}

