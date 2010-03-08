
#include <stdlib.h>
#include <string.h>
#include "Python.h"

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define EXPORT(a) a
#               else
#                       define EXPORT(a) __declspec(dllexport) a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define EXPORT(a) a _export
#               else
#                       define EXPORT(a) a
#       endif
#endif
#else
#       define EXPORT(a) a
#endif




#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

#ifdef __cplusplus
extern "C" {
#endif


/*-----------*
 * FUNCTIONS *
 *-----------*/

static PyObject *_wrap_alEnable(PyObject *self, PyObject *arg) {    
  if(!PyInt_Check(arg)) return NULL;
  alEnable((ALenum) PyInt_AS_LONG (arg));
  Py_INCREF(Py_None); 
  return Py_None;
}


static PyObject *_wrap_alDisable(PyObject *self, PyObject *arg) {
  if(!PyInt_Check(arg)) return NULL;
  alDisable((ALenum) PyInt_AS_LONG (arg));
  Py_INCREF(Py_None); 
  return Py_None;
}


static PyObject *_wrap_alIsEnabled(PyObject *self, PyObject *arg) {
  if(!PyInt_Check(arg)) return NULL;
  if(alIsEnabled((ALenum) PyInt_AS_LONG (arg))) return PyInt_FromLong(1); else return PyInt_FromLong(0);
}


static PyObject *_wrap_alGetBooleanv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALboolean *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetBooleanv",&arg1,&arg2)) return NULL;
    result = (ALboolean *) malloc(arg2 * sizeof(ALboolean));
    alGetBooleanv(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      if(result[i]) 
        PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong (1));
      else 
        PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong (0));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetIntegerv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALint *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetIntegerv",&arg1,&arg2)) return NULL;
    result = (ALint *) malloc(arg2 * sizeof(ALint));
    alGetIntegerv(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong ((long) result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetFloatv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALfloat *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetFloatv",&arg1,&arg2)) return NULL;
    result = (ALfloat *) malloc(arg2 * sizeof(ALfloat));
    alGetFloatv(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyFloat_FromDouble ((double) result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetDoublev(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALdouble *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetDoublev",&arg1,&arg2)) return NULL;
    result = (ALdouble *) malloc(arg2 * sizeof(ALdouble));
    alGetDoublev(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyFloat_FromDouble (result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetString(PyObject *self, PyObject *arg) {
    ALubyte *result;
    
    if(!PyInt_Check(arg)) return NULL;
    result = (ALubyte *)alGetString((ALenum) PyInt_AS_LONG(arg));
   
    if(result == NULL) {
      Py_INCREF(Py_None);
      return Py_None;
    } else { 
      return PyString_FromString (result);
    }
}


static PyObject *_wrap_alGetError(PyObject *self) {
    return PyInt_FromLong ((long) alGetError());
}


static PyObject *_wrap_alIsExtensionPresent(PyObject *self, PyObject *args) {
    ALubyte* name;
    ALboolean result;
    
    if(!PyArg_ParseTuple(args,(char *)"s:alIsExtensionPresent",&name)) return NULL;
    result = alIsExtensionPresent((ALubyte const *)name);
    
    if(result) return PyInt_FromLong(1); else return PyInt_FromLong(0);
}


static PyObject *_wrap_alGetProcAddress(PyObject *self, PyObject *args) {
    ALubyte* name;
    void *result;
    
    if(!PyArg_ParseTuple(args,(char *)"s:alGetProcAddress",&name)) return NULL;
    result = (void *)alGetProcAddress((ALubyte const *)name);
    
    if (result) {
        return PyCObject_FromVoidPtr(result, NULL);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}


static PyObject *_wrap_alGetEnumValue(PyObject *self, PyObject *args) {
    ALubyte* name;
    ALenum result;
    
    if(!PyArg_ParseTuple(args,(char *)"s:alGetEnumValue",&name)) return NULL;
    result = alGetEnumValue((ALubyte const *)name);

    return PyInt_FromLong((long) result);
}


static PyObject *_wrap_alListenerf(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    ALfloat arg2 ;
    
    if(!PyArg_ParseTuple(args,(char *)"if:alListenerf",&arg1,&arg2)) return NULL;
    alListenerf(arg1,arg2);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alListener3f(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    ALfloat arg2 ;
    ALfloat arg3 ;
    ALfloat arg4 ;
    
    if(!PyArg_ParseTuple(args,(char *)"ifff:alListener3f",&arg1,&arg2,&arg3,&arg4)) return NULL;
    alListener3f(arg1,arg2,arg3,arg4);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alListenerfv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    PyObject *obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alListenerfv",&arg1,&obj1)) return NULL;
    if(!PySequence_Check(obj1)) return NULL;

    {
      int i;
      int nb = PySequence_Size(obj1);
      PyObject *o;
      ALfloat arg2[nb] ;

      for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM (obj1, i);
          if(!PyFloat_Check(o)) return NULL;
          arg2[i] = (ALfloat) PyFloat_AS_DOUBLE (o);
      }

      alListenerfv(arg1,arg2);
    }

    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alGetListeneriv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALint *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetListeneriv",&arg1,&arg2)) return NULL;
    result = (ALint *) malloc(arg2 * sizeof(ALint));
    alGetListeneriv(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong ((long) result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetListenerfv(PyObject *self, PyObject *args) {
    ALenum arg1 ;
    int arg2 ;
    int i;
    ALfloat *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"ii:alGetListenerfv",&arg1,&arg2)) return NULL;
    result = (ALfloat *) malloc(arg2 * sizeof(ALfloat));
    alGetListenerfv(arg1,result);
    
    resultobj = PyTuple_New(arg2);
    for(i = 0; i < arg2; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyFloat_FromDouble ((double) result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGenSources(PyObject *self, PyObject *arg) {
    if(!PyInt_Check(arg)) return NULL;
    {
        int nb = (int) PyInt_AS_LONG (arg);
        ALuint result[nb];

        alGenSources(nb,result);

        if(nb == 1) {
            return PyInt_FromLong((long) result[0]);
        } else {
            PyObject *resultobj;
            int i;
            resultobj = PyTuple_New(nb);
            for(i = 0; i < nb; i++) {
                PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong((long) result[i]));
            }
            return resultobj;
        }
    }
}


static PyObject *_wrap_alDeleteSources(PyObject *self, PyObject *args) {
    ALsizei arg1 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alDeleteSources",&arg1,&obj1)) return NULL;
    if(arg1 == 1) {
        ALuint arg2 ;
        if(!PyInt_Check(obj1)) return NULL;
        arg2 = (ALuint) PyInt_AS_LONG(obj1);
        alDeleteSources(arg1,&arg2);
    } else {
        if(!PySequence_Check(obj1)) return NULL;
        {
            int i;
            int nb = PySequence_Size(obj1);
            PyObject *o;
            ALuint arg2[nb];

            for(i = 0; i < nb; i++) {
                o = (PyObject *) PySequence_Fast_GET_ITEM(obj1, i);
                if(!PyInt_Check(o)) return NULL;
                arg2[i] = (ALuint) PyInt_AS_LONG(o);
            }
            alDeleteSources(arg1,arg2);
        }
    }
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alIsSource(PyObject *self, PyObject *arg) {
    if(!PyInt_Check(arg)) return NULL;
    if (alIsSource((ALuint ) PyInt_AS_LONG(arg)))
        return PyInt_FromLong (1);
    else 
        return PyInt_FromLong (0);
}


static PyObject *_wrap_alSourcei(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    ALint arg3 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iii:alSourcei",&arg1,&arg2,&arg3)) return NULL;
    alSourcei(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSourcef(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    ALfloat arg3 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iif:alSourcef",&arg1,&arg2,&arg3)) return NULL;
    alSourcef(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSource3f(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    ALfloat arg3 ;
    ALfloat arg4 ;
    ALfloat arg5 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iifff:alSource3f",&arg1,&arg2,&arg3,&arg4,&arg5)) return NULL;
    alSource3f(arg1,arg2,arg3,arg4,arg5);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSourcefv(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iiO:alSourcefv",&arg1,&arg2,&obj2)) return NULL;
    if(!PySequence_Check(obj2)) return NULL;

    {
        int nb = PySequence_Size(obj2);
        int i;
        ALfloat arg3[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM(obj2, i);
          if(!PyFloat_Check(o)) return NULL;
          arg3[i] = (ALfloat) PyFloat_AS_DOUBLE(o);
        }
        
        alSourcefv(arg1,arg2,arg3);
    }

    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alGetSourceiv(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    int nb ;
    
    if(!PyArg_ParseTuple(args,(char *)"iii:alGetSourceiv",&arg1,&arg2,&nb)) return NULL;

    {
        ALint arg3[nb];
        PyObject *resultobj;
        int i;

        alGetSourceiv(arg1,arg2,arg3);

        resultobj = PyTuple_New(nb);
        for(i = 0; i < nb; i++) {
          PyTuple_SET_ITEM (resultobj, i, PyInt_FromLong((long) arg3[i]));
        }
        return resultobj;
    }
}


static PyObject *_wrap_alGetSourcefv(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    int nb ;
    
    if(!PyArg_ParseTuple(args,(char *)"iii:alGetSourcefv",&arg1,&arg2,&nb)) return NULL;

    {
        ALfloat arg3[nb];
        PyObject *resultobj;
        int i;

        alGetSourcefv(arg1,arg2,arg3);

        resultobj = PyTuple_New(nb);
        for(i = 0; i < nb; i++) {
          PyTuple_SET_ITEM (resultobj, i, PyFloat_FromDouble((double) arg3[i]));
        }
        return resultobj;
    }
}


static PyObject *_wrap_alSourcePlayv(PyObject *self, PyObject *arg) {
    if(PyInt_Check(arg)) {
        alSourcePlay((ALuint) PyInt_AS_LONG(arg));
    } else if(PySequence_Check(arg)) {
        int i;
        int nb = PySequence_Size(arg);
        ALuint arg1[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM(arg, i);
          if(!PyInt_Check(o)) return NULL;
          arg1[i] = (ALuint) PyInt_AS_LONG(o);
        }
        alSourcePlayv(nb, arg1);
    }
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSourceStopv(PyObject *self, PyObject *arg) {
    if(PyInt_Check(arg)) {
        alSourceStop((ALuint) PyInt_AS_LONG(arg));
    } else if(PySequence_Check(arg)) {
        int i;
        int nb = PySequence_Size(arg);
        ALuint arg1[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM(arg, i);
          if(!PyInt_Check(o)) return NULL;
          arg1[i] = (ALuint) PyInt_AS_LONG(o);
        }
        alSourceStopv(nb, arg1);
    }
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSourceRewindv(PyObject *self, PyObject *arg) {
    if(PyInt_Check(arg)) {
        alSourceRewind((ALuint) PyInt_AS_LONG(arg));
    } else if(PySequence_Check(arg)) {
        int i;
        int nb = PySequence_Size(arg);
        ALuint arg1[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM(arg, i);
          if(!PyInt_Check(o)) return NULL;
          arg1[i] = (ALuint) PyInt_AS_LONG(o);
        }
        alSourceRewindv(nb, arg1);
    }
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alSourcePausev(PyObject *self, PyObject *arg) {
    if(PyInt_Check(arg)) {
        alSourcePause((ALuint) PyInt_AS_LONG(arg));
    } else if(PySequence_Check(arg)) {
        int i;
        int nb = PySequence_Size(arg);
        ALuint arg1[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
          o = PySequence_Fast_GET_ITEM(arg, i);
          if(!PyInt_Check(o)) return NULL;
          arg1[i] = (ALuint) PyInt_AS_LONG(o);
        }
        alSourcePausev(nb, arg1);
    }
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alGenBuffers(PyObject *self, PyObject *arg) {
    if(!PyInt_Check(arg)) return NULL;
    {
        int nb = (int) PyInt_AS_LONG (arg);
        ALuint result[nb];
        
        alGenBuffers(nb,result);
        
        if(nb == 1) {
            return PyInt_FromLong((long) result[0]);
        } else {
            PyObject *resultobj;
            int i;
            resultobj = PyTuple_New(nb);
            for(i = 0; i < nb; i++) {
                PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong((long) result[i]));
            }
            return resultobj;
        }
    }
}


static PyObject *_wrap_alDeleteBuffers(PyObject *self, PyObject *args) {
    ALsizei arg1 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alDeleteBuffers",&arg1,&obj1)) return NULL;
    if(arg1 == 1) {
        ALuint arg2 ;
        if(!PyInt_Check(obj1)) return NULL;
        arg2 = (ALuint) PyInt_AS_LONG(obj1);
        alDeleteBuffers(arg1,&arg2);
    } else {
        if(!PySequence_Check(obj1)) return NULL;
        {
            int i;
            int nb = PySequence_Size(obj1);
            PyObject *o;
            ALuint arg2[nb];

            for(i = 0; i < nb; i++) {
                o = (PyObject*) PySequence_Fast_GET_ITEM(obj1, i);
                if(!PyInt_Check(o)) return NULL;
                arg2[i] = (ALuint) PyInt_AS_LONG(o);
            }
            alDeleteBuffers(arg1,arg2);
        }
    }
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alIsBuffer(PyObject *self, PyObject *arg) {
    if(!PyInt_Check(arg)) return NULL;
    if(alIsBuffer((ALuint) PyInt_AS_LONG(arg)))
        return PyInt_FromLong(1);
    else 
        return PyInt_FromLong(0);
}


static PyObject *_wrap_alBufferData(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    void *arg3 ;
    ALsizei arg4 ;
    ALsizei arg5 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iis#i:alBufferData",&arg1,&arg2,&arg3,&arg4,&arg5)) return NULL;
    alBufferData(arg1,arg2,arg3,arg4,arg5);
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alGetBufferi(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    int arg3 ;
    int i;
    ALint *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"iii:alGetBufferi",&arg1,&arg2,&arg3)) return NULL;
    result = (ALint *) malloc(arg3 * sizeof(ALint));
    alGetBufferi(arg1,arg2,result);
    
    resultobj = PyTuple_New(arg3);
    for(i = 0; i < arg3; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyInt_FromLong ((long) result[i]));
    }
    free(result);

    return resultobj;
}


static PyObject *_wrap_alGetBufferf(PyObject *self, PyObject *args) {
    ALuint arg1 ;
    ALenum arg2 ;
    int arg3 ;
    int i;
    ALfloat *result ;
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)"iii:alGetBufferf",&arg1,&arg2,&arg3)) return NULL;
    result = (ALfloat *) malloc(arg3 * sizeof(ALfloat));
    alGetBufferf(arg1,arg2,result);
    
    resultobj = PyTuple_New(arg3);
    for(i = 0; i < arg3; i++) {
      PyTuple_SET_ITEM(resultobj, i, PyFloat_FromDouble ((double) result[i]));
    }
    free(result);

    return resultobj;
}


/* TO DO
static PyObject *_wrap_alGenEnvironmentIASIG(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALsizei arg1 ;
    ALuint *arg2 ;
    ALsizei result;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alGenEnvironmentIASIG",&arg1,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALuint,1)) == -1) return NULL;
    result = (ALsizei )alGenEnvironmentIASIG(arg1,arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_alDeleteEnvironmentIASIG(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALsizei arg1 ;
    ALuint *arg2 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alDeleteEnvironmentIASIG",&arg1,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALuint,1)) == -1) return NULL;
    alDeleteEnvironmentIASIG(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alIsEnvironmentIASIG(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:alIsEnvironmentIASIG",&obj0)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    result = (ALboolean )alIsEnvironmentIASIG(arg1);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alEnvironmentiIASIG(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    ALint arg3 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oii:alEnvironmentiIASIG",&obj0,&arg2,&arg3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    alEnvironmentiIASIG(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alEnvironmentfIASIG(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    ALuint arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiO:alEnvironmentfIASIG",&obj0,&arg2,&obj2)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    arg3 = (ALuint ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    alEnvironmentfIASIG(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}
*/

/*
static PyObject *_wrap_alSourceQueueBuffers(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALsizei arg2 ;
    ALuint *arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiO:alSourceQueueBuffers",&obj0,&arg2,&obj2)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, SWIGTYPE_p_ALuint,1)) == -1) return NULL;
    alSourceQueueBuffers(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alSourceUnqueueBuffers(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALsizei arg2 ;
    ALuint *arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiO:alSourceUnqueueBuffers",&obj0,&arg2,&obj2)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, SWIGTYPE_p_ALuint,1)) == -1) return NULL;
    alSourceUnqueueBuffers(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alQueuei(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    ALint arg3 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oii:alQueuei",&obj0,&arg2,&arg3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    alQueuei(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}
*/

static PyObject *_wrap_alDopplerFactor(PyObject *self, PyObject *arg) {
    if(!PyFloat_Check(arg)) return NULL;
    alDopplerFactor((ALfloat) PyFloat_AS_DOUBLE(arg));
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alDopplerVelocity(PyObject *self, PyObject *arg) {
    if(!PyFloat_Check(arg)) return NULL;
    alDopplerVelocity((ALfloat) PyFloat_AS_DOUBLE(arg));
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alDistanceModel(PyObject *self, PyObject *arg) {
  if(!PyInt_Check(arg)) return NULL;
  alDistanceModel((ALenum) PyInt_AS_LONG(arg));
  Py_INCREF(Py_None); 
  return Py_None;
}


static PyObject *_wrap_alcCreateContext(PyObject *self, PyObject *args) {
    void *result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:alcCreateContext",&obj0,&obj1)) return NULL;
    if(!PyCObject_Check(obj0)) return NULL;
    if(!PySequence_Check(obj1)) return NULL;

    {
        int nb = PySequence_Size(obj1);
        int i;
        ALint arg2[nb];
        PyObject *o;

        for(i = 0; i < nb; i++) {
            o = PySequence_Fast_GET_ITEM(obj1, i);
            if(!PyInt_Check(o)) return NULL;
            arg2[i] = PyInt_AS_LONG(o);
        }

        result = (void *)alcCreateContext((ALCdevice*) PyCObject_AsVoidPtr(obj0), arg2);
    }

    if(result == NULL) {
        Py_INCREF(Py_None); 
        return Py_None;
    } else {    
        return PyCObject_FromVoidPtr(result, NULL);
    }
}


static PyObject *_wrap_alcMakeContextCurrent(PyObject *self, PyObject *arg) {
    if(!PyCObject_Check(arg)) return NULL;
    return PyInt_FromLong((long) alcMakeContextCurrent(PyCObject_AsVoidPtr(arg)));
}


static PyObject *_wrap_alcProcessContext(PyObject *self, PyObject *arg) {
    void *result;
    
    if(!PyCObject_Check(arg)) return NULL;
    alcProcessContext(PyCObject_AsVoidPtr(arg));

    //if(result == NULL) {
        Py_INCREF(Py_None); 
        return Py_None;
    /*}  else {    
        return PyCObject_FromVoidPtr(result, NULL);
    }*/
}


static PyObject *_wrap_alcSuspendContext(PyObject *self, PyObject *arg) {
    if(!PyCObject_Check(arg)) return NULL;
    alcSuspendContext(PyCObject_AsVoidPtr(arg));
    
    Py_INCREF(Py_None); 
    return Py_None;
}


static PyObject *_wrap_alcDestroyContext(PyObject *self, PyObject *arg) {
    if(!PyCObject_Check(arg)) return NULL;
    alcDestroyContext(PyCObject_AsVoidPtr(arg));
    Py_INCREF(Py_None); 
    return Py_None;
}


//static PyObject *_wrap_alcGetError(PyObject *self, PyObject *arg) {
//    return PyInt_FromLong((long) alcGetError());
    //return PyInt_FromLong((long) alcGetError(PyCObject_AsVoidPtr(arg)));
//}


static PyObject *_wrap_alcGetCurrentContext(PyObject *self) {
    void *result;
    
    result = alcGetCurrentContext();
    
    if(result == NULL) {
        Py_INCREF(Py_None); 
        return Py_None;
    } else {    
        return PyCObject_FromVoidPtr(result, NULL);
    }
}


static PyObject *_wrap_alcOpenDevice(PyObject *self, PyObject *arg) {
    ALCdevice *result;
    
    if(arg == Py_None) {
      result = alcOpenDevice(NULL);
    } else {
      if(!PyString_Check(arg)) return NULL;
      result = alcOpenDevice((ALubyte const *) PyString_AS_STRING(arg));
    }
    
    if(result == NULL) {
        Py_INCREF(Py_None); 
        return Py_None;
    } else {    
        return PyCObject_FromVoidPtr(result, NULL);
    }
}


static PyObject *_wrap_alcCloseDevice(PyObject *self, PyObject *arg) {
    if(!PyCObject_Check(arg)) return NULL;
    alcCloseDevice(PyCObject_AsVoidPtr(arg));
    Py_INCREF(Py_None); 
    return Py_None;
}


/*
static PyObject *_wrap_alcIsExtensionPresent(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALCdevice *arg1 ;
    ALubyte *arg2 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:alcIsExtensionPresent",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_ALCdevice,1)) == -1) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALubyte,1)) == -1) return NULL;
    result = (ALboolean )alcIsExtensionPresent(arg1,arg2);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alcGetProcAddress(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALCdevice *arg1 ;
    ALubyte *arg2 ;
    void *result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:alcGetProcAddress",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_ALCdevice,1)) == -1) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALubyte,1)) == -1) return NULL;
    result = (void *)alcGetProcAddress(arg1,arg2);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_void, 0);
    return resultobj;
}


static PyObject *_wrap_alcGetEnumValue(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALCdevice *arg1 ;
    ALubyte *arg2 ;
    ALenum result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:alcGetEnumValue",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_ALCdevice,1)) == -1) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALubyte,1)) == -1) return NULL;
    result = (ALenum )alcGetEnumValue(arg1,arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}
*/

static PyObject *_wrap_alutInit(PyObject *self, PyObject *args) {
// TO DO
    alutInit(NULL,NULL);
    
    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject *_wrap_alutExit(PyObject *self) {
    alutExit();
    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject *_wrap_alutLoadWAVFile(PyObject *self, PyObject *arg) {
    ALvoid *wave = NULL;
    ALsizei format;
    ALsizei size;
    ALsizei bits;
    ALsizei freq;
    PyObject* resultobj;

    if(!PyString_Check(arg)) return NULL;

    alutLoadWAVFile((char* const) PyString_AS_STRING(arg), &wave, &format, &size, &bits, &freq);

    if(wave == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    } else {
        resultobj = PyTuple_New(5);
        PyTuple_SET_ITEM(resultobj, 0, PyString_FromStringAndSize(wave, size));
        PyTuple_SET_ITEM(resultobj, 1, PyInt_FromLong((long) format));
        PyTuple_SET_ITEM(resultobj, 2, PyInt_FromLong((long) size));
        PyTuple_SET_ITEM(resultobj, 3, PyInt_FromLong((long) bits));
        PyTuple_SET_ITEM(resultobj, 4, PyInt_FromLong((long) freq));
        return resultobj;
    }
}

/*
static PyObject *_wrap_alcGetAudioChannel_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALfloat result;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:alcGetAudioChannel_LOKI",&obj0)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    result = (ALfloat )alcGetAudioChannel_LOKI(arg1);
    
    resultobj = PyFloat_FromDouble(result);
    return resultobj;
}


static PyObject *_wrap_alcSetAudioChannel_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALfloat arg2 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Of:alcSetAudioChannel_LOKI",&obj0,&arg2)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    alcSetAudioChannel_LOKI(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alBombOnError_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    
    if(!PyArg_ParseTuple(args,(char *)":alBombOnError_LOKI")) return NULL;
    alBombOnError_LOKI();
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alBufferi_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    ALint arg3 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oii:alBufferi_LOKI",&obj0,&arg2,&arg3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    alBufferi_LOKI(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alBufferDataWithCallback_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    int (*arg2)(ALuint ,ALuint ,ALshort *,ALenum ,ALint ,ALint ) ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:alBufferDataWithCallback_LOKI",&obj0,&obj1)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_f_ALuint_ALuint_p_ALshort_ALenum_ALint_ALint__int,1)) == -1) return NULL;
    alBufferDataWithCallback_LOKI(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alBufferWriteData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    void *arg3 ;
    ALsizei arg4 ;
    ALsizei arg5 ;
    ALenum arg6 ;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiOiii:alBufferWriteData_LOKI",&obj0,&arg2,&obj2,&arg4,&arg5,&arg6)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, 0, 1)) == -1) return NULL;
    alBufferWriteData_LOKI(arg1,arg2,arg3,arg4,arg5,arg6);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alGenStreamingBuffers_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALsizei arg1 ;
    ALuint *arg2 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iO:alGenStreamingBuffers_LOKI",&arg1,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_ALuint,1)) == -1) return NULL;
    alGenStreamingBuffers_LOKI(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_alBufferAppendData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    void *arg3 ;
    ALsizei arg4 ;
    ALsizei arg5 ;
    ALsizei result;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiOii:alBufferAppendData_LOKI",&obj0,&arg2,&obj2,&arg4,&arg5)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, 0, 1)) == -1) return NULL;
    result = (ALsizei )alBufferAppendData_LOKI(arg1,arg2,arg3,arg4,arg5);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_alBufferAppendWriteData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    ALenum arg2 ;
    void *arg3 ;
    ALsizei arg4 ;
    ALsizei arg5 ;
    ALenum arg6 ;
    ALsizei result;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiOiii:alBufferAppendWriteData_LOKI",&obj0,&arg2,&obj2,&arg4,&arg5,&arg6)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, 0, 1)) == -1) return NULL;
    result = (ALsizei )alBufferAppendWriteData_LOKI(arg1,arg2,arg3,arg4,arg5,arg6);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_alCaptureInit_EXT(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALenum arg1 ;
    ALuint arg2 ;
    ALsizei arg3 ;
    ALboolean result;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"iOi:alCaptureInit_EXT",&arg1,&obj1,&arg3)) return NULL;
    arg2 = (ALuint ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (ALboolean )alCaptureInit_EXT(arg1,arg2,arg3);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alCaptureDestroy_EXT(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALboolean result;
    
    if(!PyArg_ParseTuple(args,(char *)":alCaptureDestroy_EXT")) return NULL;
    result = (ALboolean )alCaptureDestroy_EXT();
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alCaptureStart_EXT(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALboolean result;
    
    if(!PyArg_ParseTuple(args,(char *)":alCaptureStart_EXT")) return NULL;
    result = (ALboolean )alCaptureStart_EXT();
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alCaptureStop_EXT(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALboolean result;
    
    if(!PyArg_ParseTuple(args,(char *)":alCaptureStop_EXT")) return NULL;
    result = (ALboolean )alCaptureStop_EXT();
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alCaptureGetData_EXT(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    void *arg1 ;
    ALsizei arg2 ;
    ALenum arg3 ;
    ALuint arg4 ;
    ALsizei result;
    PyObject * obj0  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OiiO:alCaptureGetData_EXT",&obj0,&arg2,&arg3,&obj3)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, 0, 1)) == -1) return NULL;
    arg4 = (ALuint ) PyInt_AsLong(obj3);
    if (PyErr_Occurred()) return NULL;
    result = (ALsizei )alCaptureGetData_EXT(arg1,arg2,arg3,arg4);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_alutLoadVorbis_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    void *arg2 ;
    ALint arg3 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOi:alutLoadVorbis_LOKI",&obj0,&obj1,&arg3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, 0, 1)) == -1) return NULL;
    result = (ALboolean )alutLoadVorbis_LOKI(arg1,arg2,arg3);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alutLoadRAW_ADPCMData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    void *arg2 ;
    ALuint arg3 ;
    ALuint arg4 ;
    ALenum arg5 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOOOi:alutLoadRAW_ADPCMData_LOKI",&obj0,&obj1,&obj2,&obj3,&arg5)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, 0, 1)) == -1) return NULL;
    arg3 = (ALuint ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    arg4 = (ALuint ) PyInt_AsLong(obj3);
    if (PyErr_Occurred()) return NULL;
    result = (ALboolean )alutLoadRAW_ADPCMData_LOKI(arg1,arg2,arg3,arg4,arg5);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alutLoadIMA_ADPCMData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    void *arg2 ;
    ALuint arg3 ;
    alIMAADPCM_state_LOKI *arg4 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOOO:alutLoadIMA_ADPCMData_LOKI",&obj0,&obj1,&obj2,&obj3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, 0, 1)) == -1) return NULL;
    arg3 = (ALuint ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj3,(void **) &arg4, SWIGTYPE_p_alIMAADPCM_state_LOKI,1)) == -1) return NULL;
    result = (ALboolean )alutLoadIMA_ADPCMData_LOKI(arg1,arg2,arg3,arg4);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}


static PyObject *_wrap_alutLoadMS_ADPCMData_LOKI(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    ALuint arg1 ;
    void *arg2 ;
    int arg3 ;
    alMSADPCM_state_LOKI *arg4 ;
    ALboolean result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOiO:alutLoadMS_ADPCMData_LOKI",&obj0,&obj1,&arg3,&obj3)) return NULL;
    arg1 = (ALuint ) PyInt_AsLong(obj0);
    if (PyErr_Occurred()) return NULL;
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, 0, 1)) == -1) return NULL;
    if ((SWIG_ConvertPtr(obj3,(void **) &arg4, SWIGTYPE_p_alMSADPCM_state_LOKI,1)) == -1) return NULL;
    result = (ALboolean )alutLoadMS_ADPCMData_LOKI(arg1,arg2,arg3,arg4);
    
    resultobj = Py_BuildValue((char*)"c",result);
    return resultobj;
}
*/


/*---------*
 * OBJECTS *
 *---------*/

typedef struct {
  PyObject_HEAD
  ALuint ptr;
} PyALObject;

static PyObject* PyALObject_New (PyTypeObject* type, PyObject* args, PyObject* kwds) {
  PyObject* self;
  assert (type != NULL && type->tp_alloc != NULL);
  self = type->tp_alloc (type, 0);
  return self;
}

static void PyALObject_Dealloc (PyObject* o) {
  o->ob_type->tp_free (o);
}

static ALCdevice* device = NULL;

static PyObject* PyAL_InitDevice (PyObject* module, PyObject* arg) {
  if (arg == Py_None) {
    device = alcOpenDevice (NULL);
  } else {
    device = alcOpenDevice ((ALubyte const*) PyString_AS_STRING (arg));
  }
  if (device == NULL) { 
    PyErr_SetString (PyExc_RuntimeError, "no sound device found");
  }
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyAL_QuitDevice (PyObject* module) {
  if (device != NULL) alcCloseDevice (device);
  device = NULL;
  Py_INCREF (Py_None);
  return Py_None;
}


/*-----------------*
 * LISTENER OBJECT * (mixed with context because you can have only 1 unique listener per context)
 *-----------------*/

typedef struct {
  PyObject_HEAD
  ALuint ptr;
  void* context;
} PyALListener;

static int PyALListener_Init (PyObject* self, PyObject* args, PyObject* kwds) {
  PyALListener* o = (PyALListener*) self;
  if (device == NULL) {
    PyErr_SetString (PyExc_RuntimeError, "no device opened");
    return -1;
  }
  if (args == Py_None) {
    o->context = alcCreateContext ((ALCdevice* const) device, NULL);
  } else {
    ALint attrs[6];
    int nb = PySequence_Size (args);
    /* args are: (freq, refresh, sync) */
    attrs[0] = ALC_FREQUENCY;
    switch (nb) {
    case 1:
      attrs[1] = (ALint) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 0));
      attrs[2] = ALC_INVALID;
      break;
    case 2:
      attrs[1] = (ALint) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 0));
      attrs[2] = ALC_REFRESH;
      attrs[3] = (ALint) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 1));
      attrs[4] = ALC_INVALID;
      break;
    case 3:
      attrs[1] = (ALint) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 0));
      attrs[2] = ALC_REFRESH;
      attrs[3] = (ALint) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 1));
      if (PyObject_IsTrue (PySequence_Fast_GET_ITEM (args, 2))) {
        attrs[4] = ALC_SYNC;
        attrs[5] = ALC_INVALID;
      } else {
        attrs[4] = ALC_INVALID;
      }
      break;
    }
    o->context = alcCreateContext ((ALCdevice* const) device, attrs);
  }
  if (o->context == NULL) {
    PyErr_SetString (PyExc_RuntimeError, "can't create context");
    return -1; 
  } else {
    alcMakeContextCurrent (o->context);
  }
	return 0;
}

static void PyALListener_Dealloc (PyALListener* o) {
  if (device != NULL && o->context != NULL) {
    if (alcGetCurrentContext () == o->context) alcMakeContextCurrent (NULL);
    alcDestroyContext (o->context);
  }
  o->ob_type->tp_free ((PyObject*) o);
}

static PyObject* PyALListener_MakeCurrent (PyALListener* o) {
  alcMakeContextCurrent (o->context);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALListener_ProcessContext (PyALListener* o) {
  alcProcessContext (o->context);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALListener_SuspendContext (PyALListener* o) {
  alcSuspendContext (o->context);
  Py_INCREF (Py_None);
  return Py_None;
}

//static PyObject* PyALListener_GetError (PyALListener* o) {
//  return PyInt_FromLong ((long) alcGetError ());
  //return PyInt_FromLong ((long) alcGetError (device));
//}

static PyMethodDef PyALListener_Methods[] = {
  { "make_current", (PyCFunction) PyALListener_MakeCurrent,    METH_NOARGS },
  { "process",      (PyCFunction) PyALListener_ProcessContext, METH_NOARGS },
  { "suspend",      (PyCFunction) PyALListener_SuspendContext, METH_NOARGS },
//  { "get_error",    (PyCFunction) PyALListener_GetError,       METH_NOARGS },
  { NULL, NULL } /* sentinel */
};

static PyObject* PyALListener_GetPosition (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat p[3];
  alGetListenerfv (AL_POSITION, p);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) p[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) p[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) p[2]));
  return tuple;
}

static int PyALListener_SetPosition (PyALObject* o, PyObject* value, void* context) {
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alListener3f (AL_POSITION, 
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0)),
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1)),
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2)));
  return 0;
}

static PyObject* PyALListener_GetVelocity (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat p[3];
  alGetListenerfv (AL_VELOCITY, p);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) p[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) p[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) p[2]));
  return tuple;
}

static int PyALListener_SetVelocity (PyALObject* o, PyObject* value, void* context) {
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alListener3f (AL_VELOCITY, 
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0)),
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1)),
                (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2)));
  return 0;
}

