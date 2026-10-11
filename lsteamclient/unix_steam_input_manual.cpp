#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

#include <unordered_map>

#ifdef __linux__
#include <X11/keysym.h>
#endif

#ifdef __linux__
static const uint32_t vk_to_xkeysym[0xFF] =
{
    0,            /* 0x0  Undefined */
    0,            /* VK_LBUTTON */
    0,            /* VK_RBUTTON */
    XK_Cancel,    /* VK_CANCEL */
    0,            /* VK_MBUTTON */
    0,            /* VK_XBUTTON1 */
    0,            /* VK_XBUTTON2 */
    0,            /* 0x07 Undefined */
    XK_BackSpace, /* VK_BACK */
    XK_Tab,       /* VK_TAB */
    0,            /* 0x0A-0x0B  Undefined */
    0,
    XK_Clear,  /* VK_CLEAR */
    XK_Return, /* VK_RETURN */
    0,         /* 0x0E-0x0F  Undefined */
    0,
    XK_Shift_L,     /* VK_SHIFT */
    XK_Control_L,   /* VK_CONTROL */
    XK_Alt_L,       /* VK_MENU */
    XK_Pause,       /* VK_PAUSE */
    XK_Caps_Lock,   /* VK_CAPITAL */
    0,              /* VK_KANA */
    0,              /* 0x16  Undefined */
    0,              /* VK_JUNJA */
    0,              /* VK_FINAL */
    0,              /* VK_HANJA */
    0,              /* 0x1A  Undefined */
    XK_Escape,      /* VK_ESCAPE */
    XK_Henkan_Mode, /* VK_CONVERT */
    XK_Muhenkan,    /* VK_NONCONVERT */
    0,              /* VK_ACCEPT */
    0,              /* VK_MODECHANGE */
    ' ',            /* VK_SPACE */
    XK_Prior,       /* VK_PRIOR */
    XK_Next,        /* VK_NEXT */
    XK_End,         /* VK_END */
    XK_Home,        /* VK_HOME */
    XK_Left,        /* VK_LEFT */
    XK_Up,          /* VK_UP */
    XK_Right,       /* VK_RIGHT */
    XK_Down,        /* VK_DOWN */
    XK_Select,      /* VK_SELECT */
    XK_Print,       /* VK_PRINT */
    XK_Execute,     /* VK_EXECUTE */
    XK_Print,       /* VK_SNAPSHOT */
    XK_Insert,      /* VK_INSERT */
    XK_Delete,      /* VK_DELETE */
    XK_Help,        /* VK_HELP */

    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    0,
    0,
    0,
    0,
    0,
    0,
    0, /* 0x3A-0x40  Undefined */
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',

    XK_Super_L,      /* VK_LWIN */
    XK_Super_R,      /* VK_RWIN */
    XK_Menu,         /* VK_APPS */
    0,               /* 0x5E  Unassigned */
    0,               /* VK_SLEEP */
    XK_KP_0,         /* VK_NUMPAD0 */
    XK_KP_1,         /* VK_NUMPAD1 */
    XK_KP_2,         /* VK_NUMPAD2 */
    XK_KP_3,         /* VK_NUMPAD3 */
    XK_KP_4,         /* VK_NUMPAD4 */
    XK_KP_5,         /* VK_NUMPAD5 */
    XK_KP_6,         /* VK_NUMPAD6 */
    XK_KP_7,         /* VK_NUMPAD7 */
    XK_KP_8,         /* VK_NUMPAD8 */
    XK_KP_9,         /* VK_NUMPAD9 */
    XK_KP_Multiply,  /* VK_MULTIPLY */
    XK_KP_Add,       /* VK_ADD */
    XK_KP_Separator, /* VK_SEPARATOR */
    XK_KP_Subtract,  /* VK_SUBTRACT */
    XK_KP_Decimal,   /* VK_DECIMAL */
    XK_KP_Divide,    /* VK_DIVIDE */
    XK_F1,           /* VK_F1 */
    XK_F2,           /* VK_F2 */
    XK_F3,           /* VK_F3 */
    XK_F4,           /* VK_F4 */
    XK_F5,           /* VK_F5 */
    XK_F6,           /* VK_F6 */
    XK_F7,           /* VK_F7 */
    XK_F8,           /* VK_F8 */
    XK_F9,           /* VK_F9 */
    XK_F10,          /* VK_F10 */
    XK_F11,          /* VK_F11 */
    XK_F12,          /* VK_F12 */
    XK_F13,          /* VK_F13 */
    XK_F14,          /* VK_F14 */
    XK_F15,          /* VK_F15 */
    XK_F16,          /* VK_F16 */
    XK_F17,          /* VK_F17 */
    XK_F18,          /* VK_F18 */
    XK_F19,          /* VK_F19 */
    XK_F20,          /* VK_F20 */
    XK_F21,          /* VK_F21 */
    XK_F22,          /* VK_F22 */
    XK_F23,          /* VK_F23 */
    XK_F24,          /* VK_F24 */
    0,               /* VK_NAVIGATION_VIEW */
    0,               /* VK_NAVIGATION_MENU */
    0,               /* VK_NAVIGATION_UP */
    0,               /* VK_NAVIGATION_DOWN */
    0,               /* VK_NAVIGATION_LEFT */
    0,               /* VK_NAVIGATION_RIGHT */
    0,               /* VK_NAVIGATION_ACCEPT */
    0,               /* VK_NAVIGATION_CANCEL */
    XK_Num_Lock,     /* VK_NUMLOCK */
    XK_Scroll_Lock,  /* VK_SCROLL */
    XK_KP_Equal,     /* VK_OEM_NEC_EQUAL */
    0,               /* VK_OEM_FJ_JISHO */
    0,               /* VK_OEM_FJ_MASSHOU */
    0,               /* VK_OEM_FJ_TOUROKU */
    0,               /* VK_OEM_FJ_LOYA */
    0,               /* VK_OEM_FJ_ROYA */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,            /* 0x97-0x9F  Unassigned */
    XK_Shift_L,   /* VK_LSHIFT */
    XK_Shift_R,   /* VK_RSHIFT */
    XK_Control_L, /* VK_LCONTROL */
    XK_Control_R, /* VK_RCONTROL */
    XK_Alt_L,     /* VK_LMENU */
    XK_Alt_R,     /* VK_RMENU */

    /* below are OEM, browser keys, etc */
};

