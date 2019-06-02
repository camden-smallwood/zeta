
/* ---------- headers */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <cseries/cseries.h>
#include <cache/cache_files.h>
#include <cache/cache_files_gen3.h>
#include <tag_files/tag_groups.h>

/* ---------- definitions */

TAG_ENUM(cache_partition_type_enum, NUMBER_OF_CACHE_PARTITIONS)
{
    { "resources", _cache_partition_type_resources },
    { "sound_resources", _cache_partition_type_sound_resources },
    { "global_tags", _cache_partition_type_global_tags },
    { "shared_tags", _cache_partition_type_shared_tags },
    { "base", _cache_partition_type_base },
    { "map_tags", _cache_partition_type_map_tags }
};

TAG_STRUCT(cache_partition_struct, sizeof(cache_partition))
{
    { _field_dword_integer, "base_address" },
    { _field_long_integer, "size" },
    { _field_terminator }
};

TAG_ENUM(cache_section_type_enum, NUMBER_OF_CACHE_SECTIONS)
{
    { "debug", _cache_section_type_debug },
    { "resource", _cache_section_type_resource },
    { "tag", _cache_section_type_tag },
    { "localization", _cache_section_type_localization }
};

TAG_STRUCT(cache_section_struct, sizeof(cache_section))
{
    { _field_dword_integer, "virtual_address" },
    { _field_long_integer, "size" },
    { _field_terminator }
};

TAG_ARRAY(_field_struct, cache_interop_sections_array, NUMBER_OF_CACHE_SECTIONS, &cache_section_struct);

TAG_STRUCT(cache_interop_struct, sizeof(cache_interop))
{
    { _field_dword_integer, "resource_base_address" },
    { _field_long_integer, "debug_section_size" },
    { _field_dword_integer, "runtime_base_address" },
    { _field_dword_integer, "unknown_base_address" },
    { _field_array, "sections", &cache_interop_sections_array },
    { _field_terminator }
};

TAG_ARRAY(_field_struct, cache_header_gen3_partitions_array, NUMBER_OF_CACHE_PARTITIONS, &cache_partition_struct);
TAG_ARRAY(_field_long_integer, cache_header_gen3_sha1_array, 5);
TAG_ARRAY(_field_long_integer, cache_header_gen3_rsa_array, 64);
TAG_ARRAY(_field_long_integer, cache_header_gen3_guid_array, 4);

long const cache_header_gen3_elements1_length = 0x2300;
long const cache_header_gen3_elements2_length = 0x708;
long const cache_header_gen3_elements3_length = 0x12C;

extern enum_definition cache_version_enum;
extern enum_definition cache_type_enum;
extern enum_definition cache_shared_type_enum;

