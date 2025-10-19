#define CODENAME "AetheriaMUD"
#define CODEVERSION "1.0.0"

// Backward compatibility for snippets and such.
#define mudstrlcpy strlcpy
#define mudstrlcat strlcat
#define str_dup strdup

const bool TRUE = true;
const bool FALSE = false;
const short BERR = 255;

#define KEY(literal, field, value) \
	if (!str_cmp(word, (literal)))  \
	{                               \
		(field) = (value);           \
		fMatch = TRUE;               \
		break;                       \
	}

// Macro for safe fclose
#define FCLOSE(fp) \
	fclose((fp));   \
	(fp) = NULL;

#define DUR_CONV 23.333333333333333333333333
#define HIDDEN_TILDE '*'

#define BV00 (1 << 0)
#define BV01 (1 << 1)
#define BV02 (1 << 2)
#define BV03 (1 << 3)
#define BV04 (1 << 4)
#define BV05 (1 << 5)
#define BV06 (1 << 6)
#define BV07 (1 << 7)
#define BV08 (1 << 8)
#define BV09 (1 << 9)
#define BV10 (1 << 10)
#define BV11 (1 << 11)
#define BV12 (1 << 12)
#define BV13 (1 << 13)
#define BV14 (1 << 14)
#define BV15 (1 << 15)
#define BV16 (1 << 16)
#define BV17 (1 << 17)
#define BV18 (1 << 18)
#define BV19 (1 << 19)
#define BV20 (1 << 20)
#define BV21 (1 << 21)
#define BV22 (1 << 22)
#define BV23 (1 << 23)
#define BV24 (1 << 24)
#define BV25 (1 << 25)
#define BV26 (1 << 26)
#define BV27 (1 << 27)
#define BV28 (1 << 28)
#define BV29 (1 << 29)
#define BV30 (1 << 30)
#define BV31 (1 << 31)
// 32 USED! DO NOT ADD MORE! SB

#define MAX_KEY_HASH 2048
#define MAX_STRING_LENGTH 4096 /* buf */
#define MAX_INPUT_LENGTH 1024  /* arg */
