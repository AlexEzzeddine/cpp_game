/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:44:06 by bpuschel          #+#    #+#             */
/*   Updated: 2018/01/14 00:08:40 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP
#include "Entity.hpp"

class Bullet : public Entity
{
	public:
		Bullet(Point const & pos, char const symbol);
		Bullet(Bullet const & b);
		Bullet&	operator=(Bullet const & b);
		~Bullet();
		char	getSym() const;
};
#endif
