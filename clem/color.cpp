// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台字体属性

#include "color.h"
#include "os.h"
#include <assert.h>

using std::map;
using std::string;
using std::to_string;

map<ushort, string> Color::index;

Color::Color(ushort attr)
{
	const auto it = index.find(attr);
	if(it == index.end())
		index.insert({attr, compile(attr)});
	pStr = &it->second;
}

const string& Color::operator()() const
{
	return *pStr;
}

void Color::on() const
{
	printf("%s", pStr->c_str());
}

void Color::off() const
{
	printf("%s", "\x1b[0m");
}

string Color::compile(ushort attr) const
{
	const auto fore = attr & 0x000f;
	const auto back = attr & 0x00f0;
	const auto mode = attr & 0x0f00;

	string str = "\x1b[";

	if(fore)
		str += '3' + to_string(fore - 1) + ';';

	if(back)
		str += '4' + to_string(back - 1) + ';';

	while(mode)
	{
		;
	}

	if(str.back() == ';')
		str.pop_back();

	str += 'm';

	return str;
}

