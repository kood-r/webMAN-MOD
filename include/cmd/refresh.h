	if(islike(param, "/refresh.ps3") && refreshing_xml == 0)
	{
		// /refresh.ps3               refresh XML
		// /refresh.ps3?xmb           refresh XML & reload XMB
		// /refresh.ps3?cover=<mode>  refresh XML using cover type (icon0, mm, disc, online)
		// /refresh.ps3?ntfs          refresh NTFS volumes and show NTFS volumes
		// /refresh.ps3?prepntfs      refresh NTFS volumes & scan ntfs ISOs (clear cached .ntfs[PS*ISO] files in /dev_hdd0/tmp/wmtmp)
		// /refresh.ps3?prepntfs(0)   refresh NTFS volumes & scan ntfs ISOs (keep cached files)

		char *params = (char *)param + 12;

		#ifdef USE_NTFS
		if(islike(params, "?ntfs") || islike(params, "?prepntfs"))
		{
			check_ntfs_volumes();

			int ngames = 0; *header = NULL;
			if(islike(params, "?prepntfs"))
			{
				bool clear_ntfs = (strstr(params, "ntfs(0)") != NULL);
				ngames = prepNTFS(clear_ntfs);
				sprintf(header, " • <a href=\"%s\">%i</a> <a href=\"/index.ps3?ntfs\">%s</a>", WMTMP, ngames, STR_GAMES);
			}

			sprintf(param, "NTFS VOLUMES: %i%s", mountCount, header); is_busy = false;

			keep_alive = http_response(conn_s, header, param, CODE_HTTP_OK, param);
			goto exit_handleclient_www;
		}
		#endif

		refresh_xml(templn);

		if(strstr(params, "xmb")) reload_xmb();

	 #ifndef ENGLISH_ONLY
		sprintf(templn, "<br>");

		char *STR_XMLRF = (char *)templn + 4;

		sprintf(STR_XMLRF, "Game list refreshed (<a href=\"%s\">mygames.xml</a>).%s", MY_GAMES_XML, "<br>Click <a href=\"/restart.ps3\">here</a> to restart your PLAYSTATION®3 system.");

		language("STR_XMLRF", STR_XMLRF, STR_XMLRF);
		close_language();

		_concat(&sbuffer, templn);
	 #else
		sprintf(templn,  "<br>%s", STR_XMLRF); _concat(&sbuffer, templn);
	 #endif
		if(IS_ON_XMB && file_exists(RELOADXMB_EBOOT) && is_app_home_onxmb())
		{
			sprintf(templn, " [<a href=\"/reloadxmb.ps3\">%s XMB</a>]", STR_REFRESH);
			_concat(&sbuffer, templn);
		}
	}
	else
