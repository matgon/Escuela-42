#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 1024

typedef struct s_node {
	int num_digits;
    char *name;
    char *num;
} t_node;

int ft_strncmp(const char *str1, const char *str2, size_t n) {
	int i;

	i = 0;
    while (i < n) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        if (str1[i] == '\0' || str2[i] == '\0')
            return (0);
		i++;
    }
    return (0);
}

char *ft_strcat(const char *str1, const char *str2) {
	int len1;
	int len2;
	int i;
	int j;
	char *ret;
	
	len1 = 0;
    while (str1[len1] != '\0') {
		len1++;
    }
    len2 = 0;
    while (str2[len2] != '\0') {
		len2++;
    }
    ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	i = 0;
    while (i < len1)
		ret[i++] = str1[i];
	j = 0;
	while (j < len2)
		ret[i++] = str2[j++];
    ret[i] = '\0';
    return (ret);
}

char *ft_strncpy(char *dest, const char *src, unsigned int n) {
    char *cpy = dest;
	int i;
	
	i = 0;
    while (*src != '\0' && i < n) {
        *dest = *src;
        dest++;
        src++;
		i++;
    }
    *dest = '\0';
    return (cpy);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int countDigits(const char *str) {
	int count = 0;
    while (*str) {
		if (*str >= '0' && *str <= '9') {
			count++;
        }
        str++;
    }
    return count;
}

int	count_file_lines(const char *filename)
{
	int fd;
	char buffer;
	int ret;
	
	ret = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error al intentar abrir el archivo\n", 35);
		return (-1);
	}
	while (read(fd, &buffer, 1) > 0) {
		if (buffer == '\n') {
			ret++;
        }
    }
	close(fd);
	return (ret);
}

int ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

void process_line(char *line, t_node *node) {
	char *num;
	char *name;
	int length;
	int i;

	num = line;
	i = 0;
	while(ft_is_number(num[i]))
		i++;
	node->num = (char *) malloc(sizeof(char) * i);
	ft_strncpy(node->num, num, i);
	name = line + i;
	i = 0;
	while(name[i] == ' ' || name[i] == ':')
		i++;
	name += i;
	node->name = (char *) malloc(sizeof(char) * ft_strlen(name));
	ft_strncpy(node->name, name, ft_strlen(name));
	node->num_digits = countDigits(node->num);
}

t_node *load_dict(const char *filename, int *size) {
	int fd = open(filename, O_RDONLY);
    char *buffer = (char *)malloc(MAX_BUFFER_SIZE);
	char *line;
	t_node *nodes = (t_node *)malloc(sizeof(t_node) * count_file_lines(filename) + 1);
    int i = 0;
	int buffer_size = 0;

    while (read(fd, &buffer[buffer_size], 1) > 0) {
        if (buffer[buffer_size] == '\n') {
            buffer[buffer_size] = '\0';
            line = (char *)malloc(buffer_size + 1);
            ft_strncpy(line, buffer, buffer_size);
            process_line(line, &nodes[i]);
            free(line);
            i++;
			buffer_size = 0;
        }
		else
	        buffer_size++;
    }
	nodes[i].num = (char *) malloc(4);
	nodes[i].num = NULL;
	free(buffer);
    *size = i;
    close(fd);
    return nodes;
}

void printNumberWords(t_node *nodes, int size) {
	for (int i = 0; i < size; i++) {
		write(1, "Number: ", 8);
        write(1, nodes[i].num, strlen(nodes[i].num));
        write(1, ", Name: ", 8);
        write(1, nodes[i].name, strlen(nodes[i].name));
        write(1, ", Digits: ", 10);
        char digits[20];
        int len = sprintf(digits, "%d", nodes[i].num_digits);
        write(1, digits, len);
        write(1, "\n", 1);
    }
}

char *search_number(char *nbr, int digits, const t_node *dict)
{
	int i;

	i = 0;
	while (dict[i].num != NULL) {
		if (ft_strncmp(nbr, dict[i].num, digits) == 0)
			return dict[i].name;
		i ++;
	}
	return NULL;
}

