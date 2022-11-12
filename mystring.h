// mystring.h
#ifndef MYSTRING_H
#define MYSTRING_H
// 对字符串中的字符计数
// 例：3 == my_string_length("foo")
int my_string_length(const char * str);
// 对字符串中特定的字符计数
// 例：2 == my_char_count("foo", 'o')
int my_count_char(const char * str, char c);
// 将字符串中的小写英文转换为大写
// 例：char * str = "Hello";
//     my_string_upper(str);
//     str == "HELLO"
void my_string_upper(char * str);
// 返回字符串中特定字符第一次出现的指针
// 没有出现则返回NULL
// 例：char * str = "Hello";
//     char * res = my_find_char(str, 'l');
//     res == str + 2
char *  my_find_char(char * str, char ch);
#endif /* MYSTRING_H */
