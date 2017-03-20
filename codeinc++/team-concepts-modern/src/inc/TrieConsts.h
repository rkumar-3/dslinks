#pragma once

static const int kEnglishAlphabetMax = 26;
static const int const_sizeof_english_alphabet = 26;
static const int const_not_an_english_alphabet = -1;

/**
 *   enable the following block for memory profiling.
 *   using CRT Debug Heap mechanism
 */
#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_CLIENTBLOCK
#endif // _DEBUG

#ifdef _DEBUG
#define new DEBUG_CLIENTBLOCK
#endif
