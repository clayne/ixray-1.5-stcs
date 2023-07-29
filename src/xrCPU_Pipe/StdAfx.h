#pragma once

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif // _WIN32_WINNT

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#pragma warning(disable:4995)
#include <xmmintrin.h>
#pragma warning(default:4995)

#define ENGINE_API
#define ECORE_API

#include "../xrCore/xrCore.h"
#include "xrCPU_Pipe.h"
