#!/bin/bash

scons platform=x11 tools=no target=release bits=64 CCFLAGS="-I$1/include" LINKFLAGS="-L$1/lib" -j2

