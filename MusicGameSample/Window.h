#pragma once
#include <boost/type_erasure/any_cast.hpp>
#include <boost/type_erasure/member.hpp>
#include <boost/mpl/vector.hpp>
#include <Windows.h>
#include <memory>
#include <string>

BOOST_TYPE_ERASURE_MEMBER((has_update), update, 0)

typedef boost::mpl::vector<
	has_update<void()>
> Updatable;

BOOST_TYPE_ERASURE_MEMBER((has_render), render, 0)

typedef boost::mpl::vector<
	has_render<void()>
> Renderer;
