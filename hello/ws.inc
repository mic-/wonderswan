; ws.inc
; Useful constants and macros for WonderSwan development with NASM
; /Mic, 2016

;---------------------------
; RAM base addresses (segment 0)
;---------------------------
RAM_IVT_BASE				equ 0x0000
RAM_2BPP_TILES_BASE 		equ 0x2000
RAM_4BPP_TILES_BANK0_BASE 	equ 0x4000
RAM_4BPP_PALETTE_BASE		equ 0xfe00

;---------------------------
; Hardware register ports
;---------------------------
REG_DISP_CTRL 		equ 0x00
REG_BACK_COLOR		equ 0x01
REG_LINE_CUR		equ 0x02
REG_LINE_CMP		equ 0x03
REG_SPR_BASE		equ 0x04
REG_SPR_FIRST		equ 0x05
REG_SPR_COUNT		equ 0x06
REG_MAP_BASE 		equ 0x07
REG_SCR2_WIN_X0		equ 0x08
REG_SCR2_WIN_Y0		equ 0x09
REG_SCR2_WIN_X1		equ 0x0A
REG_SCR2_WIN_Y1		equ 0x0B
REG_SPR_WIN_X0		equ 0x0C
REG_SPR_WIN_Y0		equ 0x0D
REG_SPR_WIN_X1		equ 0x0E
REG_SPR_WIN_Y1		equ 0x0F
REG_SCR1_X			equ 0x10
REG_SCR1_Y			equ 0x11
REG_SCR2_X			equ 0x12
REG_SCR2_Y			equ 0x13
REG_LCD_CTRL		equ 0x14
REG_LCD_ICON		equ 0x15
REG_LCD_VTOTAL		equ 0x16
REG_LCD_VSYNC		equ 0x17
; ---
REG_PALMONO_POOL_0	equ 0x1C
REG_PALMONO_POOL_1	equ 0x1D
REG_PALMONO_POOL_2	equ 0x1E
REG_PALMONO_POOL_3	equ 0x1F
REG_PALMONO_0_L		equ 0x20
REG_PALMONO_0_H		equ 0x21
REG_PALMONO_1_L		equ 0x22
REG_PALMONO_1_H		equ 0x23
REG_PALMONO_2_L		equ 0x24
REG_PALMONO_2_H		equ 0x25
REG_PALMONO_3_L		equ 0x26
REG_PALMONO_3_H		equ 0x27
REG_PALMONO_4_L		equ 0x28
REG_PALMONO_4_H		equ 0x29
REG_PALMONO_5_L		equ 0x2A
REG_PALMONO_5_H		equ 0x2B
REG_PALMONO_6_L		equ 0x2C
REG_PALMONO_6_H		equ 0x2D
REG_PALMONO_7_L		equ 0x2E
REG_PALMONO_7_H		equ 0x2F
REG_PALMONO_8_L		equ 0x30
REG_PALMONO_8_H		equ 0x31
REG_PALMONO_9_L		equ 0x32
REG_PALMONO_9_H		equ 0x33
REG_PALMONO_A_L		equ 0x34
REG_PALMONO_A_H		equ 0x35
REG_PALMONO_B_L		equ 0x36
REG_PALMONO_B_H		equ 0x37
REG_PALMONO_C_L		equ 0x38
REG_PALMONO_C_H		equ 0x39
REG_PALMONO_D_L		equ 0x3A
REG_PALMONO_D_H		equ 0x3B
REG_PALMONO_E_L		equ 0x3C
REG_PALMONO_E_H		equ 0x3D
REG_PALMONO_F_L		equ 0x3E
REG_PALMONO_F_H		equ 0x3F
REG_DMA_SRC_LO		equ 0x40
REG_DMA_SRC_MID		equ 0x41
REG_DMA_SRC_HI		equ 0x42
; ---
REG_DMA_DST_LO		equ 0x44
REG_DMA_DST_HI		equ 0x45
REG_DMA_LEN_LO		equ 0x46
REG_DMA_LEN_HI		equ 0x47
REG_DMA_CTRL		equ 0x48
; ---
REG_SDMA_SRC_LO		equ 0x4A
REG_SDMA_SRC_MID	equ 0x4B
REG_SDMA_SRC_HI		equ 0x4C
; ---
REG_SDMA_LEN_LO		equ 0x4E
REG_SDMA_LEN_MID	equ 0x4F
REG_SDMA_LEN_HI		equ 0x50
; ---
REG_SDMA_CTRL		equ 0x52
; ---
REG_DISP_MODE		equ 0x60
REG_WSC_SYSTEM		equ 0x62
; ---
REG_HYPER_CTRL		equ 0x6A
; ---
REG_SND_CH1_PITCH_LO	equ 0x80
REG_SND_CH1_PITCH_HI	equ 0x81
REG_SND_CH2_PITCH_LO	equ 0x82
REG_SND_CH2_PITCH_HI	equ 0x83
REG_SND_CH3_PITCH_LO	equ 0x84
REG_SND_CH3_PITCH_HI	equ 0x85
REG_SND_CH4_PITCH_LO	equ 0x86
REG_SND_CH4_PITCH_HI	equ 0x87
REG_SND_CH1_VOL			equ 0x88
REG_SND_CH2_VOL			equ 0x89
REG_SND_CH3_VOL			equ 0x8A
REG_SND_CH4_VOL			equ 0x8B
REG_SND_SWEEP_VALUE		equ 0x8C
REG_SND_SWEEP_TIME		equ 0x8D
REG_SND_NOISE			equ 0x8E
REG_SND_WAVE_BASE		equ 0x8F
REG_SND_CTRL			equ 0x90
REG_SND_OUTPUT			equ 0x91
REG_SND_RANDOM_LO		equ 0x92
REG_SND_RANDOM_HI		equ 0x93
; ---
REG_HW_FLAGS			equ 0xA0
; ---
REG_TMR_CTRL 			equ 0xA2
; ---
REG_HTMR_FREQ			equ 0xA4
REG_HTMR_FREQ_LO 		equ 0xA4
REG_HTMR_FREQ_HI 		equ 0xA5
REG_VTMR_FREQ	 		equ 0xA6
REG_VTMR_FREQ_LO 		equ 0xA6
REG_VTMR_FREQ_HI 		equ 0xA7
REG_HTMR_CTR	 		equ 0xA8
REG_HTMR_CTR_LO 		equ 0xA8
REG_HTMR_CTR_HI 		equ 0xA9
REG_VTMR_CTR	 		equ 0xAA
REG_VTMR_CTR_LO 		equ 0xAA
REG_VTMR_CTR_HI 		equ 0xAB
; ---
REG_INT_BASE 			equ 0xB0
REG_SER_DATA 			equ 0xB1
REG_INT_ENABLE 			equ 0xB2
REG_SER_STATUS 			equ 0xB3
REG_INT_STATUS 			equ 0xB4
REG_KEYPAD 				equ 0xB5
REG_INT_ACK 			equ 0xB6
; ---
REG_BANK_ROM2 			equ 0xC0
REG_BANK_SRAM 			equ 0xC1
REG_BANK_ROM0 			equ 0xC2
REG_BANK_ROM1 			equ 0xC3
REG_EEP_DATA_LO 		equ 0xC4
REG_EEP_DATA_HI 		equ 0xC5
REG_EEP_ADDR_LO 		equ 0xC6
REG_EEP_ADDR_HI 		equ 0xC7
REG_EEP_STATUS 			equ 0xC8
REG_EEP_CMD 			equ 0xC8
; ---
REG_RTC_STATUS 			equ 0xCA
REG_RTC_CMD 			equ 0xCA
REG_RTC_DATA	 		equ 0xCB
REG_GPO_EN 				equ 0xCC
REG_GPO_DATA 			equ 0xCD
REG_WW_FLASH_CE 		equ 0xCE



