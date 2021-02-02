/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:57:55 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/31 22:14:02 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define K_UP 65362
#define K_DOWN 65364
#define K_LEFT 65361
#define K_RIGHT 65363

void *g_mlx_ptr;
void *g_win_ptr;
char **g_map;
int g_width;
int g_height;
//design morba3 (g_map 2D)
char **g_line;
int g_y_len;
int g_x;
int g_y;
int g_k = 0;
int g_remaind = 50;
int g_none = 1;
//g_wall
int g_wall = 50;
int swiitch = 1;
// Player movement
double g_X_player;
double g_Y_player;   
double g_rotationAngle = 0;
int g_j;
double g_rotation;

double g_rot;
//DATA COLLECTION FOR IMAGE 
int g_a;
int g_b;
int g_c;
int *g_data;
void *g_image;


//int g_k = 0;
//Remainding the old position of g_x && g_y Player
int g_Y_remainder;
int g_X_remainder;
//Ray Intersaction && steps
 double g_xintercept;
 double g_yintercept;

 double g_ystep;
 double g_xstep;

    int g_remain_argc;
 double g_nextHoriX;
 double g_nextHoriY;
 //g_check if g_wall is hited
 double g_wallHoriHit;
 double g_wallVertHit;
 double g_HorizwallHitX;
 double g_HorizwallHitY;
 double g_VertwallHitX;
 double g_VertwallHitY;
 

 int g_color_c;
 int g_color_f;


 double g_WallHitX;
 double g_WallHitY;
// Ray g_direction 
int g_rayFacingDown;
int g_rayFacingUp;
int g_rayFacingRight;
int g_rayFacingLeft;

// g_distance between Vertical && Horizontal
double g_HorzHitDistance;
double g_VertHitDistance;
double g_distance;
double g_wasHitVertical;
//key g_up / g_down
int g_up;
int g_down;
int g_left;
int g_right;
int g_a;
int g_d;
//Rendering 3D g_map
double g_correctWallDistance;
double g_distanceProjectionPlan;
double g_wallStripHeight;
//color
unsigned int g_DarkColor;
//bullshit variables for data (LEARN LATER)
int g_tab[20];
void *g_img1;
unsigned int *g_textu0;
unsigned int *g_textu1;
unsigned int *g_textu2;
unsigned int *g_textu3;
unsigned int *g_textu4;
double g_xOfsset;
double g_yOffset;
int g_mhah;
double g_pourcent;
int g_f;
int g_rightleftupdown;
int g_N;
    int g_sprite;
int g_sprite_indicator;

//// SAVE g_x AND g_y CENTER;
int g_center_x;
int g_center_y;

char **g_check;
////////////
int g_sprite_number;
int g_dontenteragain;

typedef struct s_sprite
{
double g_wallVertHit;
double g_VertwallHitX;
double g_VertwallHitY;
double g_wallHoriHit;
double g_HorizwallHitX;
double g_HorizwallHitY;
double g_mhah;
double g_wasHitVertical;
double g_VertHitDistance;
double g_HorzHitDistance;
double g_WallHitX;
double g_WallHitY;
double xcentre;
double ycentre;
double g_distance;
double g_rotation;
double g_x;
double g_y;
double xoff;
}               t_sprite;
t_sprite g_sprites[1000],g_sprites_temp;

typedef struct s_spritefinder
{
    double g_point_x;
    double g_point_y;
    double g_point_distance_x;
    double g_point_distance_y;
    double new_angle;
    double x_offset;
    double g_angle_sghira;
    double angle_kbira;
    double g_angle_wanted;
    double g_angle_jdida;
    double g_center_x;
    double g_center_y;
}               t_spritefinder;
t_spritefinder g_finder;

int g_sprite_count;
typedef struct s_mapcount
{
    int mapx;
    int strx;
    int linex;
    int lenghtx;
}               t_mapcount;
t_mapcount g_mapcount[1000];

int inde;

typedef struct s_direction
{
    int we;
    int ea;
    int su;
    int no;
    int r;
    int s;
    int f;
    int c;
}               t_direction;
t_direction g_direction;

typedef struct s_screenmap
{
    char *header;
    short int bit_count;
    unsigned int g_width;
    unsigned int g_height;
    int width_in_byte;
    unsigned int image_size;
    unsigned int size_header;
    unsigned int offset_bits;
    int file_size;
    short int planes;
    int fd;
    char *img;

}               t_screenmap;
t_screenmap g_screenmap;
char *g_chorfi;
char *g_mapo;
int g_t = 0;
int g_empty_line;
int g_fd;
int g_indexo;
double g_angle_wanted;
double g_angle_sghira;
double g_point_x;
double g_point_y;
double g_point_distance_x;
double g_point_distance_y;
double g_angle_jdida;
int g_count;
int g_calcul_parameter;

void ft_design_morba3_2(int g_j, int i, int y_copy)
{
    if ((g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E' || g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S' ) && g_none == 1)
    {
        g_X_player = i * 50 + 25;
        g_Y_player = g_j * 50 + 25;
        g_none++;
    }
    g_y = y_copy;
    g_x = g_x + g_wall;
}
int     design_morba3(int i, unsigned int color, int g_j)
{
    int save;
    int y_copy;

    y_copy = g_y;
    save = g_k;
    while (g_k < g_x)
    {
        g_k++;
        if (g_k == g_x)
        {
            g_k = save;
            g_y = g_y - 1;
            if (g_y == g_remaind - g_wall - 1)
            {
                g_k += g_wall;
                break;
            }
        }
    }
    ft_design_morba3_2(g_j,i,y_copy);
    return g_k;
}