char *check_dict(char *nbr, int pos, const t_node *dict)
{
	int i;
	char *ret;
	
	i = 0;
	if (pos % 3 == 0){
		if (*nbr == 1)
			return (search_number(nbr, 2, dict));
		return (search_number(nbr, 1, dict));
	}
	else if (pos % 3 == 2){
		if (*nbr == '1')
			return (search_number(nbr, 2, dict));
		return (search_number(nbr, 1, dict));
	}
	else if (pos % 3 == 1){
		ret = search_number(nbr, 1, dict);
		return ret;
	}
	
	return "";
}

char *create_chain(char *nbr, int pos, const t_node *dict)
{
	int i;
	char *hundreds;
	char *ret;

	i = 0;
	hundreds = (char *) malloc(sizeof(char) * pos + 1);
	while (i < pos){
		if (i == 0)
			hundreds[i] = '0';
		else
			hundreds[i] = '0';
		i++;
	}
	hundreds[i] = '\0';
	
	ret = "";
	i = 0;
	int eleven_flag = 0;
	while (i < 3){
		if (nbr[i]!= '0'){
			hundreds[i] = nbr[i];
			if (i == 0)
			{
				ret = ft_strcat(ret, search_number(&hundreds[i], 1, dict));
				ret = ft_strcat(ret, " ");
				hundreds[i] = '1';
				ret = ft_strcat(ret, search_number(&hundreds[i], 3, dict));
				ret = ft_strcat(ret, " ");
			}
			else if(i == 1)
			{
				if (nbr[i] == '1')
				{
					eleven_flag = 1;
					hundreds[i+1] = nbr[i+1];
					ret = ft_strcat(ret, search_number(&hundreds[i], 2, dict));
					ret = ft_strcat(ret, " ");
				}
				else {
					ret = ft_strcat(ret, search_number(&hundreds[i], 2, dict));
					ret = ft_strcat(ret, " ");
				}
			}
			else if(i == 2 && !eleven_flag)
			{
				ret = ft_strcat(ret, search_number(&hundreds[i], 1, dict));
				ret = ft_strcat(ret, " ");
			}
		}
		if (pos > 3 && i == 2)
		{
			hundreds[i] = '1';
			ret = ft_strcat(ret, search_number(&hundreds[i], i + 1 + pos - 3, dict));
			ret = ft_strcat(ret, " ");
		}
		i++;
	}
	free(hundreds);
	return (ret);
}

char *recursion(char *nbr, const t_node *dict){
	static int pos = 0;
	char *str;
	char *str2;
	char *ret;
	if (*nbr)
	{
		str = recursion(nbr+1, dict);
		pos++;
		if (pos % 3 == 0){
			ret = ft_strcat(create_chain(nbr, pos, dict), str);
			return (ret);
		}
		return (str);
	}
	return ("");
}

char *fill_with_zeros(char *str)
{
	int length = ft_strlen(str);
	int n_zeros = (3 - (length %  3)) % 3;
	if (n_zeros == 0)
		return str;
	int new_length = length + n_zeros;
	int i = 0;
	char *zeros = (char *) malloc(sizeof(char) * n_zeros);
	char *ret = (char *) malloc(sizeof(char) * new_length);
	while(i < n_zeros)
		zeros[i++] = '0';
	ret = ft_strcat(zeros, str);
	free(zeros);
	return (ret);
}

int main() {
	const char *filename = "numbers.dict";
    int num_lines = 0;
	t_node *nodes = load_dict(filename, &num_lines);
	
	//IMPORTANTE: check del 0
	char *str = fill_with_zeros("97845");
	char *str2 = recursion(str, nodes);
	printf("%s\n", str2);
	free(str);
	free(str2);
	
	int i = 0;
    while (i < num_lines) {
		free(nodes[i].name);
		free(nodes[i].num);
		i++;
	}
    free(nodes);
	
    return 0;
}