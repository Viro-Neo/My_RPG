/*
** EPITECH PROJECT, 2021
** my
** File description:
** echo $?
*/

#ifndef MY_H_
    #define MY_H_

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_getnbr_inc(char **);
int my_isneg(int);
int my_is_prime(int);
int my_putchar(char);
void my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
int my_show_word_array(char * const *);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *, char);
int my_printf(const char *s, ...);
int my_putchar(char c);
int my_putstr(char const *str);
void my_putnbr(int nb);
int my_put_bin(int nb);
int my_intlen(int nb);
char *my_revstr(char *str);
int my_strlen(char const *str);
unsigned int my_put_unbr(unsigned int nb);
void my_put_hex_min(unsigned int nb);
char *my_itoa(int nb);
void my_put_hex_maj(unsigned int nb);
void print_int_array(int **map);
int my_putstr_s_maj(char const *str);
void free_2d_char_array(char **map);
void free_2d_int_array(int **map);
int **map_to_int_array(char **map);
char **recover_map_in_array(char *filepath, char delimiter);
void my_print_array(char **map);
int verify_file_integrity(char *filepath);
char *read_file(char *path);
char **str_to_array(char *, char);
int my_atoi(char *);
void m_strcat(char *dest, char const *src);

#endif/*MY_H_*/
