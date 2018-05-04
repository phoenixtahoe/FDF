
#include "fdf.h"

void	killer(t_links *head, t_rotation *rot, t_env *all)
{
	t_links *links;

	links = head;
	all->rot->radian_x = all->rot->degree_x * (PI / 180);
	all->rot->radian_y = all->rot->degree_y * (PI / 180);
	all->rot->radian_z = all->rot->degree_z * (PI / 180);
	while (links)
	{
		rot->x0 = (double)links->x;
		rot->y0 = ((links->y) * cos(rot->radian_x)) + (TRANS_Y);
		rot->z0 = (links->altitude * cos(rot->radian_x)) - (TRANS_Z);
		rot->x1 = (rot->x0 * cos(rot->radian_y)) - (rot->z0 * SIN_Y);
		rot->y1 = rot->y0;
		rot->z1 = (rot->z0 * cos(rot->radian_y)) + (rot->x0 * SIN_Y);
		rot->x2 = (rot->x1 * cos(rot->radian_z)) + (rot->y1 * SIN_Z);
		rot->y2 = (rot->y1 * cos(rot->radian_z)) - (rot->x1 * SIN_Z);
		rot->x2 *= (WIDTH - 320) / all->x_max;
		rot->y2 *= (HEIGHT - 300) / all->y_max;
		rot->x2 += 150;
		rot->y2 += 150;
		links->tru_y = rot->y2;
		links->tru_x = rot->x2;
		links = links->next;
	}
}


t_plc	*find_points(t_cam *cam, t_plc *current)
{
	t_rot	*alg;
	t_plc	*cur;

	cur = current;
	alg = (t_rot *)malloc(sizeof(t_rot));
	alg->x0 = cur->x;
	alg->y0 = (cur->y * cos(cam->angle_x)) + (cur->z * sin(cam->angle_x));
	alg->z0 = (cur->z * cos(cam->angle_x)) - (cur->y * sin(cam->angle_x));
	alg->x1 = (alg->x0 * cos(cam->angle_y)) - (alg->z0 * sin(cam->angle_y));
	alg->y1 = alg->y0;
	alg->z1 = (alg->z0 * cos(cam->angle_y)) + (alg->x0 * sin(cam->angle_y));
	alg->x2 = (alg->x1 * cos(cam->angle_z)) + (alg->y1 * sin(cam->angle_z));
	alg->y2 = (alg->y1 * cos(cam->angle_z)) - (alg->x1 * sin(cam->angle_z));
	alg->x2 *= 10;
	alg->y2 *= 10;
	alg->x2 += 150;
	alg->y2 += 150;
	cur->x_place = (int)alg->x2;
	cur->y_place = (int)alg->y2;
	free(alg);
	return (cur);
}
