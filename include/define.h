/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#include <SFML/Graphics.h>

// BASE

const char *BASE_PATH = "templates/tower/base.png";

// ENV

const char *ENV_DISPLAY = "DISPLAY";

// USAGE

const char *USAGE_FLAG = "-h";
const char *USAGE = "DESCRIPTION:\n\t./my_defender \
\n\nUSAGE:\n\tLaunch the game and head to the how to play section to see \
the different contents.\n \
\nCREATE MAP AND TOWER:\n\tRefer to the legend.md file\n\nDOCUMENTATION:\n\t\
Head to the doc.md file\n\nINFORMATION ABOUT COMPIL AND LAUNCH THE GAME:\n\t\
Head to the Readme.md";

// WINDOW

const unsigned short int WINDOW_WIDTH = 1920;
const unsigned short int WINDOW_HEIGHT = 1000;
const unsigned char WINDOW_BITS_PER_PIXEL = 32;
const unsigned char WINDOW_FRAMERATE = 60;
const char *WINDOW_NAME = "My Defender";
const char *ICON_PATH = "templates/icon.png";

const sfColor GAME_BACKGROUND_COLOR = {66, 98, 116, 0};

// MUSIC

const char *MENU_MUSIC_PATH = \
"templates/sounds/background_menu.ogg";

// SCOR
const char *BASE_SCORE = "Score : ";
const char *BASE_HIGHSCORE = "Highscore :";

// FRAMERATE

const float MAX_FRAME_RANGE = 0.25;
const float DELAY_BETWEEN_UPDATE = 1 / 30.0;
const float SECOND_IN_MICRO = 1000000.0;

// MAIN MENU

const unsigned short TITLE_X = (WINDOW_WIDTH - 1274) / 2;
const unsigned short TITLE_Y = 0;
const char *TITLE_PATH = "templates/menu/menu_bg_test_with_text.jpg";

const char *TITLE_UNDERLINE_PATH = "templates/menu/title_underline.png";
const unsigned short TITLE_UNDERLINE_X = 480;
const unsigned short TITLE_UNDERLINE_Y = 200;
const sfIntRect *TITLE_UNDERLINE_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 959, 80},
    &(sfIntRect){0, 80, 959, 80},
    &(sfIntRect){0, 160, 959, 80},
    &(sfIntRect){0, 240, 959, 80},
    &(sfIntRect){0, 320, 959, 80},
    &(sfIntRect){0, 400, 959, 80},
    &(sfIntRect){0, 480, 959, 80},
    &(sfIntRect){0, 560, 959, 80},
    &(sfIntRect){0, 640, 959, 80},
    NULL
};

const char *ARROW_PATH = "templates/menu/arrow.png";
const char *BACKGROUND_INFO = "templates/menu/in_game_menu_background.jpg";

const sfIntRect *ARROW_LEFT_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 100, 72},
    &(sfIntRect){0, 72, 100, 72},
    &(sfIntRect){0, 144, 100, 72},
    &(sfIntRect){0, 216, 100, 72},
    &(sfIntRect){0, 288, 100, 72},
    &(sfIntRect){0, 360, 100, 72},
    &(sfIntRect){0, 432, 100, 72},
    &(sfIntRect){0, 504, 100, 72},
    &(sfIntRect){0, 576, 100, 72},
    &(sfIntRect){0, 648, 100, 72},
    &(sfIntRect){0, 720, 100, 72},
    NULL};
const sfIntRect *ARROW_RIGHT_FRAME_KEYS[] = {
    &(sfIntRect){100, 0, 100, 72},
    &(sfIntRect){100, 72, 100, 72},
    &(sfIntRect){100, 144, 100, 72},
    &(sfIntRect){100, 216, 100, 72},
    &(sfIntRect){100, 288, 100, 72},
    &(sfIntRect){100, 360, 100, 72},
    &(sfIntRect){100, 432, 100, 72},
    &(sfIntRect){100, 504, 100, 72},
    &(sfIntRect){100, 576, 100, 72},
    &(sfIntRect){100, 648, 100, 72},
    &(sfIntRect){100, 720, 100, 72},
    NULL};

const char *RETURN_BUTTON_PATH = "templates/menu/return.png";
const unsigned short RETURN_BUTTON_X = (WINDOW_WIDTH - 264) / 2;
const unsigned short RETURN_BUTTON_Y = 900;

