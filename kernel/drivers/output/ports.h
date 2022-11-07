#ifndef PORTS_H
#define PORTS_H

unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

#define CMOS_READ(addr) ({ \
  outb(0x80|addr,0x70); \
  inb(0x71); \
})

#endif
