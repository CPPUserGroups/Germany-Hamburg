#include <Python.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
} cust_MathiasObject;

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

