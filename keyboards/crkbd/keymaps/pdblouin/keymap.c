

#include <stdint.h>
#include QMK_KEYBOARD_H

const key_override_t spacebar_override  = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_ENT);
//const key_override_t close_paren_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &spacebar_override,
    //&close_paren_override
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
      KC_ESC,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,  RM_VALD, RM_VALU,     KC_QUOT,   KC_F,    KC_O,    KC_U, KC_J,  KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  KC_N,ALT_T(KC_R),CTL_T(KC_T),SFT_T(KC_S),KC_G,RM_OFF,RM_ON,     KC_Y,SFT_T(KC_H),CTL_T(KC_A),KC_E, KC_I,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                     KC_K,    KC_P,    KC_COMM,  KC_DOT, KC_MINS,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(3),   MO(1),  KC_SPC,     KC_BSPC, MO(2),  MO(4)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, C(KC_L), C(KC_D), XXXXXXX, C(KC_Z), QK_BOOT,    XXXXXXX,  XXXXXXX, KC_PSCR, KC_PGDN, KC_PGUP, KC_PAUS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_DEL, XXXXXXX,    RM_TOGG,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_LLCK, C(KC_X), XXXXXXX, C(KC_C), C(KC_V),                     XXXXXXX, KC_HOME, KC_END,  KC_HOME, KC_END,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,     _______,   TO(0), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_1,      KC_2,      KC_3,     KC_4, KC_5, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_6,SFT_T(KC_7),CTL_T(KC_8),   KC_9,  KC_0,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, QK_LLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,KC_LBRC, KC_RBRC, KC_BSLS,  KC_SLSH, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   TO(0),  KC_ENT,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, QK_BOOT,    XXXXXXX,  XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    RM_TOGG,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_LLCK, KC_BRID, KC_LGUI, KC_BRIU, XXXXXXX,                     XXXXXXX, KC_HOME, KC_END,  KC_HOME, KC_END,   XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,     XXXXXXX,   XXXXXXX, XXXXXXX
                                            //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3_ex2(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, QK_BOOT,    XXXXXXX,  XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    RM_TOGG,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
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
