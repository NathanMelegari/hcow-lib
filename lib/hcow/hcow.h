/*
 * HCOW [v0.0.1] - A library for shell automation integrated in C code.
 *
 * OBJECTIVE:
 *  Run process directly from the C file, faciliting work with servers,
 *  systems in a geral.
 *
 * LIBRARY FUNCTIONS:
 *  hcow_log() => Print messages at the command line
 *  hcow_run() => Execute shell commands passing an array of instructions
 *  hcow_exists() => Verify if the destine defined exists
 *  hcow_cd() => Access directories passing a destine
 *
 * FUTURE UPDATES:
 *
 * 
 * SUPPORT 2026-03-23:
 *  Maintainer: Nathan Melegari
*/

#ifndef HCOW_H
#define HCOW_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void hcow_log(const char *level, const char *fmt, ...);
#define HCOW_INFO "INFO"
#define HCOW_WARNING "WARNING"
#define HCOW_ERROR "ERROR"


int hcow_run(char *args[]);

int hcow_exists(const char *path);

int hcow_cd(const char *path);

char *hcow_capture(char *args[]);

pid_t hcow_run_async(char *args[]);

char hcow_run_script(char *file);


#endif
