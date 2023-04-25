#ifndef LIMINE_REQS_H
#define LIMINE_REQS_H

#include <limine.h>

const struct limine_framebuffer_response* get_framebuffer_response();

const struct limine_bootloader_info_response* get_bootloader_info_response();
const struct limine_memmap_response* get_memmap_response();

const struct limine_rsdp_response* get_rsdp_response();
const struct limine_smbios_response* get_smbios_response();
const struct limine_efi_system_table_response* get_efi_system_table_response();

const struct limine_boot_time_response* get_boot_time_response();

#endif
