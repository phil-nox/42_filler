#include "flr_visual.h"

static inline void	ft_init_player_settext(t_player *p, t_sfml *sfml)
{
	sfText_setString(p->txt_name, p->name);
	sfText_setFont(p->txt_name, sfml->p_font);
	sfText_setCharacterSize(p->txt_name, P_FONT_SZ/2);
	sfText_setFont(p->txt_score, sfml->p_font);
	sfText_setCharacterSize(p->txt_score, P_FONT_SZ/2);
	sfTexture_setRepeated(p->texture, sfTrue);
	sfSprite_setTexture(p->sprite, p->texture, 0);
	p->score = 0;
}

t_player			*ft_init_player(char *img_path, char *sound_path,
																t_sfml *sfml)
{
	char		*s;
	char		*fnd;
	char		*tmp;
	t_player	*p;

	while (get_next_line(0, &s) && *s != '$')
		free(s);
	if (*s != '$')
		return (NULL);
	if (!(p = (t_player *)malloc(sizeof(t_player))) ||
		!(p->texture = sfTexture_createFromFile(img_path, NULL)) ||
		!(p->sound = sfSoundBuffer_createFromFile(sound_path)) ||
		!(p->txt_name = sfText_create()) || !(p->txt_score = sfText_create()) ||
		!(p->sprite = sfSprite_create()))
		return (NULL);
	tmp = s;
	s += 14;
	s = (fnd = ft_strchr(s, '/')) ? ++fnd : ++s;
	fnd = s;
	while (*s && *s != '.')
		s++;
	ft_strlcpy(p->name, fnd, s - fnd + 1 >= NAME_MAX ? NAME_MAX : s - fnd + 1);
	free(tmp);
	ft_init_player_settext(p, sfml);
	return (p);
}

void				ft_sfml_null(t_sfml *sfml)
{
	sfml->p1 = NULL; 
	sfml->p2 = NULL;
	sfml->footer = NULL;
	sfml->title = NULL;
	sfml->window = NULL;
	sfml->render = NULL;
	sfml->render_cur = NULL;
	sfml->sprite = NULL;
	sfml->sprite_cur = NULL;
	sfml->sprite_rndr = NULL;
	sfml->music = NULL;
	sfml->sound = NULL;
	sfml->p_font = NULL;
}
