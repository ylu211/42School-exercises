all :
	@cd libft/ && make all
	@gcc -Wall -Werror -Wextra -Imlx_Linux -lXext -lX11 -lm -lz so_long.c ./libft/libft.a -o so_long

clean :
	@cd libft/ && make clean
	@rm -rf so_long
	@rm -rf so_long.dSYM
	@rm -rf libft.a

fclean : clean
	@cd libft/ && make fclean

re : fclean all
