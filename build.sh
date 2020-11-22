#!/bin/bash
# Copyright 2020 SMS
# License(Apache-2.0)

cd "$( cd "$( dirname "$0"  )" && pwd  )"
if [ ! -d "./build" ]; then
	mkdir build
fi
cd build
cmake ..
cmake --build .
ctest

