/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:55:24 by bpuschel          #+#    #+#             */
/*   Updated: 2018/01/14 00:09:40 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(Point const & pos, char const symbol) : Entity(pos, symbol)
{
	this->pos = pos;
	this->symbol = symbol;
}

Bullet::Bullet(Bullet const & b) : Entity(b)
{
	*this = b;
}

Bullet&	Bullet::operator=(Bullet const & b)
{
	this->pos = b.getPos();
	this->symbol = b.getSym();
	return (*this);
}

Bullet::~Bullet()
{
}

char	Bullet::getSym() const
{
	return (this->symbol);
}
