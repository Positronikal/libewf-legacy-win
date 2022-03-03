/*
 * Chunk data functions
 *
 * Copyright (c) 2006-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libewf_libcerror.h"
#include "libewf_libcnotify.h"

#include "libewf_checksum.h"
#include "libewf_chunk_data.h"
#include "libewf_compression.h"
#include "libewf_definitions.h"
#include "libewf_empty_block.h"

#include "ewf_definitions.h"

/* Initialize the chunk data
 * Returns 1 if successful or -1 on error
 */
int libewf_chunk_data_initialize(
     libewf_chunk_data_t **chunk_data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libewf_chunk_data_initialize";

	if( chunk_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid chunk data.",
		 function );

		return( -1 );
	}
	if( *chunk_data != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid chunk data value already set.",
		 function );

		return( -1 );
	}
	if( ( data_size == 0 )
	 || ( data_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	*chunk_data = memory_allocate_structure(
	               libewf_chunk_data_t );

	if( *chunk_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create chunk data.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *chunk_data,
	     0,
	     sizeof( libewf_chunk_data_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear chunk data.",
		 function );

		goto on_error;
	}
	( *chunk_data )->data = (uint8_t *) memory_allocate(
	                                     sizeof( uint8_t ) * ( data_size + sizeof( uint32_t ) ) );

	if( ( *chunk_data )->data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create data.",
		 function );

		goto on_error;
	}
	( *chunk_data )->allocated_data_size = data_size + sizeof( uint32_t );

	return( 1 );

on_error:
	if( *chunk_data != NULL )
	{
		memory_free(
		 *chunk_data );

		*chunk_data = NULL;
	}
	return( -1 );
}

/* Frees the chunk data including elements
 * Returns 1 if successful or -1 on error
 */
int libewf_chunk_data_free(
     libewf_chunk_data_t **chunk_data,
     libcerror_error_t **error )
{
	static char *function = "libewf_chunk_data_free";

	if( chunk_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid chunk data.",
		 function );

		return( -1 );
	}
	if( *chunk_data != NULL )
	{
		if( ( *chunk_data )->data != NULL )
		{
			memory_free(
			 ( *chunk_data )->data );
		}
		if( ( *chunk_data )->compressed_data != NULL )
		{
			memory_free(
			 ( *chunk_data )->compressed_data );
		}
		memory_free(
		 *chunk_data );

		*chunk_data = NULL;
	}
	return( 1 );
}

/* Packs the chunk data
 * This function either adds the checksum or compresses the chunk data
 * Returns 1 if successful or -1 on error
 */
int libewf_chunk_data_pack(
     libewf_chunk_data_t *chunk_data,
     int8_t compression_level,
     uint8_t compression_flags,
     uint8_t ewf_format,
     size32_t chunk_size,
     const uint8_t *compressed_zero_byte_empty_block,
     size_t compressed_zero_byte_empty_block_size,
     libcerror_error_t **error )
{
	static char *function        = "libewf_chunk_data_pack";
	void *reallocation           = NULL;
	uint32_t calculated_checksum = 0;
	int is_empty_zero_block      = 0;
	int result                   = 0;

	if( chunk_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid chunk data.",
		 function );

		return( -1 );
	}
	if( chunk_data->data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_MISSING,
		 "%s: invalid chunk data - missing data.",
		 function );

		return( -1 );
	}
	if( chunk_data->is_packed != 0 )
	{
		return( 1 );
	}
	chunk_data->is_compressed = 0;

	/* Skip the empty block check only if the compression is none and
	 * the empty block compression flag is not set.
	 */
	if( ( compression_level != EWF_COMPRESSION_NONE )
	 || ( ( compression_flags & LIBEWF_FLAG_COMPRESS_EMPTY_BLOCK ) != 0 ) )
	{
		result = libewf_empty_block_test(
			  chunk_data->data,
			  chunk_data->data_size,
			  error );

		if( result == -1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to determine if chunk data is empty an empty block.",
			 function );

			return( -1 );
		}
		else if( result == 1 )
		{
			if( ( chunk_data->data )[ 0 ] == 0 )
			{
				is_empty_zero_block = 1;
			}
			else if( compression_level == EWF_COMPRESSION_NONE )
			{
				compression_level = EWF_COMPRESSION_DEFAULT;
			}
		}
	}
	if( ( ewf_format == EWF_FORMAT_S01 )
	 || ( compression_level != EWF_COMPRESSION_NONE )
	 || ( is_empty_zero_block != 0 ) )
	{
		chunk_data->compressed_data_size = 2 * chunk_data->data_size;

		chunk_data->compressed_data = (uint8_t *) memory_allocate(
		                                           sizeof( uint8_t ) * chunk_data->compressed_data_size );

		if( chunk_data->compressed_data == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create compressed data.",
			 function );

			return( -1 );
		}
		if( ( is_empty_zero_block != 0 )
		 && ( chunk_data->data_size == (size_t) chunk_size )
		 && ( compressed_zero_byte_empty_block != NULL ) )
		{
			if( memory_copy(
			     chunk_data->compressed_data,
			     compressed_zero_byte_empty_block,
			     compressed_zero_byte_empty_block_size ) == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
				 "%s: unable to copy compressed zero byte empty block to compressed chunk buffer.",
				 function );

				return( -1 );
			}
			chunk_data->compressed_data_size = compressed_zero_byte_empty_block_size;
		}
		else
		{
			result = libewf_compress_data(
				  chunk_data->compressed_data,
				  &( chunk_data->compressed_data_size ),
				  compression_level,
				  chunk_data->data,
				  chunk_data->data_size,
				  error );

			/* Check if the compressed buffer was too small
			 * and a new compressed data size buffer was passed back
			 */
			if( ( result == -1 )
			 && ( chunk_data->compressed_data_size > 0 ) )
			{
				libcerror_error_free(
				 error );

				reallocation = memory_reallocate(
						chunk_data->compressed_data,
						sizeof( uint8_t ) * chunk_data->compressed_data_size );

				if( reallocation == NULL )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_MEMORY,
					 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
					 "%s: unable to resize compressed data.",
					 function );

					return( -1 );
				}
				chunk_data->compressed_data = (uint8_t *) reallocation;

				result = libewf_compress_data(
					  chunk_data->compressed_data,
					  &( chunk_data->compressed_data_size ),
					  compression_level,
					  chunk_data->data,
					  chunk_data->data_size,
					  error );
			}
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_COMPRESSION,
				 LIBCERROR_COMPRESSION_ERROR_COMPRESS_FAILED,
				 "%s: unable to compress chunk data.",
				 function );

				return( -1 );
			}
		}
	 	if( ( ewf_format == EWF_FORMAT_S01 )
		 || ( chunk_data->compressed_data_size < chunk_data->data_size ) )
		{
			memory_free(
			 chunk_data->data );

			chunk_data->data      = chunk_data->compressed_data;
			chunk_data->data_size = chunk_data->compressed_data_size;

			chunk_data->compressed_data      = NULL;
			chunk_data->compressed_data_size = 0;

			chunk_data->is_compressed = 1;
		}
	}
	if( chunk_data->is_compressed == 0 )
	{
		if( ( chunk_data->data_size + sizeof( uint32_t ) ) > chunk_data->allocated_data_size )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: chunk data size value out of bounds.",
			 function );

			return( -1 );
		}
		if( libewf_checksum_calculate_adler32(
		     &calculated_checksum,
		     chunk_data->data,
		     chunk_data->data_size,
		     1,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to calculate checksum.",
			 function );

			return( -1 );
		}
		byte_stream_copy_from_uint32_little_endian(
		 &( ( chunk_data->data )[ chunk_data->data_size ] ),
		 calculated_checksum );

		chunk_data->data_size += sizeof( uint32_t );
	}
	chunk_data->is_packed = 1;

	return( 1 );
}

