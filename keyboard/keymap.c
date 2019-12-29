#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTZ 0
#define _ACCENT 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTZ = SAFE_RANGE,
  ACCENT,
  LOWER,
  RAISE,
  ADJUST,
};

enum {
  TD_DOT_COMM = 0
  TD_SLSH_AST = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM)
  [TD_SLSH_AST] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_KP_ASTERISK)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 * ,-----------------------------------------.   .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Z  |   U  |   I  |   O  |   Ü  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |EsCAPs|   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   P  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Adjust|   Y  |   X  |   C  |   V  |   B  |   |Raise |   N  |   M  |  .,  |  Ö   |  -*  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |M_Shft| Ctrl | GUI  | Alt  |Lower |ACCENT|   |Space |lead?!| Left | Down |  Up  |Right |
 * `------------------------------------------   ------------------------------------------'
 */
[_QWERTZ] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_MINS, KC_BSPC, \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_ENT, \
  ADJUST,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAISE,   KC_N,    KC_M,    TD(TD_DOT_COMM),  KC_0,    TD_SLSH_AST, \
  OSM(MOD_LSFT),  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   ACCENT,  KC_SPC,  ________,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* ACCENT
 * ,-----------------------------------------.   .-----------------------------------------.
 * | Tab  |      |      |   É  |      |      |   |      |   Ú  |   Í  |   Ó  |   Ű  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |CAPEsc|   Á  |      |      |AltTab|      |   |      |   (  |  )   |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |   |      |   [  |  ]   |   Ő  |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower | hold |   |Space |   {  |  }   | Down |  Up  |Right |
 * `------------------------------------------   ------------------------------------------'
 * TODO: create macros for parentheses open-close-stepin for double tap on open
 */

[_ACCENT] = LAYOUT_ortho_4x12( \
  KC_TAB,  _______, _______, KC_SCLN, _______,      _______, _______, KC_RBRC,       KC_NUBS,       KC_EQL, KC_NUHS, KC_BSPC, \
  KC_ESC,  KC_QUOT, _______, _______, LALT(KC_TAB), _______, _______, KC_LPRN,       KC_RPRN,       _______, _______, _______, \
  KC_LSFT, _______, _______, _______, _______,      _______, _______, KC_LBRC,       KC_RBRC,       _______, _______, _______, \
  _______, _______, _______, _______, _______,      _______, _______, LSFT(KC_LBRC), LSFT(KC_RBRC), _______, _______, _______ \
),


/* Lower
 * ,------------------------------------------   ------------------------------------------.
 * |      |      |   1  |   2  |   3  |      |   |  F1  |  F2  |  F3  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |CAPEsc|      |   4  |   5  |   6  |      |   |  F4  |  F5  |  F6  |      |   \  |  |   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |      |   |  F7  |  F8  |  F9  |  Next|      |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |   0  |      |      |   |  F10 |  F11 |  F12 | Vol- | Vol+ | Play |
 * `------------------------------------------   ------------------------------------------'
 */

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_1,    KC_2,   KC_3,  _______,   KC_F1,  KC_F2,  KC_F3, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_ESC,  KC_F1,   KC_4,    KC_5,   KC_6,  _______,   KC_F4,  KC_F5,  KC_F6, KC_LCBR, KC_RCBR, KC_PIPE, \
  BL_STEP, KC_F7,   KC_7,    KC_8,   KC_9,  _______,   KC_F7,  KC_F8,  KC_F9, KC_MNXT, _______, _______, \
  _______, _______, _______, KC_GRV, _______, _______, KC_F10, KC_F11, KC_F12, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,------------------------------------------   .-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |   |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------   ------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------|   |-----------------------------------------.
 * |      | Reset|      |      |      |      |   |   gT | TabL | TabR |  gt  |      |  Del |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|   | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      | Pdwn | Pup  |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `------------------------------------------   ------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDN), _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, QWERTZ,  _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTZ:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTZ);
      }
      return false;
      break;
    case ACCENT:
      if (record->event.pressed) {
        layer_on(_ACCENT);
      } else {
        layer_off(_ACCENT);
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
