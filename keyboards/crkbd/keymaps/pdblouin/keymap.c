

#include <stdint.h>
#include QMK_KEYBOARD_H

const key_override_t spacebar_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_ENT);
const key_override_t lbracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LBRC);
const key_override_t rbracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RBRC);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &spacebar_override,
    &lbracket_override,
    &rbracket_override
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            uint8_t layer = get_highest_layer(layer_state);

            switch (layer) {
                case 0:
                    rgb_matrix_set_color(index, RGB_GREEN);
                    break;
                case 1:
                    rgb_matrix_set_color(index, RGB_BLUE);
                    break;
                case 2:
                    rgb_matrix_set_color(index, RGB_ORANGE);
                    break;
                case 3:
                    rgb_matrix_set_color(index, RGB_RED);
                    break;
                case 4:
                    rgb_matrix_set_color(index, RGB_GOLD);
                    break;
            }


            uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});
            if (keycode == KC_TRNS) {
                keycode = keymap_key_to_keycode(0, (keypos_t){col,row});
            };

            switch (keycode) {

                case KC_NO:
                    rgb_matrix_set_color(index, RGB_BLACK);
                    break;
                case KC_0:
                    rgb_matrix_set_color(index, RGB_GREEN);
                    break;
                case KC_Z:
                    rgb_matrix_set_color(index, RGB_BLUE);
                    break;
                case KC_BSPC:
                case KC_DEL:
                    rgb_matrix_set_color(index, RGB_RED);
                    break;
            }
        }
    }
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_B,    KC_L,       KC_D,      KC_W,    KC_Z, RM_VALD,RM_VALU, KC_QUOT,  KC_F,       KC_O, KC_U,   KC_J,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX,KC_N,ALT_T(KC_R),CTL_T(KC_T),LT(3,KC_S),   KC_G, RM_OFF, RM_ON,   KC_Y,LT(4,KC_H),CTL_T(KC_A),KC_E,   KC_I,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_Q,    KC_X,       KC_M,      KC_C,    KC_V,                  KC_K,     KC_P,    KC_COMM, KC_DOT, KC_MINS,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(2),   KC_SPC,  MO(1),     KC_ENT, KC_LSFT,  MO(2)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_ESC, C(KC_L), C(KC_D), C(KC_W), C(KC_Z), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END, KC_PAUS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TAB, KC_LALT, KC_LCTL, KC_LSFT, KC_DEL, XXXXXXX,    XXXXXXX,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_LLCK, C(KC_X), KC_LGUI, C(KC_C), C(KC_V),                     XXXXXXX, KC_PSCR, KC_PGDN,  KC_PGUP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,     _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX, KC_F7,  KC_F8,  KC_F9, KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_MPLY, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, KC_F4,  KC_F5,  KC_F6, KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, KC_BRID, KC_LGUI, KC_BRIU, XXXXXXX,                      XXXXXXX, KC_F1,  KC_F2,  KC_F3, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, KC_ENT,    _______, _______, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, KC_7, KC_8, KC_9, KC_PLUS, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,    XXXXXXX,  KC_0,    KC_4, KC_5, KC_6, KC_EQL,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_1, KC_2, KC_3, KC_MINS, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, _______, XXXXXXX,     XXXXXXX, _______, KC_0
                                            //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_GRV,  XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CW_TOGG, KC_BSPC, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_AMPR, KC_BSLS, KC_SLSH, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, _______, XXXXXXX,     XXXXXXX,   _______, XXXXXXX
                                            //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, _______, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_LLCK, KC_BRID, KC_LGUI, KC_BRIU, XXXXXXX,                     XXXXXXX, KC_HOME, KC_END,  KC_HOME, KC_END,   XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______,     _______,   _______, _______
      //`--------------------------'  `--------------------------'
  ),

  [6] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, _______, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_LLCK, KC_BRID, KC_LGUI, KC_BRIU, XXXXXXX,                     XXXXXXX, KC_HOME, KC_END,  KC_HOME, KC_END,   XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______,     _______,   _______, _______
      //`--------------------------'  `--------------------------'
  )

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
