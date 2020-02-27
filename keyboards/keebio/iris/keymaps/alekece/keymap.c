#include QMK_KEYBOARD_H

enum layer_t {
  LT_QW = 0,
  LT_PROG = 1,
  LT_FN = 2,
  LT_CTRL = 3
};

enum custom_keycode_t {
  MC_ARROW = SAFE_RANGE,
  MC_LTE,
  MC_GTE,
  MC_NEQ,
  MC_MATCH,
  MC_HOME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LT_QW] = LAYOUT(
		LT(LT_CTRL,KC_GRV), KC_1, KC_2,   KC_3,  KC_4,   KC_5,                    KC_6,   KC_7, KC_8, KC_9,    KC_0,    KC_MINS,
		LALT_T(KC_TAB),     KC_Q, KC_W,   KC_E,  KC_R,   KC_T,                    KC_Y,   KC_U, KC_I, KC_O,    KC_P,    RALT_T(KC_EQL),
		LCTL_T(KC_ESC),     KC_A, KC_S,   KC_D,  KC_F,   KC_G,                    KC_H,   KC_J, KC_K, KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
		KC_LSFT,            KC_Z, KC_X,   KC_C,  KC_V,   KC_B, MO(LT_FN), KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		                          KC_CAPS, LT(LT_PROG,KC_SPC), MO(LT_FN), KC_ENT, KC_BSPC, KC_LGUI
	),
	[LT_PROG] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_LALT, MC_LTE,  MC_MATCH, KC_LCBR, KC_RCBR, KC_AMPR,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT,
		KC_LCTL, MC_GTE,  MC_ARROW, KC_LPRN, KC_RPRN, KC_PIPE,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
		KC_TRNS, MC_NEQ,  MC_HOME,  KC_LBRC, KC_RBRC, KC_EXLM, KC_NO, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS, KC_TRNS,
		                                         KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[LT_FN] = LAYOUT(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,
		KC_LALT, KC_PGUP, KC_HOME, KC_UP,   KC_END, KC_MPRV,                  KC_VOLD, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_RALT,
		KC_LCTL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MNXT,                 KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_RCTL,
		KC_TRNS, KC_NO,   KC_ACL2, KC_ACL1, KC_ACL0, KC_MPLY, KC_NO, KC_TRNS, KC_MUTE, KC_WH_D, KC_WH_U, KC_WH_R, KC_WH_L, KC_TRNS,
		                                        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_DEL, KC_TRNS
	),
	[LT_CTRL] = LAYOUT(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,   RGB_M_P,  RGB_M_B, KC_M_SN, KC_M_K,   KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               BL_DEC,  RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SAD, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               BL_INC,  RGB_MOD,  RGB_HUI, RGB_VAI, RGB_SAI, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_TOGG, RGB_TOG,  KC_NO,   KC_NO,   KC_NO,   RESET,
                                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_ARROW: SEND_STRING("->"); break;
            case MC_LTE: SEND_STRING("<="); break;
            case MC_GTE: SEND_STRING(">="); break;
            case MC_HOME: SEND_STRING("~/"); break;
            case MC_NEQ: SEND_STRING("!="); break;
            case MC_MATCH: SEND_STRING("=>"); break;
        }
    }

    return true;
}
