#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char * str);
char	*ft_strcpy(char *dest, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_write(int fd, char const *str, size_t len);

void	test_strlen();
void	test_strcpy();
void	test_strcmp();

int	main(void)
{

	ft_write(1, "Hello World", ft_strlen("Hello World"));

	printf("\n\n----STRLEN----\n");
	test_strlen();
	printf("\n\n----STRCPY----\n");
	test_strcpy();
	printf("\n\n----STRCMP----\n");
	test_strcmp();

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