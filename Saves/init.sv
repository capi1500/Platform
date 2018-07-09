Ground{
    position 110 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 50 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 210 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 170 110
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 50 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 200 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 350 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 500 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 520 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 540 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 560 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 580 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 600 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 620 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 640 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 660 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Ground{
    position 680 130
    size 20 20
    shape box
    texture Textures/redBox.png
}
Portal{
    position 720 110
    size 20 20
    shape circle
    texture Textures/lightBlueBox.png
    target Saves/init1.sv
    sound Audio/BonusCube.ogg
}
Player{
    position 125 132
    size 19 19
    friction 0
    density 1
    shape circle
    name Player
    texture Textures/blueBox.png
    sound Audio/jump.ogg
    sound Audio/RPG-SFX/stones_01.ogg
}
NPC{
    position 300 130
    size 20 20
    shape circle
    name Antoni
    texture Textures/blueBox.png
    talks{
        hello Hello.;
        quest1 Can you collect 5 carrots.;
        quest2 so I can make carrot brew.;
        quest3 I'll reward you with 100 gold coins.;
        bye Goodbye.;
        quest_in_progress1 Nah, you don't have enough.;
        quest_in_progress2 Bring me 5 carrots.;
        quest_finished1 Very well, now I'm going to prepere my meal.;
        quest_finished2 and here are your coins.;
        after_quest1 Thank you very much for help.;
        after_quest2 I will remember your deed.;
    }
    target Point
    ammount 5
    reward Money
    rewardAmmount 100
    sound Audio/RPG-SFX/item_misc_02.ogg
}
Collectible{
    position 350 85
    size 10 10
    shape box
    type kinematic
    name Point
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}
Collectible{
    position 290 95
    size 10 10
    shape box
    type kinematic
    name Point
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}
Collectible{
    position 175 95
    size 10 10
    shape box
    type kinematic
    name Point
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}
Collectible{
    position 450 95
    size 10 10
    shape box
    type kinematic
    name Point
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}
Collectible{
    position 600 95
    size 10 10
    shape box
    type kinematic
    name Point
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}