%module leveldbwrapperlib

%{
#include <string>
#include "leveldb_interface.h"
%}

%include <std_string.i>
%include "leveldb_interface.h"