static PyObject* PyALListener_GetGain (PyALObject* o, void* context) {
  ALfloat g;
  alGetListenerfv (AL_GAIN, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALListener_SetGain (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alListenerf (AL_GAIN, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALListener_GetOrientationAt (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat v[6];
  alGetListenerfv (AL_ORIENTATION, v);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) v[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) v[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) v[2]));
  return tuple;
}

static int PyALListener_SetOrientationAt (PyALObject* o, PyObject* value, void* context) {
  ALfloat v[6];
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alGetListenerfv (AL_ORIENTATION, v);
  v[0] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0));
  v[1] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1));
  v[2] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2));
  alListenerfv (AL_ORIENTATION, v);
  return 0;
}

static PyObject* PyALListener_GetOrientationUp (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat v[6];
  alGetListenerfv (AL_ORIENTATION, v);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) v[3]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) v[4]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) v[5]));
  return tuple;
}

static int PyALListener_SetOrientationUp (PyALObject* o, PyObject* value, void* context) {
  ALfloat v[6];
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alGetListenerfv (AL_ORIENTATION, v);
  v[3] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0));
  v[4] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1));
  v[5] = (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2));
  alListenerfv (AL_ORIENTATION, (ALfloat*) v);
  return 0;
}

static PyGetSetDef PyALListener_GetSets[] = {
	{"position", (getter) PyALListener_GetPosition,      (setter) PyALListener_SetPosition,      NULL},
	{"velocity", (getter) PyALListener_GetVelocity,      (setter) PyALListener_SetVelocity,      NULL},
	{"gain",     (getter) PyALListener_GetGain,          (setter) PyALListener_SetGain,          NULL},
	{"at",       (getter) PyALListener_GetOrientationAt, (setter) PyALListener_SetOrientationAt, NULL},
	{"up",       (getter) PyALListener_GetOrientationUp, (setter) PyALListener_SetOrientationUp, NULL},
	{ NULL }
};