void	sorting(void)
{
	int indd;
	int g_j;

	indd = 1;
	g_j = 0;
	while (indd < g_sprite_count)
	{
		while (g_j < g_sprite_count - indd)
		{
			if (g_sprites[g_j].g_distance > g_sprites[g_j + 1].g_distance)
			{
				g_sprites_temp = g_sprites[g_j];
				g_sprites[g_j] = g_sprites[g_j + 1];
				g_sprites[g_j + 1] =g_sprites_temp;
			}
			g_j++;
		}
		g_j = 0;
		indd++;
	}
    g_sprites[g_sprite_count].g_distance = '\0';
}
void ft_directions(int g_j,int i)
{
    if (g_line[g_j][i] == 'N')
        g_rotationAngle = 3 * (M_PI)/2;
    else if (g_line[g_j][i] == 'S')
        g_rotationAngle = M_PI / 2;
    else if (g_line[g_j][i] == 'W')
        g_rotationAngle = 0;
    else if (g_line[g_j][i] == 'E')
        g_rotationAngle = M_PI;

}

void ft_morba3_2(int color, int i, int g_j)
{
    color = 0xFFFFFF;
    design_morba3(i, color, g_j);
    if(g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E' || g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S')
    {
        g_N++;
        ft_directions(g_j,i);
    }
}
void ft_morba3_3(int color, int i, int g_j)
{
     if (g_line[g_j][i] == '1'  || g_line[g_j][i] == ' ')
        {
            color = 0x6f665d;
            design_morba3(i, color, g_j);
        }
        else if(g_line[g_j][i] == '0' || g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E' || g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S')
            ft_morba3_2(color,i,g_j);
        else if(g_line[g_j][i] == '2')
        {
            color = 0xdcd3f6;
            design_morba3(i, color, g_j);
            g_sprite_number++;
        }
}
void ft_morba3()
{
    int i;
    unsigned int color;
    g_sprite_number = 0;

    g_N = 0;
    i = 0;
    g_j = 0;
    while(g_j < inde && g_line[g_j][i])
    {
        ft_morba3_3(color, i , g_j);
        i++;
        if (g_line[g_j][i] == '\0')
        {
            i = 0;
            if (g_j < inde)
            {
                g_j++;
                g_y = g_y + g_wall;
                g_x = g_wall;
                g_remaind = g_remaind + g_wall;
                g_k = 0;
            }
            else
                break;
        }    
    }
}
int abs (int n)
{ 
    return ( (n>0) ? n : ( n * (-1))); 
}

unsigned int    *ft_texture(char     *file, unsigned int *texture)
{
    g_f = 0;
    g_img1 = mlx_xpm_file_to_image(g_mlx_ptr,file,&g_tab[g_f],&g_tab[g_f + 1]);
    if ((int)(g_img1) == 0)
    {
        ft_putstr("INVALID g_map");
        exit (0);
    }
    texture = (unsigned int *)mlx_get_data_addr(g_img1,&g_tab[g_f + 2],&g_tab[g_f + 3], &g_tab[g_f + 4]);
    g_f = g_f + 5;
    return texture;
}

unsigned int    convert_rgb(int r, int g, int b)
{
    unsigned int color;
    color = r;
    color = (color << 8) + g;
    color = (color << 8) + b;
    return (color);
} 
unsigned int    check_opacity(unsigned int hexcolor)
{
    double red;
    double green;
    double blue;
    double oppasity;

    oppasity = (g_distance / 1600) > 1 ? 1 : 1 - (g_distance / 1600) ;
    red = ((hexcolor >> 16) & 255) * oppasity;
    green = ((hexcolor >> 8) & 255) * oppasity;
    blue = (hexcolor & 255) * oppasity;
    return (convert_rgb(red, green, blue));
}

int wall_checker()
{
    int X_pos;
    int Y_pos;

    X_pos = g_nextHoriX / g_wall;
    Y_pos = g_nextHoriY / g_wall;
    if ((X_pos >= 0 &&  X_pos <= g_mapcount[0].lenghtx) && (Y_pos >= 0 &&  Y_pos < inde))
    {

        if (g_line[Y_pos][X_pos] == '2')
        {
            g_sprite = 1;
            g_sprite_indicator = 1;
        }
        if (g_line[Y_pos][X_pos] == '1')
            return (1);
        
    }
    return 0;

}
 int wall_collision()
{
    int X_pos;
    int Y_pos;

    X_pos = g_X_remainder / g_wall;
    Y_pos = g_Y_remainder / g_wall;
    if (g_line[Y_pos][X_pos] == '1' || g_line[Y_pos][X_pos] == '2')
    {
        return (1);
    }
    return 0;

}

