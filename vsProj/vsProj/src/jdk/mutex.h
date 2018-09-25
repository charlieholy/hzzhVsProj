#ifndef _JAVASOFT_WIN32_MUTEX_MD_H_
#define _JAVASOFT_WIN32_MUTEX_MD_H_

#include <windows.h>

typedef CRITICAL_SECTION mutex_t;

#define mutexInit(m)    InitializeCriticalSection(m)
#define mutexDestroy(m) DeleteCriticalSection(m)
#define mutexLock(m)    EnterCriticalSection(m)
#define mutexUnlock(m)  LeaveCriticalSection(m)

#endif /* !_JAVASOFT_WIN32_MUTEX_MD_H_ */
