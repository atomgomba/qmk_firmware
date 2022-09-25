/*
Copyright 2020 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// index of the Y key
#define Y_POS 21

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _WIN,
    _MAC,
    _FN1,
    _FN2,
};

enum combo_actions {
    QWE,
};

enum tapd_dance {
    HUU,
    HUI,
    /*
    TF1,
    TF2,
    TF3,
    TF4,
    TF5,
    TF6,
    TF7,
    TF8,
    TF9,
    TF10,
    TF11,
    TF12,
    */
    HOMND,
};

const uint16_t PROGMEM qwe_combo[] = {KC_Q, KC_W, KC_E, COMBO_END};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// clang-format off
 /*      Row:         0          1          2          3        4         5        6         7        8        9          10         11         12         13         14         15        */
      [_WIN] = {  {   KC_GESC,   KC_1,      KC_2,      KC_3,    KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     KC_DEL   },
                  {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,     KC_T,    KC_Y,     TD(HUU), TD(HUI), KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLASH, KC_NO,     TD(HOMND)   },
                  {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_PGUP   },
                  {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_PGDOWN },
                  {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,    KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     MO(_FN1),  MO(_FN2),  KC_RCTRL,  KC_LEFT,   KC_DOWN,   KC_RGHT   }
               },
      [_MAC] = {  {   KC_GESC,   KC_1,      KC_2,      KC_3,    KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     KC_DEL   },
                  {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLASH, KC_NO,     TD(HOMND)   },
                  {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_PGUP   },
                  {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_PGDOWN },
                  {   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_NO,   KC_NO,    KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     MO(_FN1),  MO(_FN2),  KC_RCTRL,  KC_LEFT,   KC_DOWN,   KC_RGHT   }
               },
      [_FN1] = {  {   KC_GRV,    KC_SLCK,   KC_PAUS,   KC_APP,  KC_NO,    RGB_VAD, RGB_VAI,  KC_NO,   KC_NO,   KC_NO,     KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,     KC_NO,     KC_PGUP    },
                  {   KC_NO,     RGB_M_P,   RGB_M_B,   RGB_M_R, RGB_M_SW, RGB_M_T, RGB_SPD,  RGB_SPI, KC_NO,   KC_NO,     KC_INS,    KC_DEL,    KC_END,    KC_NO,     KC_NO,     KC_PGDOWN  },
                  {   KC_NO,     KC_VOLD,   KC_VOLU,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     RGB_SAD,   RGB_SAI,   KC_NO,     KC_NO,     KC_NO,     KC_PGUP    },
                  {   KC_NO,     KC_NO,     KC_NO,     RGB_TOG, KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   RGB_RMOD,  RGB_MOD,   KC_NO,     KC_NO,     KC_NO,     KC_MSTP,   KC_PGDOWN  },
                  {   KC_GRV,    KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   RESET,    KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_NO,     KC_MPRV,   KC_MPLY,   KC_MNXT    }
               },
      [_FN2] = {  {   KC_GRV,    KC_F1,     KC_F2,     KC_F3,   KC_F4,    KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     KC_NO,     KC_PGUP    },
                  {   KC_NO,     RGB_M_P,   RGB_M_B,   RGB_M_R, RGB_M_SW, RGB_M_T, RGB_SPD,  RGB_SPI, KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_PGDOWN  },
                  {   KC_NO,     KC_VOLD,   KC_VOLU,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     RGB_SAD,   RGB_SAI,   KC_NO,     KC_NO,     KC_NO,     KC_PGUP    },
                  {   KC_NO,     KC_NO,     KC_NO,     RGB_TOG, KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   RGB_RMOD,  RGB_MOD,   KC_NO,     KC_NO,     KC_NO,     KC_MSTP,   KC_PGDOWN  },
                  {   KC_GRV,    KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   RESET,    KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_NO,     KC_MPRV,   KC_MPLY,   KC_MNXT    }
               },
};
// clang-format on

bool is_yz_swap_active = false;

uint8_t mod_state;

combo_t key_combos[] = {
    [QWE] = COMBO_ACTION(qwe_combo),
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [HUU] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_NUHS),  // Ű
    [HUI] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_NUBS),  // Í

    [HOMND] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),

    /*
    [TF1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TF2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TF3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TF4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TF5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TF6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TF7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TF8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TF9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TF10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TF11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [TF12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
    */
};

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:            // macos/windows togggle
            if (active) {  // macos
                layer_off(_WIN);
                layer_on(_MAC);
            } else {  // windows
                layer_on(_WIN);
                layer_off(_MAC);
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();

    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case QWE:
            if (pressed) {
                is_yz_swap_active = !is_yz_swap_active;
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case KC_Y:
            if (is_yz_swap_active) {
                if (record->event.pressed) {
                    register_code(KC_Z);
                } else {
                    unregister_code(KC_Z);
                }
                return false;
            }
            break;

        case KC_Z:
            if (is_yz_swap_active) {
                if (record->event.pressed) {
                    register_code(KC_Y);
                } else {
                    unregister_code(KC_Y);
                }
                return false;
            }
            break;
    }

    return true;
}

void rgb_matrix_indicators_user(void) {
    if (is_yz_swap_active) {
        rgb_matrix_set_color(Y_POS, RGB_WHITE);
    } else {
        rgb_matrix_set_color(Y_POS, RGB_BLACK);
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (host_keyboard_led_state().caps_lock) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_CORAL);
            }
        }
        if (layer_state_is(_FN2)) {
            if (0 < i && i < 13) {
                rgb_matrix_set_color(i, RGB_MAGENTA);
            }
        }
    }
}