/* Unpacks the chunk data
 * This function either validates the checksum or decompresses the chunk data
 * Returns 1 if successful or -1 on error
 */
int libewf_chunk_data_unpack(
     libewf_chunk_data_t *chunk_data,
     size_t chunk_size,
     libcerror_error_t **error )
{
	static char *function        = "libewf_chunk_data_unpack";
	uint32_t calculated_checksum = 0;
	uint32_t stored_checksum     = 0;
	int result                   = 0;

	if( chunk_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid chunk data.",
		 function );

		return( -1 );
	}
	if( chunk_data->data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_MISSING,
		 "%s: invalid chunk data - missing data.",
		 function );

		return( -1 );
	}
	if( ( chunk_size == 0 )
	 || ( chunk_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: chunk size value out of bounds.",
		 function );

		return( -1 );
	}
	if( chunk_data->is_packed == 0 )
	{
		return( 1 );
	}
	if( chunk_data->is_compressed == 0 )
	{
		if( ( chunk_data->data_size < sizeof( uint32_t ) )
		 || ( chunk_data->data_size > (size_t) SSIZE_MAX ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: chunk data size value out of bounds.",
			 function );

			return( -1 );
		}
		chunk_data->data_size -= sizeof( uint32_t );

		byte_stream_copy_to_uint32_little_endian(
		 &( ( chunk_data->data )[ chunk_data->data_size ] ),
		 stored_checksum );

		if( libewf_checksum_calculate_adler32(
		     &calculated_checksum,
		     chunk_data->data,
		     chunk_data->data_size,
		     1,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to calculate checksum.",
			 function );

			return( -1 );
		}
		if( stored_checksum != calculated_checksum )
		{
#if defined( HAVE_VERBOSE_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: chunk data checksum does not match (stored: 0x%08" PRIx32 " calculated: 0x%08" PRIx32 ").\n",
				 function,
				 stored_checksum,
				 calculated_checksum );
			}
#endif
			chunk_data->is_corrupt = 1;
		}
	}
	else
	{
		if( chunk_data->compressed_data != NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
			 "%s: invalid chunk data - compressed data value already set.",
			 function );

			return( -1 );
		}
		chunk_data->compressed_data      = chunk_data->data;
		chunk_data->compressed_data_size = chunk_data->data_size;

		/* Reserve 4 bytes for the checksum
		 */
		chunk_data->allocated_data_size = chunk_size + sizeof( uint32_t );

		chunk_data->data = (uint8_t *) memory_allocate(
		                                sizeof( uint8_t ) * chunk_data->allocated_data_size );

		if( chunk_data->data == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create data.",
			 function );

			return( -1 );
		}
		chunk_data->data_size = chunk_size;

		result = libewf_decompress_data(
			  chunk_data->compressed_data,
			  chunk_data->compressed_data_size,
			  chunk_data->data,
			  &( chunk_data->data_size ),
			  error );

		if( result == -1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_COMPRESSION,
			 LIBCERROR_COMPRESSION_ERROR_DECOMPRESS_FAILED,
			 "%s: unable to decompress chunk data.",
			 function );

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				if( ( error != NULL )
				 && ( *error != NULL ) )
				{
					libcnotify_print_error_backtrace(
					 *error );
				}
			}
#endif
			libcerror_error_free(
			 error );
		}
		if( result != 1 )
		{
#if defined( HAVE_VERBOSE_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: unable to decompress chunk data.\n",
				 function );
			}
#endif
			chunk_data->is_corrupt = 1;
			chunk_data->data_size  = chunk_size;
		}
	}
	chunk_data->is_packed = 0;

	return( 1 );
}