double ft_normalize_angle(double angle)
{
    while (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    while (angle < 0)
        angle += (2 * M_PI);
    return (angle);
}

void ft_nizar_calcul()
{
     if(g_mhah)
    {
        if (g_rayFacingDown)
        {
           g_rightleftupdown = 1;
        }
        else if (g_rayFacingUp)
        {
          g_rightleftupdown = 2;
        }
    }
    else if(!g_mhah)
    {
        if (g_rayFacingLeft)
        {
           g_rightleftupdown = 3;
        }
        else if (g_rayFacingRight)
        {
           g_rightleftupdown = 4;
        }
    }
}

void ft_render_sprite(int g_j, int i , int start)
{
     g_pourcent = (g_j - start) / g_wallStripHeight;
    g_yOffset = 50 * g_pourcent;
        
    if(check_opacity(g_textu0[(int)g_yOffset * 50 + (int)g_sprites[g_count].xoff]) != 0x000000)
    g_data[g_width * g_j + i] = check_opacity(g_textu0[(int)g_yOffset * 50 + (int)g_sprites[g_count].xoff]);
}
void render_column1(int i, int g_count)
{
        int start;
    int g_j;
    g_j = 0;
    start = (g_height / 2) - (g_wallStripHeight / 2);
    
    while(g_j < start)
    {
        g_data[g_width * g_j + i] = g_color_c;//+ pc;
         g_j++;
    }
    
    while(g_j < start + g_wallStripHeight && g_j < g_height)
    {
       ft_render_sprite(g_j , i, start);
        g_j++;
    }
    while(g_j < g_height)
    {
         g_data[g_width * g_j + i] = g_color_f;
         g_j++;
    }

}

void ft_render_walls(int g_j , int i, int start)
{
    g_pourcent = (g_j - start) / g_wallStripHeight;
    g_yOffset = 50 * g_pourcent;
    if(g_rightleftupdown == 1)
    {
        g_data[g_width * g_j + i] = check_opacity(g_textu4[(int)g_yOffset * 50 + (int)g_xOfsset]);
    }
    else if(g_rightleftupdown == 2)
    {
        g_data[g_width * g_j + i] = check_opacity(g_textu1[(int)g_yOffset * 50 + (int)g_xOfsset]);
    }
    else if(g_rightleftupdown == 3)
    {
        g_data[g_width * g_j + i] = check_opacity(g_textu2[(int)g_yOffset * 50 + (int)g_xOfsset]);
    }
    else if(g_rightleftupdown == 4)
    {
        g_data[g_width * g_j + i] = check_opacity(g_textu3[(int)g_yOffset * 50 + (int)g_xOfsset]);
    }
}
void render_colomn(int i)
{
    int start;
    int g_j;
    g_j = 0;
    start = (g_height / 2) - (g_wallStripHeight / 2);
    
    while(g_j < start)
    {
        g_data[g_width * g_j + i] = g_color_c;
         g_j++;
    }
    while(g_j < start + g_wallStripHeight && g_j < g_height)
    {
        ft_render_walls(g_j,i,start);      
        g_j++;
    }
    while(g_j < g_height)
    {
         g_data[g_width * g_j + i] = g_color_f;
         g_j++;
    }
    
}

void render_map3D(int i)
{
    g_correctWallDistance = g_distance * cos(g_rotation - g_rotationAngle);
    g_distanceProjectionPlan = (g_width / 2) / tan(rad(45) / 2);
    g_wallStripHeight = (50 / g_correctWallDistance) * g_distanceProjectionPlan;
    g_xOfsset = g_mhah == 1 ? fmod(g_WallHitX,50) : fmod(g_WallHitY,50);
           ft_nizar_calcul();
        if(swiitch == 1)
            render_colomn(i);
}
void BubbleSort1(int g_sprite_count)
{
    int i, g_j, temp;
    for (i = 0; i < (g_sprite_count - 1); ++i)
    {
        for (g_j = 0; g_j < g_sprite_count - 1 - i; ++g_j )
        {
            if (g_sprites[g_j].g_distance > g_sprites[g_j + 1].g_distance)
            {
                temp = g_sprites[g_j + 1].g_distance;
                g_sprites[g_j + 1].g_distance = g_sprites[g_j].g_distance ;
                g_sprites[g_j].g_distance = temp;
            }
        }
    }
}
int ray_Direction()
{
    g_rayFacingDown = 0;
    g_rayFacingUp = 0;
    g_rayFacingRight = 0;
    g_rayFacingLeft = 0;

    g_rayFacingDown = (deg(g_rotation) > 0 && deg(g_rotation) < 180) ? 1 : 0;
    g_rayFacingUp = !(g_rayFacingDown) ? 1 : 0;

    g_rayFacingRight = ((deg(g_rotation) > 0 && (deg(g_rotation) < 90)) || (deg(g_rotation) > 270 && (deg(g_rotation) < 360))) ? 1 : 0;
    g_rayFacingLeft = !(g_rayFacingRight) ? 1 : 0;
  
     return 0;

}
double Distance_between_HorVer(int x1,int y1, int x2, int y2)
{
    return sqrtf(powf((x2 - x1),2) + powf((y2 - y1),2));
}

void ft_intial_variable()
{
    g_WallHitX = 0;
    g_WallHitY = 0;
    g_distance = 0;
    g_sprite = 0;
    g_sprite_indicator = 0;
    g_wallHoriHit = 0;
    ray_Direction();
}
void ft_find_intersec()
{
    int g_check;

    while(g_nextHoriX >= 0 && g_nextHoriX < g_mapcount[0].lenghtx * 50 && g_nextHoriY >= 0 && g_nextHoriY < inde * 50)
    {
        g_sprite = 0;
        g_check = wall_checker();
        if(g_sprite == 1)
        {
            g_sprites[g_sprite_count].xcentre = ((int)g_nextHoriX / 50 * 50) + 25;
            g_sprites[g_sprite_count].ycentre = ((int)g_nextHoriY / 50 * 50) + 25;
            g_sprites[g_sprite_count].g_x = g_nextHoriX;
            g_sprites[g_sprite_count].g_y = g_nextHoriY;
            g_sprites[g_sprite_count].g_distance =  sqrtf(powf(g_Y_player - g_sprites[g_sprite_count].g_y,2) + powf(g_X_player - g_sprites[g_sprite_count].g_x,2));
            g_sprites[g_sprite_count].g_rotation = atan2(g_Y_player - g_nextHoriY,  g_X_player - g_nextHoriX);
            g_sprite_count++;

        }
        if (g_check == 1)
        {
            g_wallHoriHit = 1;
            g_HorizwallHitX = g_nextHoriX;
            g_HorizwallHitY = g_nextHoriY;
            break;
        }
        else
        {
            g_nextHoriX += g_xstep;
            g_nextHoriY += g_ystep; 
        }
    }
}
void ft_yx_intercept()
{
    ft_intial_variable();
    g_yintercept = (int)(g_Y_player / g_wall) * g_wall;
    g_yintercept += g_rayFacingDown ? g_wall : 0;
    g_xintercept = g_X_player + (g_yintercept - g_Y_player) / tan(g_rotation);

    g_ystep = g_wall;
    g_ystep *= g_rayFacingUp ? -1 : 1;

    g_xstep = g_ystep / tan(g_rotation);

    g_nextHoriX = g_xintercept;
    g_nextHoriY = g_yintercept;

    if(g_rayFacingUp)
        g_nextHoriY--;
}
void ft_find_intercept1()
{
    int g_check;

    while(g_nextHoriX >= 0 && g_nextHoriX < g_mapcount[0].lenghtx * 50 && g_nextHoriY >= 0 && g_nextHoriY < inde * 50)
    {
        g_sprite = 0;
        g_check = wall_checker();
        if(g_sprite == 1)
        {
            g_sprites[g_sprite_count].xcentre = ((int)g_nextHoriX / 50 * 50) + 25;
            g_sprites[g_sprite_count].ycentre = ((int)g_nextHoriY / 50 * 50) + 25;
            g_sprites[g_sprite_count].g_rotation = atan2(g_Y_player - g_nextHoriY,  g_X_player - g_nextHoriX);
            g_sprites[g_sprite_count].g_x = g_nextHoriX;
            g_sprites[g_sprite_count].g_y = g_nextHoriY;
            g_sprites[g_sprite_count].g_distance =  sqrtf(powf(g_Y_player - g_sprites[g_sprite_count].g_y,2) + powf(g_X_player - g_sprites[g_sprite_count].g_x,2));
            g_sprite_count++;
        }
        if (g_check == 1)
        {
            g_wallVertHit = 1;
            g_VertwallHitX = g_nextHoriX;
            g_VertwallHitY = g_nextHoriY;
            break;
        }
        else
        {
            g_nextHoriX += g_xstep;
            g_nextHoriY += g_ystep; 
        }

    }
}
void ft_yx_intercept1()
{
     g_wallVertHit = 0;
    ray_Direction();
    g_xintercept = (int)(g_X_player / g_wall) * g_wall;
    g_xintercept += g_rayFacingRight ? g_wall : 0;
    g_yintercept = g_Y_player - (g_X_player - g_xintercept) * tan(g_rotation);

    g_xstep = g_wall;
    g_xstep *= g_rayFacingLeft ? -1 : 1;
    g_ystep = g_xstep * tan(g_rotation);
   

    g_nextHoriX = g_xintercept;
    g_nextHoriY = g_yintercept;

    if(g_rayFacingLeft)
        g_nextHoriX--;
}
int ft_cast_ray()
{
    int g_check;

    ft_yx_intercept();
    ft_find_intersec();
    ft_yx_intercept1();
    ft_find_intercept1();
    g_HorzHitDistance = (g_wallHoriHit) ? Distance_between_HorVer(g_X_player , g_Y_player, g_HorizwallHitX,g_HorizwallHitY) : MAX_INT;
    g_VertHitDistance = (g_wallVertHit) ? Distance_between_HorVer(g_X_player , g_Y_player, g_VertwallHitX,g_VertwallHitY) : MAX_INT;
    g_WallHitX = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorizwallHitX : g_VertwallHitX;
    g_WallHitY = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorizwallHitY : g_VertwallHitY;
    g_distance = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorzHitDistance : g_VertHitDistance;
    g_mhah = g_distance == g_HorzHitDistance ? 1 : 0;
    g_wasHitVertical = (g_VertHitDistance) < (g_HorzHitDistance);
    g_DarkColor = 0x006400;
    g_DarkColor = check_opacity(g_DarkColor);
   return 0;
}

int mlx_key_press(int key)
{
    if(key == 123)
        g_left = 1;
    if (key == 124)
        g_right = 1;
    if (key == 125)
        g_down = 1;
    if (key == 126)
        g_up = 1;
    if (key == 0)
        g_a = 1;
    if (key == 2)
        g_d = 1;
    if (key == 53)
        exit(0);
    return 0;
}
int key_release(int key)
{
    if(key == 123)
        g_left = 0;
    if(key == 124)
        g_right = 0;
    if (key == 125)
        g_down = 0;
    if (key == 126)
        g_up = 0;
    if (key == 0)
        g_a = 0;
    if (key == 2)
        g_d = 0;
    return 0;
}

void ft_collect_info_sprite()
{
    g_angle_sghira = atan2(g_Y_player - g_sprites[g_count].ycentre, g_X_player - g_sprites[g_count].xcentre);
    g_angle_wanted = g_sprites[g_count].g_rotation - g_angle_sghira;

    g_point_x = g_X_player + (g_sprites[g_count].xcentre - g_X_player) * cos(g_angle_wanted) - (g_sprites[g_count].ycentre - g_Y_player) * sin(g_angle_wanted);
    g_point_y = g_Y_player + (g_sprites[g_count].xcentre - g_X_player) * sin(g_angle_wanted) + (g_sprites[g_count].ycentre - g_Y_player) * cos(g_angle_wanted);
    g_angle_jdida = M_PI / 2 + g_angle_sghira;
    g_point_distance_x = g_sprites[g_count].xcentre + (50 / 2) * cos(g_angle_jdida);
    g_point_distance_y = g_sprites[g_count].ycentre + (50 / 2) * sin(g_angle_jdida);
    g_sprites[g_count].xoff = sqrtf(powf(g_point_distance_y - g_point_y,2) + powf(g_point_distance_x - g_point_x,2));
    double diss = sqrtf(powf(g_point_x - g_sprites[g_count].xcentre,2) + powf(g_point_y - g_sprites[g_count].ycentre,2));
    if (diss > 25)
        g_sprites[g_count].xoff = 0;
    g_correctWallDistance = sqrtf(powf((g_Y_player - g_sprites[g_count].ycentre), 2) + powf((g_X_player - g_sprites[g_count].xcentre), 2));
}
void render_sprite(int i)
{
    if (g_sprite_indicator == 1)
    {
        g_count = g_sprite_count - 1;
        while (g_count >= 0)
        {
            ft_collect_info_sprite();
            g_distanceProjectionPlan = (g_width / 2) / tan(rad(45) / 2); 
            g_wallStripHeight = (50 / g_correctWallDistance) * g_distanceProjectionPlan;
            ft_nizar_calcul();
            if(swiitch == 1)
            {
                if (g_sprites[g_count].g_distance < g_distance)
                    render_column1(i,g_count);
            }  
            g_count--;
        }
    }
}
void ft_info_render(int i)
{
           if (g_rotation > 2 * M_PI || g_rotation < 0)
            g_rotation = ft_normalize_angle(g_rotation);
        ft_cast_ray();

        g_rotation += g_rot;
        render_map3D(i);
        sorting();
        if(g_sprite_indicator == 1 )
        {
                if (g_sprites[0].g_distance < g_distance)
                {
                    render_sprite(i);
                }
             g_sprite_count = 0;
        }
}
void ft_mouvement_up()
{
    int p;

     g_X_remainder = g_X_player;
            g_Y_remainder = g_Y_player;
            g_X_remainder += cos(g_rotationAngle) * 10;
            g_Y_remainder += sin(g_rotationAngle) * 10;
            p = wall_collision();
            if (p != 1)
            {
                g_X_player += cos(g_rotationAngle) * 10;
                g_Y_player += sin(g_rotationAngle) * 10;
            } 
}
void ft_mouvement_down()
{
    int p;

     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle) * 10;
        g_Y_remainder -= sin(g_rotationAngle) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle) * 10;
            g_Y_player -= sin(g_rotationAngle) * 10;
        } 
}
void ft_mouvement_left()
{
    int p;
     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle + M_PI / 2) * 10;
        g_Y_remainder -= sin(g_rotationAngle + M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle + M_PI / 2) * 10;
            g_Y_player -= sin(g_rotationAngle + M_PI / 2) * 10;
        }
}
void ft_mouvement_right()
{
    int p;
     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle - M_PI / 2) * 10;
        g_Y_remainder -= sin(g_rotationAngle - M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle - M_PI / 2) * 10;
            g_Y_player -= sin(g_rotationAngle - M_PI / 2) * 10;
        }
}
void ft_all_mouvement()
{
    if (strcmp(g_chorfi,"--save") == 0)
        screenshot();
    if(g_down == 1)
        ft_mouvement_down();
    else if (g_up == 1)
        ft_mouvement_up();
    if(g_d == 1)
        ft_mouvement_right();
    if(g_a == 1)
        ft_mouvement_left();
    if (g_left == 1)
         g_rotationAngle -= rad(3);
    if (g_right == 1)
         g_rotationAngle += rad(3);
}
int deal_key(void)
{
    int i;
    g_x = g_wall;
    g_y = g_wall;
    g_k = 0;
    i = 0;
    g_rotation = g_rotationAngle - M_PI / 8;
    g_sprite_count = 0;
    if (g_rotationAngle > 2 * M_PI || g_rotationAngle < 0)
            g_rotationAngle = ft_normalize_angle(g_rotationAngle);
    while(i < g_width)
    {
        ft_info_render(i);
        i++;
    }
    ft_all_mouvement();
    return 0;
}

