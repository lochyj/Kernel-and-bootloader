#pragma once

#include "../drivers/ports.h"

#define CMOS_READ(addr) ({ \
  outb_p(0x80|addr,0x70); \
  inb_p(0x71); \
})

#define outb_p(value,port) \
__asm__ ("outb %%al,%%dx\n" \
                "\tjmp 1f\n" \
                "1:\tjmp 1f\n" \
                "1:"::"a" (value),"d" (port))

#define inb_p(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al\n" \
        "\tjmp 1f\n" \
        "1:\tjmp 1f\n" \
        "1:":"=a" (_v):"d" (port)); \
        _v; \
})
