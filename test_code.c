#include "./libft/libft.h"

void	print(t_list *l)
{
	char	*a;
	a = l->content;
	printf("%s\n", a);
}

int	main(void)
{
	t_list *a;
	t_list *b;


	ft_lstadd_front(&a, ft_lstnew(ft_strdup("AAA")));
	a->next = 0;
	printf("%d\n", (int)(a->next));

	ft_lstadd_front(&a, ft_lstnew(ft_strdup("BBB")));
	printf("%d\n", (int)(a->next->next));
	ft_lstadd_front(&a, ft_lstnew(ft_strdup("CCC")));


	print(a);
	print(a->next);
	print(a->next->next);

}