;--------------------------
; Bitmasks for REG_DISP_CTRL
;--------------------------
DISP_CTRL_SCR2_WIN_EN	equ 0x20
DISP_CTRL_SCR2_WIN_INC	equ 0x00
DISP_CTRL_SCR2_WIN_EXCL	equ 0x10
DISP_CTRL_SPR_WIN_EN	equ 0x08
DISP_CTRL_SPR_EN		equ 0x04
DISP_CTRL_SCR2_EN 		equ 0x02
DISP_CTRL_SCR1_EN 		equ 0x01

;--------------------------
; Bitmasks for REG_LCD_CTRL
;--------------------------
LCD_CTRL_LCD_ON			equ 0x01
LCD_CTRL_LCD_OFF 		equ 0x00

;--------------------------
; Bitmasks for REG_SDMA_CTRL
;--------------------------
SDMA_CTRL_STOP 			equ 0x00
SDMA_CTRL_START 		equ 0x80
SDMA_CTRL_ADDR_INC 		equ 0x00
SDMA_CTRL_ADDR_DEC 		equ 0x40
SDMA_CTRL_DST_CH2_VOL    equ 0x00
SDMA_CTRL_DST_HYPERVOICE equ 0x10
SDMA_CTRL_LOOP 			equ 0x08
SDMA_CTRL_4000_HZ 		equ 0x00
SDMA_CTRL_6000_HZ 		equ 0x01
SDMA_CTRL_12000_HZ 		equ 0x02
SDMA_CTRL_24000_HZ 		equ 0x03

