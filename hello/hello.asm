CPU 186

; Hello World for the WonderSwan Color by Mic
; Assemble with NASM

SegmentE:	times 65536-$+SegmentE db 0
SegmentF:

%include "ws.inc"

Start:
	cli

	xor		ax,ax
	mov		bx,ax
	mov		cx,ax
	mov		dx,ax
	mov		es,ax
	mov		ds,ax
	mov		bp,ax
	mov		ss,ax
	mov		sp,0x8000

	out		REG_DISP_CTRL,ax		; disable all layers

	; This needs to happen before we copy the palette data, since
	; the upper 48kB of RAM only are available in Color mode.
	mov		al,DISP_MODE_4BPP | DISP_MODE_COL | DISP_MODE_PLANAR
	out		REG_DISP_MODE,al

	; Copy font data
	MEMCPYW RAM_4BPP_TILES_BANK0_BASE, 0xf000, font, fontSize/2
	
	; Copy palette
	MEMCPYW RAM_4BPP_PALETTE_BASE, 0xf000, palette, paletteSize/2

	; Clear the map
	MEMSETW 0x0000, 0, MAP_WIDTH_CH*MAP_HEIGHT_CH
	
	xor		ax,ax					; reset scrolling
	out		REG_SCR1_X,ax
	out		REG_SCR2_X,ax
		
	mov		al,DISP_CTRL_SCR1_EN	; enable SCR1
	out		REG_DISP_CTRL,al

	mov		al,LCD_ICON_SLEEP	
	out		REG_LCD_ICON,al

	in		al,REG_LCD_CTRL	
	or		al,LCD_CTRL_LCD_ON
	out		REG_LCD_CTRL,al

	xor 	ax, ax					; SCR maps at 0x0000
	out		REG_MAP_BASE,al
	
	; Display the text string on SCR1
	xor		ax,ax
	mov		es,ax		
	mov		di,(MAP_WIDTH_CH*8 + 4)*2
	
	mov		ax,0xf000	
	mov		ds,ax		
	mov		si,text
	xor		ax,ax
nextChar:	
	lodsb
	test	al,al
	jz		textLoopEnd
	sub		al,' '
	stosw
	jmp		nextChar
	
textLoopEnd:
	jmp 	$	; loop forever


text	db	'Hello, WS Flashmasta',0

font:	incbin	"c64font.bin"
fontSize equ $ - font
palette:		dw WSC_COLOR(4,3,10), WSC_COLOR(8,7,13)
paletteSize equ $ - palette

times 0xfff0-$+SegmentF nop

; Entry point
jmp word 0xf000:Start

times 0xfff6-$+SegmentF nop

Header:
	db	0xCD	; Developer ID
	db	0x00	; Wonderswan color
	db	0x01	; Cart number
	db	0x00	; ?
	db	0x00	; Cart Size (1 Mb)
	db	0x00	; SRAM size (0 k)
	db	0x04	; Horizontal game
	db	0x00	; ?
	dw	0x0000	; Checksum (?)