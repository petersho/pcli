struct cmd_table cmd_2nd_tbl[];
struct cmd_table cmd_3rd_tbl[];

#define CMD_TBL_STATUS  CMD_TBL_ENTRY(		\
	"status",	6,	cmd_status,	\
	"status		- status message",	\
	cmd_2nd_tbl,	cmd_main_tbl		\
),

#define CMD_TBL_INFO	CMD_TBL_ENTRY(		\
	"info",		4,      cmd_info,	\
	"info		- Command i info",	\
	cmd_3rd_tbl,	cmd_2nd_tbl		\
),

#define CMD_TBL_BOOT	CMD_TBL_ENTRY(		\
	"boot",		4,	cmd_boot,	\
	"boot		- Command boot",	\
	NULL,		NULL			\
),

#define CMD_TBL_BOCK	CMD_TBL_ENTRY(		\
	"bock",		4,	NULL,	\
	"bock		- Command bock",	\
	NULL,		NULL			\
),

#define CMD_TBL_VER	CMD_TBL_ENTRY(		\
	"ver",		3,	NULL,	\
	"ver		- Command ver",	\
	NULL,		NULL			\
),

int cmd_status(int argc, char* argv[]);
int cmd_info(int argc, char* argv[]);
int cmd_boot(int argc, char* argv[]);
struct cmd_table cmd_2nd_tbl[] = {
	CMD_TBL_STATUS
	CMD_TBL_BOCK
	CMD_TBL_INFO
	CMD_TBL_BOOT
	CMD_TBL_HELP
	CMD_TBL_BACK
	CMD_TBL_QUIT
	CMD_TBL_ENTRY(NULL, 0, NULL, NULL, NULL, NULL)
};

struct cmd_table cmd_3rd_tbl[] = {
	CMD_TBL_INFO
	CMD_TBL_VER
	CMD_TBL_HELP
	CMD_TBL_BACK
	CMD_TBL_QUIT
	CMD_TBL_ENTRY(NULL, 0, NULL, NULL, NULL, NULL)
};
