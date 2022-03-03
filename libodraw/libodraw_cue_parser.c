/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cue_scanner_parse
#define yylex           cue_scanner_lex
#define yyerror         cue_scanner_error
#define yydebug         cue_scanner_debug
#define yynerrs         cue_scanner_nerrs

#define yylval          cue_scanner_lval
#define yychar          cue_scanner_char

/* Copy the first part of user declarations.  */


/*
 * CUE parser functions
 *
 * Copyright (C) 2010-2020, Joachim Metz <joachim.metz@gmail.com>
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
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "libodraw_definitions.h"
#include "libodraw_handle.h"
#include "libodraw_libcerror.h"
#include "libodraw_libcnotify.h"
#include "libodraw_types.h"

#define YYMALLOC	cue_scanner_alloc
#define YYREALLOC	cue_scanner_realloc
#define YYFREE		cue_scanner_free

#define YYLEX_PARAM	NULL
#define YYPARSE_PARAM	parser_state

#if defined( HAVE_DEBUG_OUTPUT )
#define cue_parser_rule_print( string ) \
	if( libcnotify_verbose != 0 ) libcnotify_printf( "cue_parser: rule: %s\n", string )
#else
#define cue_parser_rule_print( string )
#endif

#if !defined( CD_SECS )
/* seconds per minute */
#define CD_SECS			60
#endif

#if !defined( CD_FRAMES )
/* frames per second */
#define CD_FRAMES		75
#endif

/* Note that the MSF are relative, so there is no need for the MSF offset correction
 */
#define cue_parser_copy_relative_msf_to_lba( msf_string, lba ) \
        lba  = ( ( msf_string[ 0 ] - '0' ) * 10 ) + ( msf_string[ 1 ] - '0' ); \
        lba *= CD_SECS; \
        lba += ( ( msf_string[ 3 ] - '0' ) * 10 ) + ( msf_string[ 4 ] - '0' ); \
        lba *= CD_FRAMES; \
        lba += ( ( msf_string[ 6 ] - '0' ) * 10 ) + ( msf_string[ 7 ] - '0' );



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "libodraw_cue_parser.h".  */
#ifndef YY_CUE_SCANNER_X_DEV_0_FORENSIC_LIBEWF_LEGACY_WIN_LIBODRAW_LIBODRAW_CUE_PARSER_H_INCLUDED
# define YY_CUE_SCANNER_X_DEV_0_FORENSIC_LIBEWF_LEGACY_WIN_LIBODRAW_LIBODRAW_CUE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int cue_scanner_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CUE_END_OF_LINE = 258,
    CUE_SEMI_COLON = 259,
    CUE_2DIGIT = 260,
    CUE_CATALOG_NUMBER = 261,
    CUE_ISRC_CODE = 262,
    CUE_KEYWORD_STRING = 263,
    CUE_MSF = 264,
    CUE_STRING = 265,
    CUE_CATALOG = 266,
    CUE_CDTEXTFILE = 267,
    CUE_FLAGS = 268,
    CUE_FILE = 269,
    CUE_INDEX = 270,
    CUE_ISRC = 271,
    CUE_POSTGAP = 272,
    CUE_PREGAP = 273,
    CUE_REMARK = 274,
    CUE_TRACK = 275,
    CUE_CDTEXT_ARRANGER = 276,
    CUE_CDTEXT_COMPOSER = 277,
    CUE_CDTEXT_DISC_ID = 278,
    CUE_CDTEXT_GENRE = 279,
    CUE_CDTEXT_MESSAGE = 280,
    CUE_CDTEXT_PERFORMER = 281,
    CUE_CDTEXT_SIZE_INFO = 282,
    CUE_CDTEXT_SONGWRITER = 283,
    CUE_CDTEXT_TITLE = 284,
    CUE_CDTEXT_TOC_INFO1 = 285,
    CUE_CDTEXT_TOC_INFO2 = 286,
    CUE_CDTEXT_UPC_EAN = 287,
    CUE_REMARK_LEAD_OUT = 288,
    CUE_REMARK_ORIGINAL_MEDIA_TYPE = 289,
    CUE_REMARK_RUN_OUT = 290,
    CUE_REMARK_SESSION = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


        /* The numeric value
         */
        uint32_t numeric_value;

        /* The string value
         */
	struct cue_string_value
	{
		/* The string data
		 */
	        const char *data;

		/* The string length
		 */
		size_t length;

	} string_value;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE cue_scanner_lval;

int cue_scanner_parse (void *parser_state);

#endif /* !YY_CUE_SCANNER_X_DEV_0_FORENSIC_LIBEWF_LEGACY_WIN_LIBODRAW_LIBODRAW_CUE_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */



typedef struct cue_parser_state cue_parser_state_t;

struct cue_parser_state
{
	/* The file
	 */
	libodraw_handle_t *handle;

