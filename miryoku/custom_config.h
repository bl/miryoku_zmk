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

/// Define a double tap mapping to the Gaming layer
/// This requires we explicitly define each layer that defines Extra, Base, Tap tap-dance layers
/// Layers based on VI Nav, Mouse, Media layer variants

// Layer 4: VI Nav
#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_GAME,      U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           &kp INS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

// Layer 5: VI Mouse
#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_GAME,      U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_MS_L,            U_MS_D,            U_MS_U,            U_MS_R,            U_NU,              \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_WH_L,            U_WH_D,            U_WH_U,            U_WH_R,            U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP

// Layer 6: VI Media
#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_GAME,      U_RGB_EFF,         U_RGB_HUI,         U_RGB_SAI,         U_RGB_BRI,         U_RGB_TOG,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp C_PREV,        &kp C_VOL_DN,      &kp C_VOL_UP,      &kp C_NEXT,        U_EP_TOG,          \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       &u_out_tog,        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP

// Layer 10: Gaming (Standard QWERTY)
// Return to base via Right inner thumb tap-dance (del)
#define MIRYOKU_LAYER_GAME \
&kp Q,      &kp W,      &kp E,      &kp R,      &kp T,      &kp Y,      &kp U,      &kp I,          &kp O,      &kp P,      \
&kp A,      &kp S,      &kp D,      &kp F,      &kp G,      &kp H,      &kp J,      &kp K,          &kp L,      &kp SQT,    \
&kp Z,      &kp X,      &kp C,      &kp V,      &kp B,      &kp N,      &kp M,      &kp COMMA,      &kp DOT,    &kp SLASH,  \
U_NP,       U_NP,       &kp ESC,    &kp BSPC,   &kp TAB,    &kp RET,    &kp SPACE,  &u_to_U_BASE,    U_NP,       U_NP

// Explicit Layermapping for GAME layer
#define MIRYOKU_LAYERMAPPING_GAME MIRYOKU_LAYOUTMAPPING_CORNE

// Standard layers + Gaming
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
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(GAME,   "Game")

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
#define U_GAME   10