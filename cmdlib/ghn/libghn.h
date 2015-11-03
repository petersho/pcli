#define CMD_TBL_GHN		CMD_TBL_ENTRY(		\
	"ghn",		3,      NULL,			\
	"ghn		- Command ghn table",	\
	cmd_ghn_tbl,		cmd_main_tbl			\
),
#define CMD_TBL_GHN_ETHBOOT	CMD_TBL_ENTRY(		\
	"ethboot",	7,      cmd_ghn_ethboot,	\
	"ethboot		- Command ether boot",	\
	NULL,		NULL			\
),

int cmd_ghn(int argc, char* argv[]);
int cmd_ghn_ethboot(int argc, char* argv[]);
struct cmd_table cmd_ghn_tbl[] = {
	CMD_TBL_GHN
	CMD_TBL_GHN_ETHBOOT
	CMD_TBL_HELP
	CMD_TBL_BACK
	CMD_TBL_QUIT
	CMD_TBL_ENTRY(NULL, 0, NULL, NULL, NULL, NULL)
};

