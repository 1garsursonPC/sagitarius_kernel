#include <stddef.h>
#include "limine_reqs.h"

// LIMINE_REQS specified that the given variable/function should be put in the .limine_reqs section
#define LIMINE_REQS __attribute__((section(".limine_reqs")))


static struct limine_framebuffer_request framebuffer_request =
{
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS void* framebuffer_req = &framebuffer_request;

static struct limine_bootloader_info_request bootloader_info_request =
{
    .id = LIMINE_BOOTLOADER_INFO_REQUEST,
    .revision = 0
    .response = NULL;
};
LIMINE_REQS void* bootloader_info_req = &bootloader_info_request;
