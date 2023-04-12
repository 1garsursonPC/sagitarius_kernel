#include <stdint.h>
#include <stddef.h>
#include <limine.h>

#define LIMINE_REQS __attribute__((section(".limine_reqs")))
// LIMINE_REQS specified that the given variable/function should be put in the .limine_reqs section

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static struct limine_framebuffer_request framebuffer_request =
{
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS void* framebuffer_req = &framebuffer_request;

// Halt and catch fire function.
static void hcf(void)
{
    asm ("cli");
    for (;;)
    {
        asm("hlt");
    }
}

// The following will be our kernel's entry point.
// If renaming kernel_main() to something else, make sure to change the
// linker script accordingly.
void kernel_main(void)
{
    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL || framebuffer_request.response->framebuffer_count < 1)
    {
        hcf();
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    for (size_t i = 0; i < 100; i++)
    {
        uint32_t *fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
    }

    // We're done, just hang...
    hcf();
}
