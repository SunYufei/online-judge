#ifndef LIB_H
#define LIB_H

void putint(int arg);
void putchar(char arg);
void loaddata(void *addr);
void setanswer(void *addr);
void putstring(char* arg);
void exit(int res);
int printbase(long v, int w, int base, int sign);
int printf(const char* fmt, ...);
int main();
__attribute__((section(".init"))) void _start();

#endif // LIB_H
