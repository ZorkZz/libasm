#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

size_t		ft_strlen(const char * str);
char		*ft_strcpy(char *dest, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
ssize_t		ft_write(int fd, char const *str, size_t len);
ssize_t		ft_read(int fd, char const *str, size_t len);
char		*ft_strdup(char const *str);

void	test_strlen();
void	test_strcpy();
void	test_strcmp();
void	test_write();
void	test_read();
void	test_strdup();

int	main(void)
{
	printf("\n\n----STRLEN----\n");
	test_strlen();
	printf("\n\n----STRCPY----\n");
	test_strcpy();
	printf("\n\n----STRCMP----\n");
	test_strcmp();
	printf("\n\n----WRITE----\n");
	test_write();
	printf("\n\n----READ----\n");
	test_read();
	printf("\n\n----STRDUP----\n");
	test_strdup();

	return (0);
}

void	test_strlen()
{
	char	*s1 = "caca";
	char	*s2 = "fartingirl";
	char	*s3 = "";
	// char	*s4 = NULL;

	printf("---test1---\n");

	printf("%s: %ld, %ld\n", s1, ft_strlen(s1), strlen(s1));

	printf("---test2---\n");

	printf("%s: %ld, %ld\n", s2, ft_strlen(s2), strlen(s2));
	
	printf("---test3---\n");
	
	printf("%s: %ld, %ld\n", s3, ft_strlen(s3), strlen(s3));
	// printf("%s: %ld, %ld\n", s4, ft_strlen(s4), strlen(s4));
}

void	test_strcpy()
{
	printf("---test1---\n");

	char	*src = "myString";
	char	*dest = malloc(sizeof(char) * (ft_strlen(src) + 1));

	printf("src: %s, ret: %s, dest: %s, funcRet: %s\n", src, ft_strcpy(dest, src), dest, strcpy(dest, src));
	free(dest);

	printf("---test2---\n");

	src = "";
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	printf("src: %s, ret: %s, dest: %s, funcRet: %s\n", src, ft_strcpy(dest, src), dest, strcpy(dest, src));
	free(dest);
	
	// src = NULL;
	// dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	// printf("src: %s, ret: %s, dest: %s, funcRet: %s\n", src, ft_strcpy(dest, src), dest, strcpy(dest, src));
}

void	test_strcmp()
{
	printf("---test1---\n");

	char	*s1 = "str1";
	char	*s2 = "str2";
	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%d, %d\n", ft_strcmp(s2, s1), strcmp(s2, s1));

	printf("---test2---\n");

	s1 = "I'm a string";
	s2 = "I'm an other string";
	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%d, %d\n", ft_strcmp(s2, s1), strcmp(s2, s1));

	printf("---test3---\n");

	s1 = "";
	s2 = "I'm an other string";
	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%d, %d\n", ft_strcmp(s2, s1), strcmp(s2, s1));

	printf("---test4---\n");

	s1 = "";
	s2 = "";
	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%d, %d\n", ft_strcmp(s2, s1), strcmp(s2, s1));

	// printf("---test6---\n");

	// s1 = NULL;
	// s2 = NULL;
	// printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	// printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s2, s1));
}

void	test_write()
{
	printf("---test1---\n");
	char	*str = "My First Str\n";
	printf("[write value: %ld, errno value %d]\n", ft_write(1, str, ft_strlen(str)), errno);
	printf("[write value: %ld, errno value %d]\n", write(1, str, ft_strlen(str)), errno);

	printf("---test2---\n");
	usleep(5);

	int	fd = open("./write_read", O_WRONLY);

	printf("[write value: %ld, errno value %d]\n", ft_write(fd, str, ft_strlen(str)), errno);
	printf("[write value: %ld, errno value %d]\n", write(fd, str, ft_strlen(str)), errno);
	close(fd);

	printf("---test3---\n");
	usleep(5);

	printf("[write value: %ld, errno value %d]\n", ft_write(1, str, ft_strlen(str)), errno);
	printf("[write value: %ld, errno value %d]\n", write(1, str, ft_strlen(str)), errno);

	printf("---test4---\n");
	usleep(5);

	fd = open("./write_read", O_RDONLY);
	printf("[write value: %ld, errno value %d]\n", ft_write(fd, str, ft_strlen(str)), errno);
	printf("[write value: %ld, errno value %d]\n", write(fd, str, ft_strlen(str)), errno);
	close(fd);

	printf("---test5---\n");
	printf("[write value: %ld, errno value %d]\n", ft_write(1, str, ft_strlen(str) - 5), errno);
	printf("[write value: %ld, errno value %d]\n", write(1, str, ft_strlen(str) - 5), errno);
}

void	test_read()
{
	int fd = open("./write_read", O_RDONLY);
	char	buff[500];

	bzero(buff, 500);
	printf("read value: %ld, errno: %d\n", read(fd, buff, 12), errno);
	printf("%s\n", buff);
	bzero(buff, 500);
	printf("my read value: %ld, errno: %d\n", ft_read(fd, buff, 12), errno);
	printf("%s\n", buff);

	printf("read value: %ld, errno: %d\n", read(-1, buff, 12), errno);
	printf("%s\n", buff);
	bzero(buff, 500);
	printf("my read value: %ld, errno: %d\n", ft_read(-1, buff, 12), errno);
	printf("%s\n", buff);

	close(fd);
}

void	test_strdup()
{
	char	*str_to_dup = "aaaaa";
	char	*str_dup = NULL;

	printf("---test1---\n");
	str_dup = ft_strdup(str_to_dup);
	printf("str to dup: %s, str dup: %s\n", str_to_dup, str_dup);

	free(str_dup);
}
