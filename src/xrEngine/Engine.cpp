// Engine.cpp: implementation of the CEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Engine.h"
#include "dedicated_server_only.h"

CEngine				Engine;
xrDispatchTable		PSGP;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEngine::CEngine()
{
	
}

CEngine::~CEngine()
{
	
}

PROTECT_API void CEngine::Initialize	(void)
{
	// Bind PSGP
	hPSGP		= LoadLibrary("xrCPU_Pipe.dll");
	R_ASSERT	(hPSGP);
	xrBinder*	bindCPU	= (xrBinder*)	GetProcAddress(hPSGP,"xrBind_PSGP");	R_ASSERT(bindCPU);
	bindCPU		(&PSGP, CPU::ID.feature & CPU::ID.os_support);

	// Other stuff
	Engine.Sheduler.Initialize			( );
}

void CEngine::Destroy	()
{
	Engine.Sheduler.Destroy				( );
#ifdef DEBUG_MEMORY_MANAGER
	extern void	dbg_dump_leaks_prepare	( );
	if (Memory.debug_mode)				dbg_dump_leaks_prepare	();
#endif // DEBUG_MEMORY_MANAGER
	Engine.External.Destroy				( );
	
	if (hPSGP)	
	{ 
		FreeLibrary	(hPSGP); 
		hPSGP		=0; 
		ZeroMemory	(&PSGP,sizeof(PSGP));
	}
}
