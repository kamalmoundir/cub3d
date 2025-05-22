
#include "get_next_line.h"


int ft_strlen(char *str)
{
  int i=0;
  while(str[i])
  i++;
  return i;
}

char	*ft_strdup(char *str)
{
	char *result;
	int i =0;
	result= malloc((ft_strlen(str)+1)*sizeof(str));
	if(!result) return NULL;
	while(str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i]='\0';
	return result;
}


char *get_next_line(int fd)
{
	char line[7000000];
	static char buffer[BUFFER_SIZE];
	static int b_pos =0;
	static int b_read = 0;
	int i =0;
	if(fd < 0 || BUFFER_SIZE <= 0)
	return NULL;
	while(1)
	{
		if(b_pos >= b_read)
		{
			b_read= read(fd, buffer, BUFFER_SIZE);
			if(b_read <= 0) break;
			b_pos = 0;
		}
		line[i++] = buffer[b_pos ++];
		if(line[i -1] == '\n') 
		break;
	} 
	if(i == 0) return NULL;
	line[i]= '\0';
	return ft_strdup(line);
}

/*
int main(void)
{
	char *line;
	int fd = open("test.txt",O_RDONLY);
	if(fd < 0) return -1;
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		free(line);
	
	}

return 0;
}*/






