# Runner

*****

Welcome to my Defender,
a tower defense game made with CSFML where your goal is to build tower and protect your base from waves of ennemy !

## Instalation

You need to install the `mysql_lib` for the highscore

### Windows Installer

Use [this](https://dev.mysql.com/get/Downloads/MySQLInstaller/mysql-installer-web-community-8.0.18.0.msi) install

### Linux Installer

Clone the repository:

    git clone https://github.com/Arcahub/Runner.git

Download the version of your distrib on [this link](https://dev.mysql.com/downloads/repo/yum/)

Then install it with:

    sudo yum localinstall mysql80-community-release-{distrib version}-{version-number}.noarch.rpm

Install CSFML

    sudo ./csfml/build_csfml.sh

To compil:

    make

Update :

    git pull && make re

## How to

If you want to play on your own map:

    ./my_runner [MAP]

Else to play with the automatic generation

    ./my_runner

## Player Input

### Space ( or A on gamepad )

First time : jump ( the more you let the key pressed the more you will jump ).
In the air : double jump ( you won't be able to jump again until you hit the ground )

### X (or X on gamepad)

Attack : default is right side but you can attack top or down using the arrow ( left joystick on gamepad ). An attack who hit a spike will make you knockback.

### A ( or B on gamepad )

Dash : will dashing you can't be hitted by spike but you can't dash until the player recover

## Credits

Dev :

Guillaume Mailhol

Big thanks to [TeamCherryGames](https://twitter.com/teamcherrygames?lang=fr) for the sprites from the beautiful game [Hollow Knight](https://store.steampowered.com/app/367520/Hollow_Knight/)