int    ft_exit()
{
    mlx_destroy_window(g_mlx_ptr,g_win_ptr);
    exit(0);
}

int loop_key()
{
    if (strcmp(g_chorfi,"--save") != 0)
    {
        mlx_hook(g_win_ptr,2,0,mlx_key_press,0);
        mlx_hook(g_win_ptr,3,0,key_release,0);
        mlx_hook(g_win_ptr,17,0L,ft_exit,0);
    }
    deal_key();
    if(swiitch == 1)
        mlx_put_image_to_window(g_mlx_ptr,g_win_ptr,g_image,0,0);
    return 0; 
}
int ft_last_line()
{
    int i = 0;
    while(strchr("1 ",g_line[inde][i]))
    {
        i++;
        if(g_line[inde][i] == ' ' && g_line[inde - 1][i] == '0')
            break;
        if(g_line[inde][i] == '\0')
            return(1);
    }
    ft_putstr("errormap\n");
    exit(0);
    return(0);
}

int ft_first_line()
{
    int i = 0;
    while(strchr("1 ",g_map[g_y_len][i]))
    {
        i++;
        if(g_map[g_y_len][i] == '\0')
            return(1);
    }
    return(0);
}
int ft_valid_map()
{
    int i = 0;

    while(strchr("012NWES ",g_map[g_y_len][i]))
    {
        i++;
        if(g_map[g_y_len][i] == '\0')
            return(1);
    }
    return(0);
}

