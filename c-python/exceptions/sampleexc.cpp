#include <Python.h>
#include <string>

static PyObject *SampleErr;

static PyObject *
f1(PyObject *self, PyObject *args)
{
  PyErr_SetString(PyExc_ValueError,"sample builtin error");
  return NULL;
}

static PyObject *
f2(PyObject *self, PyObject *args)
{
  PyErr_SetString(SampleErr, "sample custom error");
  return NULL;
}

static PyMethodDef sampleexcmethods[] = {
    {"f1",  f1, METH_VARARGS, "f1"},
    {"f2",  f2, METH_VARARGS, "f2"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef sampleexcmodule = {
   PyModuleDef_HEAD_INIT,
   "sampleexc",   /* name of module */
   "just a simple extension module", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   sampleexcmethods
};

PyMODINIT_FUNC
PyInit_sampleexc(void) {
  PyObject *m = PyModule_Create(&sampleexcmodule);
  SampleErr = PyErr_NewException("sampleexc.error",NULL,NULL);
  Py_INCREF(SampleErr);
  PyModule_AddObject(m, "error", SampleErr);
  return m;
}

