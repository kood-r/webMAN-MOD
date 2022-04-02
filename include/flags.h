#include "../flags.h"

#ifdef REX_ONLY
 #ifndef DEX_SUPPORT
 #define DEX_SUPPORT
 #endif
#endif

#ifdef PKG_LAUNCHER
 #define MOUNT_ROMS
 #define MOUNT_GAMEI
#endif

#ifdef COBRA_ONLY
 #ifndef LITE_EDITION
  #define NET_SUPPORT
  #define DEBUG_XREGISTRY
 #else
  #undef VISUALIZERS
  #undef NET_SUPPORT
 #endif
#else
 #undef WM_PROXY_SPRX
 #undef PS3MAPI
 #undef MOUNT_ROMS
 #undef MOUNT_GAMEI
 #undef PKG_LAUNCHER
 #undef PS3NET_SERVER
 #undef PHOTO_GUI
 #undef VISUALIZERS
 #undef NET_SUPPORT
 #undef LOAD_PRX
#endif

#ifndef PS3MAPI
 #undef PATCH_GAMEBOOT
#endif
#ifndef PATCH_GAMEBOOT
 #define set_mount_type(a)
 #define patch_gameboot(a)
 #define patch_gameboot_by_type(a)
#endif

#ifndef PS3_BROWSER
 #undef DEBUG_XREGISTRY
#endif

#ifdef LAST_FIRMWARE_ONLY
 #undef FIX_GAME
#endif

#ifndef WM_REQUEST
 #undef WM_CUSTOM_COMBO
 #undef PHOTO_GUI
#endif

#ifndef LAUNCHPAD
 #undef PHOTO_GUI
#endif
