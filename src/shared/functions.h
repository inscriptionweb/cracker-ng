
/*!
 * \file functions.h
 * \brief Cracker-ng (optimized) functions headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2013.01.04
 *
 * Copyright (C) 2012-2013 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef SRC_SHARED_FUNCTIONS_H_
#define SRC_SHARED_FUNCTIONS_H_

#include <algorithm>  // transform()
#include <string>
#include <cstdio>
#include <cstring>
#include "./stats.h"


namespace functions_ng {

enum FLAG {
	NONE  = 0x0,
	DEBUG = 0x1
};

typedef struct {
	size_t       * num;
	unsigned int * found;
} statistics;

typedef struct {
	std::string   module;
	std::string   version;
	std::string & filename;
	std::string & input;
	size_t      & flag;
	size_t        argc;
	char**        argv;
} arguments;

// Optimized read from stdin or wordlist
inline bool read_input(FILE *input, char *&output, const size_t &len) {
	if ( fgets(output, len, input) != NULL ) {
		char *lf = strchr(output, '\n');
		if ( lf != NULL ) {
			*lf = '\0';
		}
		return true;
	}
	return false;
}

bool argz_traitment(const arguments &);
bool file_exists(char *);
std::string format_number(const size_t &);
unsigned int get_cores();
std::string get_filename(const std::string&);
void help(const std::string&);
void result(const std::string&);
void *stats(void *argz);
void usage(const std::string&);
void version(const std::string&, const std::string&);
}

#endif  // SRC_SHARED_FUNCTIONS_H_
