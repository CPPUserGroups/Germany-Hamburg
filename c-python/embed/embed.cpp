#include <Python.h>
#include <structmember.h>
#include <iostream>
#include <string>

#include "oneclass.h"

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    OneClass *oneclass;
} pyOneClass;

// member wrappers
static char OneClass_set_doc[] = "set the value";
static PyObject * OneClass_set(PyObject *self, PyObject *args)
{
  pyOneClass *p = (pyOneClass*)self;
  const char* text;
  int number;
  if (PyArg_ParseTuple(args,"i",&number))
     p->oneclass->set(number);
  else {
    PyErr_Clear();
    if (!PyArg_ParseTuple(args,"s",&text)) return 0;
    p->oneclass->set(text);
  }
  return Py_BuildValue(""); // creates a ref to None
}

static char OneClass_calc_doc[] = "do the calc";
static PyObject * OneClass_calc(PyObject *self, PyObject *args)
{
  pyOneClass *p = (pyOneClass*)self;
  auto s = p->oneclass->calc();
  return Py_BuildValue("s",s.c_str());
}

static int OneClass_init(PyObject *self, PyObject *args, PyObject *)
{
  pyOneClass *p = (pyOneClass*)self;
  int val = 0;
  if (!PyArg_ParseTuple(args,"i",&val)) return -1;
  p->oneclass = new OneClass(val);
  return 0;
}
static void OneClass_delete(PyObject *self)
{
  pyOneClass *p = (pyOneClass*)self;
  delete p->oneclass;
}

static PyMethodDef OneClass_methods[] = {
  { "set", OneClass_set, METH_VARARGS, OneClass_set_doc },
  { "calc", OneClass_calc, METH_VARARGS, OneClass_calc_doc },
  { NULL }
};

static PyTypeObject OneClassType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "embed.OneClass",             /* tp_name */
    sizeof(pyOneClass),        /* tp_basicsize */
    0,                         /* tp_itemsize */
    OneClass_delete,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "OneClass objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    OneClass_methods,             /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    OneClass_init,             /* tp_init */
    0,                         /* tp_alloc */
    0,                         /* tp_new */
};

static PyModuleDef embedmodule = {
    PyModuleDef_HEAD_INIT,
    "embed",
    "Example module that creates an extension type.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_embed(void)
{
    PyObject* m;

    OneClassType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&OneClassType) < 0)
        return NULL;

    m = PyModule_Create(&embedmodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&OneClassType);
    PyModule_AddObject(m, "OneClass", (PyObject *)&OneClassType);
    return m;
}

PyObject* createOneClass(PyObject *module, OneClass* obj)
{
  PyObject *func = PyObject_GetAttrString(module, "OneClass");
  assert(func);
  PyObject *instance = PyObject_CallFunction(func, "i", 0);
  Py_DECREF(func);

  pyOneClass *p = (pyOneClass*)instance;
  delete p->oneclass;
  p->oneclass = obj;
  return instance;
}

void initOneClass(PyObject *m)
{
    OneClassType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&OneClassType) < 0)
        return;

    Py_INCREF(&OneClassType);
    PyModule_AddObject(m, "OneClass", (PyObject *)&OneClassType);
}

int main(int, char*[])
{
  OneClass *oc = new OneClass(2);
  oc->set("the current value is");
  std::cout << oc->calc() << std::endl;

  Py_Initialize();
  PySys_SetPath(L"."); 
  
  PyObject *pName = PyUnicode_FromString("doit");
  assert(pName!=0);
  PyObject *pModule = PyImport_Import(pName);
  assert(pModule!=0);
  Py_DECREF(pName);

  initOneClass(pModule);

  PyObject *pFunc = PyObject_GetAttrString(pModule, "f");

  PyObject *pArgs = PyTuple_New(2);

  PyObject *ocValue = createOneClass(pModule,oc);
  assert(((pyOneClass*)ocValue)->oneclass->getNumber() == 2);
  //PyObject *pValue = PyLong_FromLong(1);
  PyTuple_SetItem(pArgs,0,ocValue);

  PyObject* pValue = PyLong_FromLong(3);
  PyTuple_SetItem(pArgs,1,pValue);

  PyObject_CallObject(pFunc, pArgs);
  
  Py_DECREF(pFunc);
  Py_DECREF(pModule);

  std::cout << oc->calc() << std::endl;

  Py_DECREF(pArgs);

  return 0;
}

