#include QMK_KEYBOARD_H

// Custom keycode definitions
#define NOOP       KC_NO
#define MOD_A      LGUI_T(KC_A)
#define MOD_QUOT   LGUI_T(KC_QUOT)
#define ALT_S      LALT_T(KC_S)
#define ALT_L      LALT_T(KC_L)
#define CTL_D      RCTL_T(KC_D)
#define CTL_K      RCTL_T(KC_K)
#define SFT_F      LSFT_T(KC_F)
#define SFT_J      RSFT_T(KC_J)

#define ALGR_X     ALGR_T(KC_X)
#define ALGR_DOT   ALGR_T(KC_DOT)

// Layer-tap key definitions
#define U_SYM_SPC  LT(_U_SYM, KC_SPC)
#define U_NUM_BSPC LT(_U_NUM, KC_BSPC)
#define U_FUN_TAB  LT(_U_FUN, KC_TAB)
#define U_NAV_ENT  LT(_U_NAV, KC_ENT)

// Layer enumeration
enum layer {
    _U_BASE = 0,
    _U_NAV,
    _U_SYM,
    _U_NUM,
    _U_FUN,
};

// Combo definitions
const uint16_t PROGMEM GH[]    = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM BN[]    = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM ZSLSH[] = {KC_Z, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
    COMBO(GH,    KC_ESC),
    COMBO(BN,    KC_CAPS),
    COMBO(ZSLSH, KC_DEL),
};

// Keymap definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [_U_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        NOOP,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    MOD_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,                         KC_H,    SFT_J,   CTL_K,   ALT_L,   MOD_QUOT, NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_Z,    ALGR_X,  KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, ALGR_DOT, KC_SLSH, NOOP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      NOOP,    U_FUN_TAB, U_NAV_ENT,               U_SYM_SPC, U_NUM_BSPC, NOOP
                                    //`--------------------------'  `--------------------------'
    ),

    // Symbol Layer
    [_U_SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        NOOP,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI, NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                      NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      NOOP,    KC_RPRN, KC_UNDS,                   NOOP,    NOOP,    NOOP
                                    //`--------------------------'  `--------------------------'
    ),

    // Number Layer
    [_U_NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        NOOP,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                      NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                       NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI, NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                      NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      NOOP, KC_0,    KC_MINS,                      NOOP,    NOOP,    NOOP
                                    //`--------------------------'  `--------------------------'
    ),

    // Navigation Layer
    [_U_NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,                         NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, NOOP,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,                         KC_HOME, NOOP,    NOOP,    NOOP,    KC_END,  NOOP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      NOOP,    NOOP,    NOOP,                      NOOP,    NOOP,    NOOP
                                    //`--------------------------'  `--------------------------'
    ),

    // Function Layer
    [_U_FUN] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        NOOP,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   NOOP,                         NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   NOOP,                         NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI, NOOP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        NOOP,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   NOOP,                         NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      NOOP,    NOOP,    NOOP,                      NOOP,    NOOP,    NOOP
                                    //`--------------------------'  `--------------------------'
    )
};