PyTypeObject PyALListener_Type = {
  PyObject_HEAD_INIT(&PyType_Type)
  0,
  "_Listener",
  sizeof(PyALListener),
  0,
  (destructor) PyALListener_Dealloc,/* tp_dealloc */
  0,/* tp_print */
  0,/* tp_getattr */
  0,/* tp_setattr */
  0,/* tp_compare */
  0,/* tp_repr */
  0,/* tp_as_number */
  0,/* tp_as_sequence */
  0,/* tp_as_mapping */
  0,/* tp_hash */
  0,/* tp_call */
  0,/* tp_str */
  PyObject_GenericGetAttr,/* tp_getattro */
  0,/* tp_setattro */
  0,/* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,/* tp_flags */
  0,/* tp_doc */
  (traverseproc) 0,/* tp_traverse */
  (inquiry) 0,/* tp_clear */
  0,/* tp_richcompare */
  0,/* tp_weaklistoffset */
  0,/* tp_iter */
  0,/* tp_iternext */
  (PyMethodDef*) &PyALListener_Methods,/* tp_methods */
  0,/* tp_members */
  (PyGetSetDef*) &PyALListener_GetSets,/* tp_getset */
  0,/* tp_base */
  0,/* tp_dict */
  0,/* tp_descr_get */
  0,/* tp_descr_set */
  0,/* tp_dictoffset */
  (initproc) PyALListener_Init,/* tp_init */
  PyType_GenericAlloc,/* tp_alloc */
  (newfunc) PyALObject_New,/* tp_new */
  _PyObject_Del,/* tp_free */
};


