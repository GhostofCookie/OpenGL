#pragma once

class Object
{
public:
	Object();

	void Render();

	void Move(float, float, float);

	void Rotate(float);

private:
	float x_loc, y_loc, z_loc;

};