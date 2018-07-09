Ground{
    position 0 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 150 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 300 150
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 75 115
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 225 115
    size 150 10
    shape box
    texture Textures/ground.png
}
Ground{
    position 150 80
    size 150 10
    shape box
    texture Textures/ground.png
}
Player{
    position 0 132
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
    position 200 95
    size 20 20
    shape circle
    name Bilbo
    texture Textures/blueBox.png
    talks{
        hello Oh, hello adventurer;
        quest1 You see, I'm thief but I can't jump.;
        quest2 and key is up there. I really need it.;
        quest3 ...so can you help me for magic stone please?;
        bye Farewell adventurer.;
        quest_in_progress1 Oh you still don't got it.;
        quest_in_progress2 You can jump, can't you?;
        quest_finished1 Oh fantastic, now I can open secret door.;
        quest_finished2 Here take it, don't tell where you got that from.;
        after_quest1 Ohh thank you for that key.;
        after_quest2 Hope you haven't told who gave you the stone.;
    }
    target Key
    ammount 1
    reward MagicStone
    rewardAmmount 1
    sound Audio/RPG-SFX/item_misc_02.ogg
}
NPC{
    position 400 130
    size 20 20
    shape circle
    name Gandalf
    texture Textures/blueBox.png
    talks{
        hello Greetings;
        quest1 Let me introduce myself I'm Gandalf the Gray;
        quest2 I'm here to search for magical stone;
        quest3 If you will find one, bring it to me please;
        bye See you soon.;
        quest_in_progress1 Do you have it?;
        quest_in_progress2 Meh, you don't;
        quest_finished1 Do you have it?;
        quest_finished2 Yes? Fantastic, hand it to me, quick.;
        after_quest1 Thank you, you helped me a lot!;
        after_quest2 Sad thing you aren't also a halfling.;
    }
    target MagicStone
    ammount 1
    reward Money
    rewardAmmount 1900
    sound Audio/RPG-SFX/item_misc_02.ogg
}
Collectible{
    position 220 60
    size 10 10
    shape box
    type kinematic
    name Key
    ammount 1
    texture Textures/yellowBox.png
    sound Audio/RPG-SFX/item_coins_04.ogg
}