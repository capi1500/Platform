time 4
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
	position 369.562 96.8187
	size 19 19
	velocity 7.72947 3.5821
	angle 0
	sound Audio/jump.ogg
	sound Audio/RPG-SFX/stones_01.ogg
	texture Textures/blueBox.png
	EQ{
		Key 0
		MagicStone 0
		Money 1900
		Point 2
	}
}
NPC{
	type static
	shape circle
	name Bilbo
	position 200.5 95.5
	size 20 20
	velocity 0 0
	angle 0
	sound Audio/RPG-SFX/item_misc_02.ogg
	texture Textures/blueBox.png
	talks{
		after_quest1 Ohh thank you for that key.;
		after_quest2 Hope you haven't told who gave you the stone.;
		bye Farewell adventurer.;
		hello Oh, hello adventurer;
		quest1 You see, I'm thief but I can't jump.;
		quest2 and key is up there. I really need it.;
		quest3 ...so can you help me for magic stone please?;
		quest_finished1 Oh fantastic, now I can open secret door.;
		quest_finished2 Here take it, don't tell where you got that from.;
		quest_in_progress1 Oh you still don't got it.;
		quest_in_progress2 You can jump, can't you?;
	}
	playerNearby false
	playerMovedAway true
	questStarted true
	questDone true
	afterQuest true
	rewardGiven true
	nowTalking nothing
	ammount 1
	target Key
	rewardAmmount 1
	reward MagicStone
}
NPC{
	type static
	shape circle
	name Gandalf
	position 400.5 130.5
	size 20 20
	velocity 0 0
	angle 0
	sound Audio/RPG-SFX/item_misc_02.ogg
	texture Textures/blueBox.png
	talks{
		after_quest1 Thank you, you helped me a lot!;
		after_quest2 Sad thing you aren't also a halfling.;
		bye See you soon.;
		hello Greetings;
		quest1 Let me introduce myself I'm Gandalf the Gray;
		quest2 I'm here to search for magical stone;
		quest3 If you will find one, bring it to me please;
		quest_finished1 Do you have it?;
		quest_finished2 Yes? Fantastic, hand it to me, quick.;
		quest_in_progress1 Do you have it?;
		quest_in_progress2 Meh, you don't;
	}
	playerNearby false
	playerMovedAway true
	questStarted true
	questDone true
	afterQuest true
	rewardGiven true
	nowTalking nothing
	ammount 1
	target MagicStone
	rewardAmmount 1900
	reward Money
}
Collectible{
	type kinematic
	shape box
	name Key
	position 220 60
	size 10 10
	velocity 0 0
	angle 0
	sound Audio/RPG-SFX/item_coins_04.ogg
	texture Textures/yellowBox.png
	collected true
	ammount 1
}
