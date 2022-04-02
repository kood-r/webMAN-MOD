	if(is_setup)
	{
		// /setup.ps3?          reset webman settings
		// /setup.ps3?<params>  save settings

		if(strchr(param, '&') == NULL)
		{
			reset_settings();
		}
		if(save_settings() == CELL_FS_SUCCEEDED)
		{
			sprintf(templn, "<br> %s", STR_SETTINGSUPD); _concat(&sbuffer, templn);
		}
		else
			_concat(&sbuffer, STR_ERROR);
	}
	else
	if(islike(param, "/setup.ps3"))
	{
		// /setup.ps3    setup form with webman settings

		setup_form(pbuffer, templn);
	}
	else