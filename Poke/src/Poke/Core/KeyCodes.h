#pragma once

namespace Poke
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define PK_KEY_SPACE           ::Poke::Key::Space
#define PK_KEY_APOSTROPHE      ::Poke::Key::Apostrophe    /* ' */
#define PK_KEY_COMMA           ::Poke::Key::Comma         /* , */
#define PK_KEY_MINUS           ::Poke::Key::Minus         /* - */
#define PK_KEY_PERIOD          ::Poke::Key::Period        /* . */
#define PK_KEY_SLASH           ::Poke::Key::Slash         /* / */
#define PK_KEY_0               ::Poke::Key::D0
#define PK_KEY_1               ::Poke::Key::D1
#define PK_KEY_2               ::Poke::Key::D2
#define PK_KEY_3               ::Poke::Key::D3
#define PK_KEY_4               ::Poke::Key::D4
#define PK_KEY_5               ::Poke::Key::D5
#define PK_KEY_6               ::Poke::Key::D6
#define PK_KEY_7               ::Poke::Key::D7
#define PK_KEY_8               ::Poke::Key::D8
#define PK_KEY_9               ::Poke::Key::D9
#define PK_KEY_SEMICOLON       ::Poke::Key::Semicolon     /* ; */
#define PK_KEY_EQUAL           ::Poke::Key::Equal         /* = */
#define PK_KEY_A               ::Poke::Key::A
#define PK_KEY_B               ::Poke::Key::B
#define PK_KEY_C               ::Poke::Key::C
#define PK_KEY_D               ::Poke::Key::D
#define PK_KEY_E               ::Poke::Key::E
#define PK_KEY_F               ::Poke::Key::F
#define PK_KEY_G               ::Poke::Key::G
#define PK_KEY_H               ::Poke::Key::H
#define PK_KEY_I               ::Poke::Key::I
#define PK_KEY_J               ::Poke::Key::J
#define PK_KEY_K               ::Poke::Key::K
#define PK_KEY_L               ::Poke::Key::L
#define PK_KEY_M               ::Poke::Key::M
#define PK_KEY_N               ::Poke::Key::N
#define PK_KEY_O               ::Poke::Key::O
#define PK_KEY_P               ::Poke::Key::P
#define PK_KEY_Q               ::Poke::Key::Q
#define PK_KEY_R               ::Poke::Key::R
#define PK_KEY_S               ::Poke::Key::S
#define PK_KEY_T               ::Poke::Key::T
#define PK_KEY_U               ::Poke::Key::U
#define PK_KEY_V               ::Poke::Key::V
#define PK_KEY_W               ::Poke::Key::W
#define PK_KEY_X               ::Poke::Key::X
#define PK_KEY_Y               ::Poke::Key::Y
#define PK_KEY_Z               ::Poke::Key::Z
#define PK_KEY_LEFT_BRACKET    ::Poke::Key::LeftBracket   /* [ */
#define PK_KEY_BACKSLASH       ::Poke::Key::Backslash     /* \ */
#define PK_KEY_RIGHT_BRACKET   ::Poke::Key::RightBracket  /* ] */
#define PK_KEY_GRAVE_ACCENT    ::Poke::Key::GraveAccent   /* ` */
#define PK_KEY_WORLD_1         ::Poke::Key::World1        /* non-US #1 */
#define PK_KEY_WORLD_2         ::Poke::Key::World2        /* non-US #2 */