	/* The error
	 */
	libcerror_error_t **error;

	/* The previous file index
	 */
	int previous_file_index;

	/* The current file index
	 */
	int current_file_index;

	/* The file type
	 */
	uint8_t file_type;

	/* Value to indicate a new file command was issued
	 */
	uint8_t new_file;

	/* The previous file sector
	 */
	uint64_t previous_file_sector;

	/* The file sector
	 */
	uint64_t file_sector;

	/* The previous session start sector
	 */
	uint64_t previous_session_start_sector;

	/* The previous lead-out start sector
	 */
	uint64_t previous_lead_out_start_sector;

	/* The previous track start sector
	 */
	uint64_t previous_track_start_sector;

	/* The current start sector
	 */
	uint64_t current_start_sector;

	/* The session number of sectors
	 */
	uint64_t session_number_of_sectors;

	/* The lead-out number of sectors
	 */
	uint64_t lead_out_number_of_sectors;

	/* The track number of sectors
	 */
	uint64_t track_number_of_sectors;

	/* The previous track type
	 */
	uint8_t previous_track_type;

	/* The current track type
	 */
	uint8_t current_track_type;

	/* The previous session
	 */
	int previous_session;

	/* The current session
	 */
	int current_session;

	/* The previous lead-out
	 */
	int previous_lead_out;

	/* The current lead-out
	 */
	int current_lead_out;

	/* The previous track
	 */
	int previous_track;

	/* The current track
	 */
	int current_track;

	/* The previous index
	 */
	int previous_index;

	/* The current index
	 */
	int current_index;
};

typedef size_t yy_size_t;
typedef struct yy_buffer_state* YY_BUFFER_STATE;

extern \
int cue_scanner_suppress_error;

extern \
int cue_scanner_lex_destroy(
     void );

extern \
void *cue_scanner_alloc(
       yy_size_t size );

extern \
void *cue_scanner_realloc(
       void *buffer,
       yy_size_t size );

extern \
void cue_scanner_free(
      void *buffer );

extern \
int cue_scanner_lex(
     void *user_data );

extern \
void cue_scanner_error(
      void *parser_state,
      const char *error_string );

extern \
YY_BUFFER_STATE cue_scanner__scan_buffer(
                 char *buffer,
                 yy_size_t buffer_size );

extern \
void cue_scanner__delete_buffer(
      YY_BUFFER_STATE buffer_state );

extern \
size_t cue_scanner_buffer_offset;

static char *cue_parser_function = "cue_parser";

int cue_parser_parse_buffer(
     libodraw_handle_t *handle,
     const uint8_t *buffer,
     size_t buffer_size,
     libcerror_error_t **error );




