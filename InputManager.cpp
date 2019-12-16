/*
 * InputManager.cpp
 *
 *  Created on: 25/05/2011
 *      Author: jhr
 */

#include "InputManager.h"
#include <iostream>
using namespace std;

InputManager* InputManager::instance = 0;

InputManager::InputManager() {

	keyState = SDL_GetKeyState(NULL);
	keyDownState = new bool[322];
	keyUpState = new bool[322];

	mouseDown = mouseUp = mousePressed = mouseDownLeft = mouseDownRight = false;
	mouseX = mouseY = 0;
}

InputManager::~InputManager() {
	//delete keyDownState;
	//delete keyUpState;
}

InputManager& InputManager::getInstance() {
	if(!instance) instance = new InputManager();
	return *instance;
}

void InputManager::Update() {

	SDL_Event event;
	unsigned int i = 0;
	for(i = 0; i < 322; i++) {
		keyDownState[i] = false;
	}

	for(i = 0; i < 322; i++) {
		keyUpState[i] = false;
	}
	mouseDown = mouseUp = mouseDownLeft = mouseDownRight = false;

	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_KEYDOWN) {
			keyDownState[event.key.keysym.sym] = true;
		}
		if(event.type == SDL_KEYUP) {
			keyUpState[event.key.keysym.sym] = true;
		}
		if(event.type == SDL_MOUSEMOTION) {
			mouseX = event.motion.x;
			mouseY = event.motion.y;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == 1) {mouseDownLeft = true;}		// Distingue botao esquerdo do mouse
			if(event.button.button == 3) {mouseDownRight = true;}		// Distingue botao direito do mouse
			mouseDown = true;
			mousePressed = true;
		}
		if(event.type == SDL_MOUSEBUTTONUP) {
			mouseUp = true;
			mousePressed = false;
		}
	}

}

bool InputManager::isKeyDown(int key) {

	return(keyDownState[key]);

}

bool InputManager::isKeyPressed(int key) {

	if(keyState[key]) return true;
	return false;


}

bool InputManager::isKeyUp(int key) {

	return(keyUpState[key]);

}

bool InputManager::isMouseDown(int key) {

	return mouseDown;

}

bool InputManager::isMousePressed(int) {

	return mousePressed;

}

bool InputManager::isMouseDownLeft() {
	return mouseDownLeft;
}

bool InputManager::isMouseDownRight() {
	return mouseDownRight;
}

bool InputManager::isMouseUp(int) {

	return mouseUp;

}

int InputManager::MousePosX() {

	return(mouseX);

}

int InputManager::MousePosY() {

	return(mouseY);

}

bool InputManager::isMouseInside(Sprite* sprite) {

	return((mouseX >= sprite->x
		 && mouseX <= sprite->x + sprite->retangulo.w)
			&& (mouseY >= sprite->y
			&&  mouseY <= sprite->y + sprite->retangulo.h));

}

