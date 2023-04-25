#include <stddef.h>
#include "limine_reqs.h"

// LIMINE_REQS specified that the given variable/function should be put in the .limine_reqs section
#define LIMINE_REQS __attribute__((section(".limine_reqs")))


// default behaviour in file scope (without static) is extern,
// i.e available to all translation unit
static struct limine_framebuffer_request framebuffer_request =
{
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* framebuffer_req = &framebuffer_request;

static struct limine_bootloader_info_request bootloader_info_request =
{
    .id = LIMINE_BOOTLOADER_INFO_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* bootloader_info_req = &bootloader_info_request;

static struct limine_memmap_request memmap_request =
{
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* memmap_req = &memmap_request;

static struct limine_rsdp_request rsdp_request =
{
    .id = LIMINE_RSDP_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* rsdp_req = &rsdp_request;

static struct limine_smbios_request smbios_request =
{
    .id = LIMINE_SMBIOS_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* smbios_req = &smbios_request;

static struct limine_efi_system_table_request efi_system_table_request =
{
    .id = LIMINE_EFI_SYSTEM_TABLE_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* efi_system_table_req = &efi_system_table_request;

static struct limine_boot_time_request boot_time_request =
{
    .id = LIMINE_BOOT_TIME_REQUEST,
    .revision = 0,
    .response = NULL
};
LIMINE_REQS static void* boot_time_req = &boot_time_request;


const struct limine_framebuffer_response* get_framebuffer_response()
{
    (void)framebuffer_req; // necessary so that the compiler doesn't complain the variable is unused
    return (const struct limine_framebuffer_response*) efi_system_table_request.response; // We cast to a constant pointer
}

const struct limine_bootloader_info_response* get_bootloader_info_response()
{
    (void)bootloader_info_req;
    return (const struct limine_bootloader_info_response*) bootloader_info_request.response;
}
const struct limine_memmap_response* get_memmap_response()
{
    (void)memmap_req;
    return (const struct limine_memmap_response*) memmap_request.response;
}

const struct limine_rsdp_response* get_rsdp_response()
{
    (void)rsdp_req;
    return (const struct limine_rsdp_response*) rsdp_request.response;
}

const struct limine_smbios_response* get_smbios_response()
{
    (void)smbios_req;
    return (const struct limine_smbios_response*) smbios_request.response;
}

const struct limine_efi_system_table_response* get_efi_system_table_response()
{
    (void)efi_system_table_req;
    return (const struct limine_efi_system_table_response*) efi_system_table_request.response;
}

const struct limine_boot_time_response* get_boot_time_response()
{
    (void)boot_time_req;
    return (const struct limine_boot_time_response*) boot_time_request.response;
}
