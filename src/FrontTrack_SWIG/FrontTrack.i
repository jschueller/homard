// File      : FrontTrack.i
// Created   : Fri Apr 28 17:36:20 2017
// Author    : Edward AGAPOV (eap)

%module FrontTrack

%{
#include "FrontTrack.hxx"
#include <Standard_Failure.hxx>
#include <Standard_ErrorHandler.hxx>
#include <stdexcept>

static PyObject* setOCCException(Standard_Failure& ex)
{
  std::string msg(ex.DynamicType()->Name());
  if ( ex.GetMessageString() && strlen( ex.GetMessageString() )) {
    msg += ": ";
    msg += ex.GetMessageString();
  }
  PyErr_SetString(PyExc_Exception, msg.c_str() );
  return NULL;
}

%}


%exception
{
  try {
    OCC_CATCH_SIGNALS;
    $action }
  catch (Standard_Failure& ex) {
    return setOCCException(ex);
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_Exception, ex.what() );
    return NULL;
  }
}

%include <std_string.i>
%include <std_vector.i>

%template(svec) std::vector<std::string>;

//%feature("autodoc", "1");
//%feature("docstring");

%include "FrontTrack.hxx"
