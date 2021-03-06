#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   `  |                    |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   '  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Ctrl |                    |  Alt |   N  |   M  |   ,  |   .  |   /  |  Up  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      | Ctrl |  GUI |||||||| Lower| Shift| Space|||||||| Enter| BkSp | Raise||||||||  GUI | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,                         KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_QUOT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,                        KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   \
    _______, _______, KC_LCTL, KC_LGUI,          LOWER,   KC_LSFT,  KC_SPC,       KC_ENT, KC_BSPC, RAISE,            KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+--|
   * |  Tab |   !  |   @  |   #  |   $  |   %  |   ~  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  | EISU |                    | KANA |   6  |   7  |   8  |   9  |   0  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Ctrl |                    |  Alt |   /  |      |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |  Ctrl| Lower|||||||| Lower| Shift| Space|||||||| Enter| BkSp | Raise|||||||| Raise|  GUI | Home |  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_LANG2,                       KC_LANG1, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DQUO, \
    _______, _______, _______, _______, _______, _______, KC_LCTL,                        KC_RALT, KC_SLSH, _______, KC_LT,   KC_GT,   KC_QUES, KC_UP,   \
    _______, _______, KC_LCTL, LOWER,            KC_LGUI, KC_LSFT, KC_SPC,        KC_ENT, KC_BSPC, KC_RALT,          RAISE,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |      |   7  |   8  |   9  |   /  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |      |PageUp|  Up  |PageDn|      |   (  |                    |   )  |      |   4  |   5  |   6  |   *  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Home | Left | Down | Right|  End | EISU |                    | KANA |   H  |   1  |   2  |   3  |   -  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Ctrl |                    |  Alt |   N  |   0  |   .  | Enter|   +  |  Up  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |  Ctrl| Lower|||||||| Lower| Shift| Space|||||||| Enter| BkSp | Raise||||||||  GUI |  Left| Right| Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, _______, KC_7,    KC_8,    KC_9,    KC_SLSH, _______, \
    KC_TAB,  _______, KC_PGUP, KC_UP,   KC_PGDN, _______, KC_LPRN,                        KC_RPRN, _______, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_PIPE, \
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_LANG2,                       KC_LANG1,_______, KC_1,    KC_2,    KC_3,    KC_MINS, KC_DQT,  \
    _______, _______, _______, _______, _______, _______, KC_LCTL,                        KC_RALT, _______, KC_0,    KC_DOT,  KC_ENT,  KC_PLUS, KC_UP,   \
    _______, _______, KC_LCTL, LOWER,            KC_LGUI, KC_LSFT, KC_SPC,        KC_ENT, KC_BSPC, RAISE,            KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |                    |      |      |      |      |      |      |RGB ON|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |RClick|MousUp|LClick|MousWD|      |                    |      |      |      |MousWD|      | MODE-| MODE+|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |MousLf|MousDn|MousRg|MousWU|      |                    |      |      |MousWL|MousWU|MousWR|  VAL-|  VAL+|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Plain|Breath|Rainbw| Swirl| Snake|      |                    |      |Knight| XMas |Gradin| Test |  HUE-|  HUE+|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |  SAT-|  SAT+|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, RGB_TOG, \
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, _______,                       _______, _______, _______, KC_WH_D, _______, RGB_RMOD,RGB_MOD, \
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______,                       _______, _______, KC_WH_L, KC_WH_U, KC_WH_R, RGB_VAD, RGB_VAI, \
    _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,_______,                       _______, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_HUD, RGB_HUI, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          _______, _______, RGB_SAD, RGB_SAI  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
