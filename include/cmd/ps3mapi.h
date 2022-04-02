#ifdef PS3MAPI
	if(islike(param, "/home.ps3mapi"))
	{
		ps3mapi_home(pbuffer, templn);
	}
	else
	if(islike(param, "/buzzer.ps3mapi") || islike(param, "/beep.ps3"))
	{
		ps3mapi_buzzer(pbuffer, templn, param);
	}
	else
	if(islike(param, "/led.ps3mapi"))
	{
		ps3mapi_led(pbuffer, templn, param);
	}
	else
	if(islike(param, "/notify.ps3mapi"))
	{
		ps3mapi_notify(pbuffer, templn, param);
	}
	else
	if(islike(param, "/syscall.ps3mapi"))
	{
		ps3mapi_syscall(pbuffer, templn, param);
	}
	else
	if(islike(param, "/syscall8.ps3mapi"))
	{
		ps3mapi_syscall8(pbuffer, templn, param);
	}
	else
	if(islike(param, "/patch.ps3"))
	{
		// example: /patch.ps3?addr=19A8000&stop=19D0000&find=fs_path&rep=2&offset=16&val=2E4A5047000000002E706E67000000002E676966000000002E626D70000000002E67696D000000002E504E4700

		memcpy(param + 2, ".ps3mapi?", 9); // make alias of /getmem.ps3mapi
		ps3mapi_getmem(pbuffer, templn, param);
	}
	else
	if(islike(param, "/getmem.ps3mapi"))
	{
		ps3mapi_getmem(pbuffer, templn, param);
	}
	else
	if(islike(param, "/setmem.ps3mapi"))
	{
		ps3mapi_setmem(pbuffer, templn, param);
	}
	else
	if(islike(param, "/setidps.ps3mapi"))
	{
		ps3mapi_setidps(pbuffer, templn, param);
	}
	else
	if(islike(param, "/vshplugin.ps3mapi"))
	{
		ps3mapi_vshplugin(pbuffer, templn, param);
	}
	else
	if(islike(param, "/gameplugin.ps3mapi"))
	{
		ps3mapi_gameplugin(pbuffer, templn, param);
	}
	else
#endif // #ifdef PS3MAPI