/*---------------*
 * SOURCE OBJECT *
 *---------------*/

typedef struct {
  PyObject_HEAD
  ALuint ptr;
  PyObject* buffer;
} PyALSource;

static int PyALSource_Init (PyObject* self, PyObject* args, PyObject* kwds) {
  PyALSource* o = (PyALSource*) self;
  if (device == NULL) {
    PyErr_SetString (PyExc_RuntimeError, "no device opened");
    return -1; 
  }
  alGenSources (1, &(o->ptr));
  Py_INCREF (Py_None);
  o->buffer = Py_None;
	return 0;
}

static void PyALSource_Dealloc (PyALObject* o) {
  if (device != NULL) alDeleteSources (1, &(o->ptr));
  o->ob_type->tp_free ((PyObject*) o);
}

static int PyALSource_Traverse (PyALSource* s, visitproc visit, void* arg) {
	int err;
  err = visit (s->buffer, arg);
  if (err) { return err; }
	return 0;
}

static int PyALSource_Clear (PyALSource* self) {
  Py_XDECREF (self->buffer);
  Py_INCREF (Py_None);
  self->buffer = Py_None;
  return 0;
}

static PyObject* PyALSource_QueueBuffers (PyALObject* o, PyObject* arg) {
  if (PySequence_Check (arg)) {
    int i;
    int nb = PySequence_Size (arg);
    ALuint u[nb];
    for (i = 0; i < nb; i++) {
      u[i] = ((PyALObject*) PySequence_Fast_GET_ITEM (arg, i))->ptr;
    }
    alSourceQueueBuffers (o->ptr, nb, u);
  } else {
    ALuint u = ((PyALObject*) arg)->ptr;
    alSourceQueueBuffers (o->ptr, 1, &u);
  }
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALSource_UnqueueBuffers (PyALObject* o, PyObject* arg) {
  if (PySequence_Check (arg)) {
    int i;
    int nb = PySequence_Size (arg);
    ALuint u[nb];
    for (i = 0; i < nb; i++) {
      u[i] = ((PyALObject*) PySequence_Fast_GET_ITEM (arg, i))->ptr;
    }
    alSourceUnqueueBuffers (o->ptr, nb, u);
  } else {
    ALuint u = ((PyALObject*) arg)->ptr;
    alSourceUnqueueBuffers (o->ptr, 1, &u);
  }
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALSource_GetState (PyALObject* o) {
  ALint i;
  alGetSourceiv (o->ptr, AL_SOURCE_STATE, &i);
  return PyInt_FromLong ((long) i);
}

static PyObject* PyALSource_Play (PyALObject* o) {
  alSourcePlay (o->ptr);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALSource_Pause (PyALObject* o) {
  alSourcePause (o->ptr);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALSource_Stop (PyALObject* o) {
  alSourceStop (o->ptr);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALSource_Rewind (PyALObject* o) {
  alSourceRewind (o->ptr);
  Py_INCREF (Py_None);
  return Py_None;
}

static PyMethodDef PyALSource_Methods[] = {
  { "queue_buffers",   (PyCFunction) PyALSource_QueueBuffers,   METH_O },
  { "unqueue_buffers", (PyCFunction) PyALSource_UnqueueBuffers, METH_O },
  { "get_state",       (PyCFunction) PyALSource_GetState,       METH_NOARGS },
  { "play",            (PyCFunction) PyALSource_Play,           METH_NOARGS },
  { "pause",           (PyCFunction) PyALSource_Pause,          METH_NOARGS },
  { "stop",            (PyCFunction) PyALSource_Stop,           METH_NOARGS },
  { "rewind",          (PyCFunction) PyALSource_Rewind,         METH_NOARGS },
  { NULL, NULL } /* sentinel */
};

static PyObject* PyALSource_GetPosition (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat p[3];
  alGetSourcefv (o->ptr, AL_POSITION, p);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) p[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) p[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) p[2]));
  return tuple;
}

static int PyALSource_SetPosition (PyALObject* o, PyObject* value, void* context) {
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alSource3f (o->ptr, AL_POSITION, 
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2)));
  return 0;
}

