 /*
 * This is from the Android Project,
 * Repository: https://android.googlesource.com/platform/system/libufdt
 * File: utils/src/dt_table.h
 * Commit: 2626d8b9e4d8e8c6cc67ceb1dc4e05a47779785c
 * Copyright (C) 2017 The Android Open Source Project
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DT_TABLE_H
#define DT_TABLE_H
#include <sys/types.h>
#include <stdint.h>

#define DT_TABLE_MAGIC 0xd7b7ab1e
#define DT_TABLE_DEFAULT_PAGE_SIZE 2048
#define DT_TABLE_DEFAULT_VERSION 0

struct dt_table_header {
 uint32_t magic; /* DT_TABLE_MAGIC */
 uint32_t total_size; /* includes dt_table_header  all dt_table_entry
 * and all dtb/dtbo
 */
 uint32_t header_size; /* sizeof(dt_table_header) */

 uint32_t dt_entry_size; /* sizeof(dt_table_entry) */
 uint32_t dt_entry_count; /* number of dt_table_entry */
 uint32_t dt_entries_offset; /* offset to the first dt_table_entry
 * from head of dt_table_header.
 * The value will be equal to header_size if
 * no padding is appended
 */
 uint32_t page_size; /* flash page size we assume */
 uint32_t version; /* DTBO image version, the current version is 0.
 * The version will be incremented when the
 * dt_table_header struct is updated.
 */
};

struct dt_table_entry {
 uint32_t dt_size;
 uint32_t dt_offset; /* offset from head of dt_table_header */

 uint32_t id; /* optional, must be zero if unused */
 uint32_t rev; /* optional, must be zero if unused */
 uint32_t custom[4]; /* optional, must be zero if unused */
};


struct dt_table_entry_v1 {
  uint32_t dt_size;
  uint32_t dt_offset;  /* offset from head of dt_table_header */
  uint32_t id;         /* optional, must be zero if unused */
  uint32_t rev;        /* optional, must be zero if unused */
  uint32_t flags;      /* For version 1 of dt_table_header, the 4 least significant bits
                        of 'flags' will be used to indicate the compression
                        format of the DT entry as per the enum 'dt_compression_info' */
  uint32_t custom[3];  /* optional, must be zero if unused */
};


#define	UFDT_DEBUG
#define dtbo_error(fmt, args...)				dbgprintf("[ufdt]: "fmt, ##args)

#ifdef UFDT_DEBUG
#define dtbo_print(fmt, args...)				dbgprintf("[ufdt]: "fmt, ##args)
#define dtbo_debug(fmt, args...)				dbgprintf("[ufdt]: "fmt, ##args)
#else
#define dtbo_print(fmt, args...)				{}
#define dtbo_debug(fmt, args...)				{}
#endif

#define dt_table_header_get_header(dtboimg, field)\
	(fdt32_to_cpu(((const struct dt_table_header *)(dtboimg))->field))
#define dt_table_header_magic(dtboimg)			(dt_table_header_get_header(dtboimg, magic))
#define dt_table_header_total_size(dtboimg)			(dt_table_header_get_header(dtboimg, total_size))
#define dt_table_header_header_size(dtboimg)			(dt_table_header_get_header(dtboimg, header_size))
#define dt_table_header_dt_entry_size(dtboimg)			(dt_table_header_get_header(dtboimg, dt_entry_size))
#define dt_table_header_dt_entry_count(dtboimg)			(dt_table_header_get_header(dtboimg, dt_entry_count))
#define dt_table_header_dt_entries_offset(dtboimg)			(dt_table_header_get_header(dtboimg, dt_entries_offset))


#define dt_table_entry_get_header(dtboimg, field)\
	(fdt32_to_cpu(((const struct dt_table_entry *)(dtboimg))->field))
#define dt_table_entry_dt_size(dtboimg)			(dt_table_entry_get_header(dtboimg, dt_size))
#define dt_table_entry_dt_offset(dtboimg)			(dt_table_entry_get_header(dtboimg, dt_offset))
#define dt_table_entry_id(dtboimg)			        (dt_table_entry_get_header(dtboimg, id))
#define dt_table_entry_rev(dtboimg)			(dt_table_entry_get_header(dtboimg, rev))
#define dt_table_entry_custom(dtboimg, n)			(dt_table_entry_get_header(dtboimg, custom[n]))

#endif