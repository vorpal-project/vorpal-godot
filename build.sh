#!/bin/bash

scons platform=x11 CCFLAGS="-I$1/include" LINKFLAGS="-L$1/lib" -j2