#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   318,   318,   321,   323,   327,   328,   329,   330,   331,
     334,   336,   340,   343,   345,   349,   350,   351,   354,   356,
     360,   361,   362,   363,   364,   365,   368,   370,   374,   375,
     376,   379,   381,   385,   386,   387,   388,   392,   400,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   424,   432,   530,   537,   539,   543,   792,   800,   808,
     816,   817,   818,   819,   820,   824,   890,   898,   908,   918,
     983,  1049,  1238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CUE_END_OF_LINE", "CUE_SEMI_COLON",
  "CUE_2DIGIT", "CUE_CATALOG_NUMBER", "CUE_ISRC_CODE",
  "CUE_KEYWORD_STRING", "CUE_MSF", "CUE_STRING", "CUE_CATALOG",
  "CUE_CDTEXTFILE", "CUE_FLAGS", "CUE_FILE", "CUE_INDEX", "CUE_ISRC",
  "CUE_POSTGAP", "CUE_PREGAP", "CUE_REMARK", "CUE_TRACK",
  "CUE_CDTEXT_ARRANGER", "CUE_CDTEXT_COMPOSER", "CUE_CDTEXT_DISC_ID",
  "CUE_CDTEXT_GENRE", "CUE_CDTEXT_MESSAGE", "CUE_CDTEXT_PERFORMER",
  "CUE_CDTEXT_SIZE_INFO", "CUE_CDTEXT_SONGWRITER", "CUE_CDTEXT_TITLE",
  "CUE_CDTEXT_TOC_INFO1", "CUE_CDTEXT_TOC_INFO2", "CUE_CDTEXT_UPC_EAN",
  "CUE_REMARK_LEAD_OUT", "CUE_REMARK_ORIGINAL_MEDIA_TYPE",
  "CUE_REMARK_RUN_OUT", "CUE_REMARK_SESSION", "$accept", "cue_main",
  "cue_main_items", "cue_main_item", "cue_main_tracks", "cue_main_track",
  "cue_main_track_preceding_items", "cue_main_track_preceding_item",
  "cue_main_track_leading_items", "cue_main_track_leading_item",
  "cue_main_track_index_items", "cue_main_track_index_item",
  "cue_main_track_trailing_items", "cue_main_track_trailing_item",
  "cue_catalog", "cue_cdtext", "cue_cdtext_type", "cue_cdtextfile",
  "cue_file", "cue_flags", "cue_flags_types", "cue_index", "cue_isrc",
  "cue_postgap", "cue_pregap", "cue_remark_item", "cue_lead_out",
  "cue_original_media_type", "cue_remark", "cue_remark_start",
  "cue_run_out", "cue_session", "cue_track", "cue_empty_line", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,   -68,    -5,    -6,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,     2,     4,     6,
      11,    18,     5,    70,   -68,   -68,    16,   -68,   -68,   -68,
     -68,   -68,    27,   -68,   -68,   -68,    28,    29,    30,    37,
      38,    39,   -68,    20,    70,   -68,    44,    47,   -68,   -68,
     -68,   -68,   -68,   -68,    45,   138,   -68,   -68,    53,   -68,
     138,    54,   142,   -68,   -68,   -68,   -68,   -68,    71,    36,
     -68,    67,    69,    72,    74,    10,    36,   -68,   -68,   -68,
     -68,   -68,   -68,    75,    69,    77,    81,    82,    83,   104,
      10,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
      78,    99,   -68,   104,   -68,   -68,   -68,   -68,   -68,    87,
     106,   -68,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    72,     0,     0,    68,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     3,     5,     7,     0,     6,     8,    60,
      61,    62,     0,    63,    64,     9,     0,     0,     0,     0,
       0,     0,     1,     0,     3,     4,     0,     0,    37,    51,
      65,    66,    69,    70,     0,    10,    38,    67,     0,     2,
      10,     0,    13,    15,    16,    17,    52,    11,     0,    18,
      14,     0,    54,     0,     0,    26,    18,    20,    21,    22,
      23,    24,    25,     0,    54,     0,     0,     0,     0,    31,
      26,    28,    29,    30,    19,    71,    55,    53,    57,    59,
       0,     0,    12,    31,    33,    34,    35,    36,    27,     0,
       0,    32,    56,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -17,   -68,    26,   -68,    48,   -68,    35,   -68,
      22,   -68,    12,   -68,   -68,   -67,   -68,   -68,    91,   -68,
      32,   -68,   -68,   -68,   -68,   -55,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    22,    23,    59,    60,    61,    62,    75,    76,
      89,    90,   102,   103,    24,    25,    26,    27,    63,    78,
      85,    91,    79,   105,    80,    28,    29,    30,    31,    32,
      33,    34,    69,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    36,    77,    65,    37,    64,    45,    64,    65,    77,
      65,    38,    39,     1,    81,    40,    41,    82,    42,    43,
      92,    81,   104,    93,    82,    88,    46,    55,    47,     4,
      54,    48,    49,    50,   106,    92,   104,   107,    93,     1,
      51,    52,    53,    17,    18,    19,    20,    56,   106,    72,
      57,   107,    73,    58,    74,     4,    66,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     1,    68,    83,    71,    84,    95,    86,
      97,     2,     3,    87,    98,    99,    67,   109,   100,     4,
     112,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     1,   110,   113,
      70,    94,   108,    44,     0,   111,    96,     0,     0,     0,
       0,   101,     0,     4,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     1,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,    43,     4,   -13,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    17,    18,    19,    20
};

