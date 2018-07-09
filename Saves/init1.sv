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
}
Collectible{
    position 220 60
    size 10 10
    shape box
    type kinematic
    name Money
    ammount 10
    texture Textures/yellowBox.png
    sound Audio/laser.ogg
}