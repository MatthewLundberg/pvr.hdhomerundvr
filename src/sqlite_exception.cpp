//---------------------------------------------------------------------------
// Copyright (c) 2017 Michael G. Brehm
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "sqlite_exception.h"

#pragma warning(push, 4)				// Enable maximum compiler warnings

//-----------------------------------------------------------------------------
// sqlite_exception Constructor
//
// Arguments:
//
//	code		- SQLite error code

sqlite_exception::sqlite_exception(int code) : m_what(sqlite3_errstr(code))
{
}

//-----------------------------------------------------------------------------
// sqlite_exception Constructor
//
// Arguments:
//
//	code		- SQLite error code
//	message		- Additional message to associate with the exception

sqlite_exception::sqlite_exception(int code, char const* message) : m_what(sqlite3_errstr(code))
{
	// If a message was provided, append it to the generated error message
	if(message) m_what += std::string(": ") + message;
}

//-----------------------------------------------------------------------------
// sqlite_exception Copy Constructor

sqlite_exception::sqlite_exception(sqlite_exception const& rhs) : m_what(rhs.m_what)
{
}

//-----------------------------------------------------------------------------
// sqlite_exception char const* conversion operator

sqlite_exception::operator char const*() const
{
	return m_what.c_str();
}

//-----------------------------------------------------------------------------
// sqlite_exception::what
//
// Gets a pointer to the exception message text
//
// Arguments:
//
//	NONE

char const* sqlite_exception::what(void) const noexcept
{
	return m_what.c_str();
}

//---------------------------------------------------------------------------

#pragma warning(pop)
