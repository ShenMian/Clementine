@echo off
REM Copyright 2020 SMS
REM License(Apache-2.0)

REM �л����ű�����Ŀ¼
cd %~dp0

REM ���� build Ŀ¼, ���ڹ���
if not exist build mkdir build
cd build

REM ������ģ��, ������������
git submodule update --init --recursive

REM ����
cmake -DBUILD_SHARED_LIBS=ON ..
cmake --build .

REM ���е�Ԫ����
ctest
