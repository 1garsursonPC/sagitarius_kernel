#include <stdint.h>
#include <stddef.h>
#include <limine.h>

#include "limine_reqs.h"

// Halt and catch fire function.
static void hcf(void)
{
    asm ("cli");
    for (;;)
    {
        asm("hlt");
    }
}

void kernel_init(void)
{
    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL || framebuffer_request.response->framebuffer_count < 1)
    {
        hcf();
    }

//     // Fetch the first framebuffer.
//     struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];
//
//     // Note: we assume the framebuffer model is RGB with 32-bit pixels.
//     for (size_t i = 0; i < 100; i++)
//     {
//         uint32_t *fb_ptr = framebuffer->address;
//         fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
//     }

    // We're done, just hang...
    hcf();
}
