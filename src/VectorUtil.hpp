#pragma once
#ifndef VECTOR_UTIL_HPP_
#define VECTOR_UTIL_HPP_

#include <SFML/System/Vector2.hpp>
#include <type_traits>
#include <typeinfo>

template<typename To, typename From> sf::Vector2<To> vector2Cast(sf::Vector2<From> arg)
{
	if (!std::is_convertible<From, To>::value)
	{
		throw std::exception{ "Invalid argument to class 'vectorCast' with non convertible types" };
	}
	return sf::Vector2<To>{ static_cast<To>(arg.x), static_cast<To>(arg.y) };
}

template<typename To, typename From> sf::Vector2<To> vector2Cast(From argX, To argY)
{
	return vector2Cast<To>(sf::Vector2<From>{ argX, argY });
}

#endif //VECTOR_UTIL_HPP_
