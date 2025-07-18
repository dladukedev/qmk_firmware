#include QMK_KEYBOARD_H
#include <stdio.h>

// INSTALL COMMAND FOR CHOCOFI
// qmk flash -kb chocofi -km dladukedev -e CONVERT_TO=promicro_rp2040

// KEYMAP
enum layers {
    _BASE,
    _COLEMAK,
    _NUMBER,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        LGUI_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,            KC_U,    KC_I,    KC_O,    RGUI_T(KC_SCLN),
        KC_A,            KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,            KC_J,    KC_K,    KC_L,    KC_P,
        LALT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,            KC_M,    KC_COMM, KC_DOT,  RALT_T(KC_QUOT),
                                           KC_NO,   KC_RSFT,  MO(_NUMBER),        MO(_NAV),  RCTL_T(KC_SPC),  KC_NO
    ),

    [_COLEMAK] = LAYOUT_split_3x5_3(
        LGUI_T(KC_Q),    KC_W,    KC_F,    KC_P,    KC_B,                                 KC_J,     KC_L,    KC_U,    KC_O,    RGUI_T(KC_SCLN),
        KC_A,            KC_R,    KC_S,    KC_T,    KC_G,                                 KC_M,     KC_N,    KC_E,    KC_I,    KC_O,
        LALT_T(KC_Z),    KC_X,    KC_C,    KC_D,    KC_V,                                 KC_K,     KC_H,    KC_COMM, KC_DOT,  RALT_T(KC_QUOT),
                                           KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_NUMBER] = LAYOUT_split_3x5_3(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,                           KC_COMM,  KC_7,    KC_8,   KC_9,    KC_BSPC,
        KC_A,    KC_F5,    KC_F6,    KC_F7,    KC_F8,                           KC_BSPC,  KC_4,    KC_5,   KC_6,    KC_ENT,
        KC_Z,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                          KC_DOT,   KC_1,    KC_2,   KC_3,    KC_DEL,
                                     KC_NO,    KC_NO,   KC_TRNS,          KC_TRNS,  KC_0,     KC_NO
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_ESC,  MS_WHLL,    MS_UP,     MS_WHLR,   MS_WHLU,                             KC_PGUP,   KC_HOME,    TG(_COLEMAK),    KC_END,     KC_BSPC,
        KC_A,    MS_LEFT,    MS_DOWN,   MS_RGHT,   MS_WHLD,                             KC_LEFT,   KC_DOWN,    KC_UP,    KC_RGHT,    KC_ENT,
        KC_Z,    KC_MPRV,    KC_MPLY,   KC_MNXT,   MS_BTN3,                             KC_PGDN,   KC_VOLU,    KC_MUTE,  KC_VOLD,    KC_DEL,
                                        KC_NO,     MS_BTN1,   MS_BTN2,          KC_TRNS,  KC_NO,    KC_NO
    )
};

// COMBOS
uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _COLEMAK: return _BASE;
        case _NAV: return _NAV;
        default: return _BASE;
    }
    return layer;  // important if default is not in case.
}

enum combos {
  LT,
  GT,
  RPRN,
  LPRN,
  RCBR,
  LCBR,
  RBRC,
  LBRC,
  AT,
  EQL,
  QUES,
  BANG,
  ASTR,
  AMPR,
  PIPE,
  BSLS,
  SLSH,
  HASH,
  CRET,
  TAB,
  TILD,
  MINS,
  UNDS,
  PLUS,
  GRV
};

const uint16_t PROGMEM lt_combo[] =   {KC_G, KC_A, COMBO_END};
const uint16_t PROGMEM gt_combo[] =   {KC_H, KC_P, COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM lcbr_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_J, KC_P, COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM at_combo[] =   {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM eql_combo[] =  {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM ques_combo[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM bang_combo[] = {KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM astr_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM ampr_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_A, KC_P, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_L, KC_P, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_S, KC_F, KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cret_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM tab_combo[] =  {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_A, KC_S, KC_D,COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM grv_combo[] =  {KC_K, KC_L, KC_P, COMBO_END};

combo_t key_combos[] = {
  [LT] = COMBO(lt_combo, KC_LT),
  [GT] = COMBO(gt_combo, KC_GT),
  [RPRN] = COMBO(rprn_combo, KC_RPRN),
  [LPRN] = COMBO(lprn_combo, KC_LPRN),
  [RCBR] = COMBO(rcbr_combo, KC_RCBR),
  [LCBR] = COMBO(lcbr_combo, KC_LCBR),
  [RBRC] = COMBO(rbrc_combo, KC_RBRC),
  [LBRC] = COMBO(lbrc_combo, KC_LBRC),
  [AT] = COMBO(at_combo, KC_AT),
  [EQL] = COMBO(eql_combo, KC_EQL),
  [QUES] = COMBO(ques_combo, KC_QUES),
  [BANG] = COMBO(bang_combo, KC_EXLM),
  [ASTR] = COMBO(astr_combo, KC_ASTR),
  [AMPR] = COMBO(ampr_combo, KC_AMPR),
  [PIPE] = COMBO(pipe_combo, KC_PIPE),
  [BSLS] = COMBO(bsls_combo, KC_BSLS),
  [SLSH] = COMBO(slsh_combo, KC_SLSH),
  [HASH] = COMBO(hash_combo, KC_HASH),
  [CRET] = COMBO(cret_combo, KC_CIRC),
  [TAB] = COMBO(tab_combo, KC_TAB),
  [TILD] = COMBO(tild_combo, KC_TILD),
  [MINS] = COMBO(mins_combo, KC_MINS),
  [UNDS] = COMBO(unds_combo, KC_UNDS),
  [PLUS] = COMBO(plus_combo, KC_PLUS),
  [GRV] = COMBO(grv_combo, KC_GRV)
};

// KEY OVERRIDES
const key_override_t q_esc_key_override = ko_make_basic(MOD_MASK_CTRL, LGUI_T(KC_Q), KC_ESC);
const key_override_t h_bksp_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_H, KC_BSPC, 1<<_BASE);
const key_override_t j_entr_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_J, KC_ENT, 1<<_BASE);
const key_override_t m_bksp_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_M, KC_BSPC, 1<<_COLEMAK);
const key_override_t n_entr_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_N, KC_ENT, 1<<_COLEMAK);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&q_esc_key_override,
	&h_bksp_key_override,
	&j_entr_key_override,
	&m_bksp_key_override,
	&n_entr_key_override
};
