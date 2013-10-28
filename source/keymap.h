#ifndef KEYMAP_H
#define KEYMAP_H

#include <avr/pgmspace.h>

#define KFLA_EXTEND         0x01
#define KFLA_SPECIAL        0x02
#define KFLA_MAKEONLY       0x04
#define KFLA_MAKE_BREAK     0x08
#define KFLA_PROC_SHIFT     0x10

// Total 
#define NUM_KEY 144

#define KEY_FN          254
#define KEY_LED         253
#define KEY_BEYOND_FN   252
#define KEY_NOR         251         // beyond_fn에서 0 레이어로 점프, 0레이어의 같은 위치의 키값도 전송된다.
#define KEY_LED_UP      250     // increase led brightness 
#define KEY_LED_DOWN    249     // reduce led brightness
#define KEY_MAX         KEY_LED_DOWN     // 이 값보다 크거나 같으면 키인덱스를 처리 하지 않는다.

enum {  // for macro
    KEY_MAC1 = 201,
    KEY_MAC2,
    KEY_MAC3,
    KEY_MAC4,
    KEY_MAC5,
    KEY_MAC6,
    KEY_MAC7,
    KEY_MAC8,
    KEY_MAC9,
    KEY_MAC10,
    KEY_MAC11,
    KEY_MAC12   // 212
};

enum {
	KEY_NONE = 0,     // unused
    KEY_ErrorRollOver,
    KEY_POSTFail,
    KEY_ErrorUndefined,

    KEY_A,                // 0x04
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,

    KEY_K,
    KEY_L,
    KEY_M,                // 0x10
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,

    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_1,                //       1 and !
    KEY_2,                //       2 and @
    KEY_3,                // 0x20  3 and #
    KEY_4,                //       4 and $

    KEY_5,                //       5 and %
    KEY_6,                //       6 and ^
    KEY_7,                //       7 and &
    KEY_8,                //       8 and *
    KEY_9,                //       9 and (
    KEY_0,                // 0x27  0 and )
    KEY_ENTER,           // 0x28  enter
    KEY_ESC,           // 0x29
    KEY_BKSP,           // 0x2A  backspace
    KEY_TAB,              // 0x2B

    KEY_SPACE,         // 0x2C
    KEY_MINUS,            // 0x2D  - and _
    KEY_EQUAL,           // 0x2E  = and +
    KEY_LBR,         // 0x2F  [ and {
    KEY_RBR,         // 0x30  ] and }
    KEY_BKSLASH,        // 0x31  \ and |
    KEY_Europe1,             // 0x32  non-US # and ~
    KEY_COLON,        // 0x33  ; and :
    KEY_QUOTE,        // 0x34  ' and "
    KEY_HASH,            // 0x35  grave accent and tilde

    KEY_COMMA,            // 0x36  , and <
    KEY_DOT,              // 0x37  . and >
    KEY_SLASH,            // 0x38  / and ?
    KEY_CAPS,         // 0x39
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,

    KEY_F7,               // 0x40
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_PRNSCR,
    KEY_SCRLCK,
    KEY_PAUSE,            //       Break
    KEY_INSERT,

    KEY_HOME,
    KEY_PGUP,
    KEY_DEL,
    KEY_END,
    KEY_PGDN,
    KEY_RIGHT,
    KEY_LEFT,        // 0x50
    KEY_DOWN,
    KEY_UP,
    KEY_NUMLOCK,          //       Clear

    KEY_KP_SLASH,
    KEY_KP_AST,
    KEY_KP_MINUS,
    KEY_KP_PLUS,
    KEY_KP_ENTER,
    KEY_KP_1,              //       End
    KEY_KP_2,              //       Down Arrow
    KEY_KP_3,              //       Page Down
    KEY_KP_4,              //       Left Arrow
    KEY_KP_5,

    KEY_KP_6,              //       Right Arrow
    KEY_KP_7,              //       Home
    KEY_KP_8,              // 0x60  Up Arrow
    KEY_KP_9,              //       Page Up
    KEY_KP_0,              //       Insert
    KEY_KP_DOT,          //       Delete
    KEY_Europe2,             //       non-US \ and |
    KEY_APPS,		// 101 (0x65)

	 /* These are NOT standard USB HID - handled specially in decoding, 
     so they will be mapped to the modifier byte in the USB report */
	KEY_Modifiers,
	KEY_LCTRL,    // 0x01
	KEY_LSHIFT,   // 0x02
	KEY_LALT,     // 0x04
	KEY_LGUI,     // 0x08
	KEY_RCTRL,    // 0x10
	KEY_RSHIFT,   // 0x20
	KEY_RALT,     // 0x40
	KEY_RGUI,     // 0x80
	KEY_Modifiers_end, // 111 (0x6F)

	KEY_Multimedia,
	KEY_POWER,	KEY_SLEEP,	KEY_WAKE, KEY_EMAIL, KEY_WWW_SEARCH, KEY_WWW_HOME, KEY_WWW_BACK, KEY_WWW_FORWARD,	
	KEY_WWW_STOP, KEY_WWW_REFRESH, KEY_WWW_FAVORITE, KEY_NEXT_TRK, KEY_PREV_TRK, KEY_STOP, KEY_PLAY, KEY_MUTE, KEY_VOL_UP, KEY_VOL_DOWN,	
	KEY_MEDIA,	KEY_CALC,	KEY_MYCOM,	KEY_SCREENSAVE,	KEY_REC, KEY_REWIND, KEY_MINIMIZE, KEY_EJECT,
 	KEY_Multimedia_end,

    KEY_extend,
    KEY_HANJA,  KEY_HANGLE,
    KEY_extend_end

    // 144(0x90)
};

// for ps/2 interface
extern const uint8_t PROGMEM keycode_set2[NUM_KEY];

// usage page 01(Generic Desktop) : KEY_POWER,  KEY_SLEEP,  KEY_WAKE
// usage page 07(keyboard) : KEY_HANJA,   KEY_HANGLE
/* usage page 0C(Consumer Devices) : KEY_WWW_SEARCH, KEY_WWW_HOME, KEY_WWW_BACK, KEY_WWW_FORWARD, KEY_WWW_STOP, KEY_WWW_REFRESH, KEY_WWW_FAVORITE,KEY_EMAIL,  
                                    KEY_NEXT_TRK, KEY_PREV_TRK, KEY_STOP, KEY_PLAY, KEY_MUTE, KEY_VOL_UP, KEY_VOL_DOWN, KEY_MEDIA,  KEY_CALC,   KEY_MYCOM */
//
// windows OS 에서 미지원 키 : KEY_SCREENSAVE,    KEY_REC,    KEY_REWIND,     KEY_MINIMIZE,   KEY_EJECT

extern const uint16_t PROGMEM keycode_USB_multimedia[];
// KEY_APPS까지는 keycode 순서에 맞게 나열되어 있지만, 
// KEY_extend는 배열 순서와는 다른 키코드를 갖는 usage page 07(keyboard)의 키코드를 정의.
extern const uint16_t PROGMEM keycode_USB_extend[];

extern const uint8_t PROGMEM keycode_set2_special[];

extern const uint8_t PROGMEM keycode_set2_makeonly[];

extern const uint8_t PROGMEM keycode_set2_make_break[];

extern const uint8_t PROGMEM keycode_set2_extend[];

extern const uint8_t PROGMEM keycode_set2_proc_shift[] ;

extern const uint8_t PROGMEM keymap_code[3][17][8];

#endif