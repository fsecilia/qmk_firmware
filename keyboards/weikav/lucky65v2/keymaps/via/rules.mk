VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
USER_NAME := fsecilia

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    KEYBOARD_SHARED_EP := yes
endif
