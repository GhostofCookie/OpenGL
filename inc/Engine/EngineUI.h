#pragma once

class UI_Base
{
public:
	UI_Base();

	virtual void Render();

	bool GetCursorHovered();


};

class UI_Panel : public UI_Base
{
public:
	explicit UI_Panel(float, float, float, float);
	virtual void Render() override;


protected:
	float _x_coord, _y_coord;
private:
	float _width, _height;
};