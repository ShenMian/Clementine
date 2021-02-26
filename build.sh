#!/bin/bash
# Copyright 2020 SMS
# License(Apache-2.0)

# �л����ű�����Ŀ¼
cd "$( cd "$( dirname "$0"  )" && pwd  )"

# ���� build Ŀ¼, ���ڹ���
if [ ! -d "./build" ]; then
	mkdir build
fi
cd build

# ������ģ��, ������������
git submodule update --init --recursive

# ����
cmake ..
cmake --build .

# ���е�Ԫ����
ctest

