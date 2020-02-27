/*
** EPITECH PROJECT, 2019
** defender
** File description:
** const
*/

#include <SFML/Graphics.h>

#ifndef CONST_H
#define CONST_H

// BASE

extern const char *PATH_TO_BASE_SPRITESHEET;

// ENV

extern const char *ENV_DISPLAY;

// USAGE

extern const char *USAGE_FLAG;
extern const char *USAGE;

// WINDOW

extern const unsigned short int WINDOW_WIDTH;
extern const unsigned short int WINDOW_HEIGHT;
extern const unsigned char WINDOW_BITS_PER_PIXEL;
extern const unsigned char WINDOW_FRAMERATE;
extern const char *WINDOW_NAME;
extern const char *ICON_PATH;

extern const sfColor GAME_BACKGROUND_COLOR;

// MUSIC

extern const char *MENU_MUSIC_PATH;

// SCORE

extern const char *BASE_SCORE;
extern const char *BASE_HIGHSCORE;

// FRAMERATE

extern const float MAX_FRAME_RANGE;
extern const float DELAY_BETWEEN_UPDATE;
extern const float SECOND_IN_MICRO;

// PLAYER

extern const unsigned int PLAYER_START_X;
extern const unsigned int PLAYER_START_Y;
extern const unsigned char PLAYER_SPEED_X;
extern const unsigned char PLAYER_MAX_SPEED_X;
extern const unsigned char PLAYER_SPEED_Y;
extern const char *PLAYER_SPRITE_PATH;
extern const sfIntRect *PLAYER_RUNNING_FRAME_KEYS[];
extern const char *PLAYER_RUNNING_SOUND_PATH;
extern const sfIntRect *PLAYER_JUMPING_FRAME_KEYS[];
extern const char *PLAYER_JUMPING_SOUND_PATH;
extern const sfIntRect *PLAYER_FALLING_FRAME_KEYS[];
extern const char *PLAYER_FALLING_SOUND_PATH;

extern const unsigned char PLAYER_DASH_OFFSET;
extern const unsigned char PLAYER_DASH_SPEED;
extern const char *PLAYER_DASHING_SOUND_PATH;
extern const sfIntRect *PLAYER_DASHING_FRAME_KEYS[];

extern const char *PLAYER_ATTACKING_SOUND_PATH;

extern const unsigned char PLAYER_ATTACKING_RIGHT_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_RIGHT_FRAME_KEYS[];

extern const unsigned char PLAYER_ATTACKING_TOP_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_TOP_FRAME_KEYS[];

extern const unsigned char PLAYER_ATTACKING_DOWN_OFFSET;
extern const sfIntRect *PLAYER_ATTACKING_DOWN_FRAME_KEYS[];


extern const unsigned char PLAYER_DOUBLE_JUMPING_OFFSET;
extern const sfIntRect *PLAYER_DOUBLE_JUMPING_FRAME_KEYS[];
extern const char *PLAYER_DOUBLE_JUMPING_SOUND_PATH;

// MAIN MENU

extern const unsigned short TITLE_X;
extern const unsigned short TITLE_Y;
extern const char *TITLE_PATH;

extern const char *TITLE_UNDERLINE_PATH;
extern const unsigned short TITLE_UNDERLINE_X;
extern const unsigned short TITLE_UNDERLINE_Y;
extern const sfIntRect *TITLE_UNDERLINE_FRAME_KEYS[];

extern const char *ARROW_PATH;
extern const sfIntRect *ARROW_LEFT_FRAME_KEYS[];
extern const sfIntRect *ARROW_RIGHT_FRAME_KEYS[];

extern const char *RETURN_BUTTON_PATH;
extern const unsigned short RETURN_BUTTON_X;
extern const unsigned short RETURN_BUTTON_Y;

extern const unsigned short PLAY_BUTTON_X;
extern const unsigned short PLAY_BUTTON_Y;
extern const char *PLAY_BUTTON_PATH;
extern const unsigned short OPTION_BUTTON_X;
extern const unsigned short OPTION_BUTTON_Y;
extern const char *OPTION_BUTTON_PATH;
extern const unsigned short INFOS_BUTTON_X;
extern const unsigned short INFOS_BUTTON_Y;
extern const char *INFOS_BUTTON_PATH;
extern const unsigned short EXIT_BUTTON_X;
extern const unsigned short EXIT_BUTTON_Y;
extern const char *EXIT_BUTTON_PATH;

