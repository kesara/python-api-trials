#include <Python.h>

#define LIMIT 255
#define GENERIC_GREETING_LEN 7

static PyObject *HelloWorldError;

static PyObject *
helloworld_hello(PyObject *self, PyObject *args)
{
    const char *name;
    char greet[LIMIT];

    if (!PyArg_ParseTuple(args, "|s", &name)) {
        return NULL;
    }

    if (!strcmp(name, "") || (int)name[0] < 5) {
        sprintf(greet, "Hello World!");
    }
    else {
        if (((int)strlen(name) + GENERIC_GREETING_LEN) > LIMIT) {
            PyErr_SetString(HelloWorldError, "Name is too large.");
            return NULL;
        }
        if (PyErr_ExceptionMatches(HelloWorldError)) {
            goto error;
        }
        sprintf(greet, "Hello %s!", name);
    }

    return Py_BuildValue("s", greet);
error:
    Py_XDECREF(name);
    Py_XDECREF(greet);
    Py_RETURN_NONE;
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
    PyObject *m;

    m = PyModule_Create(&module);
    if (m == NULL) {
        return NULL;
    }

    HelloWorldError = PyErr_NewException("helloworld.Error", NULL, NULL);
    Py_INCREF(HelloWorldError);
    PyModule_AddObject(m, "Error", HelloWorldError);

    return m;
}