TAG_STRUCT(cache_header_gen3_struct, sizeof(cache_header_gen3))
{
    { _field_tag, "header_signature" },
    { _field_long_enum, "version", &cache_version_enum },
    { _field_dword_integer, "file_length" },
    { _field_dword_integer, "compressed_file_length" },
    { _field_dword_integer, "offset_to_index" },
    { _field_dword_integer, "index_stream_size" },
    { _field_dword_integer, "tag_buffer_size" },
    { _field_long_string, "source_file" },
    { _field_string, "build" },
    { _field_short_enum, "type", &cache_type_enum },
    { _field_short_enum, "shared_type", &cache_shared_type_enum },
    { _field_char_integer, "" },
    { _field_byte_integer, "tracked_build" },
    { _field_char_integer, "" },
    { _field_char_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_dword_integer, "string_id_count" },
    { _field_dword_integer, "string_id_buffer_size" },
    { _field_dword_integer, "string_id_indices_offset" },
    { _field_dword_integer, "string_id_buffer_offset" },
    { _field_long_integer, "external_dependencies" },
    { _field_long_integer, "high_date_time" },
    { _field_long_integer, "low_date_time" },
    { _field_long_integer, "ui_high_date_time" },
    { _field_long_integer, "ui_low_date_time" },
    { _field_long_integer, "shared_high_date_time" },
    { _field_long_integer, "shared_low_date_time" },
    { _field_long_integer, "campaign_high_date_time" },
    { _field_long_integer, "campaign_low_date_time" },
    { _field_string, "name" },
    { _field_long_integer, "" },
    { _field_long_string, "scenario_name" },
    { _field_dword_integer, "minor_version" },
    { _field_dword_integer, "tag_names_count" },
    { _field_dword_integer, "tag_names_buffer_offset" },
    { _field_dword_integer, "tag_names_buffer_size" },
    { _field_dword_integer, "tag_names_indices_offset" },
    { _field_dword_integer, "checksum" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_dword_integer, "base_address" },
    { _field_long_integer, "xdk_version" },
    { _field_array, "partitions", &cache_header_gen3_partitions_array },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_long_integer, "" },
    { _field_array, "sha1_a", &cache_header_gen3_sha1_array },
    { _field_array, "sha1_b", &cache_header_gen3_sha1_array },
    { _field_array, "sha1_c", &cache_header_gen3_sha1_array },
    { _field_array, "rsa", &cache_header_gen3_rsa_array },
    { _field_struct, "interop", &cache_interop_struct },
    { _field_array, "guid", &cache_header_gen3_guid_array },
    { _field_short_integer, "" },
    { _field_short_integer, "" },
    { _field_long_integer, "" },
    { _field_array, "compression_guid", &cache_header_gen3_guid_array },
    { _field_padding, "elements1", &cache_header_gen3_elements1_length },
    { _field_padding, "elements2", &cache_header_gen3_elements2_length },
    { _field_padding, "elements3", &cache_header_gen3_elements3_length },
    { _field_long_integer, "" },
    { _field_tag, "footer_signature" },
    { _field_terminator }
};

TAG_STRUCT(cache_tag_header_gen3_struct, sizeof(cache_tag_header_gen3))
{
    { _field_dword_integer, "group_tags_offset" },
    { _field_long_integer, "group_tags_count" },
    { _field_long_integer, "count" },
    { _field_dword_integer, "tags_offset" },
    { _field_long_integer, "dependent_tags_count" },
    { _field_dword_integer, "dependent_tags_offset" },
    { _field_long_integer, "dependent_tags_count2" },
    { _field_dword_integer, "dependent_tags_offset2" },
    { _field_dword_integer, "checksum" },
    { _field_tag, "signature" },
    { _field_terminator }
};

TAG_STRUCT(cache_tag_instance_gen3_struct, sizeof(cache_tag_instance_gen3))
{
    { _field_word_integer, "group_index" },
    { _field_word_integer, "identifier" },
    { _field_dword_integer, "offset" },
    { _field_terminator }
};

/* ---------- globals */

cache_file_definition cache_file_gen3_definition =
{
    cache_file_gen3_load,
    cache_file_gen3_dispose,
    cache_file_gen3_get_base_address,
    cache_file_gen3_get_tag_instance
};

cache_header_definition cache_header_gen3_definition =
{
    cache_header_gen3_get_file_length,
    cache_header_gen3_get_tag_header_offset,
    cache_header_gen3_get_tag_buffer_size,
    cache_header_gen3_get_name,
    cache_header_gen3_get_build,
    cache_header_gen3_get_type,
    cache_header_gen3_get_shared_type
};

cache_tag_header_definition cache_tag_header_gen3_definition =
{
    cache_tag_header_gen3_get_tag_count,
    cache_tag_header_gen3_get_tags_offset
};

cache_tag_instance_definition cache_tag_instance_gen3_definition =
{
    cache_tag_instance_gen3_get_group_tag,
    cache_tag_instance_gen3_get_index,
    cache_tag_instance_gen3_get_name_offset,
    cache_tag_instance_gen3_get_offset
};

/* ---------- code */

cache_file *cache_file_gen3_load(
    char const *path)
{
    FILE *stream = fopen(path, "rb");
    
    fseek(stream, 0, SEEK_END);
    dword size = ftell(stream);

    cache_file *result = malloc(size);
    
    fseek(stream, 0, SEEK_SET);
    fread(result, size, 1, stream);

    cache_header_gen3 *header = result;
    struct_byteswap(&cache_header_gen3_struct, _cache_version_gen3, header);

    return result;
}

void cache_file_gen3_dispose(
    cache_file *file)
{
    free(file);
}

dword cache_file_gen3_get_base_address()
{
    return 0xA0000000;
}

