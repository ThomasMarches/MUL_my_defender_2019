# Creation of a map

In this file, i will explain you how to create a proper map for the game my_defender. Good luck !

## The file.

Head to the folder maps and open the map.txt file.

## Content of the file.

If you want the game to launch, the .txt file of your map needs to contain only  '1'  for a ground,  '2'  for the path of your ennemies, '3'  for a little rock, '5' for your base and '4' for the ennemy spawning position.

## Important information about the file.

You need to put only one base, to take care the the path is joining the base and to be careful that there are grounds for you to put tower on it.
You also need to verify there is a castle and a spawning position inside the file.
The game won't launch if the map is invalid.

## Exemple of a map.

```bash
                       
11111111111111111111111111111
11111111111111111111111111111
11111111111113111111111111111
11111111111111111111111131111
11111111111111111111111111111
11111113111111111111111111111
11111111111111111113111111111
11111111111122211111111111111
11131111111121211111111111111
11111111122221222221111111111
11111111121111111121111111111
11111111121111111121111111111
42222222221111111121111111111
11111111111111111122222222225
11111111111111111111111111111
11111111111111111111111111111
11111111111111111111111111111
11111111111111111111111111111

```

# Creation of a tower

Here we will explain you how to create your own towers (damage, range, spritesheet, slow, aoe damage).

## The file.

Head to the folder towers and look at tower(number).txt file.

## Content of the file.

You will put on each line the value you want, and separate the different level of the tower with ':'.

## Exemple of a tower.

```bash
(level1:level2:level3)

100:150:200 // Cost
5:6:7 // Damage
10:15:20 // Range
1:1,5:2 // Attack speed
templates/towers/tower1_level1.jpg // Sprite sheet of level 1
slow:0:0:0 // Slow pourcentage
multi_damage:0:0:0 // AOE damage

```

#

## Copyright

Made by thomas.marches@epitech.eu && guillaume.maihol@epitech.eu

Project by Epitech Toulouse.