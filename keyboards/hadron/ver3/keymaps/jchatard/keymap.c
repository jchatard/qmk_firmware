#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BEPO 0
#define _FN 1
#define _MOVE 2
#define _LOWER 3
#define _RAISE 4
#define _MOUSECURSOR 8
#define _ADJUST 16

enum preonic_keycodes {
  BEPO = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  FN,
  MOVE,
  BACKLIT,
  RGBLED_TOGGLE,
  RGBLED_STEP_MODE,
  RGBLED_INCREASE_HUE,
  RGBLED_DECREASE_HUE,
  RGBLED_INCREASE_SAT,
  RGBLED_DECREASE_SAT,
  RGBLED_INCREASE_VAL,
  RGBLED_DECREASE_VAL,
  DEMOMACRO
};

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define CTL_TTAB    CTL_T(KC_TAB)               // Tap for Esc, hold for Ctrl
#define CTL_ENT     CTL_T(KC_ENT)               // Tap for Enter, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
// Requires KC_TRNS/_______ for the trigger key in the destination layer
#define LT_MC(kc)   LT(_MOUSECURSOR, kc)        // L-ayer T-ap M-ouse C-ursor
#define LT_RAI(kc)  LT(_RAISE, kc)              // L-ayer T-ap to Raise
#define TERM_KEY LCTL(LALT(BP_T))

//#define CUT LCTL()

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Bépo
 * .-----------------------------------------------------------------------------------------------------------.
 * | $      | "      | «      | »      | (      | )      | @      | +      | -      | /      | *      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------------------------.
 * | TAB    | b      | é      | p      | o      | è      | ^      | v      | d      | l      | j      | z      | w      | %      | Del    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------|
 * | MicMute| a      | u      | i      | e      | ,      | c      | t      | s      | r      | n      | m      | ç      | Next   | Vol +  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------|
 * | ê      | à      | y      | x      | .      | k      | '      | q      | g      | h      | f      | Term   | Play   | Up     | Vol -  |
 * |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------+--------+--------+--------|
 * | Fn     | Ctrl   | GUI    | Alt    | Shift  | Enter  | Space  | BckSp  | Alt    | Lower  | Raise  | Suppr  | Left   | Down   | Right  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

[_BEPO] = LAYOUT(
   BP_DLR,             BP_DQOT,    BP_LGIL,    BP_RGIL, BP_LPRN, BP_RPRN,       BP_AT,   BP_PLUS,  BP_MINUS, BP_SLASH, BP_ASTR, BP_EQL, \
   KC_TAB,             BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE,    BP_DCRC, BP_V,     BP_D,     BP_L,     BP_J,    BP_Z,     BP_W,                BP_PERC,             KC_DEL, \
   LGUI(BP_I),         BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,      BP_C,    BP_T,     BP_S,     BP_R,     BP_N,    BP_M,     BP_C_CEDILLA,        KC_MEDIA_NEXT_TRACK, KC__VOLUP , \
   LT(_MOVE, BP_ECRC),    BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,          BP_APOS, BP_Q,     BP_G,     BP_H,     BP_F,    TERM_KEY, KC_MEDIA_PLAY_PAUSE, KC_UP,               KC__VOLDOWN, \
   FN,                 KC_LCTL,    KC_LGUI,    KC_LALT, KC_LSFT, KC_ENT,        KC_SPC,  KC_BSPC,  KC_RALT,  LOWER,    RAISE,   KC_DEL,   KC_LEFT,             KC_DOWN,             KC_RGHT \
),

/* Fn layer
 * ,------+------+------+------+------+------------------------------------------------.
 * |      | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |      | F11  |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Undo | Cut  | Copy | Paste|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT(
  _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, \
  _______, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,    KC_P9, \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,    KC_P6, \
  C(BP_Z), C(BP_X), C(BP_C), C(BP_V), _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,    KC_P3, \
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PCMM,  KC_KP_EQUAL
),

/* Move layer
 * ,------+------+------+------+------+------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Home | PgDow| End  |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_END
),

/* Lower
 * ,------+------+------+------+------+------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_UNDS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,------+------+------+------+------+------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______,  _______, KC_SPC, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY   \
),

/* Adjust (Lower + Raise)
 * ,------+------+--------+------------+--------------+------------------------------------------------.
 * |  Esc |   1  |   2    |   3        |   4          |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+--------+------------+--------------+------+------+------+------+------+------+------+---------------------.
 * | Reset|RGB TG|RGB ST  |RGBH -      |RGBH +        |RGBS -|RGBS +|RGBV -|RGBV +|      |      |      |KC_NLCK|      |  Del |
 * |------+------+--------+------------+--------------+------+------+------+------+------+------+------+-------+------+------|
 * | Bépo |      |        |Aud on      |Audoff        |AGnorm|      |      |      |AGswap|Beop  |      |       |      |      |
 * |------+------+--------+------------+--------------+------+------+------+------+------+------+------+-------+------+------|
 * |      |Voice-|Voice+  |Mus on      |Musoff        |      |      |      |      |      |      |      | BL +  |BL ST |BL TG |
 * |------+------+--------+------------+--------------+------+------+------+------+------+------+------+-------+------+------|
 * |      |      | AG_TOGG|MAGIC_NO_GUI|MAGIC_UNNO_GUI|      |      |      |      |      |      |      |       |      |      |
 * `-------------------------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, KC_NLCK, _______, KC_DEL, \
  TO(_BEPO), _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, _______, _______, AG_SWAP, BEPO,  _______, _______,  _______,  _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF, _______, _______, _______,  _______, BL_DEC,  BL_INC,  BL_STEP, BL_TOGG, \
  _______, _______, AG_TOGG, MAGIC_NO_GUI, MAGIC_UNNO_GUI, _______, _______, _______, _______, _______, _______, CK_RST,  CK_DOWN, CK_UP,   CK_TOGG\
)



};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEPO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEPO);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case MOVE:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        layer_on(_MOVE);
      } else {
        layer_off(_MOVE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case DEMOMACRO:
      if (record->event.pressed) {
        SEND_STRING("hello world");
      }
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

void matrix_init_user(void) {
}


void matrix_scan_user(void) {
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
