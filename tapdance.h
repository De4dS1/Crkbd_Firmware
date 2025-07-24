// Custom tap dance functions
//
// ES_ACUT -> caps_word_on()

void Accw(tap_dance_state_t *state, void *user_data){
    if (state->count == 1) tap_code(KC_QUOT);
    else if (state->count == 2) caps_word_on();
}

// Toggle gaming and latex layer
void SymGm(tap_dance_state_t *state, void *user_data){
    if(state->count == 2) layer_on(3);
}

void FnTex(tap_dance_state_t *state, void *user_data){
    if(state->count == 2) layer_on(4);
}