uint32_t manual_convert_nNativeKeyCode( uint32_t win_vk )
{
    if(win_vk < sizeof(vk_to_xkeysym) / sizeof(*vk_to_xkeysym))
        return vk_to_xkeysym[win_vk];
    return 0;
}
#elif defined(__APPLE__)
/* Windows VK -> macOS virtual keycode (kVK_* from HIToolbox/Events.h), as used by CEF on macOS.
 * 0xffff marks keys without a macOS equivalent. */
static const uint16_t vk_to_mac_keycode[0x100] =
{
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0033, 0x0030, 0xffff, 0xffff, 0x0047, 0x0024, 0xffff, 0xffff,
    0x0038, 0x003b, 0x003a, 0xffff, 0x0039, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0x0035, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0031, 0x0074, 0x0079, 0x0077, 0x0073, 0x007b, 0x007e, 0x007c,
    0x007d, 0xffff, 0xffff, 0xffff, 0xffff, 0x0072, 0x0075, 0x0072,
    0x001d, 0x0012, 0x0013, 0x0014, 0x0015, 0x0017, 0x0016, 0x001a,
    0x001c, 0x0019, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x000b, 0x0008, 0x0002, 0x000e, 0x0003, 0x0005,
    0x0004, 0x0022, 0x0026, 0x0028, 0x0025, 0x002e, 0x002d, 0x001f,
    0x0023, 0x000c, 0x000f, 0x0001, 0x0011, 0x0020, 0x0009, 0x000d,
    0x0007, 0x0010, 0x0006, 0x0037, 0x0036, 0x006e, 0xffff, 0xffff,
    0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059,
    0x005b, 0x005c, 0x0043, 0x0045, 0xffff, 0x004e, 0x0041, 0x004b,
    0x007a, 0x0078, 0x0063, 0x0076, 0x0060, 0x0061, 0x0062, 0x0064,
    0x0065, 0x006d, 0x0067, 0x006f, 0x0069, 0x006b, 0x0071, 0x006a,
    0x0040, 0x004f, 0x0050, 0x005a, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0047, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0038, 0x003c, 0x003b, 0x003e, 0x003a, 0x003d, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x004a, 0x0049, 0x0048,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0x0029, 0x0018, 0x002b, 0x001b, 0x002f, 0x002c,
    0x0032, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0x0021, 0x002a, 0x001e, 0x0027, 0xffff,
    0xffff, 0xffff, 0x000a, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};

uint32_t manual_convert_nNativeKeyCode( uint32_t win_vk )
{
    if (win_vk < sizeof(vk_to_mac_keycode) / sizeof(*vk_to_mac_keycode) && vk_to_mac_keycode[win_vk] != 0xffff)
        return vk_to_mac_keycode[win_vk];
    return 0;
}
#else
#error You must implement VK<->Native keysym conversion for this platform.
#endif

typedef std::unordered_map< uint64_t, char * > glyph_cache;
static glyph_cache input_cache, input_cache_svg, input_cache_png, xbox_cache, controller_cache;

static const char *glyph_cache_lookup( glyph_cache &cache, const char *str, uint16_t origin,
                                       uint32_t flags, uint16_t size )
{
    uint64_t key = (uint64_t)flags << 32 | (uint64_t)size << 16 | origin;

    if (cache.find( key ) == cache.end())
    {
        char *dos_path = (char *)malloc( PATH_MAX );
        steamclient_unix_path_to_dos_path( 1, str, dos_path, PATH_MAX, 0 );
        cache[key] = dos_path;
    }

    return cache[key];
}

template< typename Iface, typename Params >
static NTSTATUS ISteamController_GetGlyphForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( controller_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamController_GetGlyphForXboxOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForXboxOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( xbox_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForXboxOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForXboxOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( xbox_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

static void (W_CDECL *w_EnableActionEventCallbacks_152)( SteamInputActionEvent_t * );
static void U_CDECL u_SteamInputActionEventCallbackPointer_152( SteamInputActionEvent_t *dat )
{
    if (w_EnableActionEventCallbacks_152) queue_cdecl_func_callback( (w_cdecl_func)w_EnableActionEventCallbacks_152, dat, sizeof(*dat) );
}

template< typename Iface, typename Params >
NTSTATUS ISteamInput_EnableActionEventCallbacks( Iface *iface, Params *params, bool wow64 )
{
    w_EnableActionEventCallbacks_152 = params->pCallback;
    iface->EnableActionEventCallbacks( params->pCallback ? &u_SteamInputActionEventCallbackPointer_152 : NULL );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphPNGForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphPNGForActionOrigin( params->eOrigin, params->eSize, params->unFlags ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache_png, params->_ret, params->eOrigin, params->unFlags, params->eSize );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphSVGForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphSVGForActionOrigin( params->eOrigin, params->unFlags ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache_svg, params->_ret, params->eOrigin, params->unFlags, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForActionOrigin_Legacy( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin_Legacy( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController005, GetGlyphForActionOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController006, GetGlyphForActionOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController007, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController007, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController008, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController008, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput001, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput001, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput002, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput002, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphForXboxOrigin );
