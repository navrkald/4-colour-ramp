#include "Error.h"

Error::Error(ErrCode errCode) : m_errCode(errCode)
{
	switch (errCode) {
	case ok:
		m_message = "";
		break;
	case paramCount:
		m_message = "Bad param count!";
		break;
	case paramFormat:
		m_message = "Bad parameters format!";
		break;
	case displaySize:
		m_message = "Width and Height of display has to be bigger than 2!";
		break;
	case displayConnect:
		m_message = "Could not connect to display!";
		break;
	default:
		m_message = "Unknown error!";
		break;
	}
}

bool Error::operator==(const Error & err) const
{
	return this->m_errCode == err.m_errCode;
}
