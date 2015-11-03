#define CMD_TBL_EXAMPLE		CMD_TBL_ENTRY(		\
	"example",		7,      NULL,			\
	"example		- Example command table",	\
	cmd_example_tbl,		cmd_main_tbl			\
),
#define CMD_TBL_EXAMPLE_TEST	CMD_TBL_ENTRY(		\
	"test",		4,      cmd_example_test,	\
	"test		- Command test",	\
	NULL,		NULL			\
),

int cmd_example_test(int argc, char* argv[]);
struct cmd_table cmd_example_tbl[] = {
	CMD_TBL_EXAMPLE
	CMD_TBL_EXAMPLE_TEST
	CMD_TBL_HELP
	CMD_TBL_BACK
	CMD_TBL_QUIT
	CMD_TBL_ENTRY(NULL, 0, NULL, NULL, NULL, NULL)
};
