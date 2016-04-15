#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    int value;
} cust_MathiasObject;

static PyMemberDef cust_Mathias_members[] = {
  { (char*)"value", T_INT, offsetof(cust_MathiasObject,value), 0, (char*)"Mathias value" },
  { NULL }
};

static PyObject * Mathias_getValue(cust_MathiasObject *self)
{
  return Py_BuildValue("i",self->value);
}
static PyObject * Mathias_setValue(cust_MathiasObject *self, PyObject *args)
{
  int val = self->value;
  if (!PyArg_ParseTuple(args,"i",&val)) return NULL;
  self->value = val;
  return Py_BuildValue("i",self->value);
}

static PyMethodDef cust_Mathias_methods[] = {
  { "getValue", (PyCFunction)Mathias_getValue, METH_NOARGS, "return value" },
  { "setValue", (PyCFunction)Mathias_setValue, METH_VARARGS, "set value" },
  { NULL }
};

static PyTypeObject cust_MathiasType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "cust.Mathias",             /* tp_name */
    sizeof(cust_MathiasObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
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
    "Mathias objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    cust_Mathias_methods,             /* tp_methods */
    cust_Mathias_members,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    0,                         /* tp_init */
    0,                         /* tp_alloc */
    0,                         /* tp_new */
};

static PyModuleDef custmodule = {
    PyModuleDef_HEAD_INIT,
    "cust",
    "Example module that creates an extension type.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_cust(void)
{
    PyObject* m;

    cust_MathiasType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&cust_MathiasType) < 0)
        return NULL;

    m = PyModule_Create(&custmodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&cust_MathiasType);
    PyModule_AddObject(m, "Mathias", (PyObject *)&cust_MathiasType);
    return m;
}