cache_tag_instance_gen3 *cache_file_gen3_get_tag_instance(
    cache_file *file,
    long index)
{
    cache_header_gen3 *header = file;
    cache_tag_header_gen3 *tag_header = (char *)file + header->offset_to_index;
    cache_tag_instance_gen3 *tag_instances =
        (cache_tag_instance_gen3 *)((char *)file + tag_header->tags_offset);
    
    return &tag_instances[index];
}

void cache_header_gen3_byteswap(
    cache_header_gen3 *header)
{
    int i;
    header->header_signature = _byteswap_ulong(header->header_signature);
    header->version = _byteswap_ulong(header->version);
    header->file_length = _byteswap_ulong(header->file_length);
    header->compressed_file_length = _byteswap_ulong(header->compressed_file_length);
    header->offset_to_index = _byteswap_ulong(header->offset_to_index);
    header->index_stream_size = _byteswap_ulong(header->index_stream_size);
    header->tag_buffer_size = _byteswap_ulong(header->tag_buffer_size);
    header->type = _byteswap_ushort(header->type);
    header->shared_type = _byteswap_ushort(header->shared_type);
    header->string_id_count = _byteswap_ulong(header->string_id_count);
    header->string_id_buffer_size = _byteswap_ulong(header->string_id_buffer_size);
    header->string_id_indices_offset = _byteswap_ulong(header->string_id_indices_offset);
    header->string_id_buffer_offset = _byteswap_ulong(header->string_id_buffer_offset);
    header->external_dependencies = _byteswap_ulong(header->external_dependencies);
    header->high_date_time = _byteswap_ulong(header->high_date_time);
    header->low_date_time = _byteswap_ulong(header->low_date_time);
    header->ui_high_date_time = _byteswap_ulong(header->ui_high_date_time);
    header->ui_low_date_time = _byteswap_ulong(header->ui_low_date_time);
    header->shared_high_date_time = _byteswap_ulong(header->shared_high_date_time);
    header->shared_low_date_time = _byteswap_ulong(header->shared_low_date_time);
    header->campaign_high_date_time = _byteswap_ulong(header->campaign_high_date_time);
    header->campaign_low_date_time = _byteswap_ulong(header->campaign_low_date_time);
    header->minor_version = _byteswap_ulong(header->minor_version);
    header->tag_names_count = _byteswap_ulong(header->tag_names_count);
    header->tag_names_buffer_offset = _byteswap_ulong(header->tag_names_buffer_offset);
    header->tag_names_buffer_size = _byteswap_ulong(header->tag_names_buffer_size);
    header->tag_names_indices_offset = _byteswap_ulong(header->tag_names_indices_offset);
    header->checksum = _byteswap_ulong(header->checksum);
    header->base_address = _byteswap_ulong(header->base_address);
    header->xdk_version = _byteswap_ulong(header->xdk_version);
    for (i = 0; i < NUMBER_OF_CACHE_PARTITIONS; i++)
    {
        header->partitions[i].base_address = _byteswap_ulong(header->partitions[i].base_address);
        header->partitions[i].size = _byteswap_ulong(header->partitions[i].size);
    }
    for (i = 0; i < 5; i++)
        header->sha1_a[i] = _byteswap_ulong(header->sha1_a[i]);
    for (i = 0; i < 5; i++)
        header->sha1_b[i] = _byteswap_ulong(header->sha1_b[i]);
    for (i = 0; i < 5; i++)
        header->sha1_c[i] = _byteswap_ulong(header->sha1_c[i]);
    for (i = 0; i < 64; i++)
        header->rsa[i] = _byteswap_ulong(header->rsa[i]);
    header->interop.resource_base_address = _byteswap_ulong(header->interop.resource_base_address);
    header->interop.debug_section_size = _byteswap_ulong(header->interop.debug_section_size);
    header->interop.runtime_base_address = _byteswap_ulong(header->interop.runtime_base_address);
    header->interop.unknown_base_address = _byteswap_ulong(header->interop.unknown_base_address);
    for (i = 0; i < NUMBER_OF_CACHE_SECTIONS; i++)
    {
        header->interop.sections[i].virtual_address = _byteswap_ulong(header->interop.sections[i].virtual_address);
        header->interop.sections[i].size = _byteswap_ulong(header->interop.sections[i].size);
    }
    for (i = 0; i < 4; i++)
        header->guid[i] = _byteswap_ulong(header->guid[i]);
    for (i = 0; i < 4; i++)
        header->compression_guid[i] = _byteswap_ulong(header->compression_guid[i]);
    header->footer_signature = _byteswap_ulong(header->footer_signature);
}