static const yytype_int8 yycheck[] =
{
      55,     6,    69,    55,    10,    60,    23,    62,    60,    76,
      62,     9,     8,     3,    69,     9,     5,    69,     0,    14,
      75,    76,    89,    75,    76,    15,    10,    44,     1,    19,
      10,     3,     3,     3,    89,    90,   103,    89,    90,     3,
       3,     3,     3,    33,    34,    35,    36,     3,   103,    13,
       3,   103,    16,     8,    18,    19,     3,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     3,    20,     8,     5,     8,     3,     7,
       3,    11,    12,     9,     3,     3,    60,     9,     5,    19,
       3,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     3,     9,     3,
      62,    76,    90,    22,    -1,   103,    84,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     3,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    14,    19,    20,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    12,    19,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    38,    39,    40,    51,    52,    53,    54,    62,    63,
      64,    65,    66,    67,    68,    70,     6,    10,     9,     8,
       9,     5,     0,    14,    55,    39,    10,     1,     3,     3,
       3,     3,     3,     3,    10,    39,     3,     3,     8,    41,
      42,    43,    44,    55,    62,    70,     3,    41,    20,    69,
      43,     5,    13,    16,    18,    45,    46,    52,    56,    59,
      61,    62,    70,     8,     8,    57,     7,     9,    15,    47,
      48,    58,    62,    70,    45,     3,    57,     3,     3,     3,
       5,    17,    49,    50,    52,    60,    62,    70,    47,     9,
       9,    49,     3,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    47,    47,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    56,    57,    57,    58,    59,    60,    61,
      62,    62,    62,    62,    62,    63,    64,    65,    66,    67,
      68,    69,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     1,     1,     1,     1,
       0,     2,     5,     0,     2,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     0,     2,     4,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parser_state, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, parser_state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *parser_state)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (parser_state);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *parser_state)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser_state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void *parser_state)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , parser_state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parser_state); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *parser_state)
{
  YYUSE (yyvaluep);
  YYUSE (parser_state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *parser_state)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (NULL);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 37:

    {
		cue_parser_rule_print(
		 "cue_catalog" );
	}

    break;

  case 38:

    {
		cue_parser_rule_print(
		 "cue_cdtext" );
	}

    break;

  case 51:

    {
		cue_parser_rule_print(
		 "cue_cdtextfile" );
	}

    break;

  case 52:

    {
		cue_parser_rule_print(
		 "cue_file" );

		if( (yyvsp[-2].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid filename.",
			 cue_parser_function );

			YYABORT;
		}
/* TODO what about the string quotation marks */
		if( (yyvsp[-1].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid file type.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_UNKNOWN;

		if( (yyvsp[-1].string_value).length == 3 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "MP3",
			     3 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_AUDIO_MPEG1_LAYER3;
			}
		}
		else if( (yyvsp[-1].string_value).length == 4 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "AIFF",
			     4 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_AUDIO_AIFF;
			}
			else if( narrow_string_compare(
			          (yyvsp[-1].string_value).data,
			          "WAVE",
			          4 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_AUDIO_WAVE;
			}
		}
		else if( (yyvsp[-1].string_value).length == 6 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "BINARY",
			     6 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_BINARY_LITTLE_ENDIAN;
			}
		}
		else if( (yyvsp[-1].string_value).length == 8 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "MOTOROLA",
			     8 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->file_type = LIBODRAW_FILE_TYPE_BINARY_BIG_ENDIAN;
			}
		}
		if( libodraw_handle_append_data_file(
		     ( (cue_parser_state_t *) parser_state )->handle,
		     (yyvsp[-2].string_value).data,
		     (yyvsp[-2].string_value).length,
		     ( (cue_parser_state_t *) parser_state )->file_type,
		     ( (cue_parser_state_t *) parser_state )->error ) != 1 )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
			 "%s: unable to append data file.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->current_file_index += 1;
	}

    break;

  case 53:

    {
		cue_parser_rule_print(
		 "cue_flags" );
	}

    break;

  case 56:

    {
		cue_parser_rule_print(
		 "cue_index" );

		if( (yyvsp[-2].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid index number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->previous_index = ( (cue_parser_state_t *) parser_state )->current_index;

		if( ( ( (yyvsp[-2].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-2].string_value).data )[ 0 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported index number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->current_index = ( (yyvsp[-2].string_value).data )[ 0 ] - '0';

		if( (yyvsp[-2].string_value).length == 2 )
		{
			( (cue_parser_state_t *) parser_state )->current_index *= 10;

			if( ( ( (yyvsp[-2].string_value).data )[ 1 ] < '0' )
			 || ( ( (yyvsp[-2].string_value).data )[ 1 ] > '9' ) )
			{
				libcerror_error_set(
				 ( (cue_parser_state_t *) parser_state )->error,
				 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
				 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
				 "%s: unsupported index number.",
				 cue_parser_function );

				YYABORT;
			}
			( (cue_parser_state_t *) parser_state )->current_index += ( (yyvsp[-2].string_value).data )[ 1 ] - '0';
		}
		if( ( ( (cue_parser_state_t *) parser_state )->current_index != 0 )
		 && ( ( (cue_parser_state_t *) parser_state )->current_index != ( ( (cue_parser_state_t *) parser_state )->previous_index + 1 ) ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported index number - values are not sequential.",
			 cue_parser_function );

			YYABORT;
		}
		if( ( (yyvsp[-1].string_value).data == NULL )
		 || ( (yyvsp[-1].string_value).length != 8 ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		if( ( ( (yyvsp[-1].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 0 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 2 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 5 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		cue_parser_copy_relative_msf_to_lba(
		 (yyvsp[-1].string_value).data,
		 ( (cue_parser_state_t *) parser_state )->current_start_sector );

		/* The MSF can be relative to the start of the file
		 */
		if( ( (cue_parser_state_t *) parser_state )->current_start_sector != 0 )
		{
			if( ( ( (cue_parser_state_t *) parser_state )->current_index == 0 )
			 || ( ( (cue_parser_state_t *) parser_state )->current_index == 1 ) )
			{
				if( ( ( (cue_parser_state_t *) parser_state )->session_number_of_sectors == 0 )
				 || ( ( (cue_parser_state_t *) parser_state )->previous_track_type == LIBODRAW_TRACK_TYPE_AUDIO ) )
				{
					if( ( (cue_parser_state_t *) parser_state )->current_start_sector < ( (cue_parser_state_t *) parser_state )->previous_session_start_sector )
					{
						libcerror_error_set(
						 ( (cue_parser_state_t *) parser_state )->error,
						 LIBCERROR_ERROR_DOMAIN_RUNTIME,
						 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
						 "%s: invalid session start sector value preceeds previous.",
						 cue_parser_function );

						YYABORT;
					}
					( (cue_parser_state_t *) parser_state )->session_number_of_sectors = ( (cue_parser_state_t *) parser_state )->current_start_sector
					                                                                   - ( (cue_parser_state_t *) parser_state )->previous_session_start_sector;
				}
				if( ( ( (cue_parser_state_t *) parser_state )->lead_out_number_of_sectors == 0 )
				 || ( ( (cue_parser_state_t *) parser_state )->previous_track_type == LIBODRAW_TRACK_TYPE_AUDIO ) )
				{
					if( ( (cue_parser_state_t *) parser_state )->current_start_sector < ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector )
					{
						libcerror_error_set(
						 ( (cue_parser_state_t *) parser_state )->error,
						 LIBCERROR_ERROR_DOMAIN_RUNTIME,
						 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
						 "%s: invalid lead-out start sector value preceeds previous.",
						 cue_parser_function );

						YYABORT;
					}
					( (cue_parser_state_t *) parser_state )->lead_out_number_of_sectors = ( (cue_parser_state_t *) parser_state )->current_start_sector
					                                                                    - ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector;
				}
			}
			if( ( (cue_parser_state_t *) parser_state )->current_index == 1 )
			{
				if( ( (cue_parser_state_t *) parser_state )->track_number_of_sectors == 0 )
				{
					if( ( (cue_parser_state_t *) parser_state )->current_start_sector < ( (cue_parser_state_t *) parser_state )->previous_track_start_sector )
					{
						libcerror_error_set(
						 ( (cue_parser_state_t *) parser_state )->error,
						 LIBCERROR_ERROR_DOMAIN_RUNTIME,
						 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
						 "%s: invalid track start sector value preceeds previous.",
						 cue_parser_function );

						YYABORT;
					}
					( (cue_parser_state_t *) parser_state )->track_number_of_sectors = ( (cue_parser_state_t *) parser_state )->current_start_sector
					                                                                 - ( (cue_parser_state_t *) parser_state )->previous_track_start_sector;
				}
			}
		}
		if( ( (cue_parser_state_t *) parser_state )->current_index == 1 )
		{
			if( ( (cue_parser_state_t *) parser_state )->current_session > 1 )
			{
				if( libodraw_handle_append_session(
				     ( (cue_parser_state_t *) parser_state )->handle,
				     ( (cue_parser_state_t *) parser_state )->previous_session_start_sector,
				     ( (cue_parser_state_t *) parser_state )->session_number_of_sectors,
				     ( (cue_parser_state_t *) parser_state )->error ) != 1 )
				{
					libcerror_error_set(
					 ( (cue_parser_state_t *) parser_state )->error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
					 "%s: unable to append session.",
					 cue_parser_function );

					YYABORT;
				}
				( (cue_parser_state_t *) parser_state )->previous_session_start_sector = ( (cue_parser_state_t *) parser_state )->current_start_sector;
				( (cue_parser_state_t *) parser_state )->session_number_of_sectors     = 0;
			}
			if( ( (cue_parser_state_t *) parser_state )->current_lead_out > ( (cue_parser_state_t *) parser_state )->previous_lead_out )
			{
				if( libodraw_handle_append_lead_out(
				     ( (cue_parser_state_t *) parser_state )->handle,
				     ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector,
				     ( (cue_parser_state_t *) parser_state )->lead_out_number_of_sectors,
				     ( (cue_parser_state_t *) parser_state )->error ) != 1 )
				{
					libcerror_error_set(
					 ( (cue_parser_state_t *) parser_state )->error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
					 "%s: unable to append lead-out.",
					 cue_parser_function );

					YYABORT;
				}
				( (cue_parser_state_t *) parser_state )->previous_lead_out          = ( (cue_parser_state_t *) parser_state )->current_lead_out;
				( (cue_parser_state_t *) parser_state )->lead_out_number_of_sectors = 0;
			}
			if( ( (cue_parser_state_t *) parser_state )->current_track > 1 )
			{
				if( ( (cue_parser_state_t *) parser_state )->previous_file_index < 0 )
				{
					( (cue_parser_state_t *) parser_state )->file_sector = ( (cue_parser_state_t *) parser_state )->previous_track_start_sector;

					( (cue_parser_state_t *) parser_state )->previous_file_index += 1;
				}
				( (cue_parser_state_t *) parser_state )->previous_file_sector = ( (cue_parser_state_t *) parser_state )->previous_track_start_sector
				                                                              - ( (cue_parser_state_t *) parser_state )->file_sector;

				if( libodraw_handle_append_track(
				     ( (cue_parser_state_t *) parser_state )->handle,
				     ( (cue_parser_state_t *) parser_state )->previous_track_start_sector,
				     ( (cue_parser_state_t *) parser_state )->track_number_of_sectors,
				     ( (cue_parser_state_t *) parser_state )->previous_track_type,
				     ( (cue_parser_state_t *) parser_state )->previous_file_index,
				     ( (cue_parser_state_t *) parser_state )->previous_file_sector,
				     ( (cue_parser_state_t *) parser_state )->error ) != 1 )
				{
					libcerror_error_set(
					 ( (cue_parser_state_t *) parser_state )->error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
					 "%s: unable to append track.",
					 cue_parser_function );

					YYABORT;
				}
				if( ( (cue_parser_state_t *) parser_state )->previous_file_index < ( (cue_parser_state_t *) parser_state )->current_file_index )
				{
					( (cue_parser_state_t *) parser_state )->file_sector = ( (cue_parser_state_t *) parser_state )->current_start_sector;

					( (cue_parser_state_t *) parser_state )->previous_file_index += 1;
				}
				( (cue_parser_state_t *) parser_state )->previous_track_start_sector = ( (cue_parser_state_t *) parser_state )->current_start_sector;
				( (cue_parser_state_t *) parser_state )->track_number_of_sectors     = 0;
			}
		}
	}

    break;

  case 57:

    {
		cue_parser_rule_print(
		 "cue_isrc" );
	}

    break;

  case 58:

    {
		cue_parser_rule_print(
		 "cue_postgap" );
	}

    break;

  case 59:

    {
		cue_parser_rule_print(
		 "cue_pregap" );
	}

    break;

  case 65:

    {
		cue_parser_rule_print(
		 "cue_lead_out" );

		if( ( (yyvsp[-1].string_value).data == NULL )
		 || ( (yyvsp[-1].string_value).length != 8 ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		if( ( ( (yyvsp[-1].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 0 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 2 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 5 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		cue_parser_copy_relative_msf_to_lba(
		 (yyvsp[-1].string_value).data,
		 ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector );

		if( ( (cue_parser_state_t *) parser_state )->track_number_of_sectors == 0 )
		{
			if( ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector < ( (cue_parser_state_t *) parser_state )->previous_track_start_sector )
			{
				libcerror_error_set(
				 ( (cue_parser_state_t *) parser_state )->error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
				 "%s: invalid lead-out start sector value preceeds previous track start sector.",
				 cue_parser_function );

				YYABORT;
			}
			( (cue_parser_state_t *) parser_state )->track_number_of_sectors = ( (cue_parser_state_t *) parser_state )->previous_lead_out_start_sector
			                                                                 - ( (cue_parser_state_t *) parser_state )->previous_track_start_sector;
		}
		( (cue_parser_state_t *) parser_state )->current_lead_out += 1;
	}

    break;

  case 66:

    {
		cue_parser_rule_print(
		 "cue_original_media_type" );
	}

    break;

  case 67:

    {
		cue_parser_rule_print(
		 "cue_remark" );

		cue_scanner_suppress_error = 0;
	}

    break;

  case 68:

    {
		/* The build-in rule error will gobble up all the tokens until the end-of-line
		 * because these are no syntax errors suppress the error output
		 */
		cue_scanner_suppress_error = 1;
	}

    break;

  case 69:

    {
		cue_parser_rule_print(
		 "cue_run_out" );

		if( ( (yyvsp[-1].string_value).data == NULL )
		 || ( (yyvsp[-1].string_value).length != 8 ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		if( ( ( (yyvsp[-1].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 0 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 1 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 2 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 3 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 4 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 5 ] != ':' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 6 ] > '9' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 7 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported index MSF.",
			 cue_parser_function );

			YYABORT;
		}
		cue_parser_copy_relative_msf_to_lba(
		 (yyvsp[-1].string_value).data,
		 ( (cue_parser_state_t *) parser_state )->current_start_sector );

		if( ( (cue_parser_state_t *) parser_state )->track_number_of_sectors == 0 )
		{
			if( ( (cue_parser_state_t *) parser_state )->current_start_sector < ( (cue_parser_state_t *) parser_state )->previous_track_start_sector )
			{
				libcerror_error_set(
				 ( (cue_parser_state_t *) parser_state )->error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
				 "%s: invalid track start sector value preceeds previous.",
				 cue_parser_function );

				YYABORT;
			}
			( (cue_parser_state_t *) parser_state )->track_number_of_sectors = ( (cue_parser_state_t *) parser_state )->current_start_sector
									                 - ( (cue_parser_state_t *) parser_state )->previous_track_start_sector;
		}
	}

    break;

  case 70:

    {
		cue_parser_rule_print(
		 "cue_session" );

		if( (yyvsp[-1].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid session number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->previous_session = ( (cue_parser_state_t *) parser_state )->current_session;

		if( ( ( (yyvsp[-1].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-1].string_value).data )[ 0 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported session number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->current_session = ( (yyvsp[-1].string_value).data )[ 0 ] - '0';

		if( (yyvsp[-1].string_value).length == 2 )
		{
			( (cue_parser_state_t *) parser_state )->current_session *= 10;

			if( ( ( (yyvsp[-1].string_value).data )[ 1 ] < '0' )
			 || ( ( (yyvsp[-1].string_value).data )[ 1 ] > '9' ) )
			{
				libcerror_error_set(
				 ( (cue_parser_state_t *) parser_state )->error,
				 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
				 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
				 "%s: unsupported session number.",
				 cue_parser_function );

				YYABORT;
			}
			( (cue_parser_state_t *) parser_state )->current_session += ( (yyvsp[-1].string_value).data )[ 1 ] - '0';
		}
		if( ( ( (cue_parser_state_t *) parser_state )->current_session != 0 )
		 && ( ( (cue_parser_state_t *) parser_state )->current_session != ( ( (cue_parser_state_t *) parser_state )->previous_session + 1 ) ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported session number - values are not sequential.",
			 cue_parser_function );

			YYABORT;
		}
	}

    break;

  case 71:

    {
		cue_parser_rule_print(
		 "cue_track" );

		if( (yyvsp[-2].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid track number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->previous_track = ( (cue_parser_state_t *) parser_state )->current_track;

		if( ( ( (yyvsp[-2].string_value).data )[ 0 ] < '0' )
		 || ( ( (yyvsp[-2].string_value).data )[ 0 ] > '9' ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported track number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->current_track = ( (yyvsp[-2].string_value).data )[ 0 ] - '0';

		if( (yyvsp[-2].string_value).length == 2 )
		{
			( (cue_parser_state_t *) parser_state )->current_track *= 10;

			if( ( ( (yyvsp[-2].string_value).data )[ 1 ] < '0' )
			 || ( ( (yyvsp[-2].string_value).data )[ 1 ] > '9' ) )
			{
				libcerror_error_set(
				 ( (cue_parser_state_t *) parser_state )->error,
				 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
				 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
				 "%s: unsupported track number.",
				 cue_parser_function );

				YYABORT;
			}
			( (cue_parser_state_t *) parser_state )->current_track += ( (yyvsp[-2].string_value).data )[ 1 ] - '0';
		}
		if( ( ( (cue_parser_state_t *) parser_state )->current_track != 0 )
		 && ( ( (cue_parser_state_t *) parser_state )->current_track != ( ( (cue_parser_state_t *) parser_state )->previous_track + 1 ) ) )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
			 "%s: unsupported track number - values are not sequential.",
			 cue_parser_function );

			YYABORT;
		}
		if( (yyvsp[-1].string_value).data == NULL )
		{
			libcerror_error_set(
			 ( (cue_parser_state_t *) parser_state )->error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
			 "%s: invalid track number.",
			 cue_parser_function );

			YYABORT;
		}
		( (cue_parser_state_t *) parser_state )->previous_track_type = ( (cue_parser_state_t *) parser_state )->current_track_type;

		( (cue_parser_state_t *) parser_state )->previous_index     = 0;
		( (cue_parser_state_t *) parser_state )->current_index      = 0;
		( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_UNKNOWN;

		if( (yyvsp[-1].string_value).length == 3 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "CDG",
			     3 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_CDG;
			}
		}
		else if( (yyvsp[-1].string_value).length == 5 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "AUDIO",
			     5 ) == 0 )
			{
				( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_AUDIO;
			}
		}
		else if( (yyvsp[-1].string_value).length == 8 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "CDI",
			     3 ) == 0 )
			{
				if( ( (yyvsp[-1].string_value).data )[ 3 ] == '/' )
				{
					if( narrow_string_compare(
					     &( ( (yyvsp[-1].string_value).data )[ 4 ] ),
					     "2336",
					     4 ) == 0 )
					{
						 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_CDI_2336;
					}
					else if( narrow_string_compare(
						  &( ( (yyvsp[-1].string_value).data )[ 4 ] ),
						  "2352",
						  4 ) == 0 )
					{
						 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_CDI_2352;
					}
				}
			}
		}
		else if( (yyvsp[-1].string_value).length == 10 )
		{
			if( narrow_string_compare(
			     (yyvsp[-1].string_value).data,
			     "MODE",
			     4 ) == 0 )
			{
				if( ( (yyvsp[-1].string_value).data )[ 5 ] == '/' )
				{
					if( ( (yyvsp[-1].string_value).data )[ 4 ] == '1' )
					{
						if( narrow_string_compare(
						     &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						     "2048",
						     4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE1_2048;
						}
						else if( narrow_string_compare(
						          &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						          "2352",
						          4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE1_2352;
						}
					}
					else if( ( (yyvsp[-1].string_value).data )[ 4 ] == '2' )
					{
						if( narrow_string_compare(
						     &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						     "2048",
						     4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE2_2048;
						}
						else if( narrow_string_compare(
						          &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						          "2324",
						          4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE2_2324;
						}
						else if( narrow_string_compare(
						          &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						          "2336",
						          4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE2_2336;
						}
						else if( narrow_string_compare(
						          &( ( (yyvsp[-1].string_value).data )[ 6 ] ),
						          "2352",
						          4 ) == 0 )
						{
							 ( (cue_parser_state_t *) parser_state )->current_track_type = LIBODRAW_TRACK_TYPE_MODE2_2352;
						}
					}
				}
			}
		}
	}

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parser_state, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parser_state, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parser_state);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, parser_state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parser_state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parser_state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, parser_state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}



int cue_parser_parse_buffer(
     libodraw_handle_t *handle,
     const uint8_t *buffer,
     size_t buffer_size,
     libcerror_error_t **error )
{
	cue_parser_state_t parser_state;
	
	YY_BUFFER_STATE buffer_state = NULL;
	size_t buffer_offset         = 0;
	int result                   = -1;

	if( buffer_size >= 3 )
	{
		if( ( buffer[ 0 ] == 0x0ef )
		 && ( buffer[ 1 ] == 0x0bb )
		 && ( buffer[ 2 ] == 0x0bf ) )
		{
			buffer_offset = 3;
		}
	}
	buffer_state = cue_scanner__scan_buffer(
	                (char *) &( buffer[ buffer_offset ] ),
	                buffer_size - buffer_offset );

	cue_scanner_buffer_offset = (size_t) buffer_offset;

	if( buffer_state != NULL )
	{
		parser_state.handle                         = handle;
		parser_state.error                          = error;
		parser_state.previous_file_index            = -1;
		parser_state.current_file_index             = -1;
		parser_state.file_type                      = 0;
		parser_state.previous_file_sector           = 0;
		parser_state.file_sector                    = 0;
		parser_state.previous_session_start_sector  = 0;
		parser_state.previous_lead_out_start_sector = 0;
		parser_state.previous_track_start_sector    = 0;
		parser_state.current_start_sector           = 0;
		parser_state.session_number_of_sectors      = 0;
		parser_state.lead_out_number_of_sectors     = 0;
		parser_state.track_number_of_sectors        = 0;
		parser_state.previous_track_type            = 0;
		parser_state.current_track_type             = 0;
		parser_state.previous_session               = 0;
		parser_state.current_session                = 0;
		parser_state.previous_lead_out              = 0;
		parser_state.current_lead_out               = 0;
		parser_state.previous_track                 = 0;
		parser_state.current_track                  = 0;
		parser_state.previous_index                 = 0;
		parser_state.current_index                  = 0;

		if( cue_scanner_parse(
		     &parser_state ) == 0 )
		{
			result = 1;
		}
		cue_scanner__delete_buffer(
		 buffer_state );

		if( parser_state.current_session > 0 )
		{
			if( libodraw_handle_append_session(
			     parser_state.handle,
			     parser_state.previous_session_start_sector,
			     0,
			     parser_state.error ) != 1 )
			{
				libcerror_error_set(
				 parser_state.error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
				 "%s: unable to append session.",
				 cue_parser_function );

				result = -1;
			}
		}
		if( parser_state.current_lead_out > parser_state.previous_lead_out )
		{
			if( libodraw_handle_append_lead_out(
			     parser_state.handle,
			     parser_state.previous_lead_out_start_sector,
			     0,
			     parser_state.error ) != 1 )
			{
				libcerror_error_set(
				 parser_state.error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
				 "%s: unable to append lead-out.",
				 cue_parser_function );

				result = -1;
			}
		}
		if( parser_state.current_track > 0 )
		{
			if( parser_state.previous_file_index < 0 )
			{
				parser_state.file_sector = parser_state.previous_track_start_sector;

				parser_state.previous_file_index += 1;
			}
			parser_state.previous_file_sector = parser_state.previous_track_start_sector
			                                  - parser_state.file_sector;

			if( libodraw_handle_append_track(
			     parser_state.handle,
			     parser_state.previous_track_start_sector,
			     0,
			     parser_state.current_track_type,
			     parser_state.current_file_index,
			     parser_state.previous_file_sector,
			     parser_state.error ) != 1 )
			{
				libcerror_error_set(
				 parser_state.error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
				 "%s: unable to append track.",
				 cue_parser_function );

				result = -1;
			}
		}
	}
	cue_scanner_lex_destroy();

	return( result );
}