void ft_check_zero1(int g_j, int i)
{
    if(g_line[g_j][0] == '0' || g_line[g_j][i + 1] == ' ' || g_line[g_j][i - 1] == ' ' || g_line[g_j - 1][i] == ' ' || g_line[g_j][i + 1] == '\0' || g_line[g_j + 1][i] == ' ')
    {
        ft_putstr("error in g_map");
        exit (0);
    }
}
void ft_check_sprite(int g_j, int i)
{
     if(g_line[g_j][i] == '2' && (g_line[g_j][i + 1] == ' ' || g_line[g_j][i - 1] == ' ' || g_line[g_j + 1][i] == ' '|| g_line[g_j - 1][i] == ' '))
    {
        ft_putstr("error in g_map");
        exit (0);
    } 
}
void ft_check_zero()
{
    int i;
    int g_j;

    i = 0;
    g_j = 0;
    while(g_line[g_j][i] && inde > g_j)
    {
        if(g_line[g_j][i] == '0')
            ft_check_zero1(g_j ,i);
        else if(g_line[g_j][i] == '2')
            ft_check_sprite(g_j, i);
        i++;
        if (g_line[g_j][i] == '\0' && inde > g_j)
        {
            i = 0;
            if (g_line[g_j + 1] == NULL)
                break;
            else
                g_j++;
        }
    }
}


