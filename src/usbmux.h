/*
 * usbmux.h
 * Defines structures and variables pertaining to the usb multiplexing.
 *
 * Copyright (c) 2008 Zach C. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef USBMUX_H
#define USBMUX_H

#ifndef IPHONE_H
#include "iphone.h"
#endif

typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint8_t uint8;


typedef struct {
	uint32 type, length;
	uint16 sport, dport;
	uint32 scnt, ocnt;
	uint8 offset, tcp_flags;
	uint16 window, nullnull, length16;
} usbmux_tcp_header;

struct iphone_umux_client_int {
	usbmux_tcp_header *header;
	iphone_device_t phone;
	char *recv_buffer;
	int r_len;
};

usbmux_tcp_header *new_mux_packet(uint16 s_port, uint16 d_port);

typedef struct {
	uint32 type, length, major, minor, allnull;
} usbmux_version_header;

usbmux_version_header *version_header();


#endif
