/*
 * This header I think be auto created by a script
 *
 */
#include "console.h"
struct cmd_table cmd_main_tbl[];

#include "cmdlib/status/libstatus.h"
#include "cmdlib/ghn/libghn.h"
#include "cmdlib/example/libexample.h"

struct cmd_table cmd_main_tbl[] = {
	CMD_TBL_MAIN
	CMD_TBL_EXAMPLE
	CMD_TBL_GHN
	CMD_TBL_STATUS
	CMD_TBL_HELP
	CMD_TBL_QUIT
	CMD_TBL_ENTRY(NULL, 0, NULL, NULL, NULL, NULL)
};
