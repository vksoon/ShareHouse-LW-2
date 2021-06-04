#pragma once

/* C Libraries */
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

/* STL Containers */
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <unordered_map>
#include <unordered_set>

/* STL Alogrithms & Functions */
#include <algorithm>
#include <functional>
#include <limits>
#include <iterator>

#define SAFE_DELETE(object)		\
	if(object)					\
		delete object;			\
	object = nullptr			

#define SAFE_RELEASE(object)	\
	if(object)					\
		object->Release();		\
	object = nullptr			