/* Function keys */
#define PK_KEY_ESCAPE          ::Poke::Key::Escape
#define PK_KEY_ENTER           ::Poke::Key::Enter
#define PK_KEY_TAB             ::Poke::Key::Tab
#define PK_KEY_BACKSPACE       ::Poke::Key::Backspace
#define PK_KEY_INSERT          ::Poke::Key::Insert
#define PK_KEY_DELETE          ::Poke::Key::Delete
#define PK_KEY_RIGHT           ::Poke::Key::Right
#define PK_KEY_LEFT            ::Poke::Key::Left
#define PK_KEY_DOWN            ::Poke::Key::Down
#define PK_KEY_UP              ::Poke::Key::Up
#define PK_KEY_PAGE_UP         ::Poke::Key::PageUp
#define PK_KEY_PAGE_DOWN       ::Poke::Key::PageDown
#define PK_KEY_HOME            ::Poke::Key::Home
#define PK_KEY_END             ::Poke::Key::End
#define PK_KEY_CAPS_LOCK       ::Poke::Key::CapsLock
#define PK_KEY_SCROLL_LOCK     ::Poke::Key::ScrollLock
#define PK_KEY_NUM_LOCK        ::Poke::Key::NumLock
#define PK_KEY_PRINT_SCREEN    ::Poke::Key::PrintScreen
#define PK_KEY_PAUSE           ::Poke::Key::Pause
#define PK_KEY_F1              ::Poke::Key::F1
#define PK_KEY_F2              ::Poke::Key::F2
#define PK_KEY_F3              ::Poke::Key::F3
#define PK_KEY_F4              ::Poke::Key::F4
#define PK_KEY_F5              ::Poke::Key::F5
#define PK_KEY_F6              ::Poke::Key::F6
#define PK_KEY_F7              ::Poke::Key::F7
#define PK_KEY_F8              ::Poke::Key::F8
#define PK_KEY_F9              ::Poke::Key::F9
#define PK_KEY_F10             ::Poke::Key::F10
#define PK_KEY_F11             ::Poke::Key::F11
#define PK_KEY_F12             ::Poke::Key::F12
#define PK_KEY_F13             ::Poke::Key::F13
#define PK_KEY_F14             ::Poke::Key::F14
#define PK_KEY_F15             ::Poke::Key::F15
#define PK_KEY_F16             ::Poke::Key::F16
#define PK_KEY_F17             ::Poke::Key::F17
#define PK_KEY_F18             ::Poke::Key::F18
#define PK_KEY_F19             ::Poke::Key::F19
#define PK_KEY_F20             ::Poke::Key::F20
#define PK_KEY_F21             ::Poke::Key::F21
#define PK_KEY_F22             ::Poke::Key::F22
#define PK_KEY_F23             ::Poke::Key::F23
#define PK_KEY_F24             ::Poke::Key::F24
#define PK_KEY_F25             ::Poke::Key::F25

/* Keypad */
#define PK_KEY_KP_0            ::Poke::Key::KP0
#define PK_KEY_KP_1            ::Poke::Key::KP1
#define PK_KEY_KP_2            ::Poke::Key::KP2
#define PK_KEY_KP_3            ::Poke::Key::KP3
#define PK_KEY_KP_4            ::Poke::Key::KP4
#define PK_KEY_KP_5            ::Poke::Key::KP5
#define PK_KEY_KP_6            ::Poke::Key::KP6
#define PK_KEY_KP_7            ::Poke::Key::KP7
#define PK_KEY_KP_8            ::Poke::Key::KP8
#define PK_KEY_KP_9            ::Poke::Key::KP9
#define PK_KEY_KP_DECIMAL      ::Poke::Key::KPDecimal
#define PK_KEY_KP_DIVIDE       ::Poke::Key::KPDivide
#define PK_KEY_KP_MULTIPLY     ::Poke::Key::KPMultiply
#define PK_KEY_KP_SUBTRACT     ::Poke::Key::KPSubtract
#define PK_KEY_KP_ADD          ::Poke::Key::KPAdd
#define PK_KEY_KP_ENTER        ::Poke::Key::KPEnter
#define PK_KEY_KP_EQUAL        ::Poke::Key::KPEqual

#define PK_KEY_LEFT_SHIFT      ::Poke::Key::LeftShift
#define PK_KEY_LEFT_CONTROL    ::Poke::Key::LeftControl
#define PK_KEY_LEFT_ALT        ::Poke::Key::LeftAlt
#define PK_KEY_LEFT_SUPER      ::Poke::Key::LeftSuper
#define PK_KEY_RIGHT_SHIFT     ::Poke::Key::RightShift
#define PK_KEY_RIGHT_CONTROL   ::Poke::Key::RightControl
#define PK_KEY_RIGHT_ALT       ::Poke::Key::RightAlt
#define PK_KEY_RIGHT_SUPER     ::Poke::Key::RightSuper
#define PK_KEY_MENU            ::Poke::Key::Menu