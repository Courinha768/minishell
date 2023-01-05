#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_command {
	char	*command;
	char	**arguments;
}	t_command;

typedef struct s_prompt {
	char	*user;
	char	*colour;
	char	*init_pwd;
}	t_prompt;

#endif