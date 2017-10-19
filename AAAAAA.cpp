// AAAAAA.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <windows.h>


void DbgPrintf(LPCSTR pszFormat, ...)
{
	va_list argList;
	va_start(argList, pszFormat);
	char pszBuffer[1024];
	vsnprintf(pszBuffer, _countof(pszBuffer), pszFormat, argList);
	va_end(argList);
	OutputDebugStringA(pszBuffer);
}

void DbgPrintf(LPCWSTR pszFormat, ...)
{
	va_list argList;
	va_start(argList, pszFormat);
	WCHAR pszBuffer[1024];
	vswprintf_s(pszBuffer, _countof(pszBuffer), pszFormat, argList);
	va_end(argList);
	OutputDebugStringW(pszBuffer);
}


/************************************************************************/
/* ������װ�����Բ鿴�ĸ��ļ���һ��                                        */
/************************************************************************/

#define  CONSTSTR_DEBUG     "[DEBUG] "
#define  CONSTSTR_INFO      "[INFO] "
#define  CONSTSTR_WARNING   "[WARNING] "
#define  CONSTSTR_ERROR     "[ERROR] "


#define  LOGLEVEL_CLOSE     0
#define  LOGLEVEL_DEBUG     1
#define  LOGLEVEL_INFO      2
#define  LOGLEVEL_WARN      3
#define  LOGLEVEL_ERROR     4

#define  LOGLEVEL			LOGLEVEL_CLOSE

/************************************************************************/
/* �е��Եȼ��ģ����޸�                                                   */
/************************************************************************/
#define DBGLOG(level, s, ...)\
	switch(level)\
	{\
		case LOGLEVEL_DEBUG:\
			DbgPrintf(CONSTSTR_DEBUG" VERSION:%s FILE:%s LINE:%d "s, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__);\
			break;\
		case LOGLEVEL_INFO:\
			DbgPrintf(CONSTSTR_INFO" VERSION:%s FILE:%s LINE:%d "s, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__);\
			break;\
		case LOGLEVEL_WARN:\
			DbgPrintf(CONSTSTR_WARNING" VERSION:%s FILE:%s LINE:%d "s, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__);\
			break;\
		case LOGLEVEL_ERROR:\
			DbgPrintf(CONSTSTR_ERROR" VERSION:%s FILE:%s LINE:%d "s, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__);\
			break;\
		default:\
			break;\
	}

/************************************************************************/
/* ��Ҫʹ�����                                                          */
/************************************************************************/
#define OUTDBGLOG

#ifdef OUTDBGLOG
#define DBGLOG(s, ...) DbgPrintf(CONSTSTR_DEBUG" VERSION:%s FILE:%s LINE:%d "s, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DBGLOG(s, ...) 
#endif




int main()
{
	DBGLOG("AAAAAAAAAAAAAAAAAAA");
	return 0;
}