static PyObject* PyALSource_GetDirection (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat p[3];
  alGetSourcefv (o->ptr, AL_DIRECTION, p);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) p[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) p[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) p[2]));
  return tuple;
}

static int PyALSource_SetDirection (PyALObject* o, PyObject* value, void* context) {
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alSource3f (o->ptr, AL_DIRECTION, 
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2)));
  return 0;
}

static PyObject* PyALSource_GetVelocity (PyALObject* o, void* context) {
  PyObject* tuple;
  ALfloat p[3];
  alGetSourcefv (o->ptr, AL_VELOCITY, p);
  tuple = PyTuple_New (3);
  PyTuple_SET_ITEM (tuple, 0, PyFloat_FromDouble ((double) p[0]));
  PyTuple_SET_ITEM (tuple, 1, PyFloat_FromDouble ((double) p[1]));
  PyTuple_SET_ITEM (tuple, 2, PyFloat_FromDouble ((double) p[2]));
  return tuple;
}

static int PyALSource_SetVelocity (PyALObject* o, PyObject* value, void* context) {
  if (!PySequence_Check (value) || PySequence_Size (value) < 3) return -1;
  alSource3f (o->ptr, AL_VELOCITY, 
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 0)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 1)),
              (ALfloat) PyFloat_AS_DOUBLE (PySequence_Fast_GET_ITEM (value, 2)));
  return 0;
}

