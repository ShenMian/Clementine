// Copyright 2021 SMS
// License(Apache-2.0)

#include "profiler.h"
#include "log.h"
#include <cassert>
#include <iomanip>

using namespace std::chrono;

Instrumentor& Instrumentor::getInstance()
{
	static Instrumentor instance;
	return instance;
}

void Instrumentor::begin(const char* filepath)
{
	assert(!session);
	CLEM_ENGINE_WARN("Being of a profile session: {}", filepath);

	session = true;
	file.open(filepath);
	assert(file.is_open());
	writeHead();
}

void Instrumentor::end()
{
	assert(session);
	CLEM_ENGINE_WARN("End of a profile session");

	writeFooter();
	file.close();
	session = false;
}

void Instrumentor::writeRecord(const ProfileRecord& r)
{
	assert(session);

	std::stringstream s;
	s << std::setprecision(3) << std::fixed;
	s << ",{";
	s << "\"cat\":\"function\",";
	s << "\"dur\":" << r.elapsed.count() << ',';
	s << "\"name\":\"" << r.name << "\",";
	s << "\"ph\":\"X\",";
	s << "\"pid\":0,";
	s << "\"tid\":" << r.threadId << ",";
	s << "\"ts\":" << r.start.count();
	s << "}";

	std::lock_guard<std::mutex> lock(mutex);
	file << s.str();
}

Instrumentor::~Instrumentor()
{
	if(session)
		end();
	std::lock_guard<std::mutex> lock(mutex);
}

void Instrumentor::writeHead()
{
	file << "{\"otherData\": {},\"traceEvents\":[{}";
}

void Instrumentor::writeFooter()
{
	file << "]}";
}

InstrumentationCounter::InstrumentationCounter(const char* name)
		: name(name), stopped(false)
{
	begin = std::chrono::steady_clock::now();
}

InstrumentationCounter::~InstrumentationCounter()
{
	if(!stopped)
		stop();
}

void InstrumentationCounter::stop()
{
	stopped      = true;
	auto end     = steady_clock::now();
	auto start   = begin.time_since_epoch();
	auto elapsed = time_point_cast<microseconds>(end).time_since_epoch() - time_point_cast<microseconds>(begin).time_since_epoch();
	Instrumentor::getInstance().writeRecord({name, start, elapsed, std::this_thread::get_id()});
}
