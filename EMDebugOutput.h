/*******************************************************
* Creator: Martin Rudefelt
* Portability: non-native
*-------------------------------------------------------
* Contains some native code
*******************************************************/

// Note: This is one of the few (the only one?) files that does not include EMGlobals.h
// since EMGlobals.h includes this file instead

#ifndef __EM_DEBUG_OUTPUT
#define __EM_DEBUG_OUTPUT

#ifdef __EM_DEBUG_LIBRARY_IS_BUILDING
#define EM_DEBUG_LIBRARY_DECLSPECIFIER __declspec(dllexport)
#define EM_DEBUG_LIBRARY_EXPIMP_TEMPLATE
#else
#define EM_DEBUG_LIBRARY_DECLSPECIFIER __declspec(dllimport)
#define EM_DEBUG_LIBRARY_EXPIMP_TEMPLATE extern "C"
#endif

#include <sys/types.h>
#include <list>
#include <sstream>
#include <string>

using namespace std;

//EM_DEBUG_LIBRARY_EXPIMP_TEMPLATE class EM_DEBUG_LIBRARY_DECLSPECIFIER basic_string;

class EMDebugOutput 
{
public:
	EMDebugOutput();
	~EMDebugOutput();
	EMDebugOutput& operator<<(short p_vInput);
	EMDebugOutput& operator<<(const char* p_vpInput);
	EMDebugOutput& operator<<(unsigned short p_vInput);
	EMDebugOutput& operator<<(int p_vInput);
	EMDebugOutput& operator<<(unsigned int p_vInput);
	EMDebugOutput& operator<<(long p_vInput);
	EMDebugOutput& operator<<(unsigned long p_vInput);
	EMDebugOutput& operator<<(float p_vInput);
	EMDebugOutput& operator<<(double p_vInput);

//	EMDebugOutput& operator<<( p_vInput);

//	EMDebugOutput& operator<<(string p_oInput);

	EMDebugOutput& operator<<(EMDebugOutput& (*p_opFunction)(EMDebugOutput&));
	EMDebugOutput& EMFlush();

	list<string> m_oMailBoxList;

private:
//	void MethodThatIsNotUsed() {};
	void CreateDebugWindow();
	void OutputString(string p_oString);

private:
	string m_oOutputString;
	bool m_vWindowCreated;
};

// Global method that calls the corresponding class method in EMDebugOutput
EMDebugOutput& ef(EMDebugOutput& p_oStream);
//{
//	return p_oStream.EMFlush();
//}

// Global object used to output debug strings
extern "C" EMDebugOutput eo;

//Enters debugger and prints out a message (if supported by the platform)
inline void EMDebugger(const char* p_vpMessage)
{
//#ifdef EM_DEBUG
#ifdef PLATFORM_BEOS
	// TODO emerr non riesco a capire dove sta
	// mi sono limitato a commentarlo nel codice
	// in ogni caso basta diffare per mantenere le mie modifiche
	// ma comunque non credo che sia conveniente mantenere il sistema di
	// debug di Titan, discutiamone.

	//emerr << (char*) p_vpMessage << endl;
	debugger(p_vpMessage);
#endif
//#endif
}


void EMDebugger(const char* p_vpMessage);

#endif

