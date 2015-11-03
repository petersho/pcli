#define CMDBUF_SIZE	128

struct cmd_table {
	char	*name;
	int	len_name;
	int 	(*Func)(int argc, char* argv[]);
	char 	*usage;
	struct	cmd_table 	*next_lv;
	struct	cmd_table 	*prev_lv;
	
};

int cmd_help(int argc, char* argv[]);
int cmd_back(int argc, char* argv[]);
int cmd_quit(int argc, char* argv[]);

#define CMD_TBL_ENTRY(name, len_name, cmd, usage, next_lv, prev_lv)  {name, len_name, cmd, usage, next_lv, prev_lv}

/* Main Level */
#define CMD_TBL_MAIN    CMD_TBL_ENTRY(          \
	"main",		4,	NULL,       \
	"main		- Main the program",	\
	NULL,		NULL			\
),

/* Common command */
#define CMD_TBL_QUIT    CMD_TBL_ENTRY(          \
	"quit",		4,	cmd_quit,       \
	"quit		- Quit the program",	\
	NULL,		NULL			\
),

#define CMD_TBL_HELP	CMD_TBL_ENTRY(		\
	"help",					\
	4,					\
	cmd_help,				\
	"help		- Show usage message",	\
	NULL,		NULL			\
),

#define CMD_TBL_BACK	CMD_TBL_ENTRY(		\
	"back",		4,	cmd_back,	\
	"back		- Back to prev level",	\
	NULL,		NULL			\
),
