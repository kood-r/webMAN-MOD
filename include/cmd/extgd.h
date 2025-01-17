#ifdef EXT_GDATA
	if(islike(param, "/extgd.ps3"))
	{
		// /extgd.ps3          toggle external GAME DATA
		// /extgd.ps3?         show status of external GAME DATA
		// /extgd.ps3?status   show status of external GAME DATA
		// /extgd.ps3?1        enable external GAME DATA
		// /extgd.ps3?enable   enable external GAME DATA
		// /extgd.ps3?0        disable external GAME DATA
		// /extgd.ps3?disable  disable external GAME DATA

		#ifdef COBRA_ONLY
		if(!cobra_version || syscalls_removed) goto exit_nocobra_error;
		#endif

		if( param[10] == 0)   extgd ^= 1; else	//toggle
		if( param[11] != 0 && param[11] != 's') //status
		{
			if( param[11] & 1) extgd = 1; else	//enable
			if(~param[11] & 1) extgd = 0;		//disable
		}

		_concat(&sbuffer, "External Game DATA: ");

		if((param[11] != 's') && set_gamedata_status(extgd, true))
			_concat(&sbuffer, STR_ERROR);
		else
			_concat(&sbuffer, extgd ? STR_ENABLED : STR_DISABLED);
	}
	else
#endif
