#include <stdint.h>
#include <stddef.h>
#include <limine.h>

#include "limine_reqs.h"

// Halt and catch fire function.
static void hcf(void)
{
    asm("cli");
    for (;;)
    {
        asm("hlt");
    }
}

void kernel_init(void)
{
    const struct limine_bootloader_info_response* bootloader_info = get_bootloader_info_response();
    if (bootloader_info == NULL)
    {
        // TODO : print an error message on the serial port
        hcf();
    }

    const struct limine_framebuffer_response* framebuffer_info = get_framebuffer_response();
    if (framebuffer_info == NULL)
    {
        // TODO : print an error message on the serial port
        hcf();
    }

    // TODO : print bootloader info


    // We're done, just hang...
    hcf();
}
