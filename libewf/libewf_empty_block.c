/*
 * Empty block test functions
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
#include <memory.h>
#include <types.h>

#include "libewf_empty_block.h"
#include "libewf_libcerror.h"

/* Check for empty block
 * An empty block is a block that contains the same value for every byte
 * Returns 1 if block is empty, 0 if not or -1 on error
 */
int libewf_empty_block_test(
     const uint8_t *block_buffer,
     size_t block_size,
     libcerror_error_t **error )
{
	static char *function = "libewf_empty_block_test";

	if( block_buffer == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid block buffer.",
		 function );

		return( -1 );
	}
	if( block_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid block size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( block_size == 0 )
	{
		return( 0 );
	}
	else if( block_size == 1 )
	{
		return( 1 );
	}
	if( memory_compare(
	     block_buffer,
	     &( block_buffer[ 1 ] ),
	     block_size - 1 ) != 0 )
	{
		return( 0 );
	}
	return( 1 );
}

/* Previous version keep for now */
#ifdef TEST_EMPTY_BLOCK_MEMCMP

/* The largest primary (or scalar) available
 * supported by a single load and store instruction
 */
typedef unsigned long int libewf_aligned_t;

/* Check for empty block
 * An empty block is a block that contains the same value for every byte
 * Returns 1 if block is empty, 0 if not or -1 on error
 */
int libewf_empty_block_test(
     const uint8_t *block_buffer,
     size_t block_size,
     libcerror_error_t **error )
{
	uint8_t *block_iterator   = NULL;
	uint8_t *block_start      = NULL;
	static char *function     = "libewf_empty_block_test";
	size_t aligned_block_size = 0;

	if( block_buffer == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid block buffer.",
		 function );

		return( -1 );
	}
	if( block_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid block size value exceeds maximum.",
		 function );

		return( -1 );
	}
	block_start    = (uint8_t *) block_buffer;
	block_iterator = (uint8_t *) block_buffer + 1;
	block_size    -= 1;

	/* Only optimize for blocks larger than the alignment
	 */
	if( block_size > ( 2 * sizeof( libewf_aligned_t ) ) )
	{
		/* Align the block start
		 */
		while( ( (intptr_t) block_start % sizeof( libewf_aligned_t ) ) != 0 )
		{
			if( *block_start != *block_iterator )
			{
				return( 0 );
			}
			block_start    += 1;
			block_iterator += 1;
			block_size     -= 1;
		}
		aligned_block_size = ( block_size / sizeof( libewf_aligned_t ) ) * sizeof( libewf_aligned_t );

		if( memory_compare(
		     block_start,
		     &( block_start[ sizeof( libewf_aligned_t ) ] ),
		     aligned_block_size - sizeof( libewf_aligned_t ) ) != 0 )
		{
			return( 0 );
		}
		block_iterator = &( block_start[ aligned_block_size ] );
		block_size    -= aligned_block_size;
	}
	while( block_size != 0 )
	{
		if( *block_start != *block_iterator )
		{
			return( 0 );
		}
		block_iterator += 1;
		block_size     -= 1;
	}
	return( 1 );
}

#endif /* TEST_EMPTY_BLOCK_MEMCMP */

