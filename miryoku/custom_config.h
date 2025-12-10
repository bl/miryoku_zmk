// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define MIRYOKU_NAV_VI

// Must be defined for local builds
#define MIRYOKU_KEYBOARD_CORNE

#if defined (MIRYOKU_KEYBOARD_CORNE)

// NOTE: Mapping hierarchy for context
// MIRYOKU_LAYERMAPPING_EXTRA
//     ↓ (if not defined)
// MIRYOKU_MAPPING
//     ↓ (if not defined)
// MIRYOKU_LAYOUTMAPPING_<KEYBOARD>
//     ↓ (if not defined)

// Base layer: Trying out standard 6 column keys for now
#define MIRYOKU_LAYERMAPPING_BASE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp TAB     K00  K01    K02  K03  K04       K05  K06  K07  K08  K09  &kp BSLH \
&kp LCTRL   K10  K11    K12  K13  K14       K15  K16  K17  K18  K19  &kp SQT \
&kp LSHFT   K20  K21    K22  K23  K24       K25  K26  K27  K28  K29  &kp RSHFT \
                        K32  K33  K34       K35  K36  K37

// All other layers: 6th column is transparent
// NOTE: All variations will be mapped to this when not explicitly defined
// (ie MIRYOKU_LAYERMAPPING_EXTRA -> MIRYOKU_LAYOUTMAPPING_CORNE)
#define MIRYOKU_LAYOUTMAPPING_CORNE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&trans      K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &trans \
&trans      K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &trans \
&trans      K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &trans \
                      K32  K33  K34    K35  K36  K37

#endif

// Layer 0: Swapping Backspace & space on ColelmakDH
#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp F,             &kp P,             &kp B,             &kp J,             &kp L,             &kp U,             &kp Y,             &kp SQT,           \
U_MT(LGUI, A),     U_MT(LALT, R),     U_MT(LCTRL, S),    U_MT(LSHFT, T),    &kp G,             &kp M,             U_MT(LSHFT, N),    U_MT(LCTRL, E),    U_MT(LALT, I),     U_MT(LGUI, O),     \
U_LT(U_BUTTON, Z), U_MT(RALT, X),     &kp C,             &kp D,             &kp V,             &kp K,             &kp H,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, BSPC),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, SPACE), U_LT(U_FUN, DEL),  U_NP,              U_NP

// Layer 1: Swapping Backspace & space on QWERTY base
// NOTE: Unclear why, but input must be pressed immediately after double tap, otherwise input not registered
#define MIRYOKU_LAYER_EXTRA \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
U_MT(LGUI, A),     U_MT(LALT, S),     U_MT(LCTRL, D),    U_MT(LSHFT, F),    &kp G,             &kp H,             U_MT(LSHFT, J),    U_MT(LCTRL, K),    U_MT(LALT, L),     U_MT(LGUI, SQT),   \
U_LT(U_BUTTON, Z), U_MT(RALT, X),     &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, BSPC),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, SPACE), U_LT(U_FUN, DEL),  U_NP,              U_NP

// Standard layers
// TODO: configure follow-up layer
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9