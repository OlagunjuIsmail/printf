#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int print_str(char *s);
int print_char(char c);
int print_int(int num);
int print_base(unsigned int, unsigned int, char, int);
char hex(unsigned int num, char flag);
int len(char *s);
unsigned int len_int(int);
void save_int(char *, int, unsigned int);
#endif
