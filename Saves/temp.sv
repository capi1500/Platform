time 3
Ground{
	type static
	shape box
	name default
	position 0 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 150 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 300 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 75 115
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 225 115
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 150 80
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Player{
	type dynamic
	density 1
	friction 0
	shape circle
	name Player
	position 385.732 130.926
	size 19 19
	velocity -66.4732 0
	angle 0
	sound Audio/jump.ogg
	texture Textures/blueBox.png
	EQ{
		Money 110
		Point 0
	}
}
Collectible{
	type kinematic
	shape box
	name Money
	position 220 60
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected true
	ammount 10
}
