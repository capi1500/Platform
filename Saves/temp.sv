time 1
Ground{
	type static
	shape box
	name default
	position 110 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 50 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 210 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 170 110
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 50 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 200 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 350 150
	size 150 10
	velocity 0 0
	angle 0
	texture Textures/ground.png
}
Ground{
	type static
	shape box
	name default
	position 500 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 520 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 540 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 560 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 580 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 600 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 620 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 640 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 660 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Ground{
	type static
	shape box
	name default
	position 680 130
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/redBox.png
}
Player{
	type dynamic
	density 1
	friction 0
	shape circle
	name Player
	position 130.05 130.95
	size 19 19
	velocity 0 -5.48743e-09
	angle 0
	sound Audio/jump.ogg
	texture Textures/blueBox.png
	EQ{
		Money 0
		Point 0
	}
}
NPC{
	type static
	shape circle
	name Antoni
	position 300.5 130.5
	size 20 20
	velocity 0 0
	angle 0
	texture Textures/blueBox.png
	talks{
		after_quest1 Ohh thank you for help;
		after_quest2 I will remember your deed;
		bye goodbye;
		hello hello;
		quest1 Can you collect 5 carrots;
		quest2 so I can make carrot brew;
		quest3 I'll reward you with 100 gold coins;
		quest_finished1 Very well, now I'm going to prepere my meal;
		quest_finished2 Oh and here are your coins;
		quest_in_progress1 Nah, you don't have enough;
		quest_in_progress2 Bring me 5 carrots;
	}
	playerNearby false
	playerMovedAway true
	questStarted false
	questDone false
	afterQuest false
	rewardGiven false
	nowTalking nothing
	ammount 5
	target Point
	rewardAmmount 100
	reward Money
}
Collectible{
	type kinematic
	shape box
	name Point
	position 350 85
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected false
	ammount 1
}
Collectible{
	type kinematic
	shape box
	name Point
	position 290 95
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected false
	ammount 1
}
Collectible{
	type kinematic
	shape box
	name Point
	position 175 95
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected false
	ammount 1
}
Collectible{
	type kinematic
	shape box
	name Point
	position 450 95
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected false
	ammount 1
}
Collectible{
	type kinematic
	shape box
	name Point
	position 600 95
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/laser.ogg
	texture Textures/yellowBox.png
	collected false
	ammount 1
}