static PyObject* PyALSource_GetGain (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_GAIN, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetGain (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_GAIN, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetMinGain (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_MIN_GAIN, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetMinGain (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_MIN_GAIN, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetMaxGain (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_MAX_GAIN, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetMaxGain (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_MAX_GAIN, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetRelative (PyALObject* o, void* context) {
  ALint b;
  alGetSourceiv (o->ptr, AL_SOURCE_RELATIVE, &b);
  if (b == AL_TRUE) return PyInt_FromLong (1); else return PyInt_FromLong (0);
}

static int PyALSource_SetRelative (PyALObject* o, PyObject* value, void* context) {
  ALboolean b;
  if (!PyInt_Check (value)) return -1;
  if (PyInt_AS_LONG (value) == 0) b = AL_FALSE; else b = AL_TRUE;
  alSourcei (o->ptr, AL_SOURCE_RELATIVE, b);
  return 0;
}

static PyObject* PyALSource_GetLooping (PyALObject* o, void* context) {
  ALuint b;
  alGetSourceiv (o->ptr, AL_LOOPING, &b);
  if (b == AL_TRUE) return PyInt_FromLong (1); else return PyInt_FromLong (0);
}

static int PyALSource_SetLooping (PyALObject* o, PyObject* value, void* context) {
  ALuint b;
  if (!PyInt_Check (value)) return -1;
  if (PyInt_AS_LONG (value) == 0) b = AL_FALSE; else b = AL_TRUE;
  alSourcei (o->ptr, AL_LOOPING, b);
  return 0;
}

static PyObject* PyALSource_GetBuffer (PyALSource* o, void* context) {
  Py_INCREF (o->buffer);
  return o->buffer;
}

static int PyALSource_SetBuffer (PyALSource* o, PyObject* value, void* context) {
  ALuint b;
  Py_XDECREF (o->buffer);
  Py_INCREF (value);
  o->buffer = value;
  if (value == Py_None) {
    alSourcei (o->ptr, AL_BUFFER, 0);
  } else {
    b = ((PyALObject*) value)->ptr;
    alSourcei (o->ptr, AL_BUFFER, b);
  }
  return 0;
}

static PyObject* PyALSource_GetReferenceDistance (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_REFERENCE_DISTANCE, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetReferenceDistance (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_REFERENCE_DISTANCE, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetRolloffFactor (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_ROLLOFF_FACTOR, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetRolloffFactor (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_ROLLOFF_FACTOR, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetMaxDistance (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_MAX_DISTANCE, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetMaxDistance (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_MAX_DISTANCE, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetPitch (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_PITCH, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetPitch (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_PITCH, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyObject* PyALSource_GetConeInnerAngle (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_CONE_INNER_ANGLE, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetConeInnerAngle (PyALObject* o, PyObject* value, void* context) {
  if (PyFloat_Check (value)) {
    alSourcef (o->ptr, AL_CONE_INNER_ANGLE, (ALfloat) PyFloat_AS_DOUBLE (value));
  } else {
    if (!PyInt_Check (value)) return -1;
    alSourcei (o->ptr, AL_CONE_INNER_ANGLE, (ALint) PyInt_AS_LONG (value));
  }
  return 0;
}

static PyObject* PyALSource_GetConeOuterAngle (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_CONE_OUTER_ANGLE, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetConeOuterAngle (PyALObject* o, PyObject* value, void* context) {
  if (PyFloat_Check (value)) {
    alSourcef (o->ptr, AL_CONE_OUTER_ANGLE, (ALfloat) PyFloat_AS_DOUBLE (value));
  } else {
    if (!PyInt_Check (value)) return -1;
    alSourcei (o->ptr, AL_CONE_OUTER_ANGLE, (ALint) PyInt_AS_LONG (value));
  }
  return 0;
}

static PyObject* PyALSource_GetConeOuterGain (PyALObject* o, void* context) {
  ALfloat g;
  alGetSourcefv (o->ptr, AL_CONE_OUTER_GAIN, &g);
  return PyFloat_FromDouble ((double) g);
}

static int PyALSource_SetConeOuterGain (PyALObject* o, PyObject* value, void* context) {
  if (!PyFloat_Check (value)) return -1;
  alSourcef (o->ptr, AL_CONE_OUTER_GAIN, (ALfloat) PyFloat_AS_DOUBLE (value));
  return 0;
}

static PyGetSetDef PyALSource_GetSets[] = {
	{"position",           (getter) PyALSource_GetPosition,          (setter) PyALSource_SetPosition,          NULL},
	{"direction",          (getter) PyALSource_GetDirection,         (setter) PyALSource_SetDirection,         NULL},
	{"velocity",           (getter) PyALSource_GetVelocity,          (setter) PyALSource_SetVelocity,          NULL},
	{"gain",               (getter) PyALSource_GetGain,              (setter) PyALSource_SetGain,              NULL},
	{"min_gain",           (getter) PyALSource_GetMinGain,           (setter) PyALSource_SetMinGain,           NULL},
	{"max_gain",           (getter) PyALSource_GetMaxGain,           (setter) PyALSource_SetMaxGain,           NULL},
	{"relative",           (getter) PyALSource_GetRelative,          (setter) PyALSource_SetRelative,          NULL},
	{"looping",            (getter) PyALSource_GetLooping,           (setter) PyALSource_SetLooping,           NULL},
	{"buffer",             (getter) PyALSource_GetBuffer,            (setter) PyALSource_SetBuffer,            NULL},
	{"reference_distance", (getter) PyALSource_GetReferenceDistance, (setter) PyALSource_SetReferenceDistance, NULL},
	{"rolloff_factor",     (getter) PyALSource_GetRolloffFactor,     (setter) PyALSource_SetRolloffFactor,     NULL},
	{"max_distance",       (getter) PyALSource_GetMaxDistance,       (setter) PyALSource_SetMaxDistance,       NULL},
	{"pitch",              (getter) PyALSource_GetPitch,             (setter) PyALSource_SetPitch,             NULL},
	{"cone_inner_angle",   (getter) PyALSource_GetConeInnerAngle,    (setter) PyALSource_SetConeInnerAngle,    NULL},
	{"cone_outer_angle",   (getter) PyALSource_GetConeOuterAngle,    (setter) PyALSource_SetConeOuterAngle,    NULL},
	{"cone_outer_gain",    (getter) PyALSource_GetConeOuterGain,     (setter) PyALSource_SetConeOuterGain,     NULL},
	{ NULL }
};

PyTypeObject PyALSource_Type = {
  PyObject_HEAD_INIT(&PyType_Type)
  0,
  "_Source",
  sizeof(PyALSource),
  0,
  (destructor) PyALSource_Dealloc,/* tp_dealloc */
  0,/* tp_print */
  0,/* tp_getattr */
  0,/* tp_setattr */
  0,/* tp_compare */
  0,/* tp_repr */
  0,/* tp_as_number */
  0,/* tp_as_sequence */
  0,/* tp_as_mapping */
  0,/* tp_hash */
  0,/* tp_call */
  0,/* tp_str */
  PyObject_GenericGetAttr,/* tp_getattro */
  0,/* tp_setattro */
  0,/* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,/* tp_flags */
  0,/* tp_doc */
  (traverseproc) PyALSource_Traverse,/* tp_traverse */
  (inquiry) PyALSource_Clear,/* tp_clear */
  0,/* tp_richcompare */
  0,/* tp_weaklistoffset */
  0,/* tp_iter */
  0,/* tp_iternext */
  (PyMethodDef*) &PyALSource_Methods,/* tp_methods */
  0,/* tp_members */
  (PyGetSetDef*) &PyALSource_GetSets,/* tp_getset */
  0,/* tp_base */
  0,/* tp_dict */
  0,/* tp_descr_get */
  0,/* tp_descr_set */
  0,/* tp_dictoffset */
  (initproc) PyALSource_Init,/* tp_init */
  PyType_GenericAlloc,/* tp_alloc */
  (newfunc) PyALObject_New,/* tp_new */
  _PyObject_Del,/* tp_free */
};


/*---------------*
 * BUFFER OBJECT *
 *---------------*/

static int PyALBuffer_Init (PyObject* self, PyObject* args, PyObject* kwds) {
  PyALObject* o = (PyALObject*) self;
  if (device == NULL) {
    PyErr_SetString (PyExc_RuntimeError, "no device opened");
    return -1; 
  }
  alGenBuffers (1, &(o->ptr));
	return 0;
}

static void PyALBuffer_Dealloc (PyALObject* o) {
  if (o->ptr != 0 && device != NULL) alDeleteBuffers (1, &(o->ptr));
  o->ob_type->tp_free ((PyObject*) o);
}

static PyObject* PyALBuffer_SetData (PyALObject* o, PyObject* args) {
  PyObject* data;
  data = PySequence_Fast_GET_ITEM (args, 1);
  alBufferData (o->ptr, 
                (ALenum)  PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 0)), /* format */
                (ALvoid*) PyString_AS_STRING (data), /* data */
                (ALsizei) PyString_Size (data),
                (ALsizei) PyInt_AS_LONG (PySequence_Fast_GET_ITEM (args, 2)) /* freq */
                );
  Py_INCREF (Py_None);
  return Py_None;
}

static PyObject* PyALBuffer_GetFrequency (PyALObject* o) {
  ALsizei g;
  alGetBufferi (o->ptr, AL_FREQUENCY, &g);
  return PyInt_FromLong ((long) g);
}

static PyObject* PyALBuffer_GetSize (PyALObject* o) {
  ALsizei g;
  alGetBufferi (o->ptr, AL_SIZE, &g);
  return PyInt_FromLong ((long) g);
}

static PyMethodDef PyALBuffer_Methods[] = {
  { "set_data",      (PyCFunction) PyALBuffer_SetData,      METH_VARARGS },
  { "get_frequency", (PyCFunction) PyALBuffer_GetFrequency, METH_NOARGS },
  { "get_size",      (PyCFunction) PyALBuffer_GetSize,      METH_NOARGS },
  { NULL, NULL } /* sentinel */
};

PyTypeObject PyALBuffer_Type = {
  PyObject_HEAD_INIT(&PyType_Type)
  0,
  "_Buffer",
  sizeof(PyALObject),
  0,
  (destructor) PyALBuffer_Dealloc,/* tp_dealloc */
  0,/* tp_print */
  0,/* tp_getattr */
  0,/* tp_setattr */
  0,/* tp_compare */
  0,/* tp_repr */
  0,/* tp_as_number */
  0,/* tp_as_sequence */
  0,/* tp_as_mapping */
  0,/* tp_hash */
  0,/* tp_call */
  0,/* tp_str */
  PyObject_GenericGetAttr,/* tp_getattro */
  0,/* tp_setattro */
  0,/* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,/* tp_flags */
  0,/* tp_doc */
  (traverseproc) 0,/* tp_traverse */
  (inquiry) 0,/* tp_clear */
  0,/* tp_richcompare */
  0,/* tp_weaklistoffset */
  0,/* tp_iter */
  0,/* tp_iternext */
  (PyMethodDef*) &PyALBuffer_Methods,/* tp_methods */
  0,/* tp_members */
  (PyGetSetDef*) 0,/* tp_getset */
  0,/* tp_base */
  0,/* tp_dict */
  0,/* tp_descr_get */
  0,/* tp_descr_set */
  0,/* tp_dictoffset */
  (initproc) PyALBuffer_Init,/* tp_init */
  PyType_GenericAlloc,/* tp_alloc */
  (newfunc) PyALObject_New,/* tp_new */
  _PyObject_Del,/* tp_free */
};


/*--------*
 * MODULE *
 *--------*/

static PyMethodDef OpenALMethods[] = {
	 { (char *)"init", (PyCFunction) PyAL_InitDevice, METH_O },
	 { (char *)"quit", (PyCFunction) PyAL_QuitDevice, METH_NOARGS },

	 { (char *)"alEnable", (PyCFunction) _wrap_alEnable, METH_O },
	 { (char *)"alDisable", (PyCFunction) _wrap_alDisable, METH_O },
	 { (char *)"alIsEnabled", (PyCFunction) _wrap_alIsEnabled, METH_O },
	 { (char *)"alGetBooleanv", (PyCFunction) _wrap_alGetBooleanv, METH_VARARGS },
	 { (char *)"alGetIntegerv", (PyCFunction) _wrap_alGetIntegerv, METH_VARARGS },
	 { (char *)"alGetFloatv", (PyCFunction) _wrap_alGetFloatv, METH_VARARGS },
	 { (char *)"alGetDoublev", (PyCFunction) _wrap_alGetDoublev, METH_VARARGS },
	 { (char *)"alGetString", (PyCFunction) _wrap_alGetString, METH_O },
	 { (char *)"alGetError", (PyCFunction) _wrap_alGetError, METH_NOARGS },
	 { (char *)"alIsExtensionPresent", (PyCFunction) _wrap_alIsExtensionPresent, METH_VARARGS },
	 { (char *)"alGetProcAddress", (PyCFunction) _wrap_alGetProcAddress, METH_VARARGS },
	 { (char *)"alGetEnumValue", (PyCFunction) _wrap_alGetEnumValue, METH_VARARGS },
	 { (char *)"alListenerf", (PyCFunction) _wrap_alListenerf, METH_VARARGS },
	 { (char *)"alListener3f", (PyCFunction) _wrap_alListener3f, METH_VARARGS },
	 { (char *)"alListenerfv", (PyCFunction) _wrap_alListenerfv, METH_VARARGS },
	 { (char *)"alGetListeneriv", (PyCFunction) _wrap_alGetListeneriv, METH_VARARGS },
	 { (char *)"alGetListenerfv", (PyCFunction) _wrap_alGetListenerfv, METH_VARARGS },
	 { (char *)"alGenSources", (PyCFunction) _wrap_alGenSources, METH_O },
	 { (char *)"alDeleteSources", (PyCFunction) _wrap_alDeleteSources, METH_VARARGS },
	 { (char *)"alIsSource", (PyCFunction) _wrap_alIsSource, METH_O },
	 { (char *)"alSourcei", (PyCFunction) _wrap_alSourcei, METH_VARARGS },
	 { (char *)"alSourcef", (PyCFunction) _wrap_alSourcef, METH_VARARGS },
	 { (char *)"alSource3f", (PyCFunction) _wrap_alSource3f, METH_VARARGS },
	 { (char *)"alSourcefv", (PyCFunction) _wrap_alSourcefv, METH_VARARGS },
	 { (char *)"alGetSourceiv", (PyCFunction) _wrap_alGetSourceiv, METH_VARARGS },
	 { (char *)"alGetSourcefv", (PyCFunction) _wrap_alGetSourcefv, METH_VARARGS },
	 { (char *)"alSourcePlayv", (PyCFunction) _wrap_alSourcePlayv, METH_O },
	 { (char *)"alSourceStopv", (PyCFunction) _wrap_alSourceStopv, METH_O },
	 { (char *)"alSourceRewindv", (PyCFunction) _wrap_alSourceRewindv, METH_O },
	 { (char *)"alSourcePausev", (PyCFunction) _wrap_alSourcePausev, METH_O },
	 { (char *)"alGenBuffers", (PyCFunction) _wrap_alGenBuffers, METH_O },
	 { (char *)"alDeleteBuffers", (PyCFunction) _wrap_alDeleteBuffers, METH_VARARGS },
	 { (char *)"alIsBuffer", (PyCFunction) _wrap_alIsBuffer, METH_O },
	 { (char *)"alBufferData", (PyCFunction) _wrap_alBufferData, METH_VARARGS },
	 { (char *)"alGetBufferi", (PyCFunction) _wrap_alGetBufferi, METH_VARARGS },
	 { (char *)"alGetBufferf", (PyCFunction) _wrap_alGetBufferf, METH_VARARGS },
/*
	 { (char *)"alGenEnvironmentIASIG", (PyCFunction) _wrap_alGenEnvironmentIASIG, METH_VARARGS },
	 { (char *)"alDeleteEnvironmentIASIG", (PyCFunction) _wrap_alDeleteEnvironmentIASIG, METH_VARARGS },
	 { (char *)"alIsEnvironmentIASIG", (PyCFunction) _wrap_alIsEnvironmentIASIG, METH_VARARGS },
	 { (char *)"alEnvironmentiIASIG", (PyCFunction) _wrap_alEnvironmentiIASIG, METH_VARARGS },
	 { (char *)"alEnvironmentfIASIG", (PyCFunction) _wrap_alEnvironmentfIASIG, METH_VARARGS },
*/
/*
	 { (char *)"alSourceQueueBuffers", (PyCFunction) _wrap_alSourceQueueBuffers, METH_VARARGS },
	 { (char *)"alSourceUnqueueBuffers", (PyCFunction) _wrap_alSourceUnqueueBuffers, METH_VARARGS },
	 { (char *)"alQueuei", (PyCFunction) _wrap_alQueuei, METH_VARARGS },
*/
	 { (char *)"alDopplerFactor", (PyCFunction) _wrap_alDopplerFactor, METH_O },
	 { (char *)"alDopplerVelocity", (PyCFunction) _wrap_alDopplerVelocity, METH_O },
	 { (char *)"alDistanceModel", (PyCFunction) _wrap_alDistanceModel, METH_O },
	 { (char *)"alcCreateContext", (PyCFunction) _wrap_alcCreateContext, METH_VARARGS },
	 { (char *)"alcMakeContextCurrent", (PyCFunction) _wrap_alcMakeContextCurrent, METH_O },
	 { (char *)"alcProcessContext", (PyCFunction) _wrap_alcProcessContext, METH_O },
	 { (char *)"alcSuspendContext", (PyCFunction) _wrap_alcSuspendContext, METH_O },
	 { (char *)"alcDestroyContext", (PyCFunction) _wrap_alcDestroyContext, METH_O },
//	 { (char *)"alcGetError", (PyCFunction) _wrap_alcGetError, METH_O },
	 { (char *)"alcGetCurrentContext", (PyCFunction) _wrap_alcGetCurrentContext, METH_NOARGS },
	 { (char *)"alcOpenDevice", (PyCFunction) _wrap_alcOpenDevice, METH_O },
	 { (char *)"alcCloseDevice", (PyCFunction) _wrap_alcCloseDevice, METH_O },
/*
	 { (char *)"alcIsExtensionPresent", (PyCFunction) _wrap_alcIsExtensionPresent, METH_VARARGS },
	 { (char *)"alcGetProcAddress", (PyCFunction) _wrap_alcGetProcAddress, METH_VARARGS },
	 { (char *)"alcGetEnumValue", (PyCFunction) _wrap_alcGetEnumValue, METH_VARARGS },
*/
	 { (char *)"alutInit", (PyCFunction) _wrap_alutInit, METH_VARARGS },
	 { (char *)"alutExit", (PyCFunction) _wrap_alutExit, METH_NOARGS },
	 { (char *)"alutLoadWAVFile", (PyCFunction) _wrap_alutLoadWAVFile, METH_VARARGS },
/*
	 { (char *)"alcGetAudioChannel_LOKI", (PyCFunction) _wrap_alcGetAudioChannel_LOKI, METH_VARARGS },
	 { (char *)"alcSetAudioChannel_LOKI", (PyCFunction) _wrap_alcSetAudioChannel_LOKI, METH_VARARGS },
	 { (char *)"alBombOnError_LOKI", (PyCFunction) _wrap_alBombOnError_LOKI, METH_VARARGS },
	 { (char *)"alBufferi_LOKI", (PyCFunction) _wrap_alBufferi_LOKI, METH_VARARGS },
	 { (char *)"alBufferDataWithCallback_LOKI", (PyCFunction) _wrap_alBufferDataWithCallback_LOKI, METH_VARARGS },
	 { (char *)"alBufferWriteData_LOKI", (PyCFunction) _wrap_alBufferWriteData_LOKI, METH_VARARGS },
	 { (char *)"alGenStreamingBuffers_LOKI", (PyCFunction) _wrap_alGenStreamingBuffers_LOKI, METH_VARARGS },
	 { (char *)"alBufferAppendData_LOKI", (PyCFunction) _wrap_alBufferAppendData_LOKI, METH_VARARGS },
	 { (char *)"alBufferAppendWriteData_LOKI", (PyCFunction) _wrap_alBufferAppendWriteData_LOKI, METH_VARARGS },
	 { (char *)"alCaptureInit_EXT", (PyCFunction) _wrap_alCaptureInit_EXT, METH_VARARGS },
	 { (char *)"alCaptureDestroy_EXT", (PyCFunction) _wrap_alCaptureDestroy_EXT, METH_VARARGS },
	 { (char *)"alCaptureStart_EXT", (PyCFunction) _wrap_alCaptureStart_EXT, METH_VARARGS },
	 { (char *)"alCaptureStop_EXT", (PyCFunction) _wrap_alCaptureStop_EXT, METH_VARARGS },
	 { (char *)"alCaptureGetData_EXT", (PyCFunction) _wrap_alCaptureGetData_EXT, METH_VARARGS },
	 { (char *)"alutLoadVorbis_LOKI", (PyCFunction) _wrap_alutLoadVorbis_LOKI, METH_VARARGS },
	 { (char *)"alutLoadRAW_ADPCMData_LOKI", (PyCFunction) _wrap_alutLoadRAW_ADPCMData_LOKI, METH_VARARGS },
	 { (char *)"alutLoadIMA_ADPCMData_LOKI", (PyCFunction) _wrap_alutLoadIMA_ADPCMData_LOKI, METH_VARARGS },
	 { (char *)"alutLoadMS_ADPCMData_LOKI", (PyCFunction) _wrap_alutLoadMS_ADPCMData_LOKI, METH_VARARGS },
*/
	 { NULL, NULL }
};


EXPORT(void) init_openal(void) {
    PyObject *m;
    PyObject *d;

    m = Py_InitModule((char *) "_openal", OpenALMethods);
    d = PyModule_GetDict(m);
    
    Py_INCREF (&PyALListener_Type);
    PyDict_SetItemString (d, "_Listener", (PyObject*) &PyALListener_Type);
    Py_INCREF (&PyALSource_Type);
    PyDict_SetItemString (d, "_Source", (PyObject*) &PyALSource_Type);
    Py_INCREF (&PyALBuffer_Type);
    PyDict_SetItemString (d, "_Buffer", (PyObject*) &PyALBuffer_Type);

    PyModule_AddIntConstant(m, "AL_INVALID", AL_INVALID);
    PyModule_AddIntConstant(m, "AL_NONE", AL_NONE);
    PyModule_AddIntConstant(m, "AL_FALSE", AL_FALSE);
    PyModule_AddIntConstant(m, "AL_TRUE", AL_TRUE);
    PyModule_AddIntConstant(m, "AL_SOURCE_TYPE", AL_SOURCE_TYPE);
    PyModule_AddIntConstant(m, "AL_SOURCE_RELATIVE", AL_SOURCE_RELATIVE);
    PyModule_AddIntConstant(m, "AL_CONE_INNER_ANGLE", AL_CONE_INNER_ANGLE);
    PyModule_AddIntConstant(m, "AL_CONE_OUTER_ANGLE", AL_CONE_OUTER_ANGLE);
    PyModule_AddIntConstant(m, "AL_PITCH", AL_PITCH);
    PyModule_AddIntConstant(m, "AL_POSITION", AL_POSITION);
    PyModule_AddIntConstant(m, "AL_DIRECTION", AL_DIRECTION);
    PyModule_AddIntConstant(m, "AL_VELOCITY", AL_VELOCITY);
    PyModule_AddIntConstant(m, "AL_LOOPING", AL_LOOPING);
    PyModule_AddIntConstant(m, "AL_STREAMING", AL_STREAMING);
    PyModule_AddIntConstant(m, "AL_BUFFER", AL_BUFFER);
    PyModule_AddIntConstant(m, "AL_GAIN", AL_GAIN);
    PyModule_AddIntConstant(m, "AL_MIN_GAIN", AL_MIN_GAIN);
    PyModule_AddIntConstant(m, "AL_MAX_GAIN", AL_MAX_GAIN);
    PyModule_AddIntConstant(m, "AL_ORIENTATION", AL_ORIENTATION);
    PyModule_AddIntConstant(m, "AL_SOURCE_STATE", AL_SOURCE_STATE);
    PyModule_AddIntConstant(m, "AL_INITIAL", AL_INITIAL);
    PyModule_AddIntConstant(m, "AL_PLAYING", AL_PLAYING);
    PyModule_AddIntConstant(m, "AL_PAUSED", AL_PAUSED);
    PyModule_AddIntConstant(m, "AL_STOPPED", AL_STOPPED);
    PyModule_AddIntConstant(m, "AL_BUFFERS_QUEUED", AL_BUFFERS_QUEUED);
    PyModule_AddIntConstant(m, "AL_BUFFERS_PROCESSED", AL_BUFFERS_PROCESSED);
    PyModule_AddIntConstant(m, "AL_FORMAT_MONO8", AL_FORMAT_MONO8);
    PyModule_AddIntConstant(m, "AL_FORMAT_MONO16", AL_FORMAT_MONO16);
    PyModule_AddIntConstant(m, "AL_FORMAT_STEREO8", AL_FORMAT_STEREO8);
    PyModule_AddIntConstant(m, "AL_FORMAT_STEREO16", AL_FORMAT_STEREO16);
    PyModule_AddIntConstant(m, "AL_REFERENCE_DISTANCE", AL_REFERENCE_DISTANCE);
    PyModule_AddIntConstant(m, "AL_ROLLOFF_FACTOR", AL_ROLLOFF_FACTOR);
    PyModule_AddIntConstant(m, "AL_CONE_OUTER_GAIN", AL_CONE_OUTER_GAIN);
    PyModule_AddIntConstant(m, "AL_MAX_DISTANCE", AL_MAX_DISTANCE);
    PyModule_AddIntConstant(m, "AL_FREQUENCY", AL_FREQUENCY);
    PyModule_AddIntConstant(m, "AL_BITS", AL_BITS);
    PyModule_AddIntConstant(m, "AL_CHANNELS", AL_CHANNELS);
    PyModule_AddIntConstant(m, "AL_SIZE", AL_SIZE);
    PyModule_AddIntConstant(m, "AL_UNUSED", AL_UNUSED);
    PyModule_AddIntConstant(m, "AL_NO_ERROR", AL_NO_ERROR);
    PyModule_AddIntConstant(m, "AL_INVALID_NAME", AL_INVALID_NAME);
    PyModule_AddIntConstant(m, "AL_ILLEGAL_ENUM", AL_ILLEGAL_ENUM);
    PyModule_AddIntConstant(m, "AL_INVALID_VALUE", AL_INVALID_VALUE);
    PyModule_AddIntConstant(m, "AL_ILLEGAL_COMMAND", AL_ILLEGAL_COMMAND);
    PyModule_AddIntConstant(m, "AL_OUT_OF_MEMORY", AL_OUT_OF_MEMORY);
    PyModule_AddIntConstant(m, "AL_VENDOR", AL_VENDOR);
    PyModule_AddIntConstant(m, "AL_VERSION", AL_VERSION);
    PyModule_AddIntConstant(m, "AL_RENDERER", AL_RENDERER);
    PyModule_AddIntConstant(m, "AL_EXTENSIONS", AL_EXTENSIONS);
    PyModule_AddIntConstant(m, "AL_DOPPLER_FACTOR", AL_DOPPLER_FACTOR);
    PyModule_AddIntConstant(m, "AL_DOPPLER_VELOCITY", AL_DOPPLER_VELOCITY);
    PyModule_AddIntConstant(m, "AL_DISTANCE_MODEL", AL_DISTANCE_MODEL);
    PyModule_AddIntConstant(m, "AL_INVERSE_DISTANCE", AL_INVERSE_DISTANCE);
    PyModule_AddIntConstant(m, "AL_INVERSE_DISTANCE_CLAMPED", AL_INVERSE_DISTANCE_CLAMPED);
//    PyModule_AddIntConstant(m, "AL_FORMAT_IMA_ADPCM_MONO16_EXT", AL_FORMAT_IMA_ADPCM_MONO16_EXT);
//    PyModule_AddIntConstant(m, "AL_FORMAT_IMA_ADPCM_STEREO16_EXT", AL_FORMAT_IMA_ADPCM_STEREO16_EXT);
//    PyModule_AddIntConstant(m, "AL_FORMAT_WAVE_EXT", AL_FORMAT_WAVE_EXT);
//    PyModule_AddIntConstant(m, "AL_FORMAT_VORBIS_EXT", AL_FORMAT_VORBIS_EXT);
//    PyModule_AddIntConstant(m, "AL_GAIN_LINEAR_LOKI", AL_GAIN_LINEAR_LOKI);
    PyModule_AddIntConstant(m, "ALC_INVALID", ALC_INVALID);
    PyModule_AddIntConstant(m, "ALC_FREQUENCY", ALC_FREQUENCY);
    PyModule_AddIntConstant(m, "ALC_REFRESH", ALC_REFRESH);
    PyModule_AddIntConstant(m, "ALC_SYNC", ALC_SYNC);
    PyModule_AddIntConstant(m, "ALC_NO_ERROR", ALC_NO_ERROR);
    PyModule_AddIntConstant(m, "ALC_INVALID_DEVICE", ALC_INVALID_DEVICE);
    PyModule_AddIntConstant(m, "ALC_INVALID_CONTEXT", ALC_INVALID_CONTEXT);
    PyModule_AddIntConstant(m, "ALC_INVALID_ENUM", ALC_INVALID_ENUM);
    PyModule_AddIntConstant(m, "ALC_INVALID_VALUE", ALC_INVALID_VALUE);
   
}

#ifdef __cplusplus
}
#endif
