/*
 * /home/ms/files/source/libsidtune/RCS/SidTuneTools.h,v
 *
 * Copyright (C) Michael Schwendt <mschwendt@yahoo.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TOOLS_H
#define TOOLS_H

#include "SidTuneTypes.h"

#include <string.h>
#if defined(SID_HAVE_STRSTREA_H)
  #include <strstrea.h>
#else
  #include <strstream.h>
#endif

#if defined(SID_HAVE_STRCASECMP)
  #undef stricmp
  #define stricmp strcasecmp
#endif

#if defined(SID_HAVE_STRNCASECMP)
  #undef strnicmp
  #define strnicmp strncasecmp
#endif

class SidTuneTools
{
 public:

	// Wrapper for ``strnicmp'' without third argument.
	static int myStrNcaseCmp(const char* s1, const char* s2)
	{
	    return strnicmp(s1,s2,strlen(s2));
	}

	// Own version of strdup, which uses new instead of malloc.
	static char* myStrDup(const char *source);

	// Return pointer to file name position in complete path.
	static char* fileNameWithoutPath(char* s);

	// Return pointer to file name position in complete path.
	// Special version: file separator = forward slash.
	static char* slashedFileNameWithoutPath(char* s);

	// Return pointer to file name extension in path.
	// Searching backwards until first dot is found.
	static char* fileExtOfPath(char* s);

	// Parse input string stream. Read and convert a hexa-decimal number up 
	// to a ``,'' or ``:'' or ``\0'' or end of stream.
	static udword_sidt readHex(istrstream& parseStream);

	// Parse input string stream. Read and convert a decimal number up 
	// to a ``,'' or ``:'' or ``\0'' or end of stream.
	static udword_sidt readDec(istrstream& parseStream);

	// Search terminated string for next newline sequence.
	// Skip it and return pointer to start of next line.
	static const char* returnNextLine(const char* pBuffer);

	// Skip any characters in an input string stream up to '='.
	static void skipToEqu(istrstream& parseStream);

	// Start at first character behind '=' and copy rest of string.
	static void copyStringValueToEOL(const char* pSourceStr, char* pDestStr, int destMaxLen);
};

#endif  /* TOOLS_H */
