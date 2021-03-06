#include "linux-gamepad.hpp"
#ifdef LINUX

/**
 * This file is part of input-overlay
 * which is licenced under the MIT licence.
 * See LICENCE or https://mit-license.org
 * github.com/univrsal/input-overlay
 */

void LinuxGamepad::update(uint8_t id, uint16_t r_dz, uint16_t l_dz)
{
    m_state = &pad_states[id];
    m_pad_id = id;
	m_r_dead_zone = r_dz;
	m_l_dead_zone = l_dz;
}

#define SYNC_STATE(b)   ((*m_keys)[b].m_pressed = m_state->key_state(b))

void LinuxGamepad::check_keys()
{
	if (!m_state->valid())
            return;

    for (int i = 0; i < PAD_BUTTON_COUNT; i++)
        SYNC_STATE(i);
}
#endif