;---------------------------
; Bitmasks for REG_DISP_MODE
;---------------------------
DISP_MODE_2BPP		equ 0x00
DISP_MODE_4BPP		equ 0x80
DISP_MODE_MONO		equ 0x00
DISP_MODE_COL		equ 0x40
DISP_MODE_PLANAR	equ 0x00
DISP_MODE_PACKED	equ 0x20


;---------------------------
; Bitmasks for REG_WSC_SYSTEM
;---------------------------
WSC_SYSTEM_IS_WSC	equ 0x00
WSC_SYSTEM_IS_SC	equ 0x80
WSC_SYSTEM_PWR_DOWN equ 0x01

;---------------------------
; Bitmasks for REG_SND_CTRL
;---------------------------
SND_CTRL_CH4_WAVE	equ 0x00
SND_CTRL_CH4_NOISE	equ 0x80
SND_CTRL_CH3_SWEEP	equ 0x40
SND_CTRL_CH2_WAVE	equ 0x00
SND_CTRL_CH2_VOICE	equ 0x20
SND_CTRL_CH4_EN		equ 0x08
SND_CTRL_CH3_EN		equ 0x04
SND_CTRL_CH2_EN		equ 0x02
SND_CTRL_CH1_EN		equ 0x01

SND_CHN_VOL_L_SHIFT	equ 4
SND_CHN_VOL_R_SHIFT	equ 0

;---------------------------
; Bitmasks for REG_SND_NOISE
;---------------------------
SND_NOISE_EN		equ 0x10
SND_NOISE_RESET		equ 0x08
SND_NOISE_TAP_7_14	equ 0x00
SND_NOISE_TAP_7_10	equ 0x01
SND_NOISE_TAP_7_13	equ 0x02
SND_NOISE_TAP_4_7	equ 0x03
SND_NOISE_TAP_7_8	equ 0x04
SND_NOISE_TAP_6_7	equ 0x05
SND_NOISE_TAP_7_9	equ 0x06
SND_NOISE_TAP_7_11	equ 0x07

;---------------------------
; Bitmasks for REG_SND_VOICE_CTRL
;---------------------------
SND_VOICE_CTRL_L_HALF	equ 0x08
SND_VOICE_CTRL_L_FULL	equ 0x04
SND_VOICE_CTRL_R_HALF	equ 0x02
SND_VOICE_CTRL_R_FULL	equ 0x01

;---------------------------
; Bitmasks for REG_SND_OUTPUT
;---------------------------
SND_OUTPUT_HPH_CONN	equ 0x80
SND_OUTPUT_HPH_EN	equ 0x08
SND_OUTPUT_SPKR_EN	equ 0x01

HWINT_SER_TX		equ 0
HWINT_KEY			equ 1
HWINT_CART			equ 2
HWINT_SER_RX		equ 3
HWINT_LINE			equ 4
HWINT_VBLANK_TMR	equ 5
HWINT_VBLANK		equ 6
HWINT_HBLANK_TMR	equ 7

