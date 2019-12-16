/*
 * InputManager.h
 *
 *  Created on: 25/05/2011
 *      Author: jhr
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_


#include "Sprite.h"

class InputManager {
private:
	static InputManager *instance;
	Uint8 *keyState;
	bool *keyDownState;
	bool *keyUpState;
	int mouseX;
	int mouseY;
	bool mousePressed;
	bool mouseDown;
	bool mouseUp;
	bool mouseDownLeft;
	bool mouseDownRight;
	InputManager();


public:
	//InputManager();
	virtual ~InputManager();
	bool isKeyDown(int);
	bool isKeyPressed(int);
	bool isKeyUp(int);
	bool isMouseDown(int);
	bool isMouseDownLeft();
	bool isMouseDownRight();
	bool isMousePressed(int);
	bool isMouseUp(int);
	int MousePosX();
	int MousePosY();
	bool isMouseInside(Sprite*);
	void Update();
	static InputManager& getInstance();
};

#endif /* INPUTMANAGER_H_ */