extern const sfVector2i MAIN_MENU_COORDS[];

// IN-GAME_MENU

extern const char *IN_GAME_MENU_BACKGROUND;

extern const unsigned short CONTINUE_BUTTON_X;
extern const unsigned short CONTINUE_BUTTON_Y;
extern const char *CONTINUE_BUTTON_PATH;
extern const unsigned short OPTION_BUTTON_Y_IN_GAME;
extern const unsigned short MAIN_MENU_BUTTON_X;
extern const unsigned short MAIN_MENU_BUTTON_Y;
extern const char *MAIN_MENU_BUTTON_PATH;

extern const unsigned short TOP_FLEUR_X;
extern const unsigned short TOP_FLEUR_Y;
extern const char *TOP_FLEUR_PATH;
extern const sfIntRect *TOP_FLEUR_FRAME_KEYS[];

extern const unsigned short BOTTOM_FLEUR_X;
extern const unsigned short BOTTOM_FLEUR_Y;
extern const char *BOTTOM_FLEUR_PATH;
extern const sfIntRect *BOTTOM_FLEUR_FRAME_KEYS[];

// PHYSICS

extern const float JUMP_SPEED;
extern const float JUMP_SPEED_MIN;
extern const float FALLING_MAX_SPEED;

// OPTIONS

extern const char *OPTION_TITLE;
extern const unsigned short OPTION_TITLE_X;
extern const unsigned short OPTION_TITLE_Y;

extern const char *GLOBAL_VOLUME_TEXT;

extern const char *BAR_PATH;
extern const char *BAR_BACKGROUND_PATH;
extern const unsigned short BAR_WIDTH;
extern const unsigned short BAR_HEIGHT;
extern const unsigned char BAR_BOX_OFFSET;
extern const unsigned short VOLUME_BAR_X;
extern const unsigned short VOLUME_BAR_Y;

extern const unsigned char VOLUME_UNIT;
extern const unsigned char MAX_VOLUME;
extern const unsigned char MIN_VOLUME;

extern const char *INDICATOR_PATH;
extern const unsigned short INDICATOR_WIDTH;
extern const unsigned short INDICATOR_X;
extern const unsigned short INDICATOR_Y;

extern const char *FONT_PATH;
extern const char *CURSOR_PATH;

// INFOS

extern const char *INFOS_TITLE;
extern const unsigned short INFOS_TITLE_X;
extern const unsigned short INFOS_TITLE_Y;

extern const unsigned short INFOS_ARROW_Y;
extern const unsigned short INFOS_ARROW_LEFT_X;
extern const unsigned short INFOS_ARROW_RIGHT_X;

extern const char *INFOS_CONTENT_PATH;
extern const sfIntRect *INFOS_CONTENT_FRAME_KEYS[];

// GG MENU

extern const char *RESTART_PATH;
extern const unsigned short RESTART_X;
extern const unsigned short RESTART_Y;

extern const char *GG_TOP_PATH;
extern const unsigned short GG_TOP_X;
extern const unsigned short GG_TOP_Y;
extern const sfIntRect *GG_TOP_FRAME_KEYS[];

extern const char *GG_BOT_PATH;
extern const unsigned short GG_BOT_X;
extern const unsigned short GG_BOT_Y;
extern const sfIntRect *GG_BOT_FRAME_KEYS[];

extern const unsigned short GG_MAIN_MENU_BUTTON_Y;

// LEVEL DESIGN

extern const unsigned char TILE_WIDTH;
extern const unsigned char TILE_HEIGHT;
extern const unsigned char TILES_PER_CHUNK;
extern const unsigned short TILE_MAX_HEIGHT;

extern const unsigned char MAX_FLOOR_WIDTH;

extern const unsigned short CHUNK_WIDTH;
extern const unsigned short CHUNK_HEIGHT;

extern const char *GROUND_PATH;
extern const unsigned char GROUND_WIDTH;
extern const unsigned char GROUND_HEIGHT;

extern const char *SPIKES_PATH;
extern const unsigned char SPIKE_WIDTH;
extern const unsigned char SPIKE_HEIGHT;

//MAP_GESTIOn

extern const char *CASLTE_NOT_REACHABLE;
extern const char *TOO_MANY_CASTLE;
extern const char *NOT_ENOUGH_GROUND;
extern const char *NOT_ENOUGH_PATH;
extern const char *NOT_ENOUGH_CASTLE;

#endif