void BubbleSort(int inde)
{
    int i, g_j, temp;
    for (i = 0; i < (inde - 1); ++i)
    {
        for (g_j = 0; g_j < inde - 1 - i; ++g_j )
        {
            if (g_mapcount[g_j].lenghtx < g_mapcount[g_j+1].lenghtx)
            {
                temp = g_mapcount[g_j+1].lenghtx;
                g_mapcount[g_j+1].lenghtx = g_mapcount[g_j].lenghtx;
                g_mapcount[g_j].lenghtx = temp;
            }
        }
    }
}
void fd_tab2()
{
    int c = 0;
    
    c = ft_valid_map();
  
        if(c == 1)
        g_line[inde] = ft_strdup(g_map[g_y_len]);
        else
        {
            ft_putstr("error in g_map");
            exit(0);
        }  
}
int check_valid(char *g_check)
{
    if(strcmp(strrchr(g_check ,'.'),".xpm") == 0)
        return (1);
    return(0);
}
void ft_check_weird()
{
    int i = 0;
    while(g_check[1][i])
    {
        if(!((g_check[1][i] >= '0' && g_check[1][i] <= '9') || g_check[1][i] == ','))
        {
            ft_putstr("weirdooo g_a khey malaoui o yahya 39t bikom");
            exit(0);
        }
        i++;
    }
}

void ft_check_virg()
{
    int i;

    i = 0;
    while(g_check[1][i])
    {
        if(g_check[1][i] == ',')
            g_split++;
        i++;
    }
}
void ft_check_resolution()
{
    if(g_width > 2560 || g_height > 1440)
    {
        if (g_width > 2560)
            g_width = 2560;
        else
            g_height = 1440;
        
    }
}
void ft_check_NO()
{
    g_direction.no++;
    if(counter != 2)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_f = check_valid(g_check[1]);
    if (g_f == 1)
        g_textu1 = ft_texture(g_check[1], g_textu1);
    if (g_f == 0)
    {
        ft_putstr("invalidmap\n");
        exit (0);
    }
    g_calcul_parameter++;
}
void ft_check_R()
{
    g_direction.r++;
    if(counter != 3)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_width = ft_atoi_w(g_check[1]);
    g_height = ft_atoi_h(g_check[2]);
    if(g_width > 2550 || g_height > 1440)
    {
        if (g_width > 2550)
            g_width = 2550;
        if (g_height > 1440)
            g_height = 1440;
    }
    if(g_width < 0 || g_height < 0)
    {
        ft_putstr("invalid resolution\n");
        exit (0);
    }
    ft_check_resolution();
    g_calcul_parameter++;
}
void ft_check_WE()
{
    g_direction.we++;
    if(counter != 2)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_f = check_valid(g_check[1]);
    if (g_f == 1)
        g_textu2 = ft_texture(g_check[1], g_textu2);
    if (g_f == 0)
    {
        ft_putstr("invalidmap\n");
        exit (0);
    }
    g_calcul_parameter++;
}

