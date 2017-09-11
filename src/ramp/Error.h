#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <iostream>

using namespace std;


enum ErrCode {
	ok = 0,
	paramCount,
	paramFormat,
	displaySize,
	displayConnect,
};

class Error
{
public:
	Error(ErrCode);
	bool Failed() { return m_errCode != ok; };
	void PrintErrorMessage() { cerr << m_message << endl; }
	void PrintErrorMessageAndExit() { PrintErrorMessage(); exit(m_errCode); }
	int GetErrCode() { return m_errCode; }
	bool operator==(const Error& err) const;

private:

	ErrCode m_errCode;
	std::string m_message;
	static const Error errors[];
};

#endif // !ERROR_H
