#include <windows.h>
#include <iostream>
using namespace std;
//mutex class

class Mutex
{
public:
	//the default constructor
	Mutex()
	{
		InitializeCriticalSection(&m_criticalSection);
	}

	//destructor
	~Mutex()
	{
		DeleteCriticalSection(&m_criticalSection);
	}

	//lock
	void lock()
	{
		EnterCriticalSection(&m_criticalSection);
	}

	//unlock
	void unlock()
	{
		LeaveCriticalSection(&m_criticalSection);
	}

private:
	CRITICAL_SECTION m_criticalSection;
};

//synchronization controller object
class Lock
{
public:
	//the default constructor
	Lock(Mutex &mutex) : m_mutex(mutex), m_locked(true)
	{
		mutex.lock();
	}

	//the destructor
	~Lock()
	{
		m_mutex.unlock();
	}

	//report the state of locking when used as a boolean
	operator bool() const
	{
		return m_locked;
	}

	//unlock
	void setUnlock()
	{
		m_locked = false;
	}

private:
	Mutex &m_mutex;
	bool m_locked;
};

#define synchronized(M)  for(Lock M##_lock = M; M##_lock; M##_lock.setUnlock())

//thread count
int thread_count = 0;

//mutex
Mutex mutex1;

//example thread
DWORD CALLBACK thread_proc(LPVOID params)
{
	for (int i = 0; i < 10; ++i)
	{
		synchronized(mutex1)
		{
			for (char c = 'A'; c <= 'Z'; ++c)
			{
				cout << c;
			}
			cout << endl;
		}
	}
	thread_count--;
	return 0;
}

//main
#if 0
int main()
{
	thread_count = 2;
	CreateThread(0, 0, thread_proc, 0, 0, 0);
	CreateThread(0, 0, thread_proc, 0, 0, 0);
	while (thread_count) Sleep(0);
	getchar();
	return 0;
}
#endif