const unsigned short PLAY_BUTTON_X = (WINDOW_WIDTH - 206) / 2;
const unsigned short PLAY_BUTTON_Y = 500;
const char *PLAY_BUTTON_PATH = "templates/menu/play.png";
const unsigned short OPTION_BUTTON_X = (WINDOW_WIDTH - 267) / 2;
const unsigned short OPTION_BUTTON_Y = 600;
const char *OPTION_BUTTON_PATH = "templates/menu/option.png";
const unsigned short INFOS_BUTTON_X = (WINDOW_WIDTH - 224) / 2;
const unsigned short INFOS_BUTTON_Y = 700;
const char *INFOS_BUTTON_PATH = "templates/menu/infos.png";
const unsigned short EXIT_BUTTON_X = (WINDOW_WIDTH - 196) / 2;
const unsigned short EXIT_BUTTON_Y = 800;
const char *EXIT_BUTTON_PATH = "templates/menu/exit.png";

const sfVector2i MAIN_MENU_COORDS[] = {
    {960, 601},
    {960, 701},
    {960, 801},
    {960, 901}
};

// IN-GAME MENU

const char *IN_GAME_MENU_BACKGROUND = "templates/menu/\
in_game_menu_background.jpg";

const unsigned short CONTINUE_BUTTON_X = (WINDOW_WIDTH - 290) / 2;
const unsigned short CONTINUE_BUTTON_Y = 400;
const char *CONTINUE_BUTTON_PATH = "templates/menu/continue.png";
const unsigned short OPTION_BUTTON_Y_IN_GAME = 500;
const unsigned short MAIN_MENU_BUTTON_X = (WINDOW_WIDTH - 304) / 2;
const unsigned short MAIN_MENU_BUTTON_Y = 600;
const char *MAIN_MENU_BUTTON_PATH = "templates/menu/main_menu.png";

const unsigned short TOP_FLEUR_X = (WINDOW_WIDTH - 426) / 2;
const unsigned short TOP_FLEUR_Y = 200;
const char *TOP_FLEUR_PATH = "templates/menu/top_fleur.png";
const sfIntRect *TOP_FLEUR_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 426, 123},
    &(sfIntRect) {0, 123, 426, 123},
    &(sfIntRect) {0, 246, 426, 123},
    &(sfIntRect) {0, 369, 426, 123},
    &(sfIntRect) {0, 492, 426, 123},
    &(sfIntRect) {0, 615, 426, 123},
    &(sfIntRect) {0, 738, 426, 123},
    &(sfIntRect) {0, 861, 426, 123},
    NULL
};

const unsigned short BOTTOM_FLEUR_X = (WINDOW_WIDTH - 303) / 2;
const unsigned short BOTTOM_FLEUR_Y = 700;
const char *BOTTOM_FLEUR_PATH = "templates/menu/bottom_fleur.png";
const sfIntRect *BOTTOM_FLEUR_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 303, 66},
    &(sfIntRect) {0, 66, 303, 66},
    &(sfIntRect) {0, 132, 303, 66},
    &(sfIntRect) {0, 198, 303, 66},
    &(sfIntRect) {0, 264, 303, 66},
    &(sfIntRect) {0, 330, 303, 66},
    &(sfIntRect) {0, 396, 303, 66},
    &(sfIntRect) {0, 462, 303, 66},
    &(sfIntRect) {0, 528, 303, 66},
    NULL
};

const sfVector2i IN_GAME_MENU_COORDS[] = {
    {960, 601},
    {960, 701},
    {960, 801},
    {960, 901}
};

// PHYSICS

const float JUMP_SPEED = 35.0;
const float JUMP_SPEED_MIN = 5.0;
const float FALLING_MAX_SPEED = 25.0;

// OPTIONS

const char *OPTION_TITLE = "templates/menu/options_title.png";
const unsigned short OPTION_TITLE_X = 816;
const unsigned short OPTION_TITLE_Y = 100;

const char *GLOBAL_VOLUME_TEXT = "Global Volume :";

const char *BAR_PATH = "templates/menu/bar.png";
const char *BAR_BACKGROUND_PATH = "templates/menu/bar_background.png";
const unsigned short BAR_WIDTH = 500;
const unsigned short BAR_HEIGHT = 10;
const unsigned char BAR_BOX_OFFSET = 20;
const unsigned short VOLUME_BAR_X = (WINDOW_WIDTH - BAR_WIDTH) / 2;
const unsigned short VOLUME_BAR_Y = 400;