LCD_ICON_BIG_CIRCLE		equ 5
LCD_ICON_MEDIUM_CIRCLE	equ 4
LCD_ICON_SMALL_CIRCLE	equ 3
LCD_ICON_HORZ_ORIENT	equ 2
LCD_ICON_VERT_ORIENT	equ 1
LCD_ICON_SLEEP			equ 0

HYPER_CTRL_EN		equ 0x80

;-------------------------------
; REG_TMR_CTRL
;-------------------------------
TMR_CTRL_VBL_ONCE	equ 0x00
TMR_CTRL_VBL_REPT	equ 0x08
TMR_CTRL_VBL_EN		equ 0x04
TMR_CTRL_HBL_ONCE	equ 0x00
TMR_CTRL_HBL_REPT	equ 0x02
TMR_CTRL_HBL_EN		equ 0x01

KEYPAD_BTN_EN		equ 0x40
KEYPAD_X_EN			equ 0x20
KEYPAD_Y_EN			equ 0x10
KEYPAD_B_X4_Y4		equ 0x08
KEYPAD_A_X3_Y3		equ 0x04
KEYPAD_START_X2_Y2	equ 0x02
KEYPAD_X1_Y1		equ 0x01

WW_FLASH_CE_SRAM_EN		equ 0x00
WW_FLASH_CE_FLASH_EN	equ 0x01

;-------------------------------
; Bitmasks for map entries
;-------------------------------
MAP_VFLIP			equ 0x8000
MAP_HFLIP			equ 0x4000
MAP_TILE_BANK_0		equ 0x0000
MAP_TILE_BANK_1		equ 0x2000
MAP_PALETTE_SHIFT	equ 9


PIXEL_CLK		equ 3072000

SCREEN_VISIBLE_WIDTH_PX	equ 224
SCREEN_WIDTH_PX		equ 256
SCREEN_VISIBLE_WIDTH_CH	equ (SCREEN_VISIBLE_WIDTH_PX / 8)
MAP_WIDTH_CH		equ 32
HBLANK_PX		equ 32
SCREEN_VISIBLE_HEIGHT_PX equ 144
SCREEN_HEIGHT_PX	equ 159
SCREEN_VISIBLE_HEIGHT_CH equ (SCREEN_VISIBLE_HEIGHT_PX / 8)
MAP_HEIGHT_CH		equ 32
VBLANK_PX		equ 15

; Calculate a HBL timer value approximately corresponding
; to the given (immediate) number of milliseconds.
;
%define HTMR_INTERVAL_MS(millisec) ((millisec * (PIXEL_CLK / 256)) / 1000)

; Calculate a VBL timer value approximately corresponding
; to the given (immediate) number of seconds.
;
%define VTMR_INTERVAL_S(sec) ((sec * (PIXEL_CLK / 256)) / 159)


%define ADDR_TO_MAP_BASE(addr) (addr >> 11)


; Calculate a WSC palette value based on the given
; (immediate) red/green/blue values.
;
%define WSC_COLOR(r,g,b) (b | (g << 4) | (r << 8))

%define SND_VOLUME(left,right) ((left << SND_CHN_VOL_L_SHIFT) | (right << SND_CHN_VOL_R_SHIFT))

; Copy 'count' words from 'src_seg:src_offs' to '0:dest_offs'
; Clobbers ax, cx, si, di, ds, es, flags
;
%macro MEMCPYW 4	; dest_offs, src_seg, src_offs, count
    xor 	ax,ax	
	mov		es,ax	; segment 0 (RAM) is implied	
	mov		di,%1
	mov		ax,%2
	mov		ds,ax
	mov		si,%3	
	mov		cx,%4
	cld			
	rep		movsw	
%endmacro

; Set 'count' words starting at '0:dest_offs' to 'value'
; Clobbers ax, cx, di, es, flags
;
%macro MEMSETW 3	; dest_offs, value, count
	xor		ax,ax		
	mov		es,ax	; segment 0 (RAM) is implied	
	mov		di,%1
	mov		ax,%2
	mov		cx,%3
	cld			
	rep		stosw
%endmacro
