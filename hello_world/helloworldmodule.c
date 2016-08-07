#include <Python.h>

static PyObject *
helloworld_hello(PyObject *self, PyObject *args)
{
    const char *name;
    char greet[255];

    if (!PyArg_ParseTuple(args, "|s", &name)) {
        return NULL;
    }

    if (!strcmp(name, "") || (int)name[0] < 5) {
        sprintf(greet, "Hello World!");
    }
    else {
        sprintf(greet, "Hello %s!", name);
    }

    return Py_BuildValue("s", greet);
}

static PyMethodDef HelloWorldMethods[] = {
    {"hello",  helloworld_hello, METH_VARARGS,
     "Say Hello World."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
   PyModuleDef_HEAD_INIT,
   "helloworld",
   NULL,
   -1,
   HelloWorldMethods
};

PyMODINIT_FUNC
PyInit_helloworld(void)
{
    return PyModule_Create(&module);
}
