all:
	cd libft && make all
clean:
	cd libft && make clean
fclean:
	rm -rf server.out
	rm -rf client.out
	cd libft && make fclean
re: fclean all
.PHONY: all clean fclean re