long cache_header_gen3_get_file_length(
    cache_header_gen3 *header)
{
    return header->file_length;
}

long cache_header_gen3_get_tag_header_offset(
    cache_header_gen3 *header)
{
    return header->offset_to_index;
}

long cache_header_gen3_get_tag_buffer_size(
    cache_header_gen3 *header)
{
    return header->tag_buffer_size;
}

char const *cache_header_gen3_get_name(
    cache_header_gen3 *header)
{
    return header->name;
}

char const *cache_header_gen3_get_build(
    cache_header_gen3 *header)
{
    return header->build;
}

cache_type cache_header_gen3_get_type(
    cache_header_gen3 *header)
{
    return header->type;
}

cache_shared_type cache_header_gen3_get_shared_type(
    cache_header_gen3 *header)
{
    return _cache_shared_type_none;
}

long cache_tag_header_gen3_get_tag_count(
    cache_tag_header_gen3 *header)
{
    return header->count;
}

dword cache_tag_header_gen3_get_tags_offset(
    cache_tag_header_gen3 *header)
{
    return header->tags_offset;
}

void cache_tag_header_gen3_byteswap(
    cache_tag_header_gen3 *header)
{
    header->group_tags_offset = _byteswap_ulong(header->group_tags_offset);
    header->group_tags_count = _byteswap_ulong(header->group_tags_count);
    header->count = _byteswap_ulong(header->count);
    header->tags_offset = _byteswap_ulong(header->tags_offset);
    header->dependent_tags_count = _byteswap_ulong(header->dependent_tags_count);
    header->dependent_tags_offset = _byteswap_ulong(header->dependent_tags_offset);
    header->dependent_tags_count2 = _byteswap_ulong(header->dependent_tags_count2);
    header->dependent_tags_offset2 = _byteswap_ulong(header->dependent_tags_offset2);
    header->checksum = _byteswap_ulong(header->checksum);
    header->signature = _byteswap_ulong(header->signature);
}

tag cache_tag_instance_gen3_get_group_tag(
    cache_file *file,
    cache_tag_instance_gen3 *instance)
{
    if (instance->group_index == (word)NONE)
        return NONE;

    cache_tag_header_gen3 *tag_header = cache_header_gen3_get_tag_header_offset(file);
    return *(tag *)((char *)file + tag_header->group_tags_offset + 12 * instance->group_index);
}

long cache_tag_instance_gen3_get_index(
    cache_file *file,
    cache_tag_instance_gen3 *instance)
{
    long tag_count = cache_file_get_tag_count(file);
    
    for (long i = 0; i < tag_count; i++)
    {
        cache_tag_instance_gen3 *current_instance = cache_file_gen3_get_tag_instance(file, i);

        if (instance->identifier == current_instance->identifier)
            return i | (current_instance->identifier << 16);
    }

    return NONE;
}

dword cache_tag_instance_gen3_get_name_offset(
    cache_file *file,
    cache_tag_instance_gen3 *instance)
{
    cache_header_gen3 *header = file;
    
    long *name_offsets = (char *)file + header->tag_names_indices_offset;
    long index = cache_tag_instance_gen3_get_index(file, instance);
    long name_offset = name_offsets[index & 0xFFFF];
    
    if (name_offset == NONE)
        return NONE;

    return header->tag_names_buffer_offset + name_offset;
}

dword cache_tag_instance_gen3_get_offset(
    cache_file *file,
    cache_tag_instance_gen3 *instance)
{
    return instance->offset;
}

void cache_tag_instance_gen3_byteswap(
    cache_tag_instance_gen3 *instance)
{
    instance->identifier = _byteswap_ushort(instance->identifier);
    instance->group_index = _byteswap_ushort(instance->group_index);
    instance->offset = _byteswap_ulong(instance->offset);
}