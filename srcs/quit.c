#include "cub3d.h"

// void	ft_quit_2(t_game *game)
// {
// 	if (game->text.fill_tab_no != NULL)
// 		ft_free2d(game->text.fill_tab_no);
// 	if (game->text.fill_tab_so != NULL)
// 		ft_free2d(game->text.fill_tab_so);
// 	if (game->text.fill_tab_we != NULL)
// 		ft_free2d(game->text.fill_tab_we);
// 	if (game->text.fill_tab_ea != NULL)
// 		ft_free2d(game->text.fill_tab_ea);
// 	if (game->text.colors_no != NULL)
// 		ft_free2d(game->text.colors_no);
// 	if (game->text.colors_so != NULL)
// 		ft_free2d(game->text.colors_so);
// 	if (game->text.colors_we != NULL)
// 		ft_free2d(game->text.colors_we);
// 	if (game->text.colors_ea != NULL)
// 		ft_free2d(game->text.colors_ea);
// }

void	ft_quit(t_game *game)
{
	if (game->fd != 0)
		close(game->fd);
	if (game->tab_fd != NULL)
		ft_free2d(game->tab_fd);
	if (game->map != NULL)
		ft_free2d(game->map);
	//if (game->text.textures_tab != NULL)
		//ft_free2d(game->text.textures_tab);
	if (game->square_map != NULL)
		ft_free2d(game->square_map);
	//ft_quit_2(game);
	exit(1);
}
