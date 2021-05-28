game:
	g++ src/Engine/game_object.cpp src/Engine/game.cpp src/Engine/texture.cpp src/main.cpp -o play -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0