void ft_check_SO()
{
     g_direction.su++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         g_f = check_valid(g_check[1]);
         if (g_f == 1)
            g_textu3 = ft_texture(g_check[1], g_textu3);
            if (g_f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
       
        g_calcul_parameter++;
}
void ft_check_EA()
{
     g_direction.ea++;
    if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         g_f = check_valid(g_check[1]);
         if (g_f == 1)
            g_textu4 = ft_texture(g_check[1], g_textu4);
            if (g_f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
        g_calcul_parameter++;
}
void ft_check_S()
{
    g_direction.s++;
    if(counter != 2)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_f = check_valid(g_check[1]);
    if (g_f == 1)
        g_textu0 = ft_texture(g_check[1], g_textu0);
    if (g_f == 0)
    {
        ft_putstr("invalidmap\n");
        exit (0);
    }
    g_calcul_parameter++;
}

void ft_check_C()
{
    char *tmp;
    
    g_direction.c++;
    if(counter != 2 )
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    ft_check_weird();
    ft_check_virg();
    tmp = ft_strdup(g_check[1]);
    free(g_check[0]);
    free(g_check[1]);
    free(g_check);
    if(g_split != 2)
    {
        ft_putstr("error in parameter");
        exit (0);
    }
    g_check = ft_split(tmp,',');
    free(tmp);
    if (counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0 || ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0 || ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
    {
        ft_putstr("INVALID g_map\n");
        exit (0);
    }
    g_color_c = convert_rgb(ft_atoi(g_check[0]), ft_atoi(g_check[1]), ft_atoi(g_check[2]));
    g_calcul_parameter++;
}
void ft_check_F()
{
    char *tmp;

     g_direction.f++;
     ft_check_weird();
     if(counter != 2 )
     {
         ft_putstr("missing parameter");
         exit(0);
    }
    ft_check_virg();
    if(g_split != 2)
    {
        ft_putstr("error in parameter");
        exit (0);
    }
    tmp = ft_strdup(g_check[1]);
    free(g_check[0]);
    free(g_check[1]);
    free(g_check);
    g_check = ft_split(tmp,',');
    free(tmp);
    if (counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0 || ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0 || ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
    {
        ft_putstr("INVALID g_map\n");
        exit (0);
    }
    g_color_f = convert_rgb(ft_atoi(g_check[0]), ft_atoi(g_check[1]), ft_atoi(g_check[2]));
    g_calcul_parameter++;
}
void ft_check_errormap(int p)
{
    if(strchr("1 0", g_map[g_y_len][0]) && g_mapcount[g_t].mapx > 0)
    {
        ft_return();
        ft_switch_space();
        if(g_dontenteragain == 10 && g_mapcount[g_t - 1].mapx == 0)
        {
            ft_putstr("invalid mapox");
            exit(0);
        }         
        if (g_dontenteragain == 0)
        {
            g_k = ft_first_line();
            if (g_k == 0)
            {
                ft_putstr("invalid mape");
                exit(0);
            }
            else if (g_k == 1)
            {
                g_line[inde] = ft_strdup(g_map[g_y_len]);
                g_dontenteragain = 10;
            }
        }
        else
            fd_tab2();
        g_mapcount[p].linex = ft_strlen(g_line[inde]);
        inde++;
        p++;
    }
}
void ft_check(int g_t)
{
    static int p = 0;
   
if(*g_check != NULL)
{
     if (strcmp(g_check[0],"R") == 0)
        ft_check_R();
     else if(strcmp(g_check[0],"NO") == 0)
         ft_check_NO();
     else if(strcmp(g_check[0],"WE") == 0)
         ft_check_WE();
     else if(strcmp(g_check[0],"SO") == 0)
         ft_check_SO();
     else if(strcmp(g_check[0],"EA") == 0)
         ft_check_EA();   
     else if(strcmp(g_check[0],"S") == 0)
        ft_check_S();
     else if(strcmp(g_check[0],"C") == 0)
        ft_check_C();
      else if(strcmp(g_check[0],"F") == 0)
        ft_check_F();
     else if(strchr("1 0", g_map[g_y_len][0]) && g_mapcount[g_t].mapx > 0)
        ft_check_errormap(p);
        else
        {
            ft_putstr("weird character");
            exit(0);
        }
}
}


void ft_return()
{
    if(g_direction.c != 1 || g_direction.we != 1|| g_direction.ea != 1 || g_direction.f != 1 || g_direction.su != 1 || g_direction.no != 1 || g_direction.r != 1 || g_direction.s != 1)
    {
        ft_putstr("missing or multiple parameter");
        exit(0);
    }
}
void ft_map_traitement1(int lenght,int fd)
{
    BubbleSort(lenght);
    g_y_len = 0;
    while(g_y_len <= lenght)
    {  
        g_mapcount[g_t].mapx = ft_strlen(g_map[g_y_len]);
        
        if(g_mapcount[g_t].mapx > 0)
        {   
            g_split = 0;
            if(g_calcul_parameter <= 8)
                g_check = ft_split(g_map[g_y_len],' ');
            ft_check(fd);
            if(g_calcul_parameter <= 8)
                ft_free_l3alam1();
        }       
        g_t++;
        g_y_len++;
    }
    ft_return();
    inde--;
    ft_last_line();
    ft_free_l3alam(g_map);
    g_line[++inde] = NULL;
    g_y_len++;
}
int  fd_tab(int fd)
{
    char **str;
    int c = 0;
    int lenght = 0;
    g_calcul_parameter = 0;
    g_y_len = 0;
    g_map = malloc(sizeof(char *) * (g_indexo + 2));
    str = malloc(sizeof(char *) * (g_indexo + 2));
    g_empty_line = 0;
    while(get_next_line(fd,&str[lenght]))
    {
        if(ft_strlen(str[lenght]) == 0)
            g_empty_line++;
        g_map[g_y_len] = ft_strdup(str[lenght]);
        if(ft_strchr("1 0", str[lenght][0]))
            g_mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
        lenght++;
        g_y_len++;
    }
    g_map[g_y_len] = ft_strdup(str[lenght]);
    g_mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
    g_map[++g_y_len] = NULL;
    str[g_y_len] = NULL;
    ft_free_l3alam(str);
    ft_map_traitement1(lenght,c);
}

void ft_switch_space()
{
    int i;
    int g_j;
    int f;

    i = 0;
    g_j = 0;
    f = 0;
    char *tmp;
    int variable;
    char *str;
    variable = ft_strlen(g_map[g_y_len]);
        i = g_mapcount[0].lenghtx - variable;
        str = malloc(sizeof(char) * i + 1);
        f = 0;
        while(i > f)
        {
            str[f] = ' ';
            f++;
        }
        str[f] = '\0';
        tmp = ft_strdup(g_map[g_y_len]);
        free(g_map[g_y_len]);
        g_map[g_y_len] = ft_strjoin(tmp, str);
        free(tmp);
        free(str);
}
void ft_header(void)
{
    g_screenmap.header = ft_calloc(54,1);
    g_screenmap.bit_count = 24;
    g_screenmap.g_width = g_width;
    g_screenmap.g_height = g_height;
    g_screenmap.width_in_byte = ((g_screenmap.g_width * g_screenmap.bit_count + 31) / 32) * 4;
    g_screenmap.image_size = g_screenmap.width_in_byte * g_screenmap.g_height;
    g_screenmap.size_header = 40;
    g_screenmap.offset_bits = 40 + 14;
    g_screenmap.file_size = g_screenmap.offset_bits + g_screenmap.image_size;
    g_screenmap.planes = 1;
    ft_memcpy(g_screenmap.header , "BM" , 2);
    ft_memcpy(g_screenmap.header + 2, &g_screenmap.file_size, 4);
    ft_memcpy(g_screenmap.header + 10, &g_screenmap.offset_bits, 4);
    ft_memcpy(g_screenmap.header + 14 , &g_screenmap.size_header, 4);
    ft_memcpy(g_screenmap.header + 18, &g_screenmap.g_width, 4);
    ft_memcpy(g_screenmap.header + 22 , &g_screenmap.g_height, 4);
    ft_memcpy(g_screenmap.header + 26 , &g_screenmap.planes, 2);
    ft_memcpy(g_screenmap.header + 28, &g_screenmap.bit_count, 2);
    ft_memcpy(g_screenmap.header + 34 , &g_screenmap.image_size, 4);
}
int *get_color(int coloor)
{
    int *colors;
    colors = malloc(3 * sizeof(int));
    colors[0] = ((coloor >> 16) & 0xFF);
    colors[1] = ((coloor >> 8) & 0xFF);
    colors[2] = ((coloor) & 0xFF);
    return (colors);

}

void			ft_free_l3alam1()
{
    int g_j;

    g_j = 0;
        while (g_check[g_j])
	    {
		    free(g_check[g_j]);
		    g_j++;
	    }
	    free(g_check);
	

}

void			ft_free_l3alam(char **g_tab)
{
    int g_j;

     g_j = 0;
     
	while (g_tab[g_j])
	{
		free(g_tab[g_j]);
		g_j++;
	}
	free(g_tab);
}


void create_image(void)
{
    int row;
    unsigned int col;
    int *colors;

    g_screenmap.img = malloc(g_screenmap.image_size);
    row = g_screenmap.g_height - 1;
    while(row > 0)
    {
        col = 0;
        while(col < g_screenmap.g_width)
        {
            colors = get_color(g_data[(g_screenmap.g_height - row) * g_screenmap.g_width + col]);
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 2] = colors[0];
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 1] = colors[1];
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 0] = colors[2];
            col++;
        }
        row--;
    }
}
void screenshot(void)
{
    g_screenmap.fd = open("./screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    ft_header();
    create_image();
    write(g_screenmap.fd,g_screenmap.header,54);
    write(g_screenmap.fd,g_screenmap.img,g_screenmap.image_size);
    free(g_screenmap.header);
    free(g_screenmap.img);
    exit(0);
}
void direction_global()
{
    g_direction.ea = 0;
    g_direction.no = 0;
    g_direction.su = 0;
    g_direction.we = 0;
    g_direction.s = 0;
    g_direction.f = 0;
    g_direction.c = 0;
}

void ft_check_arg(char **argv,int argc)
{
    int len;


    len = ft_strlen(argv[1]);
    len = len - 4;
    g_mapo = &argv[1][len];
    if (argc == 2)
        g_chorfi = ft_strdup("");
    else
        g_chorfi = argv[2];
    
    if(strcmp(g_mapo,".cub") != 0)
    {
        ft_putstr("error in .cub");
        exit(0);
    }

}
void ft_calcul_lenght()
{
    char *str;
    g_indexo = 0;
    while(get_next_line(g_fd,&str))
    {
        free(str);
        g_indexo++;
    }
    free(str);
}

void ft_variable_init_calcul_lengh(char **argv)
{
    g_x = g_wall;
    g_y = g_wall;
    direction_global();
    g_mlx_ptr = mlx_init();
    g_fd = open(argv[1], O_RDONLY , O_RDWR);
    inde = 0;
    if (g_fd == -1)
    {
        ft_putstr("error in file descriptor");
        exit(0);
    }
      ft_calcul_lenght();
}

void ft_map_traitement(char **argv)
{
    g_line = malloc(sizeof(char *) * (g_indexo));
    close(g_fd);
    int fd = open(argv[1], O_RDONLY, O_RDWR);
    if (fd == -1)
    {
        ft_putstr("error g_mapo");
        exit(0);
    }
    if (!fd_tab(fd))
     {
         ft_putstr("Error in g_map fd");
         exit(0);
     }
    ft_check_zero();
}

void ft_graphic_variable(int argc)
{
    if(strcmp(g_chorfi,"--save") != 0 && argc == 3)
    {
        ft_putstr("error in parameter");
        exit (0);
    }

    if(strcmp(g_chorfi,"--save") != 0)
        g_win_ptr = mlx_new_window(g_mlx_ptr, g_width, g_height,"mlx 42");
    g_image = mlx_new_image(g_mlx_ptr,g_width,g_height);
    g_data = (int *)mlx_get_data_addr(g_image,&g_b,&g_a,&g_c);
    ft_morba3();
     if (g_N > 1 || g_N == 0)
    {
        ft_putstr("error multi or miss player\n");
        exit (0);
    }
}

void ft_render_map(int i)
{
    g_rotation = g_rotationAngle - M_PI / 8;
    g_rot = rad(45) / g_width;
    g_sprite_count = 0;
    while(i < g_width)
    {
        if (g_rotation > 2 * M_PI || g_rotation < 0)
            g_rotation = ft_normalize_angle(g_rotation);
        ft_cast_ray();

        g_rotation += g_rot;
        render_map3D(i);
        sorting();
        if(g_sprite_indicator == 1 )
        {
                if (g_sprites[0].g_distance < g_distance)
                    render_sprite(i);
             g_sprite_count = 0;
        }
        i++;
    }
}
int main(int argc, char **argv)
{
    int i;
    g_split = 0;
    g_dontenteragain = 0;
    if(argc == 2 || argc == 3 )
        ft_check_arg(argv,argc);
    i = 0;
    g_remain_argc = argc;
    ft_variable_init_calcul_lengh(argv);
    ft_map_traitement(argv);
    ft_graphic_variable(argc);
    ft_render_map(i);
    mlx_loop_hook(g_mlx_ptr,loop_key,0);
    mlx_loop(g_mlx_ptr);
}