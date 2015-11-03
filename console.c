#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "schema.h"

#define PROMPT	"pCLI (%s)> "

struct cmd_table *curr_lv;
struct cmd_table cmd_main_tbl[];

int cmd_quit(int argc, char* argv[])
{
	endwin();

	exit(0);
}

int cmd_help(int argc, char* argv[])
{
	int i = 1;
	int x,y;

	x = 0;
	y = 1;

	while (curr_lv[i].usage) {
		mvprintw(y + i, x, "%s\n", curr_lv[i].usage);
		i++;
	}

	return 0;
}

int cmd_back(int argc, char* argv[])
{
	if (curr_lv[0].prev_lv) {
		curr_lv = curr_lv[0].prev_lv;
	}

	cmd_help(0, 0);

	/* cmd_back return a special value */
	return 99;
}

int parse_line()
{
	return 0;
}

int parse_cmd(char *cmd, int isTAB)
{
	int i = 1;
	int ret = 0;
	int found = 0;
	int only = 0, tmp_ind = 0;
	int y = 0, x = 0;
	char search_tmp[128];

	if (strlen(cmd) == 0)
		return 0;

	memset(search_tmp, 0, 128);
	/* isTAB > 0 mean hit TAB key */
	if (isTAB) {
		getyx(stdscr, y, x);
		while (curr_lv[i].name != NULL) {
			found = strncasecmp(curr_lv[i].name, cmd, isTAB);
			if (!found) {
				sprintf(search_tmp, "%s %s", search_tmp, curr_lv[i].name);
				only++;
				tmp_ind = i;
			}
			i++;
		}
		if (only == 1) {
			printw("                                                                                ");
			x = x - isTAB;
			move(y, x);
			printw("%s", curr_lv[tmp_ind].name);
			refresh();
			move(y, x + curr_lv[tmp_ind].len_name);
			strncpy(cmd, curr_lv[tmp_ind].name, curr_lv[tmp_ind].len_name);
			ret = curr_lv[tmp_ind].len_name - isTAB;
		} else if (only > 1) {
			move(1, 0);
			printw("%s", search_tmp);
			clrtoeol();
		} else {
			move(1, 0);
			printw("                                                                                ");
			ret = 0;
		}

		return ret;
	} else { /* isTAB == 0 */
		while (curr_lv[i].name != NULL) {
			found = strncmp(curr_lv[i].name, cmd, curr_lv[i].len_name);
			if (!found) {
				if (curr_lv[i].Func != NULL) {
					ret = curr_lv[i].Func(0,0);
				}
				if (curr_lv[i].next_lv && ret != 99) {
					curr_lv = curr_lv[i].next_lv;
				}
				cmd_help(0, 0);
				break;
			}
			i++;
		}
	
		if (found != 0) {
			ret = 0;
			printw("Command not found\n");
			refresh();
		} else {
			ret = 1;
		}
	}

	return ret;
}

int main()
{
	int c = 0;
	int i = 0;
	int len_tmp = 0;
	char history_cmd[CMDBUF_SIZE];
	char cmdbuf[CMDBUF_SIZE];
	int ret = 0;
	int row = 0, col = 0;
	
	curr_lv = cmd_main_tbl;

	initscr();
	noecho();
	raw();  
	keypad(stdscr, TRUE); 

	memset(history_cmd, 0, sizeof(history_cmd));
	memset(cmdbuf, 0, sizeof(cmdbuf));

	mvprintw(0, 0, PROMPT, curr_lv[0].name);
	refresh();

	while (1) {
		c = getch();

		if (c == 0xa) { /* enter key */
			if (i > 0) {
				clear();
				printw("\n");
				refresh();
				cmdbuf[i] = 0x0;
				ret = parse_cmd(cmdbuf, 0);
				if (ret) {
					strncpy(history_cmd, cmdbuf, i);
					history_cmd[i] = 0;
				}
				mvprintw(0, 0, PROMPT, curr_lv[0].name);
				refresh();
				memset(cmdbuf, 0, sizeof(cmdbuf));
				i = 0;
			}
		} else if (c == 0x3f) { /* "?" */
			clear();
			printw("\n");
			refresh();
			cmd_help(0, 0);
			i = 0;
			mvprintw(0, 0, PROMPT, curr_lv[0].name);
			refresh();
		} else if (c == KEY_BACKSPACE) {
			if (i > 0) {
				printw("\b");
				refresh();
				delch();
				cmdbuf[i] = 0;
				i--;
			}
		} else if (c == KEY_UP) {
			printw("%s", history_cmd);
			i = strlen(history_cmd);
			strncpy(cmdbuf, history_cmd, i);
		} else if (c == '\t') {	/* TAB key */
			getyx(stdscr, row, col);
			len_tmp = parse_cmd(cmdbuf, i);
			move(row,col+len_tmp);
			if (len_tmp)
				i = i + len_tmp;
		} else {
			printw("%c", c);
			refresh();
			cmdbuf[i] = c;
			i++;
                        
			if (i > (CMDBUF_SIZE - 1)) {
				i = 0;
				memset(cmdbuf, 0, sizeof(cmdbuf));
			} 
		}
	}

	return 0;
}