const unsigned char VOLUME_UNIT = 10;
const unsigned char MAX_VOLUME = 100;
const unsigned char MIN_VOLUME = 0;

const char *INDICATOR_PATH = "templates/menu/scrollbar_fleur_new.png";
const unsigned short INDICATOR_WIDTH = 107;
const unsigned short INDICATOR_X = VOLUME_BAR_X;
const unsigned short INDICATOR_Y = 400 - 25;

const char *FONT_PATH = "templates/font/Enchanted Land.otf";
const char *CURSOR_PATH = "templates/menu/Cursor.png";

// INFO

const char *INFOS_TITLE = "templates/menu/infos_title.png";
const unsigned short INFOS_TITLE_X = 852;
const unsigned short INFOS_TITLE_Y = 100;

const unsigned short INFOS_ARROW_Y = 464;
const unsigned short INFOS_ARROW_LEFT_X = 10;
const unsigned short INFOS_ARROW_RIGHT_X = WINDOW_WIDTH - 110;

const char *INFOS_CONTENT_PATH = "templates/menu/infos_content.png";
const sfIntRect *INFOS_CONTENT_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 1920, 1080},
    &(sfIntRect) {0, 1080, 1920, 1080},
    &(sfIntRect) {0, 2160, 1920, 1080},
    NULL
};

// GG MENU

const char *RESTART_PATH = "templates/menu/restart.png";
const unsigned short RESTART_X = (WINDOW_WIDTH - 272) / 2;
const unsigned short RESTART_Y = 575;

const char *GG_TOP_PATH = "templates/gg/gg_top.png";
const unsigned short GG_TOP_X = (WINDOW_WIDTH - 515) / 2;
const unsigned short GG_TOP_Y = 0;
const sfIntRect *GG_TOP_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 515, 495},
    &(sfIntRect) {0, 495, 515, 495},
    &(sfIntRect) {0, 990, 515, 495},
    &(sfIntRect) {0, 1485, 515, 495},
    &(sfIntRect) {0, 1980, 515, 495},
    &(sfIntRect) {0, 2475, 515, 495},
    &(sfIntRect) {0, 2970, 515, 495},
    &(sfIntRect) {0, 3465, 515, 495},
    NULL
};

const char *GG_BOT_PATH = "templates/gg/gg_bot.png";
const unsigned short GG_BOT_X = (WINDOW_WIDTH - 515) / 2;
const unsigned short GG_BOT_Y = WINDOW_HEIGHT - 270;
const sfIntRect *GG_BOT_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 515, 360},
    &(sfIntRect) {0, 360, 515, 360},
    &(sfIntRect) {0, 720, 515, 360},
    &(sfIntRect) {0, 1080, 515, 360},
    &(sfIntRect) {0, 1440, 515, 360},
    NULL
};

const unsigned short GG_MAIN_MENU_BUTTON_Y = 675;

// LEVEL DESIGN

const char *ROCK_PATH = "templates/env/rock.png";

const unsigned char TILE_WIDTH = 67;
const unsigned char TILE_HEIGHT = 64;
const unsigned char TILES_PER_CHUNK = 18;
const unsigned short TILE_MAX_HEIGHT = 950;

const unsigned char MAX_FLOOR_WIDTH = 7;

const unsigned short CHUNK_WIDTH = 1900;
const unsigned short CHUNK_HEIGHT = 1000;

const char *GROUND_PATH = "templates/env/ground.png";
const unsigned char GROUND_WIDTH = 67;
const unsigned char GROUND_HEIGHT = 64;

const char *GRASS_PATH = "templates/env/grass.png";
const unsigned char SPIKE_WIDTH = 67;
const unsigned char SPIKE_HEIGHT = 66;

//MAP_GESTION

