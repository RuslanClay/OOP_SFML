#pragma once
#include <SFML/Graphics.hpp>
#include"tool.h"
using namespace sf;

static Texture texture_white;//������ ������ �����
static Texture texture_black;


class Checker {
private:
	CircleShape checker = CircleShape(18);// ���������� ���� � �������� 18
	bool checker_color;// 0 ��� �����, 1 ��� ������
	bool select = 0;//1 ���� �������, 0 ���� ���
	bool queen = 0;//1 ���� ����� �����, 0 ���� ���
	int good_step = 0;// ����������� ���� �����
	Texture texture;//�������� ������ �����
	Sprite sprite;


public:
	CircleShape &get_checker() {//�������� �����
		return this->checker;
	}
	Vector2f get_position() {// �������� ����������
		return this->checker.getPosition();
	}
	float get_x() {//�������� ���������� X
		return (this->get_position().x - 57) / 50;
	}
	float get_y() {//�������� ���������� Y
		return (this->get_position().y - 57) / 50;
	}
	bool get_color() {// �������� ���� �����
		return this->checker_color;
	}
	bool get_select() {//�������� ��������� �����
		return this->select;
	}
	bool get_queen() {//�������� ���� �����
		return this->queen;
	}

	void dec_good_step()
	{
		this->good_step--;
	}
	void inc_good_step()
	{
		this->good_step++;
	}
	int get_good_step()
	{
		return this->good_step;
	}
	void zero_good_step()
	{
		this->good_step = -99;
	}
	void make_queen() {//��������� �����
		this->queen = 1;
	}
	void set_position(float x_positinon, float y_position) {//��������� ���������� �����
		this->checker.setPosition(x_positinon, y_position);
	}
	void set_color(Color color) {//��������� ���� �����
		this->checker.setFillColor(color);
	}
	void select_checker() {//����� ������
		this->select = 1;
	}
	void leave_checker() {//������ ������ ������
		this->select = 0;
	}

	Checker() { }

	Checker(float x_position, float y_position, bool color) {
		this->checker.setOutlineThickness(3);// ����� ������ �������� 3 �������� ������� �����
		this->checker.setOutlineColor(sf::Color(0, 0, 0));
		this->checker_color = color;

		if (color == 0)
			this->set_color(Color(255, 255, 255));//����� �����
		else if (color == 1)
			this->set_color(Color(61, 25, 7));//������ �����

		this->set_position(x_position, y_position);
		this->select = 0;
	}

	void draw_checker(RenderWindow  &_window) {// ��������� �����
		_window.draw(this->checker);
		if (queen == 1)
			if (ifImage == false)
			{
				texture_white.loadFromFile("Images//01.png");
				texture_black.loadFromFile("Images//011.png");
				if (checker_color == 0)
					this->sprite.setTexture(texture_white);
				else
					this->sprite.setTexture(texture_black);
			}
			else
			{
				if (checker_color == 0)
					this->sprite.setTexture(texture_white);
				else
					this->sprite.setTexture(texture_black);
			}
		this->sprite.setTextureRect(IntRect(0, 0, 25, 25));
		sprite.setPosition(this->get_position().x + 6, this->get_position().y + 6);
		_window.draw(this->sprite);
	}

	Checker operator = (Checker _checker) {
		this->texture = _checker.texture;
		this->sprite = _checker.sprite;
		this->select = _checker.select;
		this->queen = _checker.queen;
		this->checker_color = _checker.checker_color;

		if (_checker.checker_color == 0)
			this->set_color(Color(255, 255, 255));
		else if (_checker.checker_color == 1)
			this->set_color(Color(61, 25, 7));

		this->set_position(_checker.get_position().x, _checker.get_position().y);
		return (*this);
	}
};