const char *CASLTE_NOT_REACHABLE = ": I'm sorry to tell you that this \
map isn't playable, the castle isnt reachable. Refer to the file legend.md \
for more information";
const char *TOO_MANY_CASTLE = ": I'm sorry to tell you that this map \
isn't playable, there are too many castle. Refer to the file legend.md \
for more information";
const char *NOT_ENOUGH_GROUND = ": I'm sorry to tell you that this map \
isn't playable, there arent enough ground on it. Refer to the file \
legend.md for more information";
const char *NOT_ENOUGH_PATH = ": I'm sorry to tell you that this \
map isn't playable, there isnt any path. Refer to the file \
legend.md for more information";
const char *NOT_ENOUGH_CASTLE = ": I'm sorry to tell you that \
this map isn't playable, there isnt any castle. Refer to the \
file legend.md for more information";
const char *WRONG_CHARACTER = ": I'm sorry to tell you that \
this map isn't playable, Wrong character are inside the file. \
Refer to the file legend.md for more information";
const char *TOO_MANY_STARTING_POINT = ": I'm sorry to tell you \
that this map isn't playable, There are too many starting points. \
Refer to the file legend.md for more information";
const char *NO_STARTING_POINT = ": I'm sorry to tell you that this \
map isn't playable, There are no starting point. Refer to the file \
legend.md for more information";
//TOWER MENU

const char *TOWER_MENU_PATH = "templates/tower/tower_menu.png";
const char *FILEPATH_TABLE[] = {"towers/tower1.txt", "towers/tower2.txt", \
"towers/tower3.txt", "towers/tower4.txt", NULL};
const char *TOWER_BOARD_PATH = "templates/interface/background_interface.png";
const char *UPGRADE_BUTTON_PATH = "templates/tower/upgrade_button.png";

//ENNEMY

const sfIntRect *FIRST_ENNEMY_RECT_DOWN[] = {
    &(sfIntRect){0, 0, 48, 48},
    &(sfIntRect){0, 0, 48, 48},
    &(sfIntRect){48, 0, 48, 48},
    &(sfIntRect){48, 0, 48, 48},
    &(sfIntRect){96, 0, 48, 48},
    &(sfIntRect){96, 0, 48, 48},
    NULL
};

const sfIntRect *FIRST_ENNEMY_RECT_TOP[] = {
    &(sfIntRect){0, 144, 48, 48},
    &(sfIntRect){0, 144, 48, 48},
    &(sfIntRect){48, 144, 48, 48},
    &(sfIntRect){48, 144, 48, 48},
    &(sfIntRect){96, 144, 48, 48},
    &(sfIntRect){96, 144, 48, 48},
    NULL
};

const sfIntRect *FIRST_ENNEMY_RECT_LEFT[] = {
    &(sfIntRect){0, 48, 48, 48},
    &(sfIntRect){0, 48, 48, 48},
    &(sfIntRect){48, 48, 48, 48},
    &(sfIntRect){48, 48, 48, 48},
    &(sfIntRect){96, 48, 48, 48},
    &(sfIntRect){96, 48, 48, 48},
    NULL
};

const sfIntRect *FIRST_ENNEMY_RECT_RIGHT[] = {
    &(sfIntRect){0, 96, 48, 48},
    &(sfIntRect){0, 96, 48, 48},
    &(sfIntRect){48, 96, 48, 48},
    &(sfIntRect){48, 96, 48, 48},
    &(sfIntRect){96, 96, 48, 48},
    &(sfIntRect){96, 96, 48, 48},
    NULL
};

const char *FIRE_BULLET = "templates/tower/fireball.png";
const char *SLOW_BULLET = "templates/tower/iceball.png";
const char *AOE_BULLET = "templates/tower/aoeball.png";
const char *NORMAL_BULLET = "templates/tower/normalball.png";

const sfIntRect *TOWER1_TEXTURE_RECT[] = {
    &(sfIntRect){0, 0, 57, 67},
    &(sfIntRect){57, 0, 57, 67},
    &(sfIntRect){114, 0, 57, 67},
    NULL
};

const sfIntRect *TOWER2_TEXTURE_RECT[] = {
    &(sfIntRect){0, 0, 53, 67},
    &(sfIntRect){53, 0, 53, 67},
    &(sfIntRect){106, 0, 53, 67},
    NULL
};

const sfIntRect *TOWER3_TEXTURE_RECT[] = {
    &(sfIntRect){0, 0, 57, 67},
    &(sfIntRect){57, 0, 57, 67},
    &(sfIntRect){114, 0, 57, 67},
    NULL
};

const sfIntRect *TOWER4_TEXTURE_RECT[] = {
    &(sfIntRect){0, 0, 38, 67},
    &(sfIntRect){38, 0, 38, 67},
    &(sfIntRect){76, 0, 38, 67},
    NULL
};

#endif /* !DEFINE